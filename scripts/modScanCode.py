from os.path import normpath
import re

rxDdi = re.compile(r'^[ \t]*DDI_INSTANCE_DEC[ \t]*\([ \t]*(\w+)[ \t]*\)', re.M) 
rxMoc = re.compile(r'^[ \t]*class[ \t]+M_(\w+)[^\{]+public[ \t]+I_\1\b', re.M) 

def scanCode(rx, headers:list):
    hs = dict()
    ns = dict()
    for h in headers:
        h = normpath(h)
        with open(h, 'r') as fh:
            txt = fh.read()
            fnd = rx.findall(txt)
            if fnd:
                hs[h] = 1
                for n in fnd:
                    ns[n] = 1
    return (sorted(hs.keys()), sorted(ns.keys()))

def scanDdi(headers:list):
    return scanCode(rxDdi, headers)

def scanMoc(headers:list, appNames=None):
    includes, mocNames = scanCode(rxMoc, headers)
    if appNames:
        mocNames = sorted(list(set(appNames).intersection(mocNames)))
    return (includes, mocNames)

if __name__ == '__main__':
    from os import name as osname
    from glob import glob
    ddiPath  = None
    mocPath = None
    if osname == 'posix':
        ddiPath  = '/mnt/d/git/cppu/application/modules/*/*.h'
        mocPath = '/mnt/d/git/cppu/testing/mocks/*.h'
    else:
        ddiPath  = 'D:/git/cppu/application/modules/*/*.h'
        mocPath = 'D:/git/cppu/testing/mocks/*.h'

    print(scanDdi(glob(ddiPath)))
    print(scanMoc(glob(mocPath)))
