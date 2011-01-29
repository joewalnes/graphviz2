# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

########### install files ###############

INSTALL_FILES(FILES
	spline
)
INSTALL_FILES(FILES
	spline.README
)


#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#demodir = $(pkgdatadir)/demo
#
#if WITH_TK
#demo_SCRIPTS = spline
#demo_DATA = spline.README
#endif
#
#EXTRA_DIST = spline spline.README
