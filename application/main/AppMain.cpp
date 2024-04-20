#include <SYS/IL.h>
#include <cstdio>

int main()
{
    IL::getReader().read("dstw.proj");

    const E_Ret e = IL::getLog().maxerr();
    printf("maxerr: %u\n", e);

    return RET_NO_ERR == e ? 0 : 1;
}