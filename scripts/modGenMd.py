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
#   pre, char, inf
rxInf = re.compile(r'^(.*?)([*=-])\2{19,}\n(.*?)\n\1\2{20,}', re.M | re.S)

def isMd(fn):
    return rxMd.search(fn)

def genMd(tabs=4):
    # split into path : [files] 
    pfs = {}
    for p, f in [ (dirname(fp), basename(fp)) for fp in repoFiles()]:
        if not isMd(f): pfs.setdefault(p, []).append(f)
    rDir = repoDir()
    # scan files in directories    
    for p, fs in pfs.items():
        chdir(f'{rDir}/{p}')
        res = []
        for f in fs:
            try:
                txt = cleanFileTxt(f)
                cont = []
                for pre, char, inf in rxInf.findall(txt):
                    rx = re.compile(r'^' + pre.replace(' ', ' ?'), re.M)
                    inf = rx.sub('', inf)
                    if inf: cont.append(inf)
                if cont: res.append('\n'.join([f'**{f}**', mdCode('\n\n'.join(cont))]))
            except:
                pass
        if not res: continue
        res.insert(0, ttl)
        txt = mdTxt(mdf, ttl)
        if txt: res.insert(0, txt)
        writeFile(mdf, '\n\n'.join(res) + '\n')

if __name__ == '__main__':
    genMd()


