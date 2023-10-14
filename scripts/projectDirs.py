#   ============================================================
#   directories of this project in git
#   ============================================================
#   created by Manfred Sorgo

from modUtilz import repoDir

topDir = repoDir()
modDir = topDir + '/application/modules'
srcDir = topDir + '/scripts'
tsgDir = topDir + '/testing'
envDir = tsgDir + '/testenv'
mocDir = envDir + '/mocks'
ifsDir = topDir + '/application/ifs'

if __name__ == '__main__':
    print(modDir)
    print(srcDir)
    print(tsgDir)
    print(envDir)
    print(mocDir)
    print(ifsDir)
    