#!/bin/bash

help()
{
    echo "===================================="
    echo "build all major makes parallelly"
    echo "options:"
    echo "-r  remove all artifacts before"
    echo "-x  execute all binaries"
    echo "-h  this help"
    echo "===================================="
    exit
}

tm()
{
    en=$(date +%s)
    printf "%-25s[%3d]\n" $1 $(($en-$2))
}

mk()
{
    st=$(date +%s)
    make -j -f $1 > /dev/null
    tm ${1%.*} $st
}

rem=
exe=
while getopts hrx option; do
    case $option in
      (h)  help;;
      (r)  rem=1;;
      (x)  exe=1
    esac
done

cd $(dirname $0)

if test ! -z $rem; then rm -rf bin lib obj *.gcov; fi

st=$(date +%s)
for fn in $(ls *.make | grep -v '_'); do
    mk $fn & 
done
wait
tm "DONE" $st

if test -z $exe; then exit; fi

for b in bin/*; do
    echo ''
    echo "====== $b"
    $b -b
done
