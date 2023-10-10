from os.path import abspath, dirname

topDir = abspath(dirname(__file__) + '/..' )
modDir = topDir + '/application/modules'
tstDir = topDir + '/testing'
mocDir = tstDir + '/mocks'