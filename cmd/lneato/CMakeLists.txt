# $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:49 ellson Exp $ $Revision: 1.3 $
## Process this file with cmake to produce Makefile

########### install files ###############

INSTALL_FILES( FILES
	lneato.pdf
)
INSTALL_FILES( FILES
	lneato.1
)



#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.3 2009/06/03 01:10:49 ellson Exp $ $Revision: 1.3 $
### Process this file with automake to produce Makefile.in
#
#pdfdir = $(pkgdatadir)/doc/pdf
#
#man = lneato.1
#pdf = lneato.pdf
#
#man_MANS = $(man)
#pdf_DATA = $(pdf)
#bin_SCRIPTS = lneato
#
#lneato: ${top_srcdir}/cmd/lneato/lneato.sh
#	cp ${top_srcdir}/cmd/lneato/lneato.sh lneato
#	chmod +x lneato
#
#.1.pdf:
#	groff -Tps -man $< | ps2pdf - - >$@
#
#EXTRA_DIST = $(man) $(pdf) lneato.bsh lneato.ksh lneato.sh \
#	Makefile.old mswin32 
#
#DISTCLEANFILES = $(bin_SCRIPTS) $(pdf)
