# $Id: CMakeLists.txt,v 1.8 2009/06/03 01:10:51 ellson Exp $ $Revision: 1.8 $

INCLUDE(SRCDIRs)
INCLUDE(${common_SRCDIR}/sources.cmake)

ADD_LIBRARY(common STATIC ${common_SRCS})
