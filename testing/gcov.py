
from os.path import dirname, abspath
from subprocess import call, DEVNULL
from os import chdir
from glob import glob
import re
from sys import exit

rxNot = re.compile(r'^ *#*: *\d+:', re.M)
rxDef = re.compile(r'^ *#*: *\d+: *default *: *\n *#*: *\d+: *break; *$', re.M)
rxSrc = re.compile(r'^.*?0:Source:(.*)')

uncov = list()

chdir(abspath(dirname(__file__)))

def com(cmd:str):
    call(cmd, shell=True, stdout=DEVNULL, stderr=DEVNULL)

com('./bin/moduletests_coverage')
com('gcov -o obj/application_coverage ../application/modules/*/src/*.cpp')

def chkcov(fn:str):
    global uncov
    with open(fn) as fh:
        txt = fh.read()
        cntDef = len(rxDef.findall(txt))
        cntNot = len(rxNot.findall(txt))
        cntBad = cntNot - cntDef * 2
        if cntBad > 0:
            src = rxSrc.match(txt).group(1)
            uncov.append((cntBad, src))

for fn in glob('*.cpp.gcov'):
    chkcov(fn)

if uncov:
    print('>> not covered:')
    tot = (sum([t[0] for t in uncov]))
    uncov.append((tot, 'total'))
    for cnt, src in uncov:
        print("%6d: %s " % (cnt, src))
    exit(1)
