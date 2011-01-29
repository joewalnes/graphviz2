# $Id: sources.cmake,v 1.3 2009/06/03 01:10:47 ellson Exp $ $Revision: 1.3 $

INCLUDE_DIRECTORIES(
	${dot_SRCDIR}
	${top_SRCDIR}
	${common_SRCDIR}
	${gvc_SRCDIR}
	${pathplan_SRCDIR}
	${graph_SRCDIR}
	${cdt_SRCDIR}
)

SET(dot_SRCS
	${dot_SRCDIR}/dot.c
)
