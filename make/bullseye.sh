#!/bin/bash
#   ============================================================
#   bullseye coverage output
#   ============================================================
cov01 -0 --no-banner
bin/_bullseye
covselect -d --no-banner
covselect -a --no-banner '../application/**/*.*'
covselect -a --no-banner '../specification/ifs/*.*'
covselect -a --no-banner '!../testing/**/*.*'
covselect -a --no-banner '!../BuildCppUTest/**/*.*'
covselect -a --no-banner '!../CppUTestSteps/**/*.*'
covsrc -bm --no-banner
