#   ============================================================
#   clean SVG files from UNREGISTERED background
#   also put line breaks behind tags
#   to create smaller git diffs
#   ============================================================
#   created by Manfred Sorgo

from modUtilz import fileTxt, writeFile
import re
from sys import argv

rxClean = re.compile(r'<text.*?>UNREGISTERED</text>')
rxTags  = re.compile(r'(<[^>]*>)\n?')
rxEnd   = re.compile(r'[ \t]+$', re.M)
rxLine  = re.compile(r'^\n', re.M)

def cleanSvg(fps:list):
    for fp in fps:
        txt = fileTxt(fp)
        out = rxLine.sub('', rxEnd.sub('', rxTags.sub(r'\1\n', rxClean.sub('', txt))))
        writeFile(fp, out)

if __name__ == '__main__':
    cleanSvg(argv[1:])
    

