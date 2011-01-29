# $Id: CMakeLists.txt,v 1.7 2009/06/03 01:10:47 ellson Exp $ $Revision: 1.7 $
## Process this file with cmake to produce Makefile

INCLUDE(SRCDIRs)
INCLUDE(${dot_SRCDIR}/sources.cmake)
INCLUDE(${gvc_SRCDIR}/sources.cmake)
INCLUDE(${common_SRCDIR}/sources.cmake)
INCLUDE(${pathplan_SRCDIR}/sources.cmake)
INCLUDE(${graph_SRCDIR}/sources.cmake)
INCLUDE(${cdt_SRCDIR}/sources.cmake)

ADD_EXECUTABLE(dot
	${dot_SRCS}
	${gvc_SRCS}
	${common_SRCS}
	${pathplan_SRCS}
	${graph_SRCS}
	${cdt_SRCS}
	${gvc_SRCDIR}/no_builtins.c
	${gvc_SRCDIR}/demand_loading.c
)

TARGET_LINK_LIBRARIES(dot
	expat
	ltdl
	z
	m
)

INSTALL_TARGETS(/bin dot )
