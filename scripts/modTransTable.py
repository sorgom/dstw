#   ============================================================
#   generate transition tables from transition lists
#   -   for other generators
#   -   as md output
#   ============================================================
#   created by Manfred Sorgo

import re
from modMdTable import mdTable

class TransTable(object):
    def __init__(self):
        self.heading = ['STEP', 'EVENT', 'FROM', 'TO', 'GLUE']
        self.rxWild = re.compile(r'\*')
    def noTrans(self, evt):
        return ['', '', evt]
    
    def glue(self, src, trg, transitions:list):
        for src1, trg1, evt1 in transitions:
            for src2, trg2, evt2 in transitions:
                if src1 == src and trg1 == src2 and trg2 == trg:
                    return [
                        [src1, trg1, evt1, '*'],
                        [src2, trg2, evt2, '*']
                    ]

    def transition(self, src, trg, evt):
        return [src, trg, self.rxWild.sub(trg, evt)]

    def genTable(self, transitions:list):
        transitions = [self.transition(*tr) for tr in transitions]
        events = set()
        states = set()
        fromEvt = dict()
        for src, trg, evt in transitions:
            events.add(evt)
            states.add(src)
            states.add(trg)
            fromEvt.setdefault(src, dict())[evt] = trg
        
        noTrans = dict()
        for src in sorted(states):
            for evt in sorted(events):
                if fromEvt.get(src, dict()).get(evt) is None:
                    noTrans.setdefault(src, list()).append(evt)

        next = dict()
        for n, tr in enumerate(transitions):
            next.setdefault(tr[0], list()).append(n)

        #   build sequences using every transition once
        ln = len(transitions)
        todo = set(range(ln))
        seqs = []

        while todo:
            n = todo.pop()
            seq = [transitions[n]]
            found = True
            while found:
                found = False
                nxs = next.get(transitions[n][1])
                if nxs:
                    for nx in nxs:
                        if nx in todo:
                            seq.append(transitions[nx])
                            todo.remove(nx)
                            found = True
                            n = nx
                            break
            seqs.append(seq)

        #   try to connect sequences with transitions
        if len(seqs) > 1:
            next = dict()
            for n, tr in enumerate(transitions):
                next.setdefault(tr[0], dict())[tr[1]] = n

            for n in range(len(seqs) - 1):
                src = seqs[n][-1][1]
                trg = seqs[n + 1][0][0]
                con = next.get(src, dict()).get(trg)
                if con:
                    seqs[n].append([*transitions[con], '*'])
                else:
                    con = self.glue(src, trg, transitions)
                    if con:
                        seqs[n].extend(con)
                    else:
                        seqs[n].append(self.noTrans('NO TRANSITION')) 

        #   flatten
        res = [tr for seq in seqs for tr in seq]

        tbl = list()
        for tr in res:
            tbl.append(tr)
            trg = tr[1]
            ntr = noTrans.get(trg)
            if ntr:
                for evt in ntr:
                    tbl.append(self.noTrans(evt))
                del noTrans[trg]
        return tbl

    def mdStep(self, n, trIn:list):
        trOut = trIn.copy()
        trOut[0] = trIn[2]
        trOut[1] = trIn[0]
        trOut[2] = trIn[1]
        return [n + 1, *trOut]

    def genMd(self, transitions:list, name = 'test steps'):
        tbl = self.genTable(transitions)
        data = [
            self.heading,
            *[
                self.mdStep(n, tr) for  n, tr in enumerate(tbl)
            ]
        ]

        return '\n'.join([
            f'## {name}',
            mdTable(data)
        ])
