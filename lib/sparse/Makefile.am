# $Id: Makefile.am,v 1.6 2009/06/03 01:10:55 ellson Exp $ $Revision: 1.6 $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
        -I$(top_srcdir) \
	-I$(top_srcdir)/lib/common 

noinst_HEADERS = SparseMatrix.h
noinst_LTLIBRARIES = libsparse_C.la

libsparse_C_la_SOURCES = SparseMatrix.c

EXTRA_DIST = Makefile.old gvsparse.vcproj
