#include <SYS/IL.h>
#include <cstdio>
#include <iostream>
using std::cout, std::endl;
#include <iomanip>
using std::setw;

int main()
{
    IL::getReader().read("dstw.proj");

    const E_Ret e = IL::getLog().maxerr();
    cout 
        << "ERR: " << setw(5) << static_cast<UINT16>(e) << endl
        << "TSW: " << setw(5) << IL::getTSW_Provider().size() << endl
        << "SIG: " << setw(5) << IL::getSIG_Provider().size() << endl
        << "LCR: " << setw(5) << IL::getLCR_Provider().size() << endl
    ;

    return e;
}