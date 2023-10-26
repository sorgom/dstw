#   ============================================================
#   put line breaks into mdj files
#   to create smaller git diffs
#   ============================================================
#   created by Manfred Sorgo

from modUtilz import fileTxt, writeFile
import re
from sys import argv

rxOpen  = re.compile(r'([\[\{}])\n?')
rxClose = re.compile(r'\n?([\]\}])')

def cleanMdj(fps:list):
    for fp in fps:
        txt = fileTxt(fp)
        out = rxClose.sub(r'\n\1', rxOpen.sub(r'\1\n', txt))
        writeFile(fp, out)

if __name__ == '__main__':
    cleanMdj(argv[1:])
    

