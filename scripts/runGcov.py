#   ============================================================
#   code coverage of this project
#   ============================================================
#   created by Manfred Sorgo

from modGcov import Gcov
from projectDirs import tsgDir

def runGcov():
    Gcov().run(
        tsgDir,
        './bin/moduletests_coverage',
        'obj/application_coverage',
        '../application/modules/*/src/*.cpp'
    )

if __name__ == '__main__':
    runGcov()
