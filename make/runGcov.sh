#!/bin/bash
#   ====================================
#   run coverage using gcov
#   ====================================
cd $(dirname $0)

help()
{
    echo "Usage: $(basename $0) [options]"
    echo "run coverage using gcov"
    echo "options:"
    echo "-s  show uncovered file content"
    echo "-h  this help"
    exit
}


show=0
while getopts hs option; do
    case $option in
      (h)  help;;
      (s)  show=1;;
    esac
done
shift $(($OPTIND - 1))


gcov -o obj/gcc/coverage_app ../application/components/*/src/*.cpp > /dev/null 2> /dev/null  

out () {
    printf "%-25s: %4d\n" $1 $2
}

out files $(ls *.cpp.gcov | wc -l)
tot=0
failed=()
for cf in *.cpp.gcov; do
    nuc=$(cat $cf | grep '#####:' | wc -l)
    if test $nuc -ne 0; then
        if test $tot -eq 0; then echo; echo uncovered LOC:; fi
        tot=$((tot+nuc))
        out ${cf%.*} $nuc
        failed+=($cf)
        ret=1
    fi
done
if test $tot -ne 0; then
    out TOTAL $tot
    if test $show -eq 1; then
        for cf in ${failed[*]}; do
            cat $cf
        done
    fi
else echo OK
fi
exit $tot