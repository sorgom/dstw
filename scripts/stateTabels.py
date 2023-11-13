import re, csv

src = 'specification/diagrams/transitions_SIG_H.csv'

def pivot(data:list):
    return list(map(list, zip(*data)))

def values(arr:list):
    return [v for v in arr if v]

def transition(src, trg, evt):
    a = re.split(r' +', evt, 1)
    evt = ' '.join([*a, trg][0:2])
    return [src, trg, evt]


data = list()

with open(src, 'r') as fh:
    rdr = csv.reader(fh, delimiter = ';')
    data = [row for row in rdr]

data = pivot(data)

transitions = list()

for p in range(0, len(data), 2):
    evt = data[p][0]
    srcs = values(data[p][1:])
    trgs = values(data[p + 1][1:])
    for src in srcs:
        for trg in trgs:
            transitions.append(transition(src, trg, evt))

print(transitions)
exit()

s = set(range(10))
print(s)
s.remove(3)
print(s)

for x in s:
    print('x', x)

c = 'hello  world damned'
print(c.split(r' +', 1))
print(re.split(r' +', c, 1))

def rn(trn, trg):
    a = re.split(r' +', trn, 1)
    a.append(trg)
    return ' '.join(a[0:2])

print(rn('CMD LEFT', 'RIGHT'))
print(rn('FLD', 'RIGHT'))

dd = { 1:11, 2:22 }
print(dd)
del dd[2]
print(dd)