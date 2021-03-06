# $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:47 ellson Exp $ $Revision: 1.4 $
## Process this file with cmake to produce Makefile

INCLUDE( FindX11 )

SUBDIRS(
	ws
	os
	dot2l
	examples
)

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/ws/x11
	${CMAKE_CURRENT_SOURCE_DIR}/os/unix
	${CMAKE_CURRENT_SOURCE_DIR}/dot2l
	${X11_INCLUDE_DIR}
)

########### next target ###############

SET(lefty_SRCS
	code.c
	common.c
	display.c
	exec.c
	g.c
	gfxview.c
	internal.c
	lefty.c
	lex.c
	mem.c
	parse.c
	str.c
	tbl.c
	txtview.c
)

ADD_EXECUTABLE(lefty ${lefty_SRCS})

TARGET_LINK_LIBRARIES(lefty
	ws
	filereq
	os
	dot2l
	Xaw
	Xt
	Xmu
	Xext
	X11
#	socket
	m
)

INSTALL_TARGETS(/bin lefty )


########### install files ###############

INSTALL_FILES( FILES
	lefty.psp
)
INSTALL_FILES( FILES
	lefty.pdf
)
INSTALL_FILES( FILES
	lefty.man
)



#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:47 ellson Exp $ $Revision: 1.4 $
### Process this file with automake to produce Makefile.in
#
#SUBDIRS = ws os dot2l examples
#
## lefty build parameters
##not useful / old:
##  FEATURE_CS          coshell support
##  FEATURE_NETSCAPE    build lefty as a netscape plugin
##  FEATURE_RUSAGE      print rusage stats on exit
##  FEATURE_VFORK       use vfork instead of fork
##  FEATURE_GMAP        build performer version of lefty (source in lefty3d)
##  FEATURE_MESAGL      assume MesaGL instead of SGI's OpenGL for GMAP
## FEATURE_MINTSIZE     use int instead of short to hold object sizes.
##                      allows for larger objects (strings, hash tables, etc.)
## FEATURE_MS           assume windows system calls (as opposed to UNIX)
##                      to use when building on ms windows without UWIN
## FEATURE_X11          assume X11 graphics calls
## FEATURE_BACKINGSTORE ask X server to use backing store for canvas
## FEATURE_NEXTAW       when linking with -lnextaw a widget lib ala NeXT
## FEATURE_XAW3D        when linking with -lXaw3d a nicer looking widget lib
## FEATURE_WIN32        assume WIN32 graphics calls
## FEATURE_DOT          when linking in the dot2l code, a graph parser
#
#leftydir = $(pkgdatadir)/lefty
#pdfdir = $(pkgdatadir)/doc/pdf
#
#AM_CPPFLAGS = \
#	-I$(top_srcdir)/cmd/lefty/ws/x11 \
#	-I$(top_srcdir)/cmd/lefty/os/unix \
#	-I$(top_srcdir)/cmd/lefty/dot2l @XAW_INCLUDES@
#
#AM_CFLAGS = -DLEFTYDATADIR=\"$(leftydir)\" -DHAVE_CONFIG_H @X_CFLAGS@
#
#man = lefty.1
#pdf = lefty.pdf
#
#noinst_HEADERS = code.h common.h display.h exec.h g.h gfxview.h internal.h \
#	io.h lex.h mem.h parse.h str.h tbl.h txtview.h
#
#if WITH_X
#if WITH_XAW
#bin_PROGRAMS = lefty
#man_MANS = $(man)
#pdf_DATA = $(pdf)
#endif
#endif
#
#lefty_DATA = lefty.psp
#
#lefty_SOURCES = code.c common.c display.c exec.c g.c gfxview.c internal.c \
#	lefty.c lex.c mem.c parse.c str.c tbl.c txtview.c
#
##
## NB. -lXaw must be before -lXt or strange inability-to-get-mouse-focus
## problems can occur on some systems.
##
#lefty_LDADD = $(top_builddir)/cmd/lefty/dot2l/libdot2l.la \
#	$(top_builddir)/cmd/lefty/ws/x11/libws.la \
#	$(top_builddir)/cmd/lefty/ws/x11/libfilereq/libfilereq.la \
#	$(top_builddir)/cmd/lefty/os/unix/libos.la \
#	@X_LIBS@ @XAW_LIBS@ @X_PRE_LIBS@ @XPM_LIBS@ \
#	-lXt -lXmu -lXext -lX11 @SOCKET_LIBS@ @MATH_LIBS@
#
#.1.pdf:
#	groff -Tps -man $< | ps2pdf - - >$@
#
#EXTRA_DIST = $(lefty_DATA) $(man) $(pdf) \
#	colors.txt Makefile.old aix_mods cs2l/*
#
#DISTCLEANFILES = $(pdf)
