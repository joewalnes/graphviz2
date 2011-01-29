# $Id: CMakeLists.txt,v 1.5 2009/06/03 01:10:55 ellson Exp $ $Revision: 1.5 $

INCLUDE(SRCDIRs)
INCLUDE(${sfio_SRCDIR}/sources.cmake)

ADD_LIBRARY(sfio STATIC ${sfio_SRCS})
