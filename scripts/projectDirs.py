from os.path import abspath, dirname

topDir = abspath(dirname(__file__) + '/..' )
modDir = topDir + '/application/modules'
tsgDir = topDir + '/testing'
envDir = tsgDir + '/testenv'
mocDir = envDir + '/mocks'
ifsDir = topDir + '/application/ifs'
