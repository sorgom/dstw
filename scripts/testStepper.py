import re
from sys import argv, exit
from os.path import basename

rxTest = re.compile(r'^(( *)//[^\n]*(?:\n\2//[^\n]*)*\n\2TEST *\([^\n]*\n)(\2\{\n.*?\n\2\})', re.M | re.S)

class Test(object):
    def __init__(self, ind, head, body):
        self.ind = ind        
        rdStep = r'STEP *\( *(\d+) *\)'
        rxHead = re.compile(r'^(' + ind + r'//!? +)' + rdStep, re.M)
        rxBody = re.compile(r'^(' + ind + r' +)' + rdStep, re.M)

        self.chg  = False
        self.step = 0
        self.head = rxHead.sub(self.repl, head)
        self.step = 0
        self.body = rxBody.sub(self.repl, body)
    
    def repl(self, mo):
        self.chg  = True
        self.step += 1
        return mo.group(1) + f'STEP({self.step})'

    def changed(self):
        return self.chg

    def txt(self):
        return self.head + self.body

class TestStepper(object):
    def __init__(self, fp):
        self.tests = list()

        try:
            with open(fp, 'r') as fh:
                cont = fh.read()
                for fnd in rxTest.findall(cont):
                    self.tests.append(Test(fnd[1], fnd[0], fnd[2]))
                fh.close()
                chg = False
                for test in self.tests:
                    chg = chg or test.changed()
                if chg:
                    cont = rxTest.sub(self.repl, cont).strip() + '\n'
                    with open(fp, 'w') as fh:
                        print(f'-> {basename(fp)}')
                        fh.write(cont)
        except:
            print('error:', fp)
    
    def repl(self, mo):
        return self.tests.pop(0).txt()

if __name__ == '__main__':
    for fp in argv[1:]:
        TestStepper(fp)