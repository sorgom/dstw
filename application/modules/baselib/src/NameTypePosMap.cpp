#include <baselib/NameTypePosMap.h>

const NameTypePos& getNameTypePos(
    const ElementName& name, 
    const INT32 type, 
    const UINT32 pos)
{
    static NameTypePos n;
    Mem::copy(n.name, name);
    n.type = type;
    n.pos  = pos;
    return n;
}
