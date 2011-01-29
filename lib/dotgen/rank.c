/* $Id: rank.c,v 1.22 2011/01/25 16:30:48 ellson Exp $ $Revision: 1.22 $ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/


/*
 * Rank the nodes of a directed graph, subject to user-defined
 * sets of nodes to be kept on the same, min, or max rank.
 * The temporary acyclic fast graph is constructed and ranked
 * by a network-simplex technique.  Then ranks are propagated
 * to non-leader nodes and temporary edges are deleted.
 * Leaf nodes and top-level clusters are left collapsed, though.
 * Assigns global minrank and maxrank of graph and all clusters.
 *
 * TODO: safety code.  must not be in two clusters at same level.
 *  must not be in same/min/max/rank and a cluster at the same time.
 *  watch out for interactions between leaves and clusters.
 */

#include	"dot.h"

static void 
renewlist(elist * L)
{
    int i;
    for (i = L->size; i >= 0; i--)
	L->list[i] = NULL;
    L->size = 0;
}

static void 
cleanup1(graph_t * g)
{
    node_t *n;
    edge_t *e, *f;
    int c;

    for (c = 0; c < GD_comp(g).size; c++) {
	GD_nlist(g) = GD_comp(g).list[c];
	for (n = GD_nlist(g); n; n = ND_next(n)) {
	    renewlist(&ND_in(n));
	    renewlist(&ND_out(n));
	    ND_mark(n) = FALSE;
	}
    }
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    f = ED_to_virt(e);
	    /* Null out any other references to f to make sure we don't 
	     * handle it a second time. For example, parallel multiedges 
	     * share a virtual edge.
	     */
	    if (f && (e == ED_to_orig(f))) {
		edge_t *e1, *f1;
		for (e1 = agfstout(g, n); e1; e1 = agnxtout(g, e1)) {
		    if (e != e1) {
			f1 = ED_to_virt(e1);
			if (f1 && (f == f1)) {
			    ED_to_virt(e1) = NULL;
			}
		    }
		}
		free(f);
	    }
	    ED_to_virt(e) = NULL;
	}
    }
    free(GD_comp(g).list);
    GD_comp(g).list = NULL;
    GD_comp(g).size = 0;
}

/* When there are edge labels, extra ranks are reserved here for the virtual
 * nodes of the labels.  This is done by doubling the input edge lengths.
 * The input rank separation is adjusted to compensate.
 */
static void 
edgelabel_ranks(graph_t * g)
{
    node_t *n;
    edge_t *e;

    if (GD_has_labels(g) & EDGE_LABEL) {
	for (n = agfstnode(g); n; n = agnxtnode(g, n))
	    for (e = agfstout(g, n); e; e = agnxtout(g, e))
		ED_minlen(e) *= 2;
	GD_ranksep(g) = (GD_ranksep(g) + 1) / 2;
    }
}

/* Merge the nodes of a min, max, or same rank set. */
static void 
collapse_rankset(graph_t * g, graph_t * subg, int kind)
{
    node_t *u, *v;

    u = v = agfstnode(subg);
    if (u) {
	ND_ranktype(u) = kind;
	while ((v = agnxtnode(subg, v))) {
	    UF_union(u, v);
	    ND_ranktype(v) = ND_ranktype(u);
	}
	switch (kind) {
	case MINRANK:
	case SOURCERANK:
	    if (GD_minset(g) == NULL)
		GD_minset(g) = u;
	    else
		GD_minset(g) = UF_union(GD_minset(g), u);
	    break;
	case MAXRANK:
	case SINKRANK:
	    if (GD_maxset(g) == NULL)
		GD_maxset(g) = u;
	    else
		GD_maxset(g) = UF_union(GD_maxset(g), u);
	    break;
	}
	switch (kind) {
	case SOURCERANK:
	    ND_ranktype(GD_minset(g)) = kind;
	    break;
	case SINKRANK:
	    ND_ranktype(GD_maxset(g)) = kind;
	    break;
	}
    }
}

