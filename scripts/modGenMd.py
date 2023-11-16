#   ============================================================
#   simple md generator 
#   ============================================================
#   created by Manfred Sorgo

from os import chdir
from os.path import basename, dirname
import re
from modUtilz import cleanFileTxt, writeFile, repoDir, repoFiles, mdCode, mdTxt

mdf = 'README.md'
ttl = '## directory content'

rxMd  = re.compile(r'\.md$')
#   deco, pre, char, quo, inf
rxInf = re.compile(r'^(([^\n]*?)([*=-])\3{19,})(",?)?\n(.*?)\n\1', re.M | re.S)
rxQuo = re.compile(r'",?$', re.M)

def isMd(fn):
    return rxMd.search(fn)

def genMd(tabs=4):
    rDir = repoDir()
    chdir(rDir)
    pfs = {}
    for p, f in [ (dirname(fp), basename(fp)) for fp in repoFiles()]:
        if not isMd(f): pfs.setdefault(p, []).append(f)
    # scan files in directories    
    for p, fs in pfs.items():
        chdir(f'{rDir}/{p}')
        res = []
        for f in fs:
            try:
                txt = cleanFileTxt(f)
                cont = []
                for x, pre, y, q, inf in rxInf.findall(txt):
                    rx = re.compile(r'^' + pre.replace(' ', ' ?'), re.M)
                    inf = rx.sub('', inf)
                    if q: inf = rxQuo.sub('', inf)
                    if inf: cont.append(inf)
                if cont:
                    res.append('\n'.join([f'**{f}**', mdCode('\n\n'.join(cont))]))
            except:
                pass
        if not res: continue
        res.insert(0, ttl)
        txt = mdTxt(mdf, ttl)
        if txt: res.insert(0, txt)
        writeFile(mdf, '\n\n'.join(res) + '\n')

if __name__ == '__main__':
    genMd()


