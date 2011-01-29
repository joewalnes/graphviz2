# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:48 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

ADD_SUBDIRECTORY( unix ) 
ADD_SUBDIRECTORY( mswin32 ) 


#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:48 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#SUBDIRS = unix
#
#EXTRA_DIST = mswin32/lefty.mak mswin32/doinst mswin32/io.c
