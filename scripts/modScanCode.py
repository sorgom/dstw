from os.path import normpath
import re

rxDdi = re.compile(r'^[ \t]*DDI_INSTANCE_DEC[ \t]*\([ \t]*(\w+)[ \t]*\)', re.M) 
rxMoc = re.compile(r'^[ \t]*class[ \t]+M_(\w+)[^\{]+public[ \t]+I_\1\b', re.M) 

def scanCode(rx, headers:list):
    hs = set()
    ns = set()
    for h in headers:
        h = normpath(h)
        with open(h, 'r') as fh:
            txt = fh.read()
            fnd = rx.findall(txt)
            if fnd:
                hs.add(h)
                for n in fnd:
                    ns.add(n)
    return (hs, ns)

def scanDdi(headers:list):
    return scanCode(rxDdi, headers)

def scanMoc(headers:list):
    return scanCode(rxMoc, headers)

if __name__ == '__main__':
    from projectDirs import modDir, envDir
    from os import name as osname
    from glob import glob
    ddiPath = modDir + '/*/*.h'
    mocPath = envDir + '/mocks/*.h'

    print(scanDdi(glob(ddiPath)))
    print(scanMoc(glob(mocPath)))
