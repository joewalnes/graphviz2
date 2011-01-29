/* $Id: poly.h,v 1.6 2011/01/25 16:30:49 ellson Exp $ $Revision: 1.6 $ */
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

#ifndef POLY_H
#define POLY_H

#include "geometry.h"

    typedef struct {
	Point origin;
	Point corner;
	int nverts;
	Point *verts;
	int kind;
    } Poly;

    extern void polyFree(void);
    extern int polyOverlap(Point, Poly *, Point, Poly *);
    extern void makePoly(Poly *, Agnode_t *, float, float);
    extern void makeAddPoly(Poly *, Agnode_t *, float, float);
    extern void breakPoly(Poly *);

#endif

#ifdef __cplusplus
}
#endif
