# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:48 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

########### install files ###############

INSTALL_FILES(FILES
	box.lefty
	def.lefty
	fractal.lefty
	fractal2.lefty
	slides.lefty
	tree.lefty
)



#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:48 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#leftydir = $(pkgdatadir)/lefty
#
#lefty_DATA = box.lefty def.lefty fractal.lefty fractal2.lefty \
#	slides.lefty tree.lefty
#
#EXTRA_DIST = $(lefty_DATA)
