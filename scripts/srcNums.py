#   ============================================================
#   simple line numbering for source sample markups
#   ============================================================
#   created by Manfred Sorgo

import re
from sys import argv

class SrcNums(object):
    def __init__(self):
        self.rxLin = re.compile(r'^(.*)', re.M)

    def num(self, src):
        with open(src, 'r') as fh:
            txt = fh.read()
            nl = len(self.rxLin.findall(txt))
            ln = len(str(nl))
            self.frm = f'%0{ln}d\t%s'
            self.nr = 0
            txt = self.rxLin.sub(self.repl, txt).expandtabs(4)
            print(txt)

    def repl(self, mo):
        self.nr += 1
        return self.frm % (self.nr, mo.group(1))
    
if __name__ == '__main__':
    srcNums = SrcNums()
    for src in argv[1:]:
        srcNums.num(src)
