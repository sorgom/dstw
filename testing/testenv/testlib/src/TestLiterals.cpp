//  associated header
#include <testlib/TestLiterals.h>

#define C_STR_DEF(NAME) \
    const CONST_C_STRING c__ ## NAME = #NAME;

namespace test
{
    C_STR_DEF(ELM)

    //# C_STR_DEF
    C_STR_DEF(CmdFld)
    C_STR_DEF(Com)
    C_STR_DEF(Dispatcher)
    C_STR_DEF(ElementName)
    C_STR_DEF(FldState)
    C_STR_DEF(GuiCmd)
    C_STR_DEF(LCR)
    C_STR_DEF(LCR_Hub)
    C_STR_DEF(LCR_Provider)
    C_STR_DEF(Loader)
    C_STR_DEF(Log)
    C_STR_DEF(ProjData)
    C_STR_DEF(ProjLCR)
    C_STR_DEF(ProjSEG)
    C_STR_DEF(ProjSIG)
    C_STR_DEF(ProjTSW)
    C_STR_DEF(SIG)
    C_STR_DEF(SIG_Hub)
    C_STR_DEF(SIG_Provider)
    C_STR_DEF(StateGui)
    C_STR_DEF(TSW)
    C_STR_DEF(TSW_Hub)
    C_STR_DEF(TSW_Provider)
    //# END

} // namespace
