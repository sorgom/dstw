#include <SYS/IL.h>
#include <setup/capacities.h>
#include <cstdio>

void capOut(const CONST_C_STRING what, const UINT32 size)
{
    printf("- %3s%10u\n", what, size);
}

int main()
{
    capOut("TSW", CAPACITY_TSW);
    capOut("SIG", CAPACITY_SIG);
    capOut("LCR", CAPACITY_LCR);
    capOut("SEG", CAPACITY_SEG);
    capOut("DSP", CAPACITY_DSP);

    IL::getReader().read("dstw.proj");

    const E_Err e = IL::getLog().maxerr();
    printf("maxerr: %u\n", e);

    return NO_ERR == e ? 0 : 1;
}