#   ============================================================
#   all pre-commit script calls in one
#   ============================================================
#   created by Manfred Sorgo

from projectDirs import *
from cleanMdj import cleanMdj
from cleanSvg import cleanSvg
from modGenMd import genMd
from modGenCloc import genCloc
from runGcov import gcovToMd
from modUtilz import checkLinux

from glob import glob
from sys import argv, exit

print("* cleanMdj")
cleanMdj(glob(f'{docDir}/*.mdj'))
print("* cleanSvg")
cleanSvg(glob(f'{docDir}/*.svg'))

if len(argv) > 1: exit()

print("* genMd")
genMd()

# linux only
checkLinux()
print("* genCloc")
genCloc(['application', 'testing/testenv', 'testing/tests/moduletests', 'testing/tests/systemtests', 'specification'])
print("* gcovToMd")
gcovToMd()