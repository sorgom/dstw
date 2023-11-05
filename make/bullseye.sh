#!/bin/bash
#   ============================================================
#   selectors for bullseye coverage
#   ============================================================
covselect -d --no-banner
covselect -a --no-banner '../application/**/*.*'
covselect -a --no-banner '../specification/ifs/*.*'
covselect -a --no-banner '!../testing/**/*.*'
covselect -a --no-banner '!../BuildCppUTest/**/*.*'
covselect -a --no-banner '!../CppUTestSteps/**/*.*'
covselect -lq --no-banner 
