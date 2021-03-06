# $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:47 ellson Exp $ $Revision: 1.4 $
## Process this file with cmake to produce Makefile

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}lib/expr
	${CMAKE_SOURCE_DIR}lib/vmalloc
	${CMAKE_SOURCE_DIR}lib/sfio
	${CMAKE_SOURCE_DIR}lib/ast
	${CMAKE_SOURCE_DIR}lib/ingraphs
	${CMAKE_SOURCE_DIR}lib/agraph
	${CMAKE_SOURCE_DIR}lib/cdt
)


########### next target ###############

SET(gvpr_SRCS
	actions.c
	compile.c
	gvpr.c
	gprstate.c
	parse.c
	queue.c
)

ADD_EXECUTABLE(gvpr ${gvpr_SRCS})

#TARGET_LINK_LIBRARIES(gvpr  ${QT_AND_KDECORE_LIBS} )

INSTALL_TARGETS(/bin gvpr )


########### next target ###############

SET(mkdefs_SRCS
	mkdefs.c
)

ADD_EXECUTABLE(mkdefs ${mkdefs_SRCS})

#TARGET_LINK_LIBRARIES(mkdefs  ${QT_AND_KDECORE_LIBS} )


########### install files ###############

INSTALL_FILES( FILES
	gvpr.pdf
)



#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:47 ellson Exp $ $Revision: 1.4 $
### Process this file with automake to produce Makefile.in
#
#pdfdir = $(pkgdatadir)/doc/pdf
#
#AM_CPPFLAGS = \
#        -I$(top_srcdir) \
#        -I$(top_srcdir)/lib/expr \
#	-I$(top_srcdir)/lib/vmalloc \
#	-I$(top_srcdir)/lib/sfio \
#	-I$(top_srcdir)/lib/ast \
#	-I$(top_srcdir)/lib/ingraphs \
#	-I$(top_srcdir)/lib/agraph \
#	-I$(top_srcdir)/lib/cdt
#
#bin_PROGRAMS = gvpr
#noinst_PROGRAMS = mkdefs
#noinst_HEADERS = actions.h compile.h gprstate.h parse.h queue.h
#man_MANS = gvpr.1
#pdf_DATA = gvpr.pdf
#
#gvpr_SOURCES = actions.c compile.c gvpr.c gprstate.c parse.c queue.c
#
#gvpr_LDADD = \
#	$(top_builddir)/lib/vmalloc/libvmalloc_C.la \
#	$(top_builddir)/lib/sfio/libsfio_C.la \
#        $(top_builddir)/lib/ingraphs/libingraphs_C.la \
#	$(top_builddir)/lib/expr/libexpr.la \
#	$(top_builddir)/lib/agraph/libagraph.la @MATH_LIBS@
#
#gvpr_DEPENDENCIES = \
#       $(top_builddir)/lib/ast/libast_C.la
#
#$(gvpr_OBJECTS): gdefs.h
#
#mkdefs_SOURCES = mkdefs.c
#
#gdefs.h: $(top_srcdir)/cmd/gvpr/gprdata mkdefs
#	./mkdefs gdefs.h < $(top_srcdir)/cmd/gvpr/gprdata
#
#.1.pdf:
#	groff -Tps -man $< | ps2pdf - - >$@
#
#EXTRA_DIST = $(man_MANS) $(pdf_DATA) Makefile.old gprdata mkdefs.c gdefs.h
#
#DISTCLEANFILES = $(pdf_DATA) gdefs.h mkdefs
