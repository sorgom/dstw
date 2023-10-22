#   ============================================================
#   code coverage of this project
#   ============================================================
#   created by Manfred Sorgo

from modGcov import Gcov
from projectDirs import tsgDir
from modUtilz import mdTxt, mdCode, writeFile

ttl = '## source code coverage'

def runGcov(verbose=True):
    return Gcov().run(
        tsgDir,
        './bin/moduletests_coverage',
        'obj/application_coverage',
        '../application/modules/*/src/*.cpp',
        verbose=verbose
    )

def gcovToMd():
    cov = runGcov(verbose=False)
    if not cov: return
    mdf = f'{tsgDir}/coverage.md'
    txt = mdTxt(mdf, ttl)
    res = [txt] if txt else []
    res.append('\n'.join([ttl, mdCode(cov)]))
    writeFile(mdf, '\n\n'.join(res) + '\n')

if __name__ == '__main__':
    runGcov()
