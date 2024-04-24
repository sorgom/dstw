import re

# Regular expressions
# $1: return type, $2: function name, $3: arguments
rxDecl = re.compile(r'^( *virtual +(\w+) +(\w+) *\((.*)\)) *= *0 *;', re.M)
rxArgs = re.compile(r' *([^,]*?) +(\w+) *(?:,|$)') 
rxVirt = re.compile(r'\bvirtual\b')

def GenMock(file):
    with open(file, 'r') as f:
        cont = f.read()
        res = rxDecl.findall(cont)
        for r in res:
            call, ret, name, args = r
            mdef = rxVirt.sub('inline', call)
            print('mdef', mdef)
            args = rxArgs.findall(args)
            params = [f'.PARAM({arg[1]})' for arg in args]
            mret = 'return ' if ret != 'void' else ''
            

            print(*params)
            print(*args)

if __name__ == '__main__':
    from sys import argv
    if len(argv) > 1:
        GenMock(argv[1])
 