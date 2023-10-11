#include <comparators/ostreams.h>

using std::ostream;
using std::endl;

#define STREAM_DEF(NAME) \
    ostream& operator << (ostream& os, const NAME& d)

STREAM_DEF(TrackSwitchData)
{
    return os << d.id << endl << d.state;
}