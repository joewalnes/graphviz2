# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:55 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/lib/sfio
)


########### next target ###############

SET(sfiof_SRCS
	_sfclrerr.c
	_sfdlen.c
	_sfeof.c
	_sferror.c
	_sffileno.c
	_sfgetc.c
	_sfllen.c
	_sfputc.c
	_sfputd.c
	_sfputl.c
	_sfputm.c
	_sfputu.c
	_sfslen.c
	_sfstacked.c
	_sfulen.c
	_sfvalue.c
)

ADD_LIBRARY(sfiof STATIC ${sfiof_SRCS})


########### install files ###############




#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:55 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#AM_CPPFLAGS = -I$(top_srcdir)/lib/sfio
#
#noinst_LTLIBRARIES = libsfiof_C.la
#
#libsfiof_C_la_SOURCES = _sfclrerr.c _sfdlen.c _sfeof.c _sferror.c \
#	_sffileno.c _sfgetc.c _sfllen.c _sfputc.c _sfputd.c \
#	_sfputl.c _sfputm.c _sfputu.c _sfslen.c _sfstacked.c \
#	_sfulen.c _sfvalue.c
#
#${top_builddir}/FEATURE/sfio:  ${top_srcdir}/lib/sfio/features/sfio
#	mkdir -p ${top_builddir}/FEATURE
#	$(top_srcdir)/iffe - set cc $(CC) $(CCMODE) $(CXFLAGS) : run ${top_srcdir}/lib/sfio/features/sfio > $@
#
#$(libsfiof_C_la_OBJECTS): ${top_builddir}/FEATURE/sfio
#
#DISTCLEANFILES = ${top_builddir}/FEATURE/sfio
#
#EXTRA_DIST = Makefile.old
