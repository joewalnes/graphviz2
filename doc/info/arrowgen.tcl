#!/usr/bin/tclsh

set arrows {
    box
    crow
    diamond
    dot
    inv
    lbox
    lcrow
    ldiamond
    linv
    lnormal
    ltee
    lvee
    none
    normal
    obox
    odiamond
    odot
    oinv
    olbox
    oldiamond
    olinv
    olnormal
    onormal
    orbox
    ordiamond
    orinv
    ornormal
    rbox
    rcrow
    rdiamond
    rinv
    rnormal
    rtee
    rvee
    tee
    vee
}

set arrowexamples {
    box
    crow
    diamond
    dot
    ediamond
    empty
    forward
    halfopen
    inv
    invdot
    invempty
    invodot
    lteeoldiamond
    nohead
    none
    normal
    obox
    odiamond
    odot
    open
    tee
}

foreach {arrow} $arrows {
	set f [open aa_$arrow.dot w]
	puts $f "digraph G \{"
	puts $f "graph \[pad=\"0.05\" rankdir=LR\]"
	puts $f "a \[label=\"\" shape=point\]"
	puts $f "b \[label=\"\" shape=none width=0 height=0\]"
	puts $f "a -> b \[arrowhead=$arrow\]"
	puts $f "\}"
	close $f
	exec dot -Tgif aa_$arrow.dot -o aa_$arrow.gif

	file delete aa_$arrow.dot
}

foreach {arrow} $arrowexamples {
	set f [open a_$arrow.dot w]
	puts $f "digraph G \{"
	puts $f "graph \[pad=\"0.05\" rankdir=LR\]"
	puts $f "a \[label=\"\" shape=point\]"
	puts $f "b \[label=\"\"]"
	puts $f "a -> b \[arrowhead=$arrow\]"
	puts $f "\}"
	close $f
	exec dot -Tgif a_$arrow.dot -o a_$arrow.gif

	file delete a_$arrow.dot
}
