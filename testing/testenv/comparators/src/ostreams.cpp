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