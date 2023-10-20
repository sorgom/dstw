#include <comparators/ostreams.h>

using std::ostream;
using std::endl;

OSTREAM_DEF(ElementName)
{
    return os << fixC(d.chars);
}

OSTREAM_DEF(CmdFld)
{
    return os 
        << DOUT(name)
        << DOUT(cmd)
        << DOUT(param1)
        << DOUT(param2)
    ;
}

OSTREAM_DEF(FldState)
{
    return os 
        << DOUT(name)
        << DOUT(state1)
        << DOUT(state2)
    ;
}

OSTREAM_DEF(GuiCmd)
{
    return os 
        << DOUT(name)
        << DOUT(cmd)
        << DOUT(param1)
        << DOUT(param2)
    ;
}

OSTREAM_DEF(StateGui)
{
    return os 
        << DOUT(name)
        << DOUT(state1)
        << DOUT(state2)
    ;
}

OSTREAM_DEF(ProjTSW)
{
    return os 
        << DOUT(name)
    ;
}
