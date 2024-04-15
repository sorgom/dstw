#   ============================================================
#   simple code scanner for code generator features
#   - application instance declarations for IL
#   - mocks
#   - data structs
#   - interface declarations
#   - ostream specializations
#   ============================================================
#   created by Manfred Sorgo

from os.path import normpath
import re
from modUtilz import isHaeder

# IL instance declaration
rxDdi = re.compile(r'^[ \t]*IL_INSTANCE_DEC[ \t]*\([ \t]*(\w+)[ \t]*\)', re.M) 
# announced mock class macro
rxMoc = re.compile(r'^[ \t]*MOCK_CLASS\([ \t]*(\w+)[ \t]*\)', re.M)
# derived mock class
rxDmo = re.compile(r'^[ \t]*class[ \t]+M_(\w+)\s*:\s*public\s+M_', re.M)
# data struct
rxDat = re.compile(r'^[ \t]*struct[ \t]+(\w+)', re.M)
# interface declaration
rxInt = re.compile(r'^[ \t]*class[ \t]+I_(\w+)', re.M)
# ostream specialization
rxStr = re.compile(r'^[ \t]*OSTREAM_DEF\([ \t]*(\w+)[ \t]*\)', re.M)

def scanCode(rxs:list, files:list):
    hs = set()
    ns = set()
    for f in files:
        f = normpath(f)
        with open(f, 'r') as fh:
            txt = fh.read()
            for rx in rxs:
                fnd = rx.findall(txt)
                if fnd:
                    if isHaeder(f):
                        hs.add(f)
                    for n in fnd:
                        ns.add(n)
    return (hs, ns)

def scanDdi(files:list):
    return scanCode([rxDdi], files)

def scanMoc(files:list):
    return scanCode([rxMoc, rxDmo], files)

def scanLit(files:list):
    return scanCode([rxDat, rxInt], files)

def scanCmp(files:list):
    return scanCode([rxStr], files)

def scanDat(files:list):
    return scanCode([rxDat], files)

def scanIfs(files:list):
    return scanCode([rxInt], files)

if __name__ == '__main__':
    from projectDirs import modDir, envDir
    from os import name as osname
    from glob import glob
    ddiPath = modDir + '/*/*.h'
    mocPath = envDir + '/mocks/*.h'

    print(scanDdi(glob(ddiPath)))
    print(scanMoc(glob(mocPath)))
