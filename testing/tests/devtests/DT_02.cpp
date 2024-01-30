//  ============================================================
//  test of test features
//  - output of fixed size strings
//  - MemStream
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <testlib/MemStream.h>

#include <sstream>

namespace test
{

    TEST_GROUP_BASE(DT_02, TestGroupBase) {};

    //  ostreams
    TEST(DT_02, T01)
    {
        STEP(1)
        const CHAR chars[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
        ElementName fn;
        memcpy(&fn, chars, 9);

        std::ostringstream os;
        os << fixC(fn.chars);
        STRCMP_EQUAL("012345678", os.str().c_str());

        STEP(2)
        fn.chars[4]  = 0;
        fn.chars[7] = 127;
        os.str("");
        os << fixC(fn.chars);
        STRCMP_EQUAL("0123*56*8", os.str().c_str());
    }

    TEST(DT_02, T02)
    {
        SETUP()
        struct S1
        {
            int m1;
            int m2;
            int m3;
        };

        S1 s1 {111, 222, 333};
        MemStream str(&s1, sizeof(S1));

        int i1 = 0, i2 = 0, i3 = 0;
        str.read((char*) &i1, sizeof(int));
        str.read((char*) &i2, sizeof(int));
        str.read((char*) &i3, sizeof(int));

        L_CHECK_EQUAL(s1.m1, i1)
        L_CHECK_EQUAL(s1.m2, i2)
        L_CHECK_EQUAL(s1.m3, i3)
    }
}
