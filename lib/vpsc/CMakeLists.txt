# $Id: CMakeLists.txt,v 1.5 2009/06/03 01:10:56 ellson Exp $ $Revision: 1.5 $

INCLUDE(SRCDIRs)
INCLUDE(${vpsc_SRCDIR}/sources.cmake)

ADD_LIBRARY(vpsc STATIC ${vpsc_SRCS})
