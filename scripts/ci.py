#   ============================================================
#   run code checker if available
#   ============================================================
#   created by Manfred Sorgo

from modUtilz import repoDir, repoFiles, procOut
from os import chdir, getcwd
from os.path import abspath, exists

chdir(repoDir())
print(getcwd())

srcs = repoFiles('application/**.cpp')


gitDir = abspath('..')

print(gitDir)

toDir = gitDir + '/zsl90_workspace/tools'
ciDir = toDir + '/codeinspector'
ciExe = ciDir + '/bin/convchk.exe'
ciToc = ciDir + '/lib/config/TS.toc'
caDir = toDir + '/cadul/include'

incs = [
    caDir, caDir + '/std', caDir + '/iostl',
    'specification', 'application', 'application/modules'
]
incs = ' '.join([f'-I{i}' for i in incs])
print(incs)

ciOpts = f'{incs} --cin --cdh --cdc --toc={ciToc} --csi=""'

print(ciOpts)

if not exists(ciToc):
    print('toc not found')
    exit()

for src in srcs:
    cmd = f'{ciExe} {ciOpts} {src}'
    print(cmd)
    cck = procOut(cmd)
    print(f'*** {cck} ***')
