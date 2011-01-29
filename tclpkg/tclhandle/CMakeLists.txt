# $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.4 $

INCLUDE(SRCDIRs)
INCLUDE(${tclhandle_SRCDIR}/sources.cmake)

ADD_LIBRARY(tclhandle STATIC ${tclhandle_SRCS})
