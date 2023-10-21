#   ============================================================
#   all pre-commit script calls in one
#   ============================================================
#   created by Manfred Sorgo

from projectDirs import *
from cleanMdj import cleanMdj
from cleanSvg import cleanSvg
from modGenMd import genMd
from modGenCloc import genCloc

from glob import glob

cleanMdj(glob(f'{diaDir}/*.mdj'))
cleanSvg(glob(f'{diaDir}/*.svg'))
genMd()

# linux only
genCloc(['application', 'testing/testenv', 'testing/tests', 'specification'])