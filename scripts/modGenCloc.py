#   ============================================================
#   application of cloc tool for C++ lines of code
#   - writes CLOC.md
#   ============================================================
#   created by Manfred Sorgo

from modUtilz import checkLinux, mdCode, procOut, repoDir, writeFile
from os.path import basename, exists
from os import chdir
import re

rxCont = re.compile(r'^-------------.*', re.M | re.S)
rxSum  = re.compile(r'^SUM:.*?(\d+)\s*$', re.M)

mdf = 'CLOC.md'

def genCloc(dirs, ext="h,cpp"):
    checkLinux()
    chdir(repoDir())
    res = []
    sum = 0
    for dir in dirs:
        cont = procOut(f'cloc --include-ext="{ext}" {dir}')
        res.append(f'**{basename(dir)}**')
        res.append(mdCode(rxCont.search(cont).group(0)))
        mo = rxSum.search(cont)
        if mo: sum += int(rxSum.search(cont).group(1))
    res.insert(0, f'## total lines of code: {sum}')
    writeFile(mdf, '\n'.join(res))
    
if __name__ == '__main__':
    genCloc(['application', 'testing/testenv', 'testing/tests'])