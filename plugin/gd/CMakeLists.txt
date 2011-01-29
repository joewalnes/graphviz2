# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:56 ellson Exp $ $Revision: 1.6 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_gd_SRCDIR}/sources.cmake)
INCLUDE(${gd_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_gd STATIC ${gvplugin_gd_SRCS})
ADD_LIBRARY(gvplugin_gd MODULE ${gvplugin_gd_SRCS} ${gd_SRCS})
