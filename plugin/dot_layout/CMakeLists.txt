# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:56 ellson Exp $ $Revision: 1.6 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_dot_layout_SRCDIR}/sources.cmake)
INCLUDE(${dotgen_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_dot_layout STATIC ${gvplugin_dot_layout_SRCS})
ADD_LIBRARY(gvplugin_dot_layout MODULE ${gvplugin_dot_layout_SRCS} ${dotgen_SRCS})
