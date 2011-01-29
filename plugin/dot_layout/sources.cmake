# $Id: sources.cmake,v 1.3 2009/06/03 01:10:56 ellson Exp $ $Revision: 1.3 $

INCLUDE_DIRECTORIES(
	${gvplugin_dot_layout_SRCDIR}
        ${top_SRCDIR}
	${common_SRCDIR}
        ${graph_SRCDIR}
	${cdt_SRCDIR}
	${pathplan_SRCDIR}
	${gvc_SRCDIR}
)

SET(gvplugin_dot_layout_SRCS
	${gvplugin_dot_layout_SRCDIR}/gvplugin_dot_layout.c
	${gvplugin_dot_layout_SRCDIR}/gvlayout_dot_layout.c
)
