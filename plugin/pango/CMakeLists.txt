# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:57 ellson Exp $ $Revision: 1.6 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_pango_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_pango STATIC ${gvplugin_pango_SRCS})
ADD_LIBRARY(gvplugin_pango MODULE ${gvplugin_pango_SRCS})
