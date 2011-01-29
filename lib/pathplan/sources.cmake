# $Id: sources.cmake,v 1.3 2009/06/03 01:10:54 ellson Exp $ $Revision: 1.3 $

INCLUDE_DIRECTORIES(
	${pathplan_SRCDIR}
	${top_SRCDIR}
)

SET(pathplan_SRCS
	${pathplan_SRCDIR}/cvt.c
	${pathplan_SRCDIR}/inpoly.c
	${pathplan_SRCDIR}/route.c
	${pathplan_SRCDIR}/shortest.c
	${pathplan_SRCDIR}/shortestpth.c
	${pathplan_SRCDIR}/solvers.c
	${pathplan_SRCDIR}/triang.c
	${pathplan_SRCDIR}/util.c
	${pathplan_SRCDIR}/visibility.c
)
