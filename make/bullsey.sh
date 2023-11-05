#!/bin/bash
#   ============================================================
#   selectors for bullseye coverage
#   ============================================================
covselect -d
covselect -a '../application/**/*.*'
covselect -a '!../testing/**/*.*'
covselect -a '!../BuildCpp*/**/*.*'
covselect -lq
