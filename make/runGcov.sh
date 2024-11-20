#!/bin/bash
#   ====================================
#   run coverage using gcov
#   ====================================
cd $(dirname $0)
myDir=$(pwd)
cd ..
repo=$(pwd)
appDir=../application/components
buildDir=$repo/build
objDir=linux/obj/debug/gcovapp
bindir=$buildDir/linux/bin

cd $myDir
make -j config=debug gcovapp gcovtests

cd $buildDir
rm -f *.gcov
$bindir/gcovtests > /dev/null
gcov -o $objDir $appDir/*/src/*.cpp > /dev/null 2> /dev/null

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
    fi
done
if test $tot -ne 0; then
    out TOTAL $tot
else echo OK
fi
rm *.gcov
exit $tot
