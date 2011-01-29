# $Id: Makefile.am,v 1.8 2009/06/03 01:10:54 ellson Exp $ $Revision: 1.8 $
## Process this file with automake to produce Makefile.in

if WITH_CGRAPH
GRAPH = cgraph
else
GRAPH = graph
endif

AM_CPPFLAGS = \
        -I$(top_srcdir) \
        -I$(top_srcdir)/lib/common \
	-I$(top_srcdir)/lib/gvc \
	-I$(top_srcdir)/lib/neatogen \
	-I$(top_srcdir)/lib/fdpgen \
	-I$(top_srcdir)/lib/pack \
	-I$(top_srcdir)/lib/pathplan \
	-I$(top_srcdir)/lib/sparse \
	-I$(top_srcdir)/lib/$(GRAPH) \
	-I$(top_srcdir)/lib/cdt

noinst_HEADERS = patchwork.h
noinst_LTLIBRARIES = libpatchwork_C.la

libpatchwork_C_la_SOURCES = patchwork.c patchworkinit.c

EXTRA_DIST = Makefile.old gvpatchwork.vcproj
