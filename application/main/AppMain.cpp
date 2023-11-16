#include <SYS/IL.h>
#include <setup/capacities.h>
#include <cstdio>

#define GET_DDI(NAME) IL::get ## NAME();

void capOut(const CONST_C_STRING what, const UINT32 size)
{
    printf("- %3s%10u\n", what, size);
}

int main(const INT32 argc, const CONST_C_STRING* const argv)
{
    //# GET_DDI
    GET_DDI(Com)
    GET_DDI(Dispatcher)
    GET_DDI(LCR_Hub)
    GET_DDI(LCR_Provider)
    GET_DDI(Loader)
    GET_DDI(Log)
    GET_DDI(SIG_Hub)
    GET_DDI(SIG_Provider)
    GET_DDI(TSW_Hub)
    GET_DDI(TSW_Provider)
    //# END

    capOut("TSW", CAPACITY_TSW);
    capOut("SIG", CAPACITY_SIG);
    capOut("LCR", CAPACITY_LCR);
    capOut("SEG", CAPACITY_SEG);
    capOut("DSP", CAPACITY_DSP);

    return 0;
}