static int 
rank_set_class(graph_t * g)
{
    static char *name[] = { "same", "min", "source", "max", "sink", NULL };
    static int class[] =
	{ SAMERANK, MINRANK, SOURCERANK, MAXRANK, SINKRANK, 0 };
    int val;

    if (is_cluster(g))
	return CLUSTER;
    val = maptoken(agget(g, "rank"), name, class);
    GD_set_type(g) = val;
    return val;
}

static int 
make_new_cluster(graph_t * g, graph_t * subg)
{
    int cno;
    cno = ++(GD_n_cluster(g));
    GD_clust(g) = ZALLOC(cno + 1, GD_clust(g), graph_t *, GD_n_cluster(g));
    GD_clust(g)[cno] = subg;
    do_graph_label(subg);
    return cno;
}

static void 
node_induce(graph_t * par, graph_t * g)
{
    node_t *n, *nn;
    edge_t *e;
    int i;

    /* enforce that a node is in at most one cluster at this level */
    for (n = agfstnode(g); n; n = nn) {
	nn = agnxtnode(g, n);
	if (ND_ranktype(n)) {
	    agdelete(g, n);
	    continue;
	}
	for (i = 1; i < GD_n_cluster(par); i++)
	    if (agcontains(GD_clust(par)[i], n))
		break;
	if (i < GD_n_cluster(par))
	    agdelete(g, n);
	ND_clust(n) = NULL;
    }

    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(agroot(g), n); e; e = agnxtout(agroot(g), e)) {
	    if (agcontains(g, aghead(e)))
#ifndef WITH_CGRAPH
		aginsert(g, e);
#else /* WITH_CGRAPH */
		agsubedge(g,e,1);
#endif /* WITH_CGRAPH */
	}
    }
}

void 
dot_scan_ranks(graph_t * g)
{
    node_t *n, *leader = NULL;
    GD_minrank(g) = MAXSHORT;
    GD_maxrank(g) = -1;
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	if (GD_maxrank(g) < ND_rank(n))
	    GD_maxrank(g) = ND_rank(n);
	if (GD_minrank(g) > ND_rank(n))
	    GD_minrank(g) = ND_rank(n);
	if (leader == NULL)
	    leader = n;
	else {
	    if (ND_rank(n) < ND_rank(leader))
		leader = n;
	}
    }
    GD_leader(g) = leader;
}

static void
cluster_leader(graph_t * clust)
{
    node_t *leader, *n;
    int maxrank = 0;

    /* find number of ranks and select a leader */
    leader = NULL;
    for (n = GD_nlist(clust); n; n = ND_next(n)) {
	if ((ND_rank(n) == 0) && (ND_node_type(n) == NORMAL))
	    leader = n;
	if (maxrank < ND_rank(n))
	    maxrank = ND_rank(n);
    }
    assert(leader != NULL);
    GD_leader(clust) = leader;

    for (n = agfstnode(clust); n; n = agnxtnode(clust, n)) {
	assert((ND_UF_size(n) <= 1) || (n == leader));
	UF_union(n, leader);
	ND_ranktype(n) = CLUSTER;
    }
}

/*
 * A cluster is collapsed in three steps.
 * 1) The nodes of the cluster are ranked locally.
 * 2) The cluster is collapsed into one node on the least rank.
 * 3) In class1(), any inter-cluster edges are converted using
 *    the "virtual node + 2 edges" trick.
 */
static void 
collapse_cluster(graph_t * g, graph_t * subg)
{
    if (GD_cluster_was_collapsed(subg))
	return;
    GD_cluster_was_collapsed(subg) = TRUE;
    node_induce(g, subg);
    if (agfstnode(subg) == NULL)
	return;
    make_new_cluster(g, subg);
    if (CL_type == LOCAL) {
	dot_rank(subg, 0);
	cluster_leader(subg);
    } else
	dot_scan_ranks(subg);
}

