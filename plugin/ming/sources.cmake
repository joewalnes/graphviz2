# $Id: sources.cmake,v 1.3 2009/06/03 01:10:57 ellson Exp $ $Revision: 1.3 $

INCLUDE( UsePkgConfig )
PKGCONFIG( libming LIBMING_INCLUDE_DIR LIBMING_LIB_DIR LIBMING_LINK_FLAGS LIBMING_CFLAGS )
ADD_DEFINITIONS(${LIBMING_CFLAGS})

INCLUDE_DIRECTORIES(
	${gvplugin_ming_SRCDIR}
	${top_SRCDIR}
	${common_SRCDIR}
	${graph_SRCDIR}
	${cdt_SRCDIR}
	${pathplan_SRCDIR}
	${gvc_SRCDIR}
)

SET(gvplugin_ming_SRCS
	${gvplugin_ming_SRCDIR}/gvplugin_ming.c
	${gvplugin_ming_SRCDIR}/gvrender_ming.c
)
