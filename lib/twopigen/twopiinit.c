/* $Id: twopiinit.c,v 1.21 2011/01/28 21:24:44 erg Exp $ $Revision: 1.21 $ */
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
 * Written by Emden R. Gansner
 * Derived from Graham Wills' algorithm described in GD'97.
 */

#include    "circle.h"
#include    "adjust.h"
#include    "pack.h"
#include    "neatoprocs.h"

static void twopi_init_edge(edge_t * e)
{
#ifdef WITH_CGRAPH
    agbindrec(e, "Agedgeinfo_t", sizeof(Agedgeinfo_t), TRUE);	//node custom data
#endif /* WITH_CGRAPH */
    common_init_edge(e);
    ED_factor(e) = late_double(e, E_weight, 1.0, 0.0);
}

static void twopi_init_node_edge(graph_t * g)
{
    node_t *n;
    edge_t *e;
    int i = 0;
    rdata* alg = N_NEW(agnnodes(g), rdata);

    GD_neato_nlist(g) = N_NEW(agnnodes(g) + 1, node_t *);
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	neato_init_node(n);
	ND_alg(n) = alg + i;
	GD_neato_nlist(g)[i++] = n;
    }
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    twopi_init_edge(e);
	}
    }
}

void twopi_init_graph(graph_t * g)
{
    setEdgeType (g, ET_LINE);
    /* GD_ndim(g) = late_int(g,agfindgraphattr(g,"dim"),2,2); */
	Ndim = GD_ndim(g)=2;	/* The algorithm only makes sense in 2D */
    twopi_init_node_edge(g);
}

/* twopi_layout:
 */
void twopi_layout(Agraph_t * g)
{
    Agnode_t *ctr = 0;
    char *s;
    int setRoot = 0;

    twopi_init_graph(g);
    s = agget(g, "root");
    if ((s = agget(g, "root"))) {
	if (*s) {
	    ctr = agfindnode(g, s);
	    if (!ctr) {
		agerr(AGWARN, "specified root node \"%s\" was not found.", s);
		agerr(AGPREV, "Using default calculation for root node\n");
		setRoot = 1;
	    }
	}
	else {
	    setRoot = 1;
	}
    }
    if (agnnodes(g)) {
	Agraph_t **ccs;
	Agraph_t *sg;
	Agnode_t *c = NULL;
	int ncc;
	int i;

	ccs = ccomps(g, &ncc, 0);
	if (ncc == 1) {
	    c = circleLayout(g, ctr);
	    if (setRoot && !ctr)
		ctr = c;
	    free(ND_alg(agfstnode(g)));
	    adjustNodes(g);
	    spline_edges(g);
	} else {
	    pack_info pinfo;
	    getPackInfo (g, l_node, CL_OFFSET, &pinfo);
	    pinfo.doSplines = 1;

	    for (i = 0; i < ncc; i++) {
		sg = ccs[i];
		if (ctr && agcontains(sg, ctr))
		    c = ctr;
		else
		    c = 0;
		nodeInduce(sg);
		c = circleLayout(sg, c);
	        if (setRoot && !ctr)
		    ctr = c;
		adjustNodes(sg);
		setEdgeType (sg, ET_LINE);
		spline_edges(sg);
	    }
	    free(ND_alg(agfstnode(g)));
	    packSubgraphs(ncc, ccs, g, &pinfo);
	}
	for (i = 0; i < ncc; i++) {
	    agdelete(g, ccs[i]);
	}
	free(ccs);
    }
    if (setRoot)
	agset (g, "root", agnameof (ctr)); 
    dotneato_postprocess(g);

}

static void twopi_cleanup_graph(graph_t * g)
{
    free(GD_neato_nlist(g));
    if (g != agroot(g))
#ifndef WITH_CGRAPH
	memset(&(g->u), 0, sizeof(Agraphinfo_t));
#else /* WITH_CGRAPH */
	agclean(g,AGRAPH,"Agraphinfo_t");
#endif /* WITH_CGRAPH */
}

void twopi_cleanup(graph_t * g)
{
    node_t *n;
    edge_t *e;

    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    gv_cleanup_edge(e);
	}
	gv_cleanup_node(n);
    }
    twopi_cleanup_graph(g);
}
