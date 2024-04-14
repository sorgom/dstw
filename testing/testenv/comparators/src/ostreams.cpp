#include <comparators/ostreams.h>

OSTREAM_DEF(ComName)
{
    return os << fixC(d.chars);
}

OSTREAM_DEF(ComTele)
{
    return os 
        << DOUT(name)
        << DOUT(param1)
        << DOUT(param2)
    ;
}

OSTREAM_DEF(ComTeleFld)
{
    return os << static_cast<const ComTele&>(d);
}

OSTREAM_DEF(ComTeleGui)
{
    return os << static_cast<const ComTele&>(d);
}

