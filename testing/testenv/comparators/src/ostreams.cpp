#include <comparators/ostreams.h>

OSTREAM_DEF(ComName)
{
    return os << fixC(d.chars);
}

OSTREAM_DEF(ComCmdFld)
{
    return os 
        << DOUT(name)
        << DOUT(param1)
        << DOUT(param2)
    ;
}

OSTREAM_DEF(ComFldState)
{
    return os 
        << DOUT(name)
        << DOUT(param1)
        << DOUT(param2)
    ;
}

OSTREAM_DEF(ComGuiCmd)
{
    return os 
        << DOUT(name)
        << DOUT(param1)
        << DOUT(param2)
    ;
}

OSTREAM_DEF(ComStateGui)
{
    return os 
        << DOUT(name)
        << DOUT(param1)
        << DOUT(param2)
    ;
}
