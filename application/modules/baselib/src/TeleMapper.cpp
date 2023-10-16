#include <baselib/TeleMapper.h>

const NameNum& getNameNum(const ElementName& name, const UINT32 num)
{
    static NameNum n; 
    Mem::copy(n.name, name);
    n.num = num;
    return n;
}
