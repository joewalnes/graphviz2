# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.6 $

SUBDIRS(demo) 

INCLUDE(SRCDIRs)
INCLUDE(${tkspline_SRCDIR}/sources.cmake)

ADD_LIBRARY(tkspline MODULE ${tkspline_SRCS})

INSTALL_FILES(FILES
	tkspline.pdf
)
INSTALL_FILES(FILES
	tkspline.n
)
