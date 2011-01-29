# $Id: CMakeLists.txt,v 1.5 2009/06/03 01:10:55 ellson Exp $ $Revision: 1.5 $

INCLUDE(SRCDIRs)
INCLUDE(${twopigen_SRCDIR}/sources.cmake)

ADD_LIBRARY(twopigen STATIC ${twopigen_SRCS})
