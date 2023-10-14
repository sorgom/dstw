#   ============================================================
#   run CppUTest tests
#   - run test binary
#   - output to report text
#   - count failures reported
#   ============================================================
#   created by Manfred Sorgo

from subprocess import call
from os import chdir
import re
from sys import exit

rxErr = re.compile(r'^ *errors *\((\d+) +failures\b', re.M | re.I)

def runTests(workDir, binary, report='report.txt'):
    chdir(workDir)
    with open(report, 'w') as fh:
        call([binary, '-v'], stdout=fh, stderr=fh)
    with open(report, 'r') as fh:
        txt = fh.read()
        res = rxErr.findall(txt)
        if res:
            tot = sum([int(d) for d in res])
            print('>> failures:', tot)
            exit(1)
