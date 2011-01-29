# $Id: sources.cmake,v 1.3 2009/06/03 01:10:55 ellson Exp $ $Revision: 1.3 $

INCLUDE_DIRECTORIES(
	${twopigen_SRCDIR}
	${top_SRCDIR}
	${common_SRCDIR}
	${gvc_SRCDIR}
	${neatogen_SRCDIR}
	${pack_SRCDIR}
	${pathplan_SRCDIR}
	${graph_SRCDIR}
	${cdt_SRCDIR}
)

SET(twopigen_SRCS
	${twopigen_SRCDIR}/circle.c
	${twopigen_SRCDIR}/twopiinit.c
)
