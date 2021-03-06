# $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.6 $

SET(BASE_INCLUDES
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_BINARY_DIR}
	${CMAKE_SOURCE_DIR}/lib/gvc
	${CMAKE_SOURCE_DIR}/lib/common
	${CMAKE_SOURCE_DIR}/lib/graph
	${CMAKE_SOURCE_DIR}/lib/cdt
	${CMAKE_SOURCE_DIR}/lib/pathplan
)

INCLUDE( FindSWIG )
#IF(${SWIG_FOUND})
########### next target #################

#INCLUDE( FindCSHARP )
#IF(${CSHARP_FOUND})
#INCLUDE_DIRECTORIES(
#	${BASE_INCLUDES}
#	${CSHARP_INCLUDES}
#)
#ADD_CUSTOM_COMMAND(
#	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#	OUTPUT gv_sharp.cpp
#	DEPENDS gv.i
#	COMMAND ${SWIG_EXECUTABLE} -c++ -csharp -o gv_sharp.cpp gv.i
#)
#
#SET(gv_sharp_SRCS
#	gv.cpp
#	gv_sharp.cpp
#)
#ADD_LIBRARY(gv_sharp MODULE ${gv_sharp_SRCS})
#ENDIF(${CSHARP_FOUND})

########### next target #################

#INCLUDE( FindGUILE )
#IF(${GUILE_FOUND})
#INCLUDE_DIRECTORIES(
#	${BASE_INCLUDES}
#	${GUILE_INCLUDES}
#)
#ADD_CUSTOM_COMMAND(
#	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#	OUTPUT gv_guile.cpp
#	DEPENDS gv.i
#	COMMAND ${SWIG_EXECUTABLE} -c++ -guile -o gv_guile.cpp gv.i
#)
#
#SET(gv_guile_SRCS
#	gv.cpp
#	gv_guile.cpp
#)
#ADD_LIBRARY(gv_guile MODULE ${gv_guile_SRCS})
#ENDIF(${GUILE_FOUND})

########### next target #################

INCLUDE( FindJava )
IF(${JAVA_FOUND})
INCLUDE_DIRECTORIES(
	${BASE_INCLUDES}
	${JAVA_INCLUDES}
)
ADD_CUSTOM_COMMAND(
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	OUTPUT gv_java.cpp
	DEPENDS gv.i
	COMMAND ${SWIG_EXECUTABLE} -c++ -java -o gv_java.cpp gv.i
)

SET(gv_java_SRCS
	gv.cpp
	gv_java.cpp
)
ADD_LIBRARY(gv_java MODULE ${gv_java_SRCS})
ENDIF(${JAVA_FOUND})

########### next target #################

#INCLUDE( FindLUA )
#IF(${LUA_FOUND})
#INCLUDE_DIRECTORIES(
#	${BASE_INCLUDES}
#	${LUA_INCLUDES}
#)
#ADD_CUSTOM_COMMAND(
#	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#	OUTPUT gv_lua.cpp
#	DEPENDS gv.i
#	COMMAND ${SWIG_EXECUTABLE} -c++ -lua -o gv_lua.cpp gv.i
#)
#
#SET(gv_lua_SRCS
#	gv.cpp
#	gv_lua.cpp
#)
#ADD_LIBRARY(gv_lua MODULE ${gv_lua_SRCS})
#ENDIF(${LUA_FOUND})

########### next target #################

INCLUDE( FindPerl )
IF(${PERL_FOUND})
INCLUDE_DIRECTORIES(
	${BASE_INCLUDES}
	${PERL_INCLUDES}
)
ADD_CUSTOM_COMMAND(
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	OUTPUT gv_perl.cpp
	DEPENDS gv.i
	COMMAND ${SWIG_EXECUTABLE} -c++ -perl -o gv_perl.cpp gv.i
)

SET(gv_perl_SRCS
	gv.cpp
	gv_perl.cpp
)
ADD_LIBRARY(gv_perl MODULE ${gv_perl_SRCS})
ENDIF(${PERL_FOUND})

########### next target #################

