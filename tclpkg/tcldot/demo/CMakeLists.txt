# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

########### install files ###############

INSTALL_FILES(FILES
	doted
	gcat
)
INSTALL_FILES(FILES
	doted.README
	gcat.README
)



#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#demodir = $(pkgdatadir)/demo
#
#if WITH_TCL
#demo_SCRIPTS = doted gcat
#demo_DATA = doted.README gcat.README
#endif
#
#EXTRA_DIST = doted gcat doted.README gcat.README
