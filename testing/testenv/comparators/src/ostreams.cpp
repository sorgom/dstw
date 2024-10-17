#include <comparators/ostreams.h>


OSTREAM_DEF(ComData)
{
    return os
        << DOUT(param1)
        << DOUT(param2)
        << DOUT(param3)
    ;
}

OSTREAM_DEF(ComAddr)
{
    return os << fixT(d.chars);
}

OSTREAM_DEF(ComTele)
{
    return os
        << DOUT(addr)
        << d.data
    ;
}

OSTREAM_DEF(PosRes)
{
    return os
        << DOUT(pos)
        << DOUT(valid)
    ;
}

OSTREAM_DEF(ProjItem)
{
    return os
        << DOUT(addr)
        << DOUT(type)
    ;
}
