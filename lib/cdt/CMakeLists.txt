# $Id: CMakeLists.txt,v 1.7 2009/06/03 01:10:51 ellson Exp $ $Revision: 1.7 $

ADD_CUSTOM_COMMAND(
	OUTPUT cdt.pdf
	DEPENDS cdt.3
	COMMAND groff -Tps -man cdt.3 | ps2pdf - cdt.pdf
)

INCLUDE(SRCDIRs)
INCLUDE(${cdt_SRCDIR}/sources.cmake)

ADD_LIBRARY(cdt STATIC ${cdt_SRCS})
ADD_LIBRARY(cdt SHARED ${cdt_SRCS})

INSTALL_FILES(FILES
	libcdt.pc
)
INSTALL_FILES(FILES
	cdt.pdf
)
INSTALL_FILES(FILES
	cdt.1
)
