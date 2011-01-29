# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:56 ellson Exp $ $Revision: 1.3 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_devil_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_devil STATIC ${gvplugin_devil_SRCS})
ADD_LIBRARY(gvplugin_devil MODULE ${gvplugin_devil_SRCS})
