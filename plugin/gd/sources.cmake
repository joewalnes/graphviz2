# $Id: sources.cmake,v 1.4 2009/06/03 01:10:56 ellson Exp $ $Revision: 1.4 $

INCLUDE_DIRECTORIES(
	${gvplugin_gd_SRCDIR}
	${top_SRCDIR}
	${common_SRCDIR}
	${graph_SRCDIR}
	${cdt_SRCDIR}
	${pathplan_SRCDIR}
	${gvc_SRCDIR}
)

SET(gvplugin_gd_SRCS
	${gvplugin_gd_SRCDIR}/gvplugin_gd.c
	${gvplugin_gd_SRCDIR}/gvrender_gd.c
	${gvplugin_gd_SRCDIR}/gvtextlayout_gd.c
	${gvplugin_gd_SRCDIR}/gvloadimage_gd.c
	${gvplugin_gd_SRCDIR}/gvformatter_gd.c
)
