# $Id: sources.cmake,v 1.4 2009/06/03 01:10:50 ellson Exp $ $Revision: 1.4 $

INCLUDE_DIRECTORIES(
	${top_SRCDIR}
	${agutil_SRCDIR}
	${agraph_SRCDIR}
	${cdt_SRCDIR}
)

SET(agutil_SRCS
	${agutil_SRCDIR}/dynattr.c
	${agutil_SRCDIR}/nodeq.c
)
