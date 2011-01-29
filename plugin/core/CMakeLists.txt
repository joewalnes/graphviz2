# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:56 ellson Exp $ $Revision: 1.6 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_core_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_core STATIC ${gvplugin_core_SRCS})
ADD_LIBRARY(gvplugin_core MODULE ${gvplugin_core_SRCS})
