# $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.4 $

SUBDIRS(
	tclstubs 
	tkstubs 
	tclhandle 
	gdtclft 
	tcldot 
	tclpathplan 
	tkspline 
	gv 
)


########### install files ###############

INSTALL_FILES(  FILES pkgIndex.tcl )



#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.4 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.4 $
### Process this file with automake to produce Makefile.in
#
#pkgindexdir = $(libdir)/@PACKAGE@
#pkgindex_DATA = pkgIndex.tcl
#
#SUBDIRS = tclstubs tkstubs tclhandle gdtclft tcldot tclpathplan tkspline gv
#
#pkgIndex.tcl: @TCL_PKGINDEX@ @TK_PKGINDEX@
#	echo "# end" >end
#	cat @TCL_PKGINDEX@ @TK_PKGINDEX@ end >$@
#	rm -f end
#
#EXTRA_DIST = Makefile.old mkpkgindex.sh
#
#DISTCLEANFILES = pkgIndex.tcl
