#   ============================================================
#   simple md generator 
#   ============================================================
#   created by Manfred Sorgo

from os import walk as oswalk
from os import remove, chdir
from os.path import exists
from sys import exit
import re
from modUtilz import cleanFileTxt, isTxtFile, writeFile, procOutList, procOut
from subprocess import Popen, DEVNULL, PIPE

rxMd  = re.compile(r'\.md$')
rxInf = re.compile(r'^(.*?)([*=-])\2{19,}\n(.*?)\n\1\2{20,}', re.M | re.S)

def isMd(fn):
    return rxMd.search(fn)

def genMd(
        folders=[],
        tabs=4
    ):
    for fd in folders:
        print(fd)
        cnt = 1
        for dir, sdirs, fns in oswalk(fd):
            trg = f'{dir}/readme.md'
            res = ['## directory content']
            for (fn, fp) in [ (fn, f'{dir}/{fn}') for fn in fns if isTxtFile(fn) and not isMd(fn)]:
                print(fn, fp)
                txt = cleanFileTxt(fp)
                cont = []
                for mo in rxInf.findall(txt):
                    rx = re.compile(r'^' + mo[0].replace(' ', ' ?'), re.M)
                    inf = rx.sub('', mo[2])
                    if inf:
                        cont.append(inf)
                if cont:
                    res.append('\n'.join([f'#### {fn}', '\n\n'.join(cont)]))
            if len(res) > 1:
                writeFile(trg, '\n\n'.join(res))
            elif exists(trg):
                remove(trg)


if __name__ == '__main__':
    from projectDirs import *
    chdir(ifsDir)
    # with Popen('git ls-tree --full-tree --name-only -r HEAD'.split(), stdout=PIPE) as proc:
    # with Popen('git ls-tree --name-only -r HEAD'.split(), stdout=PIPE) as proc:
        # print(str(proc.stdout.read()).split('\n'))
    print(procOutList('git ls-tree --full-tree --name-only -r HEAD'))
    print(procOut('git rev-parse --show-toplevel'))
    # genMd([topDir])


