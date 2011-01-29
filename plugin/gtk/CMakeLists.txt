# $Id: CMakeLists.txt,v 1.5 2009/06/03 01:10:57 ellson Exp $ $Revision: 1.5 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_gtk_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_gtk STATIC ${gvplugin_gtk_SRCS})
ADD_LIBRARY(gvplugin_gtk MODULE ${gvplugin_gtk_SRCS})
