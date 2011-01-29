# $Id: CMakeLists.txt,v 1.5 2009/06/03 01:10:57 ellson Exp $ $Revision: 1.5 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_xlib_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_xlib STATIC ${gvplugin_xlib_SRCS})
ADD_LIBRARY(gvplugin_xlib MODULE ${gvplugin_xlib_SRCS})
