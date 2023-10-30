#   ============================================================
#   simple test steps re-numbering script
#   ============================================================
#   created by Manfred Sorgo

import re
from sys import argv, exit
from os.path import basename

rxWithHead = re.compile(r'^(( *)//[^\n]*(?:\n\2//[^\n]*)*\n\2TEST *\([^\n]*\n)(\2\{\n.*?\n\2\})', re.M | re.S)
rxJustTest = re.compile(r'^(( *)TEST *\([^\n]*\n)(\2\{\n.*?\n\2\})', re.M | re.S)

class Test(object):
    def __init__(self, ind, head, body):
        self.ind = ind        
        rdStep = r'STEP *\( *(\d+) *\)'
        rxHead = re.compile(r'^(' + ind + r'//!? +)' + rdStep, re.M)
        rxBody = re.compile(r'^(' + ind + r' +)' + rdStep, re.M)

        self.step = 0
        self.head = rxHead.sub(self.repl, head)
        self.step = 0
        self.body = rxBody.sub(self.repl, body)
    
    def repl(self, mo):
        self.step += 1
        return mo.group(1) + f'STEP({self.step})'

    def txt(self):
        return self.head + self.body

class TestStepper(object):
    def __init__(self, fp):
        self.tests = list()

        try:
            with open(fp, 'r') as fh:
                fCont = fh.read()
                for fnd in rxWithHead.findall(fCont):
                    self.tests.append(Test(fnd[1], fnd[0], fnd[2]))
                for fnd in rxJustTest.findall(fCont):
                    self.tests.append(Test(fnd[1], fnd[0], fnd[2]))
                fh.close()
                nCont = rxJustTest.sub(self.repl, rxWithHead.sub(self.repl, fCont))
                if nCont != fCont:
                    with open(fp, 'w') as fh:
                        print(f'-> {basename(fp)}')
                        fh.write(nCont.strip() + '\n')
        except:
            print('error:', fp)
    
    def repl(self, mo):
        return self.tests.pop(0).txt()

def usage(args):
    if '-h' in args:
        print(f'usage: {basename(__file__)} source files to re-number')
        exit()

if __name__ == '__main__':
    usage(argv)
    for fp in argv[1:]:
        TestStepper(fp)