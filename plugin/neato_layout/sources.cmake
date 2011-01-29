# $Id: sources.cmake,v 1.3 2009/06/03 01:10:57 ellson Exp $ $Revision: 1.3 $

INCLUDE_DIRECTORIES(
        ${gvplugin_neato_layout_SRCDIR}
	${top_SRCDIR}
	${common_SRCDIR}
	${graph_SRCDIR}
	${cdt_SRCDIR}
	${pathplan_SRCDIR}
	${gvc_SRCDIR}
)

SET(gvplugin_neato_layout_SRCS
	${gvplugin_neato_layout_SRCDIR}/gvplugin_neato_layout.c
	${gvplugin_neato_layout_SRCDIR}/gvlayout_neato_layout.c
)
