# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

########### install files ###############

INSTALL_FILES(FILES
	entities
)
INSTALL_FILES(FILES
	entities.README
	entities.html
)


#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#demodir = $(datadir)/@PACKAGE@/demo
#
#if WITH_TCL
#demo_SCRIPTS = entities
#demo_DATA = entities.README entities.html
#endif
#
#EXTRA_DIST = entities entities.README entities.html
