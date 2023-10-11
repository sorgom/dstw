
from subprocess import call, DEVNULL
from os import chdir
from os import name as oname
from glob import glob
import re
from sys import exit

rxUnc = re.compile(r'^ *#*: *\d+:', re.M)
rxNoc = re.compile(r'// *NO_COV *>> *\n(.*?)// *<< *NO_COV', re.S)
rxSrc = re.compile(r'^.*?0:Source:(.*)')
rxLin = re.compile(r'\n')

class Gcov(object):

    def __init__(self):
        self.clear()

    def clear(self):
        self.cntNoc = 0
        self.uncov = list()

    def com(self, cmd:str):
        call(cmd, shell=True, stdout=DEVNULL, stderr=DEVNULL)

    def run(self, workDir, app, objDir, srcs):
        if oname != 'posix':
            print('wrong os:', oname)
            return -1
        self.clear()
        chdir(workDir)
        self.com(app)
        self.com(f'gcov -o {objDir} {srcs}')
        for fn in glob('*.gcov'):
            self.chkcov(fn)
        if self.cntNoc:
            print('>> exculded lines:', self.cntNoc)
        if self.uncov:
            print('>> not covered:')
            tot = (sum([t[0] for t in self.uncov]))
            self.uncov.append((tot, 'total'))
            for cnt, src in self.uncov:
                print("%6d: %s " % (cnt, src))
            return 1
        return 0

    def cntLines(self, mo):
        self.cntNoc += len(rxLin.findall(mo.group(1)))
        return ''
    
    def chkcov(self, fn:str):
        with open(fn) as fh:
            txt = fh.read()
            txn = rxNoc.sub(self.cntLines, txt)
            cntUnc = len(rxUnc.findall(txn))
            if cntUnc > 0:
                print(txn)
                src = rxSrc.match(txt).group(1)
                self.uncov.append((cntUnc, src))

if __name__ == '__main__':
    from projectDirs import tsgDir
    ret = Gcov().run(
        tsgDir,
        './bin/moduletests_coverage',
        'obj/application_coverage',
        '../application/modules/*/src/*.cpp ../application/modules/*/*.h'
    )
    exit(ret)

