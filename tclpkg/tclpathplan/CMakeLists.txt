# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

SUBDIRS( demo ) 

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_BINARY_DIR}
	${CMAKE_SOURCE_DIR}/tclpkg/tclhandle
	${CMAKE_SOURCE_DIR}/lib/pathplan
	${TCL_INCLUDE_PATH}
)

SET(tclplan_SRCS
	find_ints.c
	intersect.c
	makecw.c
	tclpathplan.c
	wrapper.c
)

ADD_LIBRARY(tclplan MODULE ${tclplan_SRCS})



########### install files ###############




#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#SUBDIRS = demo
#
#pkgtcldir = $(pkglibdir)/tcl
#
#AM_CPPFLAGS = \
#	-I$(top_srcdir) \
#	-I$(top_srcdir)/tclpkg/tclhandle \
#	-I$(top_srcdir)/lib/pathplan @TCL_INCLUDES@
#
#AM_CFLAGS = @TCL_CFLAGS@
#
#noinst_HEADERS = simple.h
#if WITH_TCL
#pkgtcl_LTLIBRARIES = libtclplan.la
#endif
#
#libtclplan_la_SOURCES = find_ints.c intersect.c makecw.c tclpathplan.c wrapper.c
#libtclplan_la_LDFLAGS = -no-undefined
#libtclplan_la_LIBADD = \
#	$(top_builddir)/tclpkg/tclhandle/libtclhandle_C.la \
#	$(top_builddir)/tclpkg/tclstubs/libtclstubs_C.la \
#	$(top_builddir)/lib/pathplan/libpathplan.la
#
#if WITH_TCL
#all-local: pkgIndex.tcl
#
#pkgIndex.tcl: libtclplan.la
#	sh $(top_srcdir)/tclpkg/mkpkgindex.sh libtclplan.la Tclpathplan $(VERSION)
#endif
#
#CLEANFILES = pkgIndex.tcl
#
#EXTRA_DIST = $(libtclplan_la_SOURCES)
