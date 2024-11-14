from sys import path as syspath
from os.path import dirname, abspath, join
sompath = abspath(join(dirname(__file__), '../submodules/sompy/somutil'))
if sompath not in syspath:
    syspath.insert(0, sompath)
