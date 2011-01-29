# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:52 ellson Exp $ $Revision: 1.6 $

INCLUDE(SRCDIRs)
INCLUDE(${gd_SRCDIR}/sources.cmake)

# rename private copy of libgd to libgvgd
SET(gvgd_SRCS ${gd_SRCS})

ADD_LIBRARY(gvgd STATIC ${gvgd_SRCS})

INSTALL_FILES(FILES
	gd.html
)
