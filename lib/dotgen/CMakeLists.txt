# $Id: CMakeLists.txt,v 1.5 2009/06/03 01:10:52 ellson Exp $ $Revision: 1.5 $

INCLUDE(SRCDIRs)
INCLUDE(${dotgen_SRCDIR}/sources.cmake)

ADD_LIBRARY(dotgen STATIC ${dotgen_SRCS})
