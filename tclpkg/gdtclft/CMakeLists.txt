# $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.4 $
## Process this file with cmake to produce Makefile

SUBDIRS(demo) 

INCLUDE(SRCDIRs)
INCLUDE(${gdtclft_SRCDIR}/sources.cmake)
INCLUDE(${gd_SRCDIR}/sources.cmake)
INCLUDE(${tclhandle_SRCDIR}/sources.cmake)
INCLUDE(${tclstubs_SRCDIR}/sources.cmake)

ADD_LIBRARY(gdtclft MODULE
	${gdtclft_SRCS}
	${gd_SRCS}
	${tclhandle_SRCS}
	${tclstubs_SRCS}
)

INSTALL_FILES(FILES
	gdtclft.pdf
)
INSTALL_FILES(FILES
	gdtclft.n
)
