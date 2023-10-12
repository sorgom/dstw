import re
from os.path import basename

rxSpl = re.compile(r'[/\\]')
rxHdr = re.compile(r'\.h$')

def incHeader(header:str, nsubs=1):
    return f"#include <{'/'.join(rxSpl.split(header)[-(nsubs + 1):])}>"

def locHeader(header:str):
    return f'#include "{basename(header)}"'

def isHaeder(file:str):
    return rxHdr.search(file)