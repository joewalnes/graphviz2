# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:57 ellson Exp $ $Revision: 1.3 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_ming_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_ming STATIC ${gvplugin_ming_SRCS})
ADD_LIBRARY(gvplugin_ming MODULE ${gvplugin_ming_SRCS})
