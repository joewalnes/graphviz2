# $Id: CMakeLists.txt,v 1.8 2009/06/03 01:10:53 ellson Exp $ $Revision: 1.8 $

ADD_CUSTOM_COMMAND(
	OUTPUT graph.pdf
	DEPENDS graph.3
	COMMAND groff -Tps -man graph.3 | ps2pdf - graph.pdf
)

INCLUDE(SRCDIRs)
INCLUDE(${graph_SRCDIR}/sources.cmake)

ADD_LIBRARY(graph STATIC ${graph_SRCS})
ADD_LIBRARY(graph SHARED ${graph_SRCS})

INSTALL_FILES(FILES
	graph.pdf
)
INSTALL_FILES(FILES
	graph.3
)
INSTALL_FILES(FILES
	libgraph.pc
)
