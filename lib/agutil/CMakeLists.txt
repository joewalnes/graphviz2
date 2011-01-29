# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:50 ellson Exp $ $Revision: 1.6 $

INCLUDE(SRCDIRs)
INCLUDE(${agutil_SRCDIR}/sources.cmake)

ADD_LIBRARY(agutil STATIC ${agutil_SRCS})
