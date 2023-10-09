from genCode import genCode
from os.path import normpath
import re

rxInstDec = re.compile(r'^[ \t]*DDI_INSTANCE_DEC[ \t]*\([ \t]*(\w+)[ \t]*\)', re.M) 

def scanDdi(headers:list):
    hs = dict()
    ns = dict()
    for h in headers:
        h = normpath(h)
        with open(h, 'r') as fh:
            txt = fh.read()
            fnd = rxInstDec.findall(txt)
            if fnd:
                hs[h] = 1
                for n in fnd:
                    ns[n] = 1
    return (sorted(hs.keys()), sorted(ns.keys()))

if __name__ == '__main__':
    from os import name as osname
    from glob import glob
    hpath = None
    if osname == 'posix':
        hpath = '/mnt/d/git/cppu/application/modules/*/*.h'
    else:
        hpath = 'D:/git/cppu/application/modules/*/*.h'

    headers = glob(hpath)
    print(scanDdi(headers))
