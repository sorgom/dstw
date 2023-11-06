//  ============================================================
//  output of maximum capacities
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <qnd/useCout.h>
#include <sstream>

namespace test
{
    struct Dotted
    {
        inline Dotted(const UINT32 val): val(val) {}
        const UINT32 val;
    };

    std::ostream& operator << (std::ostream& os, const Dotted& d)
    {
        static UINT32 ar[4];
        UINT32 v = d.val;
        UINT8 p = 4;
        do {
            --p;
            ar[p] = v % 1000;
            v /= 1000;
        } while (v > 0 and p > 0);

        std::ostringstream str;
        str << ar[p++];
        for (; p < 4; ++p)
        {
            str << '\'' << setw(3) << setfill('0') << ar[p];
        }
        return os << str.str();
    }


    TEST_GROUP_BASE(DT_01, TestGroupBase) {};
 
    //  output of element numbers limitations
    TEST(DT_01, T01)
    {
        STEP(1)
        cout 
            << "MAX: " << setw(16) << Dotted(UINT32_MAX) << endl
            << "SIG: " << setw(16) << Dotted(UINT32_MAX / sizeof(SIG_X)) << endl
            << "TSW: " << setw(16) << Dotted(UINT32_MAX / sizeof(TSW)) << endl
            << "DSP: " << setw(16) << Dotted(UINT32_MAX / sizeof(Ntp)) << endl
        ;
    }

}
