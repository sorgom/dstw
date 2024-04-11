//  ============================================================
//  output of maximum capacities
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <qnd/useCout.h>
#include <sstream>
#include <limits>

namespace test
{
    struct Dotted
    {
        inline Dotted(const size_t val): val(val) {}
        const size_t val;
    };

    std::ostream& operator << (std::ostream& os, const Dotted& d)
    {
        static size_t ar[8];
        size_t v = d.val;
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
        const size_t maxval = std::numeric_limits<size_t>::max();
        STEP(1)
        cout 
            << "MAX: " << setw(16) << Dotted(maxval) << endl
            << "SIG: " << setw(16) << Dotted(maxval / sizeof(SIG_X)) << endl
            << "TSW: " << setw(16) << Dotted(maxval / sizeof(TSW)) << endl
            << "DSP: " << setw(16) << Dotted(maxval / sizeof(Ncp)) << endl
        ;
    }

}
