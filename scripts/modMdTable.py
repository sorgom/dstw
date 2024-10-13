#   ============================================================
#   simple md table generator
#   - numeric align right
#   - alpha   align left
#   ============================================================
#   created by Manfred Sorgo

import re, csv
rxWord = re.compile(r'[^\d]+')
rxCsv = re.compile(r'\.csv$', re.I)
rxDelim = re.compile(r'^[;,]$')

def mdLine(args):
    c = '|' + '|'.join([str(c) for c in args]) + '|'
    while '||' in c:
        c = c.replace('||', '| |')
    return c

def mdTable(data:list):
    cont = data.copy()
    heading = cont.pop(0)
    aligns = ['---:' for c in heading]
    for row in cont:
        for n, c in enumerate(row):
            if type(c) == str and rxWord.search(c):
                aligns[n] = ':---'
    return '\n'.join([
        mdLine(heading),
        mdLine(aligns),
        *[
            mdLine(row) for row in cont
        ]
    ])

def csvTable(file:str, delim:str=';'):
    with open(file, 'r') as fh:
        rdr = csv.reader(fh, delimiter=delim)
        data = [row for row in rdr]
        fh.close()
    return mdTable(data)

if __name__ == '__main__':
    from sys import argv
    delim = ';'
    csvs = []
    for arg in argv[1:]:
        if rxDelim.match(arg):
            delim = arg
        elif rxCsv.search(arg):
            csvs.append(arg)
    for file in csvs:
        print(csvTable(file, delim))
        print()
