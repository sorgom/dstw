import json, re
from os.path import abspath, basename, dirname, exists, realpath, join, isdir, getmtime, relpath

baseDir = abspath(dirname(__file__) + '/..')
print(baseDir)
mdj=baseDir + '/specification/diagrams/TSW.mdj'

# UMLStateMachine
# <-  UMLStatechartDiagram
# <-	UMLRegion
# 	<-	UMLTransition
# 		source -> UMLState
# 		target -> UMLState
# 		triggers [
# 			- name
# 			- name
# 		]
# 	<-	UMLState
# 		- name



class StateCharts(object):
    def __init__(self, data, double=True, sep='\t'):
        self.double = double
        self.sep = sep
        self.transitions = dict()
        self.states = dict()
        self.heading = ['STEP', 'FROM', 'TO', 'EVENT', 'GLUE']
        self.headline = [':---' for h in self.heading ]
        self.traverse(data)
        for k, transitions in self.transitions.items():
            states = self.states.get(k)
            self.fuse(transitions, states)

    def event(self, trg, trn):
        a = re.split(r' +', trn, 1)
        a.append(trg)
        return ' '.join(a[0:2])

    def noTrans(self, evt):
        return ['', '', evt]
    
    def glue(self, src, trg, transitions:list):
        fromSrc = None
        toTrg = None
        for src1, trg1, trn1 in transitions:
            for src2, trg2, trn2 in transitions:
                if src1 == src and trg2 == trg:
                    return [
                        [src1, trg1, trn1, '*'],
                        [src2, trg2, trn2, '*']
                    ]

    def outLine(self, data:list):
        return '|' + '|'.join(data) + '|'

    def fuse(self, transitions:list, states:dict):
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
        for src in states:
            for evt in events:
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
                    res[n].append(transitions[con])
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

        print(self.outLine(self.heading))
        print(self.outLine(self.headline))
        for p, tr in enumerate(tbl):
            print(self.outLine(tr))

    def getRef(self, data, key):
        ref = data.get(key)
        if ref is None: return None
        return ref['$ref']
    
    def traverse(self, data:dict):
        if type(data) == dict:
            tp = data.get('_type', '')
            pr = self.getRef(data, '_parent')
            if tp == 'UMLTransition':
                if pr:
                    src = self.getRef(data, 'source')
                    trg = self.getRef(data, 'target')
                    trs = data.get('triggers', [])
                    for tr in trs:
                        if tr.get('_type', '') == 'UMLEvent':
                            self.transitions.setdefault(pr, list()).append([src, trg, tr.get('name')])

            elif tp == 'UMLState':
                if pr: self.states.setdefault(pr, dict())[data['_id']] = data['name']
            else:
                for v in data.values():
                    self.traverse(v)
        elif type(data) == list:
            for v in data:
                self.traverse(v)

with open(mdj, 'r') as fh:
    data =  json.load(fh)
    StateCharts(data)
