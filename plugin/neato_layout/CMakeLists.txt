# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:57 ellson Exp $ $Revision: 1.6 $

INCLUDE(SRCDIRs)
INCLUDE(${gvplugin_neato_layout_SRCDIR}/sources.cmake)
INCLUDE(${neatogen_SRCDIR}/sources.cmake)
INCLUDE(${circogen_SRCDIR}/sources.cmake)
INCLUDE(${twopigen_SRCDIR}/sources.cmake)
INCLUDE(${fdpgen_SRCDIR}/sources.cmake)

ADD_LIBRARY(gvplugin_neato_layout STATIC ${gvplugin_neato_layout_SRCS})
ADD_LIBRARY(gvplugin_neato_layout MODULE
	${gvplugin_neato_layout_SRCS}
	${neatogen_SRCS}
	${circogen_SRCS}
	${twopigen_SRCS}
	${fdpgen_SRCS}
)
