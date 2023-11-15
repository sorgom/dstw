#   ============================================================
#   extract state transitions from StarUML state charts
#   and generate md test steps
#   ============================================================
#   created by Manfred Sorgo

from modTransTable import TransTable
import json, re
from sys import argv

class StateCharts(object):
    def __init__(self, mdj):
        self.transTable = TransTable()
        data = dict()
        with open(mdj, 'r') as fh:
            data =  json.load(fh)
            fh.close()
        self.transitions = dict()
        self.stateNames = dict()
        self.stateMachines = dict()
        self.stateChartNames = dict()
        self.regionNames = dict()
        self.traverse(data)
        self.regNames()
        out = list()
        for reg, transitions in self.transitions.items():
            stateNames = self.stateNames.get(reg)
            out.append(self.fuse(self.regionNames.get(reg, 'NN'), transitions, stateNames))

        if out:
            md = re.sub(r'\.\w+$', '_states.md', mdj)
            with open(md, 'w') as fh:
                fh.write('\n\n'.join([*out,'']))

    def regNames(self):
        for reg, sm in self.stateMachines.items():
            self.regionNames[reg] = self.stateChartNames.get(sm, 'NN')

    def event(self, trg, evt):
        a = re.split(r' +', evt, 1)
        a.append(trg)
        return ' '.join(a[0:2])

    def fuse(self, name, transitions:list, stateNames:dict):
        if stateNames is None: return
        transitions = [
            [src, trg, self.event(trg, evt) ] 
                for src, trg, evt in [[stateNames.get(src), stateNames.get(trg), evt] 
                    for src, trg, evt in transitions]
        ]
        return self.transTable.genMd(transitions, name)
    
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
                if pr: self.stateNames.setdefault(pr, dict())[id] = nm
            elif tp == 'UMLStatechartDiagram':
                self.stateChartNames[pr] = nm
            else:
                if tp == 'UMLRegion': self.stateMachines[id] = pr
                for v in data.values():
                    self.traverse(v)
        elif type(data) == list:
            for v in data:
                self.traverse(v)

if __name__ == '__main__':
    for fp in argv[1:]:
        StateCharts(fp)
