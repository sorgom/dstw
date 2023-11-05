#!/bin/bash
#   ============================================================
#   selectors for bullseye coverage
#   ============================================================
covselect -d
covselect -a '../application/**/*.*'
covselect -a '!../testing/**/*.*'
covselect -a '!../BuildCppUTest/**/*.*'
covselect -a '!../CppUTestSteps/**/*.*'
covselect -lq
CppUTestSteps