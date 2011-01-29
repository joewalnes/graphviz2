# $Id: sources.cmake,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $

INCLUDE(FindTCL)

INCLUDE_DIRECTORIES(
	${gdtclft_SRCDIR}
	${top_SRCDIR}
	${tclhandle_SRCDIR}
	${TCL_INCLUDE_PATH}
)

SET(gdtclft_SRCS
	${gdtclft_SRCDIR}/gdtclft.c
)
