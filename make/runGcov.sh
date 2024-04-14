#!/bin/bash
#   ====================================
#   run coverage using gcov
#   ====================================
cd $(dirname $0)

conf=$1
if test -z $conf; then conf=ci; fi

gcov -o obj/gcc/coverage_app/$conf ../application/components/*/src/*.cpp > /dev/null   

out () {
    printf "%-25s: %4d\n" $1 $2
}

out files $(ls *.cpp.gcov | wc -l)
tot=0
for cf in *.cpp.gcov; do
    nuc=$(cat $cf | grep '#####:' | wc -l)
    if test $nuc -ne 0; then
        if test $tot -eq 0; then echo; echo uncovered LOC:; fi
        tot=$((tot+nuc))
        out ${cf%.*} $nuc
        ret=1
    fi
done
if test $tot -ne 0; then out TOTAL $tot;
else echo OK
fi
exit $tot