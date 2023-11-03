#   ============================================================
#   simple code generator features
#   ============================================================
#   created by Manfred Sorgo

import re
from os.path import basename
from modUtilz import incHeader, locHeader

rxSec = re.compile(r'^(([ \t]*)//#[ \t]*(\w+)(?:[ \t]*:[ \t]*(\w+))?)[ \t]*\n.*?//#[ \t]*END', re.M | re.S)
rxInc = re.compile(r'^([ \t]*//##[ \t]*(INCLUDES)(_LOCAL)?)[ \t]*\n.*?//##[ \t]*END', re.M | re.S)
rxSpl = re.compile(r'[/\\]')

gIncs  = None
gNames = None
gSubs  = 1
gCfgs  = None
gCond  = None

rNames = None
rCond  = None

def genCode(targets=[], names=[], includes=[], cond=None, nsub=1):
    global gNames, gIncs, gSubs, gCond, gCfgs
    gNames = names
    gIncs  = sorted(includes)
    gSubs  = nsub
    gCond  = cond
    for file in targets:
        genTarget(file)

def inc(header:str):
    return incHeader(header, gSubs)

def replSec(mo):
    top = mo.group(1)
    ind = mo.group(2)
    sec = mo.group(3)
    cnd = mo.group(4)
    if cnd != rCond:
        return mo.group(0)
    cont = [ f'{ind}{sec}({name})' for name in sorted(rNames)]
    cont.insert(0, top)
    cont.append(f'{ind}//# END')
    return '\n'.join(cont)

def replInc(mo):
    top  = mo.group(1)
    sec  = mo.group(2)
    loc  = mo.group(3) or ''
    func = locHeader if loc else inc
    cont = [ func(name) for name in gIncs]
    cont.insert(0, top)
    cont.append('//## END')
    return '\n'.join(cont)

def genTarget(file:str):
    global rNames, rCond
    with open(file, 'r') as fh:
        oTxt = fh.read()
        fh.close()
        nTxt = rxInc.sub(replInc, oTxt)
        if type(gNames) == dict:
            for cond, names in gNames.items():
                rCond = cond
                rNames = names
                nTxt = rxSec.sub(replSec, nTxt)
        else:
            rCond = gCond
            rNames = gNames
            nTxt = rxSec.sub(replSec, nTxt)
        if nTxt != oTxt:
            with open(file, 'w') as fh:
                print('>>', file)
                fh.write(nTxt)

if __name__ == '__main__':
    from projectDirs import modDir, envDir
    incs = [
        modDir + '/SYS/IL.h',
        envDir + '/mocks/M_Instances.h'
    ]
    targets = [
        envDir + '/SYS/src/IL.cpp'
    ]
    genCode(
        targets=targets, 
        names=['wumpel', 'lola', 'zardoz'], 
        includes=incs
    )
