//  associated header
#include <testlib/TestLiterals.h>

#define C_STR_DEF(NAME) \
    const CONST_C_STRING c__ ## NAME = #NAME;

namespace test
{
    C_STR_DEF(ELEM)

    //# C_STR_DEF
    C_STR_DEF(CmdFld)
    C_STR_DEF(Dispatcher)
    C_STR_DEF(ElementName)
    C_STR_DEF(FldCom)
    C_STR_DEF(FldState)
    C_STR_DEF(GuiCmd)
    C_STR_DEF(Signal)
    C_STR_DEF(SignalPort)
    C_STR_DEF(StateGui)
    C_STR_DEF(TrackSwitch)
    C_STR_DEF(TrackSwitchHub)
    C_STR_DEF(TrackSwitchProj)
    C_STR_DEF(TrackSwitchProvider)
    //# END

} // namespace
