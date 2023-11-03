#   ============================================================
#   application of gcov tool
#   - run instrumented binary
#   - invoke gcov
#   - analyze *.gcov files of cpp sources
#   ============================================================
#   created by Manfred Sorgo

from subprocess import call, DEVNULL
from os import chdir
from os.path import exists
from glob import glob
import re
from sys import exit
from modUtilz import checkLinux, procOut, commonLen

rxUnc = re.compile(r'^ *#*: *\d+:', re.M)
rxNoc = re.compile(r'// *NO_COV *>> *\n(.*?)// *<< *NO_COV', re.S)
rxSrc = re.compile(r'^.*?0:Source:(.*)')
rxLin = re.compile(r'\n')
rxLoc = re.compile(r'^(\S+).*?(\d+)$', re.M)
rxNul = re.compile(r' 0 ')
rxNlp = re.compile(r' 0.0')

class Gcov(object):

    def __init__(self):
        self.clear()

    def clear(self):
        self.cntNoc = 0
        self.uncov = dict()
        self.locs  = list()

    def com(self, cmd:str):
        call(cmd, shell=True, stdout=DEVNULL, stderr=DEVNULL)

    def cloc(self, srcs):
        txt = procOut(f'cloc --by-file {srcs}')
        self.locs = [ [a, int(b)] for a, b in rxLoc.findall(txt) if a != 'SUM:'] 

    def run(self, workDir, app, objDir, srcs, verbose=True):
        checkLinux()
        self.clear()
        self.verbose = verbose
        chdir(workDir)
        if not exists(app): return ''
        self.cloc(srcs)
        self.com(app)
        self.com(f'gcov -o {objDir} {srcs}')
        for fn in glob('*.cpp.gcov'):
            self.chkcov(fn)
        if self.cntNoc:
            print('>> exculded lines:', self.cntNoc)
        srcs = [src for src, loc in self.locs]
        clen = commonLen(srcs)
        srcs = [src[clen:] for src in srcs]
        nlen = max([len(src) for src in srcs])

        form = f'%-{nlen}s  %5d  %9d  %7.1f'
        head = f'%-{nlen}s  lines  uncovered  percent' % 'file'
        res = list()
        tloc = 0
        tuncov = 0
        for n, (src, loc) in enumerate(self.locs):
            uncov  = self.uncov.get(src, 0)
            tloc += loc
            tuncov += uncov
            res.append(form % (srcs[n], loc, uncov, uncov * 100.0 / loc))
        res = sorted(res, key=str.lower)
        res.insert(0, head)
        res.append(form % ('total', tloc, tuncov, tuncov * 100.0 / tloc))
        out = '\n'.join(res)
        out = rxNlp.sub('  --', rxNul.sub('-- ', out))
        if self.verbose: print(out)
        return out

    def cntLines(self, mo):
        self.cntNoc += len(rxLin.findall(mo.group(1)))
        return ''
    
    def chkcov(self, fn:str):
        with open(fn) as fh:
            txt = fh.read()
            txn = rxNoc.sub(self.cntLines, txt)
            cntUnc = len(rxUnc.findall(txn))
            if cntUnc > 0:
                src = rxSrc.match(txt).group(1)
                self.uncov[src] = cntUnc
                if self.verbose: print(txn)

if __name__ == '__main__':
    from projectDirs import tsgDir
    ret = Gcov().run(
        tsgDir,
        './bin/moduletests_coverage',
        'obj/application_coverage',
        '../application/components/*/src/*.cpp ../application/components/*/*.h'
    )
    exit(ret)

