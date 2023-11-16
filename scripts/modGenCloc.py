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

mdf = 'CLOC.md'

def genCloc(dirs, ext="h,cpp"):
    checkLinux()
    chdir(repoDir())
    res = []
    for dir in dirs:
        cont = procOut(f'cloc --include-ext="{ext}" {dir}')
        res.append(f'**{basename(dir)}**')
        res.append(mdCode(rxCont.search(cont).group(0)))
    res.insert(0, '# CLOC')
    writeFile(mdf, '\n'.join(res))
    
if __name__ == '__main__':
    genCloc(['application', 'testing/testenv', 'testing/tests'])