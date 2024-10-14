#   ============================================================
#   all pre-commit script calls in one
#   ============================================================
#   created by Manfred Sorgo

from projectDirs import *
from modGenCloc import genCloc
from runGcov import gcovToMd
from modUtilz import checkLinux

from glob import glob
from sys import argv, exit

# linux only
checkLinux()
print("* genCloc")
genCloc(['application', 'testing/testenv', 'testing/tests/moduletests', 'testing/tests/systemtests', 'specification'])
print("* gcovToMd")
gcovToMd()
