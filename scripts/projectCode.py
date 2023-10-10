from glob import glob

from modScanCode import scanDdi, scanMoc
from modGenCode import genCode
from projectDirs import modDir, tstDir, mocDir

includes, appNames = scanDdi(glob(modDir + '/*/*.h'))
genCode(
    targets = [
        modDir + '/ddi/ddi.h',
        tstDir + '/ddi/ddi.h',
        tstDir + '/ddi/src/ddi.cpp'
    ],
    names = appNames,
    includes = includes,
    nsub = 1
)

includes, mocNames = scanMoc(glob(tstDir + '/mocks/*.h'), appNames)
genCode(
    targets = [
        mocDir + '/M_Instances.h',
        mocDir + '/src/M_Instances.cpp'
    ],
    names = mocNames,
    includes = includes,
    nsub = 1
)
