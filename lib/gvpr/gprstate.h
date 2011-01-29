/* $Id: gprstate.h,v 1.5 2011/01/25 16:30:49 ellson Exp $ $Revision: 1.5 $ */
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

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GPRSTATE_H
#define GPRSTATE_H

#include "sfio.h"
#include "cgraph.h"
#include "ast.h"
#include "vmalloc.h"
#include "expr.h"
#include "gvpr.h"

    typedef enum { TV_flat, TV_ne, TV_en, 
                   TV_bfs, 
                   TV_dfs, TV_fwd, TV_rev,
                   TV_postdfs, TV_postfwd, TV_postrev,
                   TV_prepostdfs, TV_prepostfwd, TV_prepostrev,
    } trav_type;

    typedef struct {
	Agraph_t *curgraph;
	Agraph_t *target;
	Agraph_t *outgraph;
	Agobj_t *curobj;
	Sfio_t *tmp;
	Exdisc_t *dp;
	Exerror_f errf;
	Exexit_f exitf;
	char *tgtname;
	char *infname;
	Sfio_t *outFile;
	Agiodisc_t* dfltIO;
	trav_type tvt;
	Agnode_t *tvroot;
	Agedge_t *tvedge;
	int name_used;
	int argc;
	char **argv;
	int flags;
	gvprbinding* bindings;
	int n_bindings;
    } Gpr_t;

    typedef struct {
	Sfio_t *outFile;
	int argc;
	char **argv;
	Exerror_f errf;
	Exexit_f exitf;
	int flags;
    } gpr_info;

    extern Gpr_t *openGPRState(gpr_info*);
    extern void addBindings(Gpr_t* state, gvprbinding*);
    extern gvprbinding* findBinding(Gpr_t* state, char*);
    extern void closeGPRState(Gpr_t* state);
    extern void initGPRState(Gpr_t *, Vmalloc_t *);
    extern int validTVT(int);

#ifdef WIN32_DLL
    extern int pathisrelative (char* path);
#endif

#endif

#ifdef __cplusplus
}
#endif
