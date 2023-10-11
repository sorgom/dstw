//  associated header
#include <testlib/TestLiterals.h>

#define C_STR_DEF(NAME) \
    const CONST_C_STRING c__ ## NAME = #NAME;

namespace test
{
    const CONST_C_STRING c__expected               = "# EXPECTED";
    const CONST_C_STRING c__actual                 = "# ACTUAL";
    const CONST_C_STRING c__matched                = "# MATCHED";
    const CONST_C_STRING c__line                   = "line";
    const CONST_C_STRING c__file                   = "file";
    const CONST_C_STRING c__func                   = "func";
    const CONST_C_STRING c__missing_comparator     = "missing comparator";
    const CONST_C_STRING c__not_implemented        = "not implemented";
    const CONST_C_STRING c__byte_allocation_error  = "byte allocation error";

    //# C_STR_DEF
    C_STR_DEF(TrackSwitchData)
    C_STR_DEF(TrackSwitchPort)
    C_STR_DEF(SignalPort)

    //# END

} // namespace
