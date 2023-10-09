
from os.path import dirname, abspath
from subprocess import call, DEVNULL
from os import chdir
from glob import glob
import re
from sys import exit

rxUnc = re.compile(r'^ *#*: *\d+:', re.M)
rxNoc = re.compile(r'// *NO_COV *>> *\n(.*?)// *<< *NO_COV', re.S)
rxSrc = re.compile(r'^.*?0:Source:(.*)')
rxLin = re.compile(r'\n')

cntNoc = 0
uncov = list()

chdir(abspath(dirname(__file__)))

def com(cmd:str):
    call(cmd, shell=True, stdout=DEVNULL, stderr=DEVNULL)

com('./bin/moduletests_coverage')
com('gcov -o obj/application_coverage ../application/modules/*/src/*.cpp')

def cntLines(mo):
    global cntNoc
    cntNoc += len(rxLin.findall(mo.group(1)))
    return ''

def chkcov(fn:str):
    global uncov
    with open(fn) as fh:
        txt = fh.read()
        txt = rxNoc.sub(cntLines, txt)
        cntUnc = len(rxUnc.findall(txt))
        if cntUnc > 0:
            src = rxSrc.match(txt).group(1)
            uncov.append((cntUnc, src))

for fn in glob('*.gcov'):
    chkcov(fn)

if cntNoc:
    print('>> exculded lines:', cntNoc)

if uncov:
    print('>> not covered:')
    tot = (sum([t[0] for t in uncov]))
    uncov.append((tot, 'total'))
    for cnt, src in uncov:
        print("%6d: %s " % (cnt, src))
    exit(1)
