#!/usr/bin/bash
#   ============================================================
#   run module tests of this project
#   - see makeTests.sh
#   ============================================================
#   created by Manfred Sorgo

mydir=$(dirname $0)
$mydir/../testing/bin/tests $@
