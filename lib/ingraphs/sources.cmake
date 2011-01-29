# $Id: sources.cmake,v 1.3 2009/06/03 01:10:53 ellson Exp $ $Revision: 1.3 $

INCLUDE_DIRECTORIES(
	${ingraphs_SRCDIR}
	${top_SRCDIR}
	${graph_SRCDIR}
	${cdt_SRCDIR}
)

SET(ingraphs_SRCS
	${ingraphs_SRCDIR}/ingraphs.c
)
