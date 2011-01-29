# $Id: CMakeLists.txt,v 1.5 2009/06/03 01:10:54 ellson Exp $ $Revision: 1.5 $

ADD_CUSTOM_COMMAND(
	OUTPUT pack.pdf
	DEPENDS pack.3
	COMMAND groff -Tps -man pack.3 | ps2pdf - pack.pdf
)

INCLUDE(SRCDIRs)
INCLUDE(${pack_SRCDIR}/sources.cmake)

ADD_LIBRARY(pack STATIC ${pack_SRCS})

INSTALL_FILES(FILES
	pack.pdf
)
INSTALL_FILES(FILES
	pack.3
)
