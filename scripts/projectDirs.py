#   ============================================================
#   directories of this project in git
#   ============================================================
#   created by Manfred Sorgo

from modUtilz import repoDir

topDir = repoDir()
modDir = topDir + '/application/components'
srcDir = topDir + '/scripts'
tsgDir = topDir + '/testing'
envDir = tsgDir + '/testenv'
mocDir = envDir + '/mocks'
spcDir = topDir + '/specification'
docDir = spcDir + '/doc'
ifsDir = spcDir + '/ifs'
appDir = topDir + '/application/main'
makDir = topDir + '/make'

if __name__ == '__main__':
    print(modDir)
    print(srcDir)
    print(tsgDir)
    print(envDir)
    print(mocDir)
    print(ifsDir)
    