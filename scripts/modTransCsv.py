#   ============================================================
#   process csv transition tables
#   -   generate md tables
#   -   generate test code
#   ============================================================
#   created by Manfred Sorgo

from modTransTable import TransTable, TransEvent
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
        self.delimiter = ';'
        self.info = False
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

    def genTransEvents(self, srcCsv):
        data = list()

        with open(srcCsv, 'r') as fh:
            rdr = csv.reader(fh, delimiter = self.delimiter)
            data = [row for row in rdr]
            fh.close()

        self.mdData = mdTable(data)

        data = self.pivot(data)

        transEvents = list()
        for p in range(0, len(data), 2):
            evt = data[p][0]
            srcs = self.values(data[p][1:])
            trgs = self.values(data[p + 1][1:])
            for src in srcs:
                for trg in trgs:
                    if trg != src: transEvents.append(TransEvent(evt, src, trg))
        return transEvents

    def genMd(self, srcCsv):
        transEvents = self.genTransEvents(srcCsv)
        trgMd = re.sub(r'\.\w+$', '.md', srcCsv)
        ttl   = re.sub(r'\.\w+$', '', basename(srcCsv)).replace('_', ' ')

        with open(trgMd, 'w') as fh:
            fh.write('\n'.join([
                f'# {ttl}',
                '## transition table',
                self.mdData,
                '',
                self.transTable.genMd(transEvents)
            ]))

    def genInfo(self, srcCsv):
        print(basename(srcCsv))
        self.transTable.genInfo(self.genTransEvents(srcCsv))
 
    def genJsonCpp(self, file):
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
                        fld0 = setup['fld0']
                    )
                )
            print('\n\n'.join(res))

    def genCpp(self, srcCsv, **args):
        return  self.transTable.genCpp(self.genTransEvents(srcCsv), **args)

    def fromFile(self, fp):
        if self.rxCsv.search(fp):
            if self.info: self.genInfo(fp)
            else: self.genMd(fp)
        elif self.rxJsn.search(fp):
            self.genJsonCpp(fp)

    def main(self):
        opts, args = getopt(argv[1:], 'd:ih')
        for o, v in opts:
            if (o == '-d'):
                self.delimiter = v
            if (o == '-i'):
                self.info = True
        for src in args:
            self.fromFile(src)        

if __name__ == '__main__':
    trc = TransCsv()
    trc.main()
