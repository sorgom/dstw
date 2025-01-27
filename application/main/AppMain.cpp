#include <SYS/IL.h>
#include <iostream>
#include <iomanip>
using std::cout, std::setw;

int main(const INT32 argc, const CONST_C_STRING* const argv)
{
    IL::getReader().read("dstw.proj");

    E_Ret res = IL::getLog().maxerr();
    cout
        << "TSW: " << setw(5) << IL::getTSW_Provider().size() << '\n'
        << "SIG: " << setw(5) << IL::getSIG_Provider().size() << '\n'
        << "LCR: " << setw(5) << IL::getLCR_Provider().size() << '\n'
        << "ERR: " << setw(5) << static_cast<UINT16>(res) << '\n'
    ;

    if (res == RET_NO_ERR and argc > 1)
    {
        cout << "run .." << '\n';
        IL::getCom().run();
        res = IL::getLog().maxerr();
        cout
            << "ERR: " << setw(5) << static_cast<UINT16>(res) << '\n'
        ;
    }
    return res;
}
