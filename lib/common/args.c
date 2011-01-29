/* $Id: args.c,v 1.23 2011/01/25 16:30:48 ellson Exp $ $Revision: 1.23 $ */
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

/* FIXME
 * This is an ugly mess.
 *
 * Args should be made independent of layout engine and arg values
 * should be stored in gvc or gvc->job.   All globals should be eliminated.
 *
 * Needs to be fixed before layout engines can be plugins.
 */

#include <ctype.h>
#include "render.h"
#include "tlayout.h"
#include "gvc.h"

static int
neato_extra_args(GVC_t *gvc, int argc, char** argv)
{
  char** p = argv+1;
  int    i;
  char*  arg;
  int    cnt = 1;

  for (i = 1; i < argc; i++) {
    arg = argv[i];
    if (arg && *arg == '-') {
      switch (arg[1]) {
      case 'x' : Reduce = TRUE; break;
      case 'n':
        if (arg[2]) {
          Nop = atoi(arg+2);
          if (Nop <= 0) {
            fprintf (stderr, "Invalid parameter \"%s\" for -n flag\n", arg+2);
            dotneato_usage (1);
          }
        }
        else Nop = 1;
        break;
      default :
        cnt++;
        if (*p != arg) *p = arg;
        p++;
        break;
      }
    }
    else {
      cnt++;
      if (*p != arg) *p = arg;
      p++;
    }
  }
  *p = 0;
  return cnt;
}

static int
memtest_extra_args(GVC_t *gvc, int argc, char** argv)
{
  char** p = argv+1;
  int    i;
  char*  arg;
  int    cnt = 1;

  for (i = 1; i < argc; i++) {
    arg = argv[i];
    if (arg && *arg == '-') {
      switch (arg[1]) {
      case 'm' : MemTest = TRUE; break;
      default :
        cnt++;
        if (*p != arg) *p = arg;
        p++;
        break;
      }
    }
    else {
      cnt++;
      if (*p != arg) *p = arg;
      p++;
    }
  }
  *p = 0;
  return cnt;
}

static int
config_extra_args(GVC_t *gvc, int argc, char** argv)
{
  char** p = argv+1;
  int    i;
  char*  arg;
  int    cnt = 1;

  for (i = 1; i < argc; i++) {
    arg = argv[i];
    if (arg && *arg == '-') {
      switch (arg[1]) {
      case 'v':
	gvc->common.verbose = 1;
	if (isdigit(arg[2]))
	  gvc->common.verbose = atoi(&arg[2]);
        break;
      case 'O' :
          gvc->common.auto_outfile_names = TRUE;
	  break;
      case 'c' :
          gvc->common.config = TRUE;
	  break;
      default :
        cnt++;
        if (*p != arg) *p = arg;
        p++;
        break;
      }
    }
    else {
      cnt++;
      if (*p != arg) *p = arg;
      p++;
    }
  }
  *p = 0;
  return cnt;
}

/* setDouble:
 * If arg is an double, value is stored in v
 * and functions returns 0; otherwise, returns 1.
 */
static int
setDouble (double* v, char* arg)
{
  char*    p;
  double   d;

  d = strtod(arg,&p);
  if (p == arg) {
    agerr (AGERR, "bad value in flag -L%s - ignored\n", arg-1);
    return 1;
  }
  *v = d;
  return 0;
}

/* setInt:
 * If arg is an integer, value is stored in v
 * and functions returns 0; otherwise, returns 1.
 */
static int
setInt (int* v, char* arg)
{
  char*    p;
  int      i;

  i = (int)strtol(arg,&p,10);
  if (p == arg) {
    agerr (AGERR, "bad value in flag -L%s - ignored\n", arg-1);
    return 1;
  }
  *v = i;
  return 0;
}

/* setFDPAttr:
 * Actions for fdp specific flags
 */
static int
setFDPAttr (char* arg)
{
  switch (*arg++) {
  case 'g' :
    fdp_parms.useGrid = 0;
    break;
  case 'O' :
    fdp_parms.useNew = 0;
    break;
  case 'n' :
    if (setInt (&fdp_parms.numIters, arg)) return 1;
    break;
  case 'U' :
    if (setInt (&fdp_parms.unscaled, arg)) return 1;
    break;
  case 'C' :
    if (setDouble (&fdp_parms.C, arg)) return 1;
    break;
  case 'T' :
    if (*arg == '*') {
      if (setDouble (&fdp_parms.Tfact, arg+1)) return 1;
    }
    else {
      if (setDouble (&fdp_parms.T0, arg)) return 1;
    }
    break;
  default :
    agerr (AGWARN, "unknown flag -L%s - ignored\n", arg-1);
    break;
  }
  return 0;
}

/* fdp_extra_args:
 * Handle fdp specific arguments.
 * These have the form -L<name>=<value>.
 */
static int
fdp_extra_args (GVC_t *gvc, int argc, char** argv)
{
  char** p = argv+1;
  int    i;
  char*  arg;
  int    cnt = 1;

  for (i = 1; i < argc; i++) {
    arg = argv[i];
    if (arg && (*arg == '-') && (*(arg+1) == 'L')) {
      if (setFDPAttr (arg+2)) dotneato_usage(1);
    }
    else {
      cnt++;
      if (*p != arg) *p = arg;
      p++;
    }
  }
  *p = 0;
  return cnt;
}

int gvParseArgs(GVC_t *gvc, int argc, char** argv)
{
    argc = neato_extra_args(gvc, argc, argv);
    argc = fdp_extra_args(gvc, argc, argv);
    argc = memtest_extra_args(gvc, argc, argv);
    argc = config_extra_args(gvc, argc, argv);
    dotneato_args_initialize(gvc, argc, argv);
    if (Verbose)
	gvplugin_write_status(gvc);
    return 0;
}