/* Execute union commands for "same rank" subgraphs and clusters. */
static void 
collapse_sets(graph_t *rg, graph_t *g)
{
    int c;
    graph_t  *subg;
    node_t *n;

#ifndef WITH_CGRAPH
    graph_t *mg;
    node_t *mn;
    edge_t *me;
    mg = g->meta_node->graph;
    for (me = agfstout(mg, g->meta_node); me; me = agnxtout(mg, me)) {
	mn = aghead(me);
	subg = agusergraph(mn);
#else /* WITH_CGRAPH */
    for (subg = agfstsubg(g); subg; subg = agnxtsubg(subg)) {
#endif /* WITH_CGRAPH */
	c = rank_set_class(subg);
	if (c) {
	    if ((c == CLUSTER) && CL_type == LOCAL)
		collapse_cluster(rg, subg);
	    else
		collapse_rankset(rg, subg, c);
	}
	else collapse_sets(rg, subg);

	/* mark nodes with ordered edges so their leaves are not collapsed */
	if (agget(subg, "ordering"))
	    for (n = agfstnode(subg); n; n = agnxtnode(subg, n))
		ND_order(n) = 1;
    }
}

static void 
find_clusters(graph_t * g)
{
    graph_t *subg;
#ifndef WITH_CGRAPH
    graph_t *mg;
    node_t *mn;
    edge_t *me;

    mg = g->meta_node->graph;
    for (me = agfstout(mg, g->meta_node); me; me = agnxtout(mg, me)) {
	mn = me->head;
	subg = agusergraph(mn);
#else /* WITH_CGRAPH */
    for (subg = agfstsubg(agroot(g)); subg; subg = agnxtsubg(subg)) {
#endif /* WITH_CGRAPH */
	if (GD_set_type(subg) == CLUSTER)
	    collapse_cluster(g, subg);
    }
}

static void 
set_minmax(graph_t * g)
{
    int c;

    GD_minrank(g) += ND_rank(GD_leader(g));
    GD_maxrank(g) += ND_rank(GD_leader(g));
    for (c = 1; c <= GD_n_cluster(g); c++)
	set_minmax(GD_clust(g)[c]);
}

/* To ensure that min and max rank nodes always have the intended rank
 * assignment, reverse any incompatible edges.
 */
static point 
minmax_edges(graph_t * g)
{
    node_t *n;
    edge_t *e;
    point  slen;

    slen.x = slen.y = 0;
    if ((GD_maxset(g) == NULL) && (GD_minset(g) == NULL))
	return slen;
    if (GD_minset(g) != NULL)
	GD_minset(g) = UF_find(GD_minset(g));
    if (GD_maxset(g) != NULL)
	GD_maxset(g) = UF_find(GD_maxset(g));

    if ((n = GD_maxset(g))) {
	slen.y = (ND_ranktype(GD_maxset(g)) == SINKRANK);
	while ((e = ND_out(n).list[0])) {
	    assert(aghead(e) == UF_find(aghead(e)));
	    reverse_edge(e);
	}
    }
    if ((n = GD_minset(g))) {
	slen.x = (ND_ranktype(GD_minset(g)) == SOURCERANK);
	while ((e = ND_in(n).list[0])) {
	    assert(agtail(e) == UF_find(agtail(e)));
	    reverse_edge(e);
	}
    }
    return slen;
}
    
static int 
minmax_edges2(graph_t * g, point slen)
{
    node_t *n;
    edge_t *e = 0;

    if ((GD_maxset(g)) || (GD_minset(g))) {
	for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	    if (n != UF_find(n))
		continue;
	    if ((ND_out(n).size == 0) && GD_maxset(g) && (n != GD_maxset(g))) {
		e = virtual_edge(n, GD_maxset(g), NULL);
		ED_minlen(e) = slen.y;
	    }
	    if ((ND_in(n).size == 0) && GD_minset(g) && (n != GD_minset(g))) {
		e = virtual_edge(GD_minset(g), n, NULL);
		ED_minlen(e) = slen.x;
	    }
	}
    }
    return (e != 0);
}

/* Run the network simplex algorithm on each component. */
void rank1(graph_t * g)
{
    int maxiter = INT_MAX;
    int c;
    char *s;

    if ((s = agget(g, "nslimit1")))
	maxiter = atof(s) * agnnodes(g);
    for (c = 0; c < GD_comp(g).size; c++) {
	GD_nlist(g) = GD_comp(g).list[c];
	rank(g, (GD_n_cluster(g) == 0 ? 1 : 0), maxiter);	/* TB balance */
    }
}

/* 
 * Assigns ranks of non-leader nodes.
 * Expands same, min, max rank sets.
 * Leaf sets and clusters remain merged.
 * Sets minrank and maxrank appropriately.
 */
static void expand_ranksets(graph_t * g, aspect_t* asp)
{
    int c;
    node_t *n, *leader;

    if ((n = agfstnode(g))) {
	GD_minrank(g) = MAXSHORT;
	GD_maxrank(g) = -1;
	while (n) {
	    leader = UF_find(n);
	    /* The following works because ND_rank(n) == 0 if n is not in a
	     * cluster, and ND_rank(n) = the local rank offset if n is in
	     * a cluster. */
	    if ((leader != n) && (!asp || (ND_rank(n) == 0)))
		ND_rank(n) += ND_rank(leader);

	    if (GD_maxrank(g) < ND_rank(n))
		GD_maxrank(g) = ND_rank(n);
	    if (GD_minrank(g) > ND_rank(n))
		GD_minrank(g) = ND_rank(n);

	    if (ND_ranktype(n) && (ND_ranktype(n) != LEAFSET))
		UF_singleton(n);
	    n = agnxtnode(g, n);
	}
	if (g == agroot(g)) {
	    if (CL_type == LOCAL) {
		for (c = 1; c <= GD_n_cluster(g); c++)
		    set_minmax(GD_clust(g)[c]);
	    } else {
		find_clusters(g);
	    }
	}
    } else {
	GD_minrank(g) = GD_maxrank(g) = 0;
    }
}

#ifdef ALLOW_LEVELS
void
setRanks (graph_t* g, attrsym_t* lsym)
{
    node_t* n;
    char*   s;
    char*   ep;
    long    v;

    for (n = agfstnode(g); n; n = agnxtnode(g,n)) {
	s = agxget (n, lsym->index);
	v = strtol (s, &ep, 10);
	if (ep == s)
	    agerr(AGWARN, "no level attribute for node \"%s\"\n", n->name);
	ND_rank(n) = v;
    }
}
#endif

#ifdef UNUSED
static node_t **virtualEdgeHeadList = NULL;
static node_t **virtualEdgeTailList = NULL;
static int nVirtualEdges = 0;

static void
saveVirtualEdges(graph_t *g)
{
    edge_t *e;
    node_t *n;
    int cnt = 0;
    int lc;
    
    if (virtualEdgeHeadList != NULL) {
	free(virtualEdgeHeadList);
    }
    if (virtualEdgeTailList != NULL) {
	free(virtualEdgeTailList);
    }

  /* allocate memory */
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (lc = 0; lc < ND_in(n).size; lc++) {
	    e = ND_in(n).list[lc];
	    if (ED_edge_type(e) == VIRTUAL) cnt++;
	}
    }

    nVirtualEdges = cnt;
    virtualEdgeHeadList = N_GNEW(cnt, node_t*);
    virtualEdgeTailList = N_GNEW(cnt, node_t*);

    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (lc = 0, cnt = 0; lc < ND_in(n).size; lc++) {
	    e = ND_in(n).list[lc];
	    if (ED_edge_type(e) == VIRTUAL) {
		virtualEdgeHeadList[cnt] = e->head;
		virtualEdgeTailList[cnt] = e->tail;
		if (Verbose)
		    printf("saved virtual edge: %s->%s\n", 
			virtualEdgeTailList[cnt]->name, 
			virtualEdgeHeadList[cnt]->name);	    
		cnt++;
	    }
	}
    }
}

