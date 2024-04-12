#!/bin/bash
#   ====================================
#   check for availability of tools
#   ====================================

for call in python python3 py gcov cppcheck; do
    printf "%-12s : %s\n" $call $(which $call)
done