INCLUDE( FindPHP4 )
IF(${PHP4_FOUND})
INCLUDE_DIRECTORIES(
	${BASE_INCLUDES}
	${PHP4_INCLUDES}
)
ADD_CUSTOM_COMMAND(
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	OUTPUT gv_php.cpp
	DEPENDS gv.i
	COMMAND ${SWIG_EXECUTABLE} -c++ -php -o gv_php.cpp gv.i
)

SET(gv_php_SRCS
	gv.cpp
	gv_php.cpp
)
ADD_LIBRARY(gv_php MODULE ${gv_php_SRCS})
ENDIF(${PHP4_FOUND})

########### next target #################

#INCLUDE( FindPython )
#IF(${PYTHON_FOUND})
#INCLUDE_DIRECTORIES(
#	${BASE_INCLUDES}
#	${PYTHON_INCLUDES}
#)
#ADD_CUSTOM_COMMAND(
#	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#	OUTPUT gv_python.cpp
#	DEPENDS gv.i
#	COMMAND ${SWIG_EXECUTABLE} -c++ -python -o gv_python.cpp gv.i
#)
#
#SET(gv_python_SRCS
#	gv.cpp
#	gv_python.cpp
#)
#ADD_LIBRARY(gv_python MODULE ${gv_python_SRCS})
#ENDIF(${PYTHON_FOUND})

########### next target #################

INCLUDE( FindRuby )
IF(${RUBY_FOUND})
INCLUDE_DIRECTORIES(
	${BASE_INCLUDES}
	${RUBY_INCLUDES}
)
ADD_CUSTOM_COMMAND(
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	OUTPUT gv_ruby.cpp
	DEPENDS gv.i
	COMMAND ${SWIG_EXECUTABLE} -c++ -ruby -o gv_ruby.cpp gv.i
)

SET(gv_ruby_SRCS
	gv.cpp
	gv_ruby.cpp
)
ADD_LIBRARY(gv_ruby MODULE ${gv_ruby_SRCS})
ENDIF(${RUBY_FOUND})

########### next target #################

INCLUDE( FindTCL )
IF(${TCL_FOUND})
INCLUDE_DIRECTORIES(
	${BASE_INCLUDES}
	${TCL_INCLUDES}
)
ADD_CUSTOM_COMMAND(
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	OUTPUT gv_tcl.cpp
	DEPENDS gv.i
	COMMAND ${SWIG_EXECUTABLE} -c++ -tcl -namespace -o gv_tcl.cpp gv.i
)
SET(gv_tcl_SRCS
	gv.cpp
	gv_tcl.cpp
)
ADD_LIBRARY(gv_tcl MODULE ${gv_tcl_SRCS})
ENDIF(${TCL_FOUND})

########### install files ###############
#ENDIF(${SWIG_FOUND})

INSTALL_FILES(FILES $(OCAML_hdr) gv_ocaml.man )
INSTALL_FILES(FILES $(PYTHON_hdr) gv_python.man )
INSTALL_FILES(FILES $(PHP_hdr) gv_php.man )
INSTALL_FILES(FILES $(LUA_hdr) gv_lua.man )
INSTALL_FILES(FILES $(GUILE_hdr) gv_guile.man )
INSTALL_FILES(FILES $(TCL_hdr) gv_tcl.man )
INSTALL_FILES(FILES $(RUBY_hdr) gv_ruby.man )
INSTALL_FILES(FILES $(JAVA_hdr) gv_java.man )
INSTALL_FILES(FILES $(IO_hdr) gv_io.man )
INSTALL_FILES(FILES $(SHARP_hdr) gv_sharp.man )
INSTALL_FILES(FILES $(PERL_hdr) gv_perl.man )

INSTALL_FILES(FILES
	gv.i
	gv.cpp
)



#original Makefile.am contents follow:

