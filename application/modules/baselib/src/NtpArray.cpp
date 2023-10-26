#include <baselib/NtpArray.h>

const Ntp& genNtp(
    const ElementName& name,
    const INT32 type,
    const UINT32 pos
)
{
    static Ntp n;
    Mem::copy(n.name, name);
    n.type = type;
    n.pos  = pos;
    return n;
}