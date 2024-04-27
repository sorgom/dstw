#include <SYS/IL.h>
#include <cstdio>
#include <iostream>
using std::cout, std::endl;
#include <iomanip>
using std::setw;

int main(const INT32 argc, const CONST_C_STRING* const argv)
{
    IL::getReader().read("dstw.proj");

    E_Ret res = IL::getLog().maxerr();
    cout 
        << "ERR: " << setw(5) << static_cast<UINT16>(res) << endl
        << "TSW: " << setw(5) << IL::getTSW_Provider().size() << endl
        << "SIG: " << setw(5) << IL::getSIG_Provider().size() << endl
        << "LCR: " << setw(5) << IL::getLCR_Provider().size() << endl
    ;

    if (res == RET_NO_ERR and argc > 1)
    {
        IL::getCom().run();
        res = IL::getLog().maxerr();
    }

    return res;
}