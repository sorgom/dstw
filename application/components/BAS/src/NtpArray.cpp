#include <BAS/NtpArray.h>

const Ntp& GenNtp::genNtp(
    const ElementName& name,
    const INT32 type,
    const UINT32 pos
)
{
    static Ntp n = {};
    Mem::cpy(n.name, name);
    n.type = type;
    n.pos  = pos;
    return n;
}