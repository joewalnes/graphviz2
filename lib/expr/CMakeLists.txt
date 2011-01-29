# $Id: CMakeLists.txt,v 1.7 2009/06/03 01:10:52 ellson Exp $ $Revision: 1.7 $

INCLUDE(SRCDIRs)
INCLUDE(${expr_SRCDIR}/sources.cmake)

ADD_LIBRARY(expr STATIC ${expr_SRCS})
ADD_LIBRARY(expr SHARED ${expr_SRCS})

INSTALL_FILES(FILES
	expr.pdf
)
INSTALL_FILES(FILES
	expr.1
)
