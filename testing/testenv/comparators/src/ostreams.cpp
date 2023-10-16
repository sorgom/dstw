#include <comparators/ostreams.h>

using std::ostream;
using std::endl;

OSTREAM_DEF(RastaTelegram)
{
    return os 
        << DOUT(type)
        << DOUT(id)
        << DOUT(state1)
        << DOUT(state2)
        << DOUT(state3)
        << DOUT(md4)
    ;
}

OSTREAM_DEF(FldTelegram)
{
    return os 
        << DOUT(type)
        << DFIX(name)
        << DOUT(state1)
        << DOUT(state2)
        << DOUT(state3)
        << DOUT(md4)
    ;
}

OSTREAM_DEF(GuiTelegram)
{
    return os 
        << DOUT(type)
        << DFIX(name)
        << DOUT(state)
        << DOUT(md4)
    ;
}