static void
restoreVirtualEdges(graph_t *g)
{
    int i;
    edge_t e;

    for (i = 0; i < nVirtualEdges; i++) {
	if (virtualEdgeTailList[i] && virtualEdgeHeadList[i]) {
	    if (Verbose)
		printf("restoring virtual edge: %s->%s\n", 
		    virtualEdgeTailList[i]->name, virtualEdgeHeadList[i]->name);
	    virtual_edge(virtualEdgeTailList[i], virtualEdgeHeadList[i], NULL);
	}
    }
    if (Verbose)
	printf("restored %d virt edges\n", nVirtualEdges);
}
#endif

/* dot_rank:
 * asp != NULL => g is root
 */
void dot_rank(graph_t * g, aspect_t* asp)
{
    point p;
#ifdef ALLOW_LEVELS
    attrsym_t* N_level;
#endif
    edgelabel_ranks(g);

    if (asp) {
	init_UF_size(g);
	initEdgeTypes(g);
    }

    collapse_sets(g,g);
    /*collapse_leaves(g); */
    class1(g);
    p = minmax_edges(g);
    decompose(g, 0);
    if (asp && ((GD_comp(g).size > 1)||(GD_n_cluster(g) > 0))) {
	asp->badGraph = 1;
	asp = NULL;
    }
    acyclic(g);
    if (minmax_edges2(g, p))
	decompose(g, 0);
#ifdef ALLOW_LEVELS
    if ((N_level = agfindattr(g->proto->n, "level")))
	setRanks(g, N_level);
    else
#endif

    if (asp)
	rank3(g, asp);
    else
	rank1(g);

    expand_ranksets(g, asp);
    cleanup1(g);
}

