# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:56 ellson Exp $ $Revision: 1.3 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_gdk_pixbuf_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_gdk_pixbuf STATIC ${gvplugin_gdk_pixbuf_SRCS})
ADD_LIBRARY(gvplugin_gdk_pixbuf MODULE ${gvplugin_gdk_pixbuf_SRCS})
