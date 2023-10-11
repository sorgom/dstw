
#ifndef TESTLIB_LITERALS_H
#define TESTLIB_LITERALS_H

#include <baselib/BaseTypes.h>

#define C_STR_DEC(NAME) \
    extern const CONST_C_STRING c__ ## NAME;

namespace test
{
    extern const CONST_C_STRING c__expected;
    extern const CONST_C_STRING c__actual;
    extern const CONST_C_STRING c__matched;
    extern const CONST_C_STRING c__line;
    extern const CONST_C_STRING c__file;
    extern const CONST_C_STRING c__func;
    extern const CONST_C_STRING c__missing_comparator;
    extern const CONST_C_STRING c__not_implemented;
    extern const CONST_C_STRING c__byte_allocation_error;

    //# C_STR_DEC
    C_STR_DEC(SignalPort)
    C_STR_DEC(TrackSwitchData)
    C_STR_DEC(TrackSwitchPort)
    //# END
} // namespace

#endif // _H