int is_cluster(graph_t * g)
{
    return (strncmp(agnameof(g), "cluster", 7) == 0);
}

#ifdef OBSOLETE
static node_t*
merge_leaves(graph_t * g, node_t * cur, node_t * new)
{
    node_t *rv;

    if (cur == NULL)
	rv = new;
    else {
	rv = UF_union(cur, new);
	ND_ht(rv) = MAX(ND_ht(cur), ND_ht(new));
	ND_lw(rv) = ND_lw(cur) + ND_lw(new) + GD_nodesep(g) / 2;
	ND_rw(rv) = ND_rw(cur) + ND_rw(new) + GD_nodesep(g) / 2;
    }
    return rv;
}

static void 
potential_leaf(graph_t * g, edge_t * e, node_t * leaf)
{
    node_t *par;

    if ((ED_tail_port(e).p.x) || (ED_head_port(e).p.x))
	return;
    if ((ED_minlen(e) != 1) || (ND_order(agtail(e)) > 0))
	return;
    par = ((leaf != aghead(e)) ? aghead(e) : agtail(e));
    ND_ranktype(leaf) = LEAFSET;
    if (par == agtail(e))
	GD_outleaf(par) = merge_leaves(g, GD_outleaf(par), leaf);
    else
	GD_inleaf(par) = merge_leaves(g, GD_inleaf(par), leaf);
}

static void 
collapse_leaves(graph_t * g)
{
    node_t *n;
    edge_t *e;

    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {

	/* consider n as a potential leaf of some other node. */
	if ((ND_ranktype(n) != NOCMD) || (ND_order(n)))
	    continue;
	if (agfstout(g, n) == NULL) {
	    if ((e = agfstin(g, n)) && (agnxtin(g, e) == NULL)) {
		potential_leaf(g, e, n);
		continue;
	    }
	}
	if (agfstin(g, n) == NULL) {
	    if ((e = agfstout(g, n)) && (agnxtout(g, e) == NULL)) {
		potential_leaf(g, e, n);
		continue;
	    }
	}
    }
}
#endif

