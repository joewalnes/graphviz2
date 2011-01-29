# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:49 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

SUBDIRS(
	prune
	diffimg
)

#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:49 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#SUBDIRS = prune diffimg
#
#EXTRA_DIST = INDEX dotmcl.pl gprof2dot.awk webdot.cgi Makefile.old \
#	sdlshapes lefty-grace dirgraph
