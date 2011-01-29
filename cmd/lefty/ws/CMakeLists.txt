# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:48 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

ADD_SUBDIRECTORY( x11 ) 
ADD_SUBDIRECTORY( mswin32 ) 
ADD_SUBDIRECTORY( none ) 


########### install files ###############




#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:48 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#SUBDIRS = x11
#
#EXTRA_DIST = mswin32 gtk none
