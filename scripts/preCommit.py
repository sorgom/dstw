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

print("* cleanMdj")
cleanMdj(glob(f'{diaDir}/*.mdj'))
print("* cleanSvg")
cleanSvg(glob(f'{diaDir}/*.svg'))
print("* genMd")
genMd()

# linux only
checkLinux()
print("* genCloc")
genCloc(['application', 'testing/testenv', 'testing/tests', 'specification'])
print("* gcovToMd")
gcovToMd()