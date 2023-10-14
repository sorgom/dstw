#include <comparators/ostreams.h>

#include <iomanip>

using std::ostream;
using std::endl;


#define OSTREAM_DEF(NAME) \
    ostream& operator << (ostream& os, const NAME& d)

#define DL(NAME) \
    std::setw(16) << std::setfill('.') << std::left << #NAME << ':' << ' ' << d.NAME << endl 

OSTREAM_DEF(RastaTelegram)
{
    return os 
        << DL(type)
        << DL(id)
        << DL(state1)
        << DL(state2)
        << DL(state3)
        << DL(md4)
    ;
}