#   ============================================================
#   process csv transition tables
#   -   generate md tables
#   -   generate test code
#   ============================================================
#   created by Manfred Sorgo

from modTransTable import TransTable
from modMdTable import mdTable
from modUtilz import repoDir
import re, csv
from json import load as jload
from os.path import basename
from sys import argv
from getopt import getopt

class TransCsv(object):
    def __init__(self):
        self.transTable = TransTable()
        self.mdData = ''
        self.statePrefix = ''
        self.rxInd = re.compile(r'^', re.M)
        self.rxCsv = re.compile(r'\.csv$', re.I)
        self.rxJsn = re.compile(r'\.json$', re.I)

    def pivot(self, data:list):
        return list(map(list, zip(*data)))

    def values(self, arr:list):
        return [v for v in arr if v]

    def transition(self, src, trg, evt):
        a = re.split(r' +', evt, 1)
        evt = ' '.join([*a, trg][0:2])
        return [src, trg, evt]

    def genTransitions(self, srcCsv, delimiter = ';'):
        data = list()

        with open(srcCsv, 'r') as fh:
            rdr = csv.reader(fh, delimiter = delimiter)
            data = [row for row in rdr]
            fh.close()

        self.mdData = mdTable(data)

        data = self.pivot(data)

        transitions = list()
        for p in range(0, len(data), 2):
            evt = data[p][0]
            srcs = self.values(data[p][1:])
            trgs = self.values(data[p + 1][1:])
            for src in srcs:
                for trg in trgs:
                    if trg != src: transitions.append(self.transition(src, trg, evt))
        return transitions

    def genMd(self, srcCsv, delimiter = ';'):
        transitions = self.genTransitions(srcCsv, delimiter)
        trgMd = re.sub(r'\.\w+$', '.md', srcCsv)
        ttl   = re.sub(r'\.\w+$', '', basename(srcCsv)).replace('_', ' ')

        with open(trgMd, 'w') as fh:
            fh.write('\n'.join([
                f'# {ttl}',
                '## transition table',
                self.mdData,
                '',
                self.transTable.genMd(transitions)
            ]))

    def cppName(self, prefix:str, state:str):
        return "%s_%s" % (prefix, state.replace(' ', '_'))
 
    def genJsonCpp(self, file, delimiter=';'):
        with open (file, 'r') as fh:
            res = []
            data = jload(fh)
            cfgs = data.get('cfgs', [{}])
            for cfg in cfgs:
                setup = data.copy()
                for k, v in cfg.items():
                    setup[k] = v
                csv = setup['csv']
                res.append(f'//  {basename(csv)}')
                res.append(
                    self.genCpp(
                        f'{repoDir()}/{csv}',
                        prefixState = setup['prefixState'],
                        prefixCmd = setup['prefixCmd'],
                        cmd1 = setup['cmd1'],
                        cmd0 = setup['cmd0'],
                        fld1 = setup['fld1'],
                        fld0 = setup['fld0'],
                        delimiter = delimiter
                    )
                )
            print('\n\n'.join(res))

    def genCpp(self, srcCsv, 
               prefixState = 'SIG_STATE',
               prefixCmd = 'SIG_STATE',
               cmd1 = 'CMD(_VAL_, 0, _VAL_, 0, _TRG_, 0);',
               cmd0 = 'CMD(_VAL_, 0);',
               fld1 = 'FLD(_VAL_, 0, _VAL_, 0);',
               fld0 = 'FLD(_VAL_, 0);',
               delimiter = ';'
            
        ):
        transitions = self.genTransitions(srcCsv, delimiter)
        tbl = self.transTable.genTable(transitions)
        step = 0
        res = list()
        for row in tbl:
            src, gui, evt = row[0:3]
            call, val = evt.split(' ', 1)
            fld = gui.replace('WAIT ', '')
            istr = src and gui
            templ = ''
            if call == 'CMD':
                templ = cmd1 if istr else cmd0
            elif call == 'FLD':
                templ = fld1 if istr else fld0
            
            if templ:
                templ = templ.replace('_VAL_', self.cppName(prefixState, val))
                templ = templ.replace('_GUI_', self.cppName(prefixState, gui))
                templ = templ.replace('_FLD_', self.cppName(prefixState, fld))
                templ = templ.replace('_CMD_', self.cppName(prefixCmd, val))
                step += 1
                res.append(f'STEP({step})')
                res.append(templ)
        return self.rxInd.sub('        ', '\n'.join(res))

    def fromFile(self, fp, delimiter=';'):
        if self.rxCsv.search(fp):
            self.genMd(fp, delimiter)
        elif self.rxJsn.search(fp):
            self.genJsonCpp(fp, delimiter)

    def main(self):
        opts, args = getopt(argv[1:], 'd:h')
        delimiter = ';'
        for o, v in opts:
            if (o == '-d'):
                delimiter = v
        for src in args:
            self.fromFile(src, delimiter = delimiter)        

if __name__ == '__main__':
    trc = TransCsv()
    trc.main()
