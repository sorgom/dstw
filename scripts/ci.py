#   ============================================================
#   run code checker if available
#   * experimental *
#   ============================================================
#   created by Manfred Sorgo

from modUtilz import repoDir, repoFiles, procOut
from os import chdir, getcwd
from os.path import abspath, exists


chdir(repoDir())
print(getcwd())


rpDir = repoDir()
giDir = abspath(rpDir + '/..')
toDir = giDir + '/zsl90_workspace/tools'
ciDir = toDir + '/codeinspector'
ciExe = ciDir + '/bin/convchk.exe'
ciToc = ciDir + '/lib/config/TS.toc'
caInc = toDir + '/cadul/include'

srcs = [ f'{rpDir}/{f}' for f in repoFiles('application/**.cpp')]
print(srcs)


locIncs = [ f'{rpDir}/{d}' for d in  ['specification', 'application', 'application/components']]
print(locIncs)

cadIncs = [caInc, caInc + '/std', caInc + '/iostl']
print(cadIncs)

locIncs.extend(cadIncs)
print(locIncs)

incs = ' '.join([f'-I{i}' for i in locIncs])
print(incs)

ciOpts = f'{incs} --cin --cdh --cdc --toc={ciToc} --csi=""'

print(ciOpts)

if not exists(ciToc):
    print('toc not found')
    exit()

# exit()
for src in srcs:
    cmd = f'{ciExe} {ciOpts} {src}'
    print(cmd)
    cck = procOut(cmd)
    print(f'*** {cck} ***')
