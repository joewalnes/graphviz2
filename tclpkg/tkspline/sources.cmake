# $Id: sources.cmake,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $

INCLUDE(FindTCL)

INCLUDE_DIRECTORIES(
        ${tkspline_SRCDIR}}
        ${top_SRCDIR}
        ${TK_INCLUDE_PATH}
        ${tkstubs_SRCDIR}
)

SET(tkspline_SRCS
	${tkspline_SRCDIR}/tkspline.c
)
