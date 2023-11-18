#   ============================================================
#   extract state transitions from StarUML state charts
#   and generate md test steps
#   ============================================================
#   created by Manfred Sorgo

from modTransTable import TransTable, TransEvent
import json, re
from sys import argv
from getopt import getopt

class StateCharts(object):
    def __init__(self):
        self.transTable = TransTable()

    def genInfo(self, mdj):
        self.scanMdj(mdj)
        for region in self.transitions.keys():
            print(self.regionNames.get(region, 'NN'))
            transitions = self.fuse(region)
            print('transitions:', len(transitions))
            print('test steps :', len(self.transTable.genTable(transitions)))

    def genMd(self, mdj):
        self.scanMdj(mdj)
        out = list()
        for region in self.transitions.keys():
            out.append(
                self.transTable.genMd(
                    self.fuse(region),
                    self.regionNames.get(region, 'NN')
                )
            )

        if out:
            md = re.sub(r'\.\w+$', '_states.md', mdj)
            with open(md, 'w') as fh:
                fh.write('\n\n'.join([*out,'']))

    def scanMdj(self, mdj):
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

    def regNames(self):
        for reg, sm in self.stateMachines.items():
            self.regionNames[reg] = self.stateChartNames.get(sm, 'NN')

    def event(self, trg, evt):
        a = re.split(r' +', evt, 1)
        a.append(trg)
        return ' '.join(a[0:2])

    def fuse(self, region):
        transitions = self.transitions.get(region)
        stateNames  = self.stateNames.get(region)
        if stateNames is None: return
        transEvents = [
            TransEvent(self.event(trg, evt), src, trg)
                for evt, src, trg in [[evt, stateNames.get(src), stateNames.get(trg)] 
                    for evt, src, trg in transitions]
        ]
        return transEvents
    
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
                    evs = data.get('triggers', [])
                    for evt in evs:
                        if evt.get('_type', '') == 'UMLEvent':
                            self.transitions.setdefault(pr, list()).append([evt.get('name'), src, trg])

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
    
    def main(self):
        opts, args = getopt(argv[1:], 'i')
        call = self.genMd
        for o, v in opts:
            if (o == '-i'): call = self.genInfo
                
        for mdj in args:
            call(mdj)        

if __name__ == '__main__':
    sc = StateCharts()
    sc.main()
