#   ============================================================
#   generate transition tables from transition lists
#   -   for other generators
#   -   as md output
#   ============================================================
#   created by Manfred Sorgo

import re
from modMdTable import mdTable

class TransEvent(object):
    def __init__(self, evt:str, src:str='', trg:str='', glue:str=''):
        self.evt = re.sub(r'\*', trg, evt)
        self.src = src
        self.trg = trg
        self.glu = glue
    def toList(self) -> list:
        return [self.evt, self.src, self.trg, self.glu]
    def isNone(self) -> bool:
        return not self.trg
    def isGlue(self) -> bool:
        return self.glu == '*'
    def glueCopy(self):
        return TransEvent(self.evt, self.src, self.trg, '*')

class TransTable(object):
    def __init__(self):
        self.heading = ['STEP', 'EVENT', 'FROM', 'TO', 'GLUE']
        self.rxInd = re.compile(r'^', re.M)

    def glue(self, src, trg, transEvents:list):
        for tre1 in transEvents:
            for tre2 in transEvents:
                if tre1.src == src and tre1.trg == tre2.src and tre2.trg == trg:
                    return [
                        tre1.glueCopy(),
                        tre2.glueCopy()
                    ]

    def genTable(self, transEvents:list):
        events = set()
        states = set()
        fromEvt = dict()
        for tre in transEvents:
            events.add(tre.evt)
            states.add(tre.src)
            states.add(tre.trg)
            fromEvt.setdefault(tre.src, dict())[tre.evt] = tre.trg
        
        noTrans = dict()
        for src in sorted(states):
            for evt in sorted(events):
                if fromEvt.get(src, dict()).get(evt) is None:
                    noTrans.setdefault(src, list()).append(evt)

        next = dict()
        for n, tre in enumerate(transEvents):
            next.setdefault(tre.src, list()).append(n)

        #   build sequences using every transition once
        ln = len(transEvents)
        todo = set(range(ln))
        seqs = []

        while todo:
            n = todo.pop()
            seq = [transEvents[n]]
            found = True
            while found:
                found = False
                nxs = next.get(transEvents[n].trg)
                if nxs:
                    for nx in nxs:
                        if nx in todo:
                            seq.append(transEvents[nx])
                            todo.remove(nx)
                            found = True
                            n = nx
                            break
            seqs.append(seq)

        #   try to connect sequences with transitions
        if len(seqs) > 1:
            next = dict()
            for n, tre in enumerate(transEvents):
                next.setdefault(tre.src, dict())[tre.trg] = n

            for n in range(len(seqs) - 1):
                src = seqs[n][-1].trg
                trg = seqs[n + 1][0].src
                con = next.get(src, dict()).get(trg)
                if con:
                    seqs[n].append(transEvents[con].glueCopy())
                else:
                    con = self.glue(src, trg, transEvents)
                    if con:
                        seqs[n].extend(con)
                    else:
                        seqs[n].append(TransEvent('NO TRANSITION')) 

        #   flatten
        res = [tr for seq in seqs for tr in seq]

        tbl = list()
        for tre in res:
            tbl.append(tre)
            ntr = noTrans.get(tre.trg)
            if ntr:
                for evt in ntr:
                    tbl.append(TransEvent(evt))
                del noTrans[tre.trg]
        return tbl


    def genMd(self, transitions:list, name = 'test steps'):
        tbl = self.genTable(transitions)
        data = [
            self.heading,
            *[
                [n + 1, *tre.toList()] for  n, tre in enumerate(tbl)
            ]
        ]

        return '\n'.join([
            f'## {name}',
            mdTable(data)
        ])

    def cppName(self, prefix:str, state:str):
        return "%s_%s" % (prefix, state.replace(' ', '_'))

    def genCpp(self, transEvents:list, 
            prefixState = 'SIG_STATE',
            prefixCmd = 'SIG_STATE',
            cmd1 = 'CMD(_VAL_, 0, _VAL_, 0, _TRG_, 0);',
            cmd0 = 'CMD(_VAL_, 0);',
            fld1 = 'FLD(_VAL_, 0, _VAL_, 0);',
            fld0 = 'FLD(_VAL_, 0);'
        
    ):
        tbl = self.genTable(transEvents)
        step = 0
        res = list()
        for tre in tbl:
            call, val = tre.evt.split(' ', 1)
            fld = tre.trg.replace('WAIT ', '')
            gui = tre.trg
            templ = ''
            if call == 'CMD':
                templ = cmd0 if tre.isNone() else cmd1
            elif call == 'FLD':
                templ = fld0 if tre.isNone() else fld1
            
            if templ:
                templ = templ.replace('_VAL_', self.cppName(prefixState, val))
                templ = templ.replace('_GUI_', self.cppName(prefixState, gui))
                templ = templ.replace('_FLD_', self.cppName(prefixState, fld))
                templ = templ.replace('_CMD_', self.cppName(prefixCmd, val))
                step += 1
                res.append(f'STEP({step})')
                res.append(templ)
        return self.rxInd.sub('        ', '\n'.join(res))

    def statOut(self, pref, num, desc):
        print("%1s %4d %s" % (pref, num, desc))

    def genInfo(self, transEvents):
        table = self.genTable(transEvents)
        nGlue = 0
        nNoTrans = 0
        nTrans = len(transEvents)
        for tre in table:
            if tre.isGlue(): nGlue += 1
            elif tre.isNone(): nNoTrans += 1

        self.statOut('', nTrans, 'test steps for transitions')
        self.statOut('+', nNoTrans, 'test steps without transition')
        self.statOut('=', nTrans +  nNoTrans, 'relevant test steps')
        self.statOut('+', nGlue, 'test steps as glue')
        self.statOut('=', len(table), 'test steps total')
