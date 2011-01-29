# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:53 ellson Exp $ $Revision: 1.6 $

INCLUDE(SRCDIRs)
INCLUDE(${neatogen_SRCDIR}/sources.cmake)

ADD_LIBRARY(neatogen STATIC ${neatogen_SRCS})
