# $Id: Makefile.am,v 1.10 2009/06/03 01:10:50 ellson Exp $ $Revision: 1.10 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
        -I$(top_srcdir) \
        -I$(top_srcdir)/lib/agraph \
        -I$(top_srcdir)/lib/cdt

if WITH_CGRAPH
else
noinst_HEADERS = agutil.h
noinst_LTLIBRARIES = libagutil_C.la
endif

libagutil_C_la_SOURCES = dynattr.c nodeq.c agutil.h

EXTRA_DIST = agutil.vcproj
