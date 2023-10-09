from glob import glob

from scanDdi import scanDdi
from genCode import genCode
from localDirs import modDir, tstDir

appHeaders = glob(modDir + '/*/*.h')
includes, names = scanDdi(appHeaders)
print(includes)
print(names)
targets = [
    modDir + '/ddi/ddi.h',
    tstDir + '/ddi/ddi.h',
    tstDir + '/ddi/src/ddi.cpp'
]

genCode(
    targets=targets,
    names=names,
    includes=includes,
    nsub=1
)
