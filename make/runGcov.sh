#!/bin/bash
#   ====================================
#   run coverage using gcov
#   ====================================
cd $(dirname $0)

conf=$1
if test -z $conf; then conf=ci; fi

gcov -o obj/gcc/coverage_app/$conf ../application/components/*/src/*.cpp > /dev/null   

echo $(ls *.cpp.gcov | wc -l) files ...
ret=0
for cf in *.cpp.gcov; do
    nuc=$(cat $cf | grep '#####:' | wc -l)
    if test $nuc -ne 0; then
        printf "%-25s: %4d\n" ${cf%.*} $nuc
        ret=1
    fi
done
if test $ret -eq 0; then echo OK; fi
exit $ret