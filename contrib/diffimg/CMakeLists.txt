# $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:49 ellson Exp $ $Revision: 1.4 $
## Process this file with cmake to produce Makefile

INCLUDE(SRCDIRs)

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}
)


########### next target ###############

SET(diffimg_SRCS
	diffimg.c
)

ADD_EXECUTABLE(diffimg ${diffimg_SRCS})

TARGET_LINK_LIBRARIES(diffimg
	gvgd
	png
	jpeg
	z
	m
)


########### install files ###############




#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:49 ellson Exp $ $Revision: 1.4 $
### Process this file with automake to produce Makefile.in
#
#VERSION=0.2
#
#AM_CPPFLAGS = @GD_INCLUDES@
#
#if WITH_LIBGD
#noinst_PROGRAMS = diffimg
#endif
#
#diffimg_SOURCES = diffimg.c
#
#diffimg_LDADD = @GD_LIBS@
#
#GRAPH = "digraph G { hello -> world }"
#
#test: diffimg
#	echo $(GRAPH) | dot -Tpng:cg >hello1.png
#	echo $(GRAPH) | dot -Tpng:cg >hello2.png
#	if `./diffimg hello1.png hello2.png >test1.png`;then echo same;else echo different;fi
#	echo $(GRAPH) | dot -Grankdir=LR -Tpng:cg >hello2.png
#	if `./diffimg hello1.png hello2.png >test2.png`;then echo same;else echo different;fi
#
#CLEANFILES = *.png
#
