#   ============================================================
#   some commonly used features
#   ============================================================
#   created by Manfred Sorgo

import re
from os.path import basename, exists
from subprocess import Popen, DEVNULL, PIPE
from os import name as oname
from sys import exit

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

def fileTxt(fp):
    with open(fp, 'r') as fh:
        return fh.read()

def cleanTxt(txt:str, tabs=4):
    return rxEnd.sub('\n', rxLin.sub('', txt.expandtabs(tabs)))

def cleanFileTxt(fp:str, tabs=4):
    return cleanTxt(fileTxt(fp), tabs)

def isTxtFile(fp):
    return rxTxt.search(fp) is not None

def writeFile(fp, cont):
    with open(fp, 'w') as fh:
        fh.write(cont)

def procOut(call) -> str:
    with Popen(call, stdout=PIPE, shell=True) as proc:
        return rxEnd.sub('', proc.stdout.read().decode('ascii'))

def procOutList(call):
    return procOut(call).split('\n')

def repoDir():
    return procOut('git rev-parse --show-toplevel')

def repoFiles(dir:str = ''):
    return procOutList(f'git ls-files {dir}')

def mdCode(cont:str):
    return '\n'.join(['```', cont, '```'])

def checkLinux():
    if oname != 'posix':
        print('linux required')
        exit(-1)

def commonLen(lines:list):
    if len(lines) < 1: return 0
    res = len(lines[0])
    for n in range(1, len(lines)):
        lin1 = lines[n - 1]
        lin2 = lines[n]
        ln = min(res, len(lin2))
        res = 0
        for p in range(0, ln):
            if lin1[p] == lin2[p]: res += 1
            else: break
    return res

def mdTxt(mdf, ttl):
    if exists(mdf):
        rxTtl = re.compile(r'\s*' + ttl + r'.*', re.M | re.S)
        return rxTtl.sub('', fileTxt(mdf))
    return ''


if __name__ == '__main__':
    from projectDirs import *
    print(isTxtFile('/buildTests.sh'))
    print(isTxtFile('/premake5.lua'))
    print(isTxtFile('/wumpel.obj'))

    print(f'## REPO: "{repoDir()}"')
    for f in repoFiles():
        print(f)
    
    print(commonLen(['wumpel', 'wumpi', 'wummi']))