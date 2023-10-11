from modGcov import Gcov
from projectDirs import tsgDir
ret = Gcov().run(
    tsgDir,
    './bin/moduletests_coverage',
    'obj/application_coverage',
    '../application/modules/*/src/*.cpp ../application/modules/*/*.h'
)
exit(ret)


