
from os.path import dirname, abspath
from subprocess import call
from os import chdir
import re
from sys import exit

rxErr = re.compile(r'^ *errors *\((\d+) +failures\b', re.M | re.I)

chdir(abspath(dirname(__file__)))

report = 'report.txt'
with open(report, 'w') as fh:
    call(['./bin/moduletests', '-v'], stdout=fh, stderr=fh)

with open(report, 'r') as fh:
    txt = fh.read()
    res = rxErr.findall(txt)
    if res:
        tot = sum([int(d) for d in res])
        print('>> failures:', tot)
        exit(1)
