# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

########### install files ###############

INSTALL_FILES(FILES
	xes.dat
	dpd.dat
	funny.dat
	maze.dat
	nested.dat
	northo.dat
	obs.dat
	other.dat
	paths.dat
	rotor.dat
	u.dat
	unknown.dat
)



#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#EXAMPLES = boxes.dat dpd.dat funny.dat maze.dat nested.dat northo.dat \
#	obs.dat other.dat paths.dat rotor.dat u.dat unknown.dat
#
#pathplanexampledir = $(datadir)/@PACKAGE@/demo/pathplan_data
#
#if WITH_TCL
#pathplanexample_DATA = $(EXAMPLES)
#endif
#
#EXTRA_DIST = $(EXAMPLES)
