/* $Id: globals.c,v 1.11 2011/01/25 16:30:48 ellson Exp $ $Revision: 1.11 $ */
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define EXTERN
#include "types.h"
#include "globals.h"

/* Default layout values, possibly set via command line; -1 indicates unset */
fdpParms_t fdp_parms = {
    1,                          /* useGrid */
    1,                          /* useNew */
    -1,                         /* numIters */
    50,                         /* unscaled */
    0.0,                        /* C */
    1.0,                        /* Tfact */
    -1.0,                       /* K - set in initParams; used in init_edge */
    -1.0,                       /* T0 */
};

