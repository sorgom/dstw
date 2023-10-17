#include <baselib/ElementNameMap.h>

const NamePos& getNamePos(const ElementName& name, const UINT32 pos)
{
    static NamePos n; 
    Mem::copy(n.name, name);
    n.pos = pos;
    return n;
}