## $Id: CMakeLists.txt,v 1.6 2009/06/03 01:10:58 ellson Exp $ $Revision: 1.6 $
### Process this file with automake to produce Makefile.in
#
#AM_CPPFLAGS = \
#	-I$(top_srcdir) \
#	-I$(top_srcdir)/lib/gvc \
#	-I$(top_srcdir)/lib/common \
#	-I$(top_srcdir)/lib/graph \
#	-I$(top_srcdir)/lib/cdt \
#	-I$(top_srcdir)/lib/pathplan $(PERL_INCLUDES) $(OCAML_INCLUDES) $(PHP_INCLUDES) $(PYTHON_INCLUDES) $(RUBY_INCLUDES) $(TCL_INCLUDES) 
#
#LIBS =  @LIBS@ -lc
#
#BASESOURCES = gv.cpp gv.i
#BASELIBS = $(top_builddir)/lib/gvc/libgvc.la
#
#pkgsharpdir = $(pkglibdir)/sharp
#SHARP_hdr = gv.cs gvPINVOKE.cs SWIGTYPE_p_Agraph_t.cs SWIGTYPE_p_Agnode_t.cs SWIGTYPE_p_Agedge_t.cs SWIGTYPE_p_Agsym_t.cs SWIGTYPE_p_FILE.cs
#nodist_libgv_sharp_la_SOURCES = gv_sharp.cpp $(SHARP_hdr)
#libgv_sharp_la_SOURCES = $(BASESOURCES)
#libgv_sharp_la_LIBADD = $(BASELIBS) @SHARP_LIBS@ 
#libgv_sharp_la_LDFLAGS = 
#gv_sharp.cpp $(SHARP_hdr): gv.i
#	$(SWIG) -c++ -csharp -namespace gv -o gv_sharp.cpp gv.i
#
#pkgguiledir = $(pkglibdir)/guile
#GUILE_hdr = 
#nodist_libgv_guile_la_SOURCES = gv_guile.cpp $(GUILE_hdr)
#libgv_guile_la_SOURCES = $(BASESOURCES)
#libgv_guile_la_LIBADD = $(BASELIBS) @GUILE_LIBS@
#libgv_guile_la_LDFLAGS = 
#gv_guile.cpp $(GUILE_hdr): gv.i
#	$(SWIG) -c++ -guile -o gv_guile.cpp gv.i
#	$(SED) -e 's/SWIG_GUILE_INIT_STATIC void/void/' <gv_guile.cpp >t
#	mv -f t gv_guile.cpp
#
#pkgiodir = $(pkglibdir)/io
#IO_hdr = 
#nodist_libgv_io_la_SOURCES = gv_io.cpp $(IO_hdr)
#libgv_io_la_SOURCES = $(BASESOURCES)
#libgv_io_la_LIBADD = $(BASELIBS) @IO_LIBS@
#libgv_io_la_LDFLAGS = 
#gv_io.cpp $(IO_hdr): gv.i
#	$(SWIG) -c++ -io -o gv_io.cpp gv.i
#
#pkgjavadir = $(pkglibdir)/java
#JAVA_hdr = gv.java gvJNI.java SWIGTYPE_p_Agraph_t.java SWIGTYPE_p_Agnode_t.java SWIGTYPE_p_Agedge_t.java SWIGTYPE_p_Agsym_t.java SWIGTYPE_p_FILE.java
#nodist_libgv_java_la_SOURCES = gv_java.cpp
#libgv_java_la_SOURCES = $(BASESOURCES) 
#libgv_java_la_LIBADD = $(BASELIBS) @JAVA_LIBS@
#libgv_java_la_LDFLAGS = 
#gv_java.cpp $(JAVA_hdr): gv.i
#	$(SWIG) -c++ -java -o gv_java.cpp gv.i
#
#pkgluadir = $(pkglibdir)/lua
#LUA_hdr = 
#nodist_libgv_lua_la_SOURCES = gv_lua.cpp $(LUA_hdr)
#libgv_lua_la_SOURCES = $(BASESOURCES)
#libgv_lua_la_LIBADD = $(BASELIBS) @LUA_LIBS@
#libgv_lua_la_LDFLAGS = 
#gv_lua.cpp $(LUA_hdr): gv.i
#	$(SWIG) -c++ -lua -o gv_lua.cpp gv.i
#
#pkgocamldir = $(pkglibdir)/ocaml
#OCAML_hdr = gv.ml gv.mli
#nodist_libgv_ocaml_la_SOURCES = gv_ocaml.cpp $(OCAML_hdr)
#libgv_ocaml_la_SOURCES = $(BASESOURCES)
#libgv_ocaml_la_LIBADD = $(BASELIBS) @OCAML_LIBS@
#libgv_ocaml_la_LDFLAGS = 
#gv_ocaml.cpp $(OCAML_hdr): gv.i
#	$(SWIG) -c++ -ocaml -o gv_ocaml.cpp gv.i
#
#pkgperldir = $(pkglibdir)/perl
#PERL_hdr = gv.pm
#nodist_libgv_perl_la_SOURCES = gv_perl.cpp $(PERL_hdr)
#libgv_perl_la_SOURCES = $(BASESOURCES)
#libgv_perl_la_LIBADD = $(BASELIBS) @PERL_LIBS@
#libgv_perl_la_LDFLAGS = 
#gv_perl.cpp $(PERL_hdr): gv.i
#	$(SWIG) -c++ -perl -o gv_perl.cpp.tmp gv.i
#	(echo "#define register" ; cat gv_perl.cpp.tmp) > gv_perl.cpp
#
#pkgphpdir = $(pkglibdir)/php
#PHP_hdr = gv.php php_gv.h
#nodist_libgv_php_la_SOURCES = gv_php.cpp $(PHP_hdr)
#libgv_php_la_SOURCES = $(BASESOURCES)
#libgv_php_la_LIBADD = $(BASELIBS) @PHP_LIBS@
#libgv_php_la_LDFLAGS = 
#gv_php.cpp $(PHP_hdr): gv.i
#	$(SWIG) -c++ -php -o gv_php.cpp gv.i
#
#pkgpythondir = $(pkglibdir)/python
#PYTHON_hdr = gv.py
#nodist_libgv_python_la_SOURCES = gv_python.cpp $(PYTHON_hdr)
#libgv_python_la_SOURCES = $(BASESOURCES)
#libgv_python_la_LIBADD = $(BASELIBS) @PYTHON_LIBS@
#libgv_python_la_LDFLAGS = 
#gv_python.cpp $(PYTHON_hdr): gv.i
#	$(SWIG) -c++ -python -o gv_python.cpp gv.i
#
#pkgrubydir = $(pkglibdir)/ruby
#RUBY_hdr = 
#nodist_libgv_ruby_la_SOURCES = gv_ruby.cpp $(RUBY_hdr)
#libgv_ruby_la_SOURCES = $(BASESOURCES)
#libgv_ruby_la_LIBADD = $(BASELIBS) @RUBY_LIBS@
#libgv_ruby_la_LDFLAGS = 
#gv_ruby.cpp $(RUBY_hdr): gv.i
#	$(SWIG) -c++ -ruby -o gv_ruby.cpp gv.i
#
#pkgtcldir = $(pkglibdir)/tcl
#TCL_hdr = 
#nodist_libgv_tcl_la_SOURCES = gv_tcl.cpp $(TCL_hdr)
#libgv_tcl_la_SOURCES = $(BASESOURCES)
#libgv_tcl_la_LIBADD = $(top_builddir)/tclpkg/tclstubs/libtclstubs_C.la $(BASELIBS) @TCL_LIBS@
#libgv_tcl_la_LDFLAGS = 
#gv_tcl.cpp $(TCL_hdr): gv.i
#	$(SWIG) -c++ -tcl -namespace -o gv_tcl.cpp gv.i
#
#pkginclude_DATA = gv.i gv.cpp
#pkglib_LTLIBRARIES = 
#TESTS =
#if WITH_SHARP
#pkgsharp_DATA = $(SHARP_hdr) gv_sharp.man
#pkgsharp_LTLIBRARIES = libgv_sharp.la
#TESTS += test_sharp
#endif
#if WITH_GUILE
#pkgguile_DATA = $(GUILE_hdr) gv_guile.man
#pkgguile_LTLIBRARIES = libgv_guile.la
#TESTS += test_guile
#endif
#if WITH_IO
#pkgio_DATA = $(IO_hdr) gv_io.man
#pkgio_LTLIBRARIES = libgv_io.la
#TESTS += test_io
#endif
#if WITH_JAVA
#pkgjava_DATA = $(JAVA_hdr) gv_java.man
#pkgjava_LTLIBRARIES = libgv_java.la
#TESTS += test_java
#endif
#if WITH_LUA
#pkglua_DATA = $(LUA_hdr) gv_lua.man
#pkglua_LTLIBRARIES = libgv_lua.la
#TESTS += test_lua
#endif
#if WITH_OCAML
#pkgocaml_DATA = $(OCAML_hdr) gv_ocaml.man
#pkgocaml_LTLIBRARIES = libgv_ocaml.la
#TESTS += test_ocaml
#endif
#if WITH_PERL
#pkgperl_DATA = $(PERL_hdr) gv_perl.man
#pkgperl_LTLIBRARIES = libgv_perl.la
#TESTS += test_perl
#endif
#if WITH_PHP
#pkgphp_DATA = $(PHP_hdr) gv_php.man
#pkgphp_LTLIBRARIES = libgv_php.la
#TESTS += test_php
#endif
#if WITH_PYTHON
#pkgpython_DATA = $(PYTHON_hdr) gv_python.man
#pkgpython_LTLIBRARIES = libgv_python.la
#TESTS += test_python
#endif
#if WITH_RUBY
#pkgruby_DATA = $(RUBY_hdr) gv_ruby.man
#pkgruby_LTLIBRARIES = libgv_ruby.la
#TESTS += test_ruby
#endif
#if WITH_TCL
#pkgtcl_DATA = $(TCL_hdr) gv_tcl.man
#pkgtcl_LTLIBRARIES = libgv_tcl.la
#TESTS += test_tcl
#
#all-local: pkgIndex.tcl
#
#pkgIndex.tcl: libgv_tcl.la
#	sh $(top_srcdir)/tclpkg/mkpkgindex.sh libgv_tcl.la gv $(VERSION)
#endif
#
#gv_sharp.man gv_guile.man gv_io.man gv_java.man gv_lua.man \
#gv_ocaml.man gv_perl.man gv_php.man gv_python.man gv_ruby.man \
#gv_tcl.man: gv.i gv_doc_writer.tcl gv_doc_template.tcl gv_doc_langs.tcl
#	./gv_doc_writer.tcl
#
#install-data-hook:
#	(cd $(DESTDIR)$(pkgluadir);    rm -f gv.so;  $(LN_S) libgv_lua.so gv.so;)
#	(cd $(DESTDIR)$(pkgperldir);   rm -f gv.so;  $(LN_S) libgv_perl.so gv.so;)
#	(cd $(DESTDIR)$(pkgpythondir); rm -f _gv.so; $(LN_S) libgv_python.so _gv.so;)
#	(cd $(DESTDIR)$(pkgrubydir);   rm -f gv.so;  $(LN_S) libgv_ruby.so gv.so;)
#	(cd $(DESTDIR)$(pkgtcldir);    rm -f gv.so;  $(LN_S) libgv_tcl.so gv.so;)
#
#uninstall-hook:
#	(cd $(DESTDIR)$(pkgluadir);    rm -f gv.so;)
#	(cd $(DESTDIR)$(pkgperldir);   rm -f gv.so;)
#	(cd $(DESTDIR)$(pkgpythondir); rm -f _gv.so;)
#	(cd $(DESTDIR)$(pkgrubydir);   rm -f gv.so;)
#	(cd $(DESTDIR)$(pkgtcldir);    rm -f gv.so;)
#
#test: $(TESTS)
#
#.PHONY: test_sharp
#test_sharp: libgv_sharp.la
#	-(mkdir -p test_sharp; cd test_sharp; \
#		ln -fs ../.libs/libgv_sharp.so libgv_sharp.so; \
#		ln -fs ../*.dot ../*.cs .; \
#		$(SHARP) *.cs -out:test.exe; \
#		mono test.exe)
#
#.PHONY: test_guile
#test_guile: libgv_guile.la
#	-(mkdir -p test_guile; cd test_guile; \
#		ln -fs ../.libs/libgv_guile.so libgv.so; \
#		ln -fs ../*.dot ../*.guile .; \
#		$(GUILE) -s test.guile)
#
#.PHONY: test_io
#test_io: libgv_io.la
#	-(mkdir -p test_io; cd test_io; \
#		ln -fs ../.libs/libgv_io.so libgv.so; \
#		ln -fs ../*.dot ../*.io .; \
#		ioc *.io; \
#		LD_LIBRARY_PATH=. io test)
#
#.PHONY: test_java
#test_java: libgv_java.la
#	-(mkdir -p test_java; cd test_java; \
#		ln -fs ../.libs/libgv_java.so libgv.so; \
#		ln -fs ../*.dot ../*.java .; \
#		javac *.java; \
#		LD_LIBRARY_PATH=. CLASSPATH=. java test)
#
#.PHONY: test_lua
#test_lua: libgv_lua.la
#	-(mkdir -p test_lua; cd test_lua; \
#		ln -fs ../.libs/libgv_lua.so ../*.dot ../*.lua .; \
#		$(LUA) test.lua)
#
#.PHONY: test_ocaml
#test_ocaml: libgv_ocaml.la
#	-(mkdir -p test_ocaml; cd test_ocaml; \
#		ln -fs ../.libs/libgv_ocaml.so libgv.so; \
#		ln -fs ../*.dot ../*.ocaml .; \
#		ocamlc *.ocaml; \
#		LD_LIBRARY_PATH=. ocaml test)
#
#.PHONY: test_perl
#test_perl: libgv_perl.la
#	-(mkdir -p test_perl; cd test_perl; \
#		ln -fs ../.libs/libgv_perl.so gv.so; \
#		ln -fs ../*.dot ../*.p[lm] .; \
#		$(PERL) ./test.pl)
#
#.PHONY: test_php
#test_php: libgv_php.la
#	-(mkdir -p test_php; cd test_php; \
#		ln -fs ../.libs/libgv_php.so libgv.so; \
#		ln -fs ../*.dot ../*.php .; \
#		$(PHP) ./test.php)
#
#.PHONY: test_python
#test_python: _gv.la
#	-(mkdir -p test_python; cd test_python; \
#		ln -fs ../.libs/libgv_python.so _gv.so; \
#		ln -fs ../*.dot ../*.py .; \
#		PYTHONPATH=. $(PYTHON) test.py)
#
#.PHONY: test_ruby
#test_ruby: gv.la
#	-(mkdir -p test_ruby; cd test_ruby; \
#		ln -fs ../.libs/libgv_ruby.so gv.so; \
#		ln -fs ../.libs/gv.so ../*.dot ../*.rb .; \
#		$(RUBY) test.rb)
#
#.PHONY: test_tcl
#test_tcl: libgv_tcl.la
#	-(mkdir -p test_tcl; cd test_tcl; \
#		ln -fs ../.libs/libgv_tcl.so libgv_tcl.so; \
#		ln -fs ../*.dot ../*.tcl .; \
#		$(TCLSH) ./test.tcl)
#
#EXTRA_DIST = demo/* gv_doc_*.tcl \
#	gv_sharp.cpp $(SHARP_hdr)
#
#CLEANFILES = test_*/* gv_*.man \
#	gv_sharp.cpp $(SHARP_hdr) \
#	gv_guile.cpp $(GUILE_hdr) \
#	gv_io.cpp $(IO_hdr) \
#	gv_java.cpp $(JAVA_hdr) \
#	gv_lua.cpp $(LUA_hdr) \
#	gv_ocaml.cpp $(OCAML_hdr) \
#	gv_perl.cpp $(PERL_hdr) \
#	gv_php.cpp $(PHP_hdr) \
#	gv_python.cpp $(PYTHON_hdr) gv.pyc \
#	gv_ruby.cpp $(RUBY_hdr) \
#	gv_tcl.cpp $(TCL_hdr)
