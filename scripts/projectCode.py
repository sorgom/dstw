from glob import glob

from modScanCode import scanDdi, scanMoc
from modGenCode import genCode
from projectDirs import modDir, envDir, mocDir

appIncludes, appNames = scanDdi(glob(modDir + '/*/*.h'))
genCode(
    targets = [
        modDir + '/ddi/ddi.h',
        envDir + '/ddi/ddi.h',
        envDir + '/ddi/src/ddi.cpp'
    ],
    names = appNames,
    includes = appIncludes,
    nsub = 1
)

mocIncludes, mocNames = scanMoc(glob(envDir + '/mocks/*.h'))
genCode(
    targets = [
        mocDir + '/M_Instances.h',
        mocDir + '/src/M_Instances.cpp'
    ],
    names = mocNames,
    includes = mocIncludes,
    nsub = 1
)
