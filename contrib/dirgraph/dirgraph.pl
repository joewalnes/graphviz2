#!/usr/bin/perl
#
# Create a dot(1) graph file from a directory hierarchy
#
# (C) Copyright 2001 Diomidis Spinellis.
#
# Permission to use, copy, and distribute this software and its
# documentation for any purpose and without fee is hereby granted,
# provided that the above copyright notice appear in all copies and that
# both that copyright notice and this permission notice appear in
# supporting documentation.
# 
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
# MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
#
# $Id: dirgraph.pl,v 1.3 2009/06/03 01:10:49 ellson Exp $
#

print "#!/usr/local/bin/dot
# Automatically generated file.
# Contains the directory representation of $ARGV[0] generated by $0
#

";

if ($#ARGV != 0) {
	print STDERR "$0: usage $0 directory\n";
	exit(1);
}

$unix = (-r '/dev/null');

if ($unix) {
	open(IN, $cmd = "find $ARGV[0] -type d -print|") || die "Unable to run $cmd: $!\n";
} else {
	# Hopefully Windows
	open(IN, $cmd = "dir /b/ad/s $ARGV[0]|") || die "Unable to run $cmd: $!\n";
}

while (<IN>) {
	chop;
	if ($unix) {
		@paths = split(/\//, $_);
	} else {
		@paths = split(/\\/, $_);
	}
	undef $op;
	undef $path;
	for $p (@paths) {
		$path .= "/$p";
		$name = $path;
		$name =~ s/[^a-zA-Z0-9]/_/g;
		$node{$name} = $p;
		$edge{"$op->$name;"} = 1 if ($op);
		$op = $name;
	}
}
close(IN);
print 'digraph G {
	nodesep=.1;
	rankdir=LR;
	node [height=.15,shape=box,fontname="Helvetica",fontsize=8];
	edge [arrowhead=none,arrowtail=none];

'
;
for $i (sort keys %node) {
	print "\t$i [label=\"$node{$i}\"];\n";
}
for $i (sort keys %edge) {
	print "\t$i\n";
}
print "}\n";
