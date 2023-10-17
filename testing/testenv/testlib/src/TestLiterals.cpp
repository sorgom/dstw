//  associated header
#include <testlib/TestLiterals.h>

#define C_STR_DEF(NAME) \
    const CONST_C_STRING c__ ## NAME = #NAME;

namespace test
{
    C_STR_DEF(ELEM)

    //# C_STR_DEF
    C_STR_DEF(ElementName)
    C_STR_DEF(FldCom)
    C_STR_DEF(FldTelegram)
    C_STR_DEF(GuiTelegram)
    C_STR_DEF(RastaPort)
    C_STR_DEF(RastaTelegram)
    C_STR_DEF(Signal)
    C_STR_DEF(SignalPort)
    C_STR_DEF(TrackSwitch)
    C_STR_DEF(TrackSwitchPort)
    C_STR_DEF(TrackSwitchProj)
    //# END

} // namespace
