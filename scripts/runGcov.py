#   ============================================================
#   code gcov coverage of this project
#   ============================================================
#   created by Manfred Sorgo

from modGcov import Gcov
from projectDirs import makDir, tsgDir
from modUtilz import mdTxt, mdCode, writeFile

ttl = '# current gcov coverage'

def runGcov(conf='ci', verbose=True):
    return Gcov().run(
        makDir,
        f'./bin/coverage_tests_{conf}',
        f'obj/gcc/coverage_app/{conf}',
        '../application/components/*/src/*.cpp',
        verbose=verbose
    )

def gcovToMd():
    cov = runGcov(verbose=True)
    if not cov: return
    print(cov)
    mdf = f'{tsgDir}/coverage_gcov.md'
    txt = mdTxt(mdf, ttl)
    res = [txt] if txt else []
    res.append('\n'.join([ttl, mdCode(cov)]))
    writeFile(mdf, '\n\n'.join(res) + '\n')

if __name__ == '__main__':
    from sys import argv
    runGcov(*argv[1:2])
