# $Id: sources.cmake,v 1.3 2009/06/03 01:10:52 ellson Exp $ $Revision: 1.3 $

INCLUDE_DIRECTORIES(
	${fdpgen_SRCDIR}
	${top_SRCDIR}
	${common_SRCDIR}
	${gvc_SRCDIR}
	${neatogen_SRCDIR}
	${pack_SRCDIR}
	${pathplan_SRCDIR}
	${graph_SRCDIR}
	${cdt_SRCDIR}
)

SET(fdpgen_SRCS
	${fdpgen_SRCDIR}/comp.c
	${fdpgen_SRCDIR}/dbg.c
	${fdpgen_SRCDIR}/grid.c
	${fdpgen_SRCDIR}/fdpinit.c
	${fdpgen_SRCDIR}/layout.c
	${fdpgen_SRCDIR}/tlayout.c
	${fdpgen_SRCDIR}/xlayout.c
	${fdpgen_SRCDIR}/clusteredges.c
)
