# $Id: CMakeLists.txt,v 1.5 2009/06/03 01:10:51 ellson Exp $ $Revision: 1.5 $

INCLUDE(SRCDIRs)
INCLUDE(${ast_SRCDIR}/sources.cmake)

ADD_LIBRARY(ast STATIC ${ast_SRCS})
