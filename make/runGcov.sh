#!/bin/bash
#   ====================================
#   run coverage using gcov
#   ====================================
cd $(dirname $0)

gcov -o obj/gcc/coverage_app/ci ../application/components/*/src/*.cpp > /dev/null   

ret=0
for cf in *.cpp.gcov; do
    nuc=$(cat $cf | grep '#####:' | wc -l)
    if test $nuc -ne 0; then
        printf "%-25s: %4d\n" ${cf%.*} $nuc
        ret=1
    fi
done
exit $ret