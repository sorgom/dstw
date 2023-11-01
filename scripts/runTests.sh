#!/usr/bin/bash
#   ============================================================
#   run module tests of this project
#   - see makeTests.sh
#   ============================================================
#   created by Manfred Sorgo

cd $(dirname $0)
. dirs.rc
$makeDir/bin/tests -b $@
