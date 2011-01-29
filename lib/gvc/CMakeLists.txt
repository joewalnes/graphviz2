# $Id: CMakeLists.txt,v 1.8 2009/06/03 01:10:53 ellson Exp $ $Revision: 1.8 $

INCLUDE(SRCDIRs)
INCLUDE(${gvc_SRCDIR}/sources.cmake)
INCLUDE(${common_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvc STATIC ${gvc_SRCS} no_builtins.c demand_loading.c)
#ADD_LIBRARY(gvc SHARED ${gvc_SRCS} ${common_SRCS} no_builtins.c demand_loading.c)
#ADD_LIBRARY(gvc_builtins STATIC ${gvc_SRCS} )

INSTALL_FILES(FILES
	libgvc.pc
	libgvc_builtins.pc
)
