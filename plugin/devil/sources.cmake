# $Id: sources.cmake,v 1.3 2009/06/03 01:10:56 ellson Exp $ $Revision: 1.3 $

INCLUDE( UsePkgConfig )
PKGCONFIG( pangocairo PANGOCAIRO_INCLUDE_DIR PANGOCAIRO_LIB_DIR PANGOCAIRO_LINK_FLAGS PANGOCAIRO_CFLAGS )
ADD_DEFINITIONS(${PANGOCAIRO_CFLAGS})
PKGCONFIG( devil DEVIL_INCLUDE_DIR DEVIL_LIB_DIR DEVIL_LINK_FLAGS DEVIL_CFLAGS )
ADD_DEFINITIONS(${DEVIL_CFLAGS})

INCLUDE_DIRECTORIES(
	${gvplugin_devil_SRCDIR}
	${top_SRCDIR}
	${common_SRCDIR}
	${graph_SRCDIR}
	${cdt_SRCDIR}
	${pathplan_SRCDIR}
	${gvc_SRCDIR}
)

SET(gvplugin_devil_SRCS
	${gvplugin_devil_SRCDIR}/gvplugin_devil.c
	${gvplugin_devil_SRCDIR}/gvrender_devil.c
)
