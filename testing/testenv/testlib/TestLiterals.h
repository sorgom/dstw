
#ifndef TESTLIB_LITERALS_H
#define TESTLIB_LITERALS_H

#include <baselib/BaseTypes.h>

#define C_STR_DEC(NAME) \
    extern const CONST_C_STRING c__ ## NAME;

namespace test
{
    //# C_STR_DEC
    C_STR_DEC(Signal)
    C_STR_DEC(SignalData)
    C_STR_DEC(SignalPort)
    C_STR_DEC(TrackSwitch)
    C_STR_DEC(TrackSwitchData)
    C_STR_DEC(TrackSwitchPort)
    //# END
} // namespace

#endif // _H
