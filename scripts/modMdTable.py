#   ============================================================
#   simple md table generator 
#   - numeric align right
#   - alpha   align left
#   ============================================================
#   created by Manfred Sorgo

import re
rxWord = re.compile(r'[^\d]+')

def mdLine(args):
    return '|' + '|'.join([str(c) for c in args]) + '|'

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

if __name__ == '__main__':
    data = [
        ['STEP', 'FROM', 'TO'],
        [1, 'B', 'KR'],
        [2, 'KR', 'B'],
    ]

    print(mdTable(data))