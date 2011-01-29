# $Id: CMakeLists.txt,v 1.5 2009/06/03 01:10:53 ellson Exp $ $Revision: 1.5 $

INCLUDE(SRCDIRs)
INCLUDE(${ingraphs_SRCDIR}/sources.cmake)

ADD_LIBRARY(ingraphs STATIC ${ingraphs_SRCS})
