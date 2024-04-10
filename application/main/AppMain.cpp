#include <SYS/IL.h>
#include <cstdio>

int main()
{
    IL::getReader().read("dstw.proj");

    const E_Err e = IL::getLog().maxerr();
    printf("maxerr: %u\n", e);

    return NO_ERR == e ? 0 : 1;
}