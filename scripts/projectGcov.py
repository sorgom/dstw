from modGcov import Gcov
from projectDirs import tstDir
ret = Gcov().run(
    tstDir,
    './bin/moduletests_coverage',
    'obj/application_coverage',
    '../application/modules/*/src/*.cpp ../application/modules/*/*.h'
)
exit(ret)


