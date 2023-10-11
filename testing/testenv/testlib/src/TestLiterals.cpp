//  associated header
#include <testlib/TestLiterals.h>

#define C_STR_DEF(NAME) \
    const CONST_C_STRING c__ ## NAME = #NAME;

namespace test
{
    //# C_STR_DEF
    C_STR_DEF(Signal)
    C_STR_DEF(SignalData)
    C_STR_DEF(SignalPort)
    C_STR_DEF(TrackSwitch)
    C_STR_DEF(TrackSwitchData)
    C_STR_DEF(TrackSwitchPort)
    //# END

} // namespace
