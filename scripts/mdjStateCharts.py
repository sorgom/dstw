#   ============================================================
#   extract state transitions from StarUML state charts
#   and generate test steps
#   ============================================================
#   created by Manfred Sorgo

import json, re
from sys import argv

class StateCharts(object):
    def __init__(self, mdj):
        data = dict()
        with open(mdj, 'r') as fh:
            data =  json.load(fh)
            fh.close()
        self.transitions = dict()
        self.states = dict()
        self.sms = dict()
        self.scnames = dict()
        self.regnames = dict()
        self.heading = ['STEP', 'FROM', 'TO', 'EVENT', 'GLUE']
        self.headline = [':---' for h in self.heading ]
        self.headline[0] = '---:'
        self.traverse(data)
        self.regNames()
        out = list()
        for reg, transitions in self.transitions.items():
            states = self.states.get(reg)
            out.append(self.fuse(self.regnames.get(reg, 'NN'), transitions, states))

        if out:
            md = re.sub(r'\.\w+$', '_states.md', mdj)
            with open(md, 'w') as fh:
                fh.write('\n\n'.join([*out,'']))

    def regNames(self):
        for reg, sm in self.sms.items():
            self.regnames[reg] = self.scnames.get(sm, 'NN')

    def event(self, trg, trn):
        a = re.split(r' +', trn, 1)
        a.append(trg)
        return ' '.join(a[0:2])

    def noTrans(self, evt):
        return ['', '', evt]
    
    def glue(self, src, trg, transitions:list):
        for src1, trg1, trn1 in transitions:
            for src2, trg2, trn2 in transitions:
                if src1 == src and trg2 == trg:
                    return [
                        [src1, trg1, trn1, '*'],
                        [src2, trg2, trn2, '*']
                    ]

    def outLine(self, *args):
        return '|' + '|'.join(args) + '|'

    def fuse(self, name, transitions:list, states:dict):
        print('FUSE', name, len(transitions), len(states.keys()))
        if states is None: return
        transitions = [
            [src, trg, self.event(trg, trn) ] 
                for src, trg, trn in [[states.get(src), states.get(trg), trn] 
                    for src, trg, trn in transitions]
        ]
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
        res = []

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
            res.append(seq)

        #   try to connect sequences with transitions
        if len(res) > 1:
            next = dict()
            for n, tr in enumerate(transitions):
                next.setdefault(tr[0], dict())[tr[1]] = n
            for n in range(len(res) - 1):
                src = res[n][-1][1]
                trg = res[n + 1][0][0]
                con = next.get(src, dict()).get(trg)
                if con:
                    res[n].append([*transitions[con], '*'])
                else:
                    con = self.glue(src, trg, transitions)
                    if con:
                        res[n].extend(con)
                    else:
                        res[n].append(self.noTrans('NO TRANSITION')) 
        
        #   flatten
        res = [i for l in res for i in l]

        tbl = list()
        for tr in res:
            tbl.append(tr)
            trg = tr[1]
            ntr = noTrans.get(trg)
            if ntr:
                for evt in ntr:
                    tbl.append(self.noTrans(evt))
                del noTrans[trg]

        out = [
            f'## {name}',
            self.outLine(*self.heading),
            self.outLine(*self.headline)
        ]
        out.extend(
            [self.outLine(str(p + 1), *tr) for  p, tr in enumerate(tbl) ]
        )
        return '\n'.join(out)

    def getRef(self, data, key):
        ref = data.get(key)
        if ref is None: return None
        return ref['$ref']
    
    def traverse(self, data:dict):
        if type(data) == dict:
            tp = data.get('_type', '')
            pr = self.getRef(data, '_parent')
            id = data.get('_id', '')
            nm = data.get('name', 'NN')
            if tp == 'UMLTransition':
                if pr:
                    src = self.getRef(data, 'source')
                    trg = self.getRef(data, 'target')
                    trs = data.get('triggers', [])
                    for tr in trs:
                        if tr.get('_type', '') == 'UMLEvent':
                            self.transitions.setdefault(pr, list()).append([src, trg, tr.get('name')])

            elif tp == 'UMLState':
                if pr: self.states.setdefault(pr, dict())[id] = nm
            elif tp == 'UMLStatechartDiagram':
                self.scnames[pr] = nm
            else:
                if tp == 'UMLRegion': self.sms[id] = pr
                for v in data.values():
                    self.traverse(v)
        elif type(data) == list:
            for v in data:
                self.traverse(v)

if __name__ == '__main__':
    for fp in argv[1:]:
        StateCharts(fp)
