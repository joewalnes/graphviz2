# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $

INCLUDE(FindTCL)
INCLUDE(SRCDIRs)
INCLUDE(${tkstubs_SRCDIR}/sources.cmake)

INCLUDE_DIRECTORIES(
	${tkstubs_SRCDIR}
	${TCL_INCLUDE_PATH}
	${TK_INCLUDE_PATH}
)

ADD_LIBRARY(tkstubs STATIC ${tkstubs_SRCS})
