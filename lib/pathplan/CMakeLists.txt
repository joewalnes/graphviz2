# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:54 ellson Exp $ $Revision: 1.6 $

ADD_CUSTOM_COMMAND(
	OUTPUT pathplan.pdf
	DEPENDS pathplan.3
	COMMAND groff -Tps -man pathplan.3 | ps2pdf - pathplan.pdf
)

INCLUDE(SRCDIRs)
INCLUDE(${pathplan_SRCDIR}/sources.cmake)

ADD_LIBRARY(pathplan STATIC ${pathplan_SRCS})
ADD_LIBRARY(pathplan SHARED ${pathplan_SRCS})

INSTALL_FILES(FILES
	pathplan.pdf
)
INSTALL_FILES(FILES
	pathplan.3
)
INSTALL_FILES(FILES
	libpathplan.pc
)
