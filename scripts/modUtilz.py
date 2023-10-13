#   ============================================================
#   some commonly used features
#   ============================================================
#   created by Manfred Sorgo

import re
from os.path import basename
from subprocess import Popen, DEVNULL, PIPE

rxSpl = re.compile(r'[/\\]')
rxHdr = re.compile(r'\.h$')
rxLin = re.compile(r' +$', re.M)
rxEnd = re.compile(r'\s*$')
#   mimetypes.guess_type did not detect .lua
#   so we just go by extension
rxTxt = re.compile(r'\.(?:cpp|cfg|dat|h|lua|md|pl|py|sh|)$')

def incHeader(header:str, nsubs=1):
    return f"#include <{'/'.join(rxSpl.split(header)[-(nsubs + 1):])}>"

def locHeader(header:str):
    return f'#include "{basename(header)}"'

def isHaeder(file:str):
    return rxHdr.search(file)

def cleanTxt(txt:str, tabs=4):
    return rxEnd.sub('\n', rxLin.sub('', txt.expandtabs(tabs)))

def cleanFileTxt(fp:str, tabs=4):
    with open(fp, 'r') as fh:
        return cleanTxt(fh.read())

def isTxtFile(fp):
    return rxTxt.search(fp) is not None

def writeFile(fp, cont):
    with open(fp, 'w') as fh:
        fh.write(cont)

def procOut(call) -> str:
    # if type(call) == str:
    #     call = call.split()
    with Popen(call, stdout=PIPE, shell=True) as proc:
        return rxEnd.sub('', proc.stdout.read().decode('ascii'))

def procOutList(call):
    # return [c for c in procOut(call).split('\n') if c]
    return procOut(call).split('\n')

if __name__ == '__main__':
    from projectDirs import *
    print(isTxtFile('/buildTests.sh'))
    print(isTxtFile('/premake5.lua'))
    print(isTxtFile('/wumpel.obj'))
