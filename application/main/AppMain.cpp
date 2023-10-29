#include <ddi/ddi.h>

#define GET_DDI(NAME) ddi::get ## NAME();

int main(const INT32 argc, const CONST_C_STRING* const argv)
{
    //# GET_DDI
    GET_DDI(Dispatcher)
    GET_DDI(FldCom)
    GET_DDI(GuiCom)
    GET_DDI(Loader)
    GET_DDI(SIG_Hub)
    GET_DDI(SIG_Provider)
    GET_DDI(TSW_Hub)
    GET_DDI(TSW_Provider)
    //# END
    return 0;
}