#   ============================================================
#   code automatization of this project
#   ============================================================
#   created by Manfred Sorgo

from glob import glob

from modScanCode import *
from modGenCode import genCode
from projectDirs import *

# application ddi
appIncludes, appNames = scanDdi(glob(modDir + '/*/*.h'))
genCode(
    targets = [
        modDir + '/ddi/ddi.h'
    ],
    names = appNames,
    includes = appIncludes,
    nsub = 1
)

# mock instances
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

# test env ddi
genCode(
    targets = [
        envDir + '/ddi/ddi.h',
        envDir + '/ddi/src/ddi.cpp'
    ],
    names = {
        None  : mocNames.union(appNames),
        'APP' : appNames,
        'MOCK': mocNames.difference(appNames)
    },
    includes = mocIncludes.union(appIncludes),
    nsub = 1
)

# test env literals
includes, litNames = scanLit(glob(ifsDir + '/*.h'))
genCode(
    targets = [
        envDir + '/testlib/TestLiterals.h',
        envDir + '/testlib/src/TestLiterals.cpp',
    ],
    names = litNames,
    includes = includes,
    nsub = 1
)

# comparator assignments
srcs, cmpNames = scanCmp([envDir + '/comparators/src/ostreams.cpp'])
genCode(
    targets = [
        envDir + '/comparators/src/installComparators.cpp',
    ],
    names = litNames.intersection(cmpNames),
    includes = [],
    nsub = 1
)

# ostream declaration
includes, datNames = scanDat(glob(ifsDir + '/*.h'))
genCode(
    targets = [
        envDir + '/comparators/ostreams.h',
    ],
    names = datNames,
    includes = includes,
    nsub = 1
)
