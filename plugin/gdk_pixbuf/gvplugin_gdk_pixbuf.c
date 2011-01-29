/* $Id: gvplugin_gdk_pixbuf.c,v 1.6 2011/01/25 16:30:51 ellson Exp $ $Revision: 1.6 $ */
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

#include "gvplugin.h"

extern gvplugin_installed_t gvdevice_gdk_pixbuf_types[];

static gvplugin_api_t apis[] = {
    {API_device, gvdevice_gdk_pixbuf_types},
    {(api_t)0, 0},
};

gvplugin_library_t gvplugin_gdk_pixbuf_LTX_library = { "gdk_pixbuf", apis };