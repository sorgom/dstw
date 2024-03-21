#include <SYS/IL.h>
#include <setup/capacities.h>
#include <cstdio>

#define CO(WHAT) printf("- %3s%10u\n", #WHAT, CAPACITY_ ## WHAT); 

int main()
{
    CO(TSW)
    CO(SIG)
    CO(LCR)
    CO(SEG)
 
    IL::getReader().read("dstw.proj");

    const E_Err e = IL::getLog().maxerr();
    printf("maxerr: %u\n", e);

    return NO_ERR == e ? 0 : 1;
}