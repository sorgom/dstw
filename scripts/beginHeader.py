from os.path import dirname, basename, isdir, exists
from sys import argv
from modUtilz import incHeader

if len(argv) < 2:
    exit(1)

hName = argv[1]
hDir  = dirname(hName)
if not isdir(hDir):
    print('not a directory:', hDir)

bName = basename(hName)

# check for cpp file
srcDir  = hDir + '/src'
srcName = srcDir + '/' + bName.replace('.h', '.cpp')

if isdir(srcDir) and not exists(srcName):
    with open(srcName, 'w') as fh:
        fh.write(incHeader(hName))

iName = bName.upper().replace('.', '_')

def1 = f'#pragma once\n#ifndef {iName}\n#define {iName}'
def2 = '#endif // H_'

data = [def1]

if exists(hName):
    with open(hName) as fh:
        txt = fh.read()
        if def1 in txt:
            print('already done')
            exit(0)
        data.append(txt)

data.append(def2)
with open(hName, 'w') as fh:
    fh.write('\n'.join(data))

