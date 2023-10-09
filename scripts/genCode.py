import re
from os.path import basename

rxSec = re.compile(r'^([ \t]*)//#[ \t]*(\w+)[ \t]*\n.*?//#[ \t]*END', re.M | re.S)
rxInc = re.compile(r'^[ \t]*//##[ \t]*(INCLUSIONS)(_LOCAL)?[ \t]*\n.*?//##[ \t]*END', re.M | re.S)
rxSpl = re.compile(r'[/\\]')

gIncs  = None
gNames = None
gSubs = 1

def genCode(targets=[], names=[], includes=[], nsub=1):
    global gNames, gIncs, gSubs
    gNames = names
    gIncs  = includes
    gSubs  = nsub
    for file in targets:
        genTarget(file)

def inc(header:str):
    return f"#include <{'/'.join(rxSpl.split(header)[-(gSubs + 1):])}>"

def incLoc(header:str):
    return f'#include "{basename(header)}"'

def replSec(mo):
    ind = mo.group(1)
    sec = mo.group(2)
    cont = [ f'{ind}{sec}({name})' for name in gNames]
    cont.insert(0, f'{ind}//# {sec}')
    cont.append(f'{ind}//# END')
    return '\n'.join(cont)

def replInc(mo):
    sec  = mo.group(1)
    loc  = mo.group(2)
    func = incLoc if loc else inc
    cont = [ func(name) for name in gIncs]
    cont.insert(0, f'//## {sec}{loc}')
    cont.append(f'//## END')
    return '\n'.join(cont)

def genTarget(file:str):
    with open(file, 'r') as fh:
        txt = fh.read()
        txt = rxSec.sub(replSec, txt)
        txt = rxInc.sub(replInc, txt)
        print(txt)

if __name__ == '__main__':
    # head = '/mnt/d/git/cppu/application/modules/ddi/ddi.h'
    # head = 'D:/git/cppu/testing/mocks/M_Instances.h'
    # head = 'D:/git/cppu/application/modules/ddi/ddi.h'
    # gNames = ['wumpel', 'lola', 'zardoz']
    incs = [
        '/mnt/d/git/cppu/application/modules/ddi/ddi.h',
        'D:/git/cppu/application/modules/ddi/ddi.h',
        'D:/git/cppu/testing/mocks/M_Instances.h'
    ]
    genCode(
        targets=['D:/git/cppu/testing/ddi/src/ddi.cpp'], 
        names=['wumpel', 'lola', 'zardoz'], 
        includes=incs
    )
