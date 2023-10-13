#   ============================================================
#   some git utilz
#   ============================================================
#   created by Manfred Sorgo

from modUtilz import procOutList, procOut

def repoDir():
    return procOut('git rev-parse --show-toplevel')

def repoFiles():
    return procOutList('git ls-tree --full-tree --name-only -r HEAD')

if __name__ == '__main__':
    print(f'## REPO: "{repoDir()}"')
    for f in repoFiles():
        print(f)