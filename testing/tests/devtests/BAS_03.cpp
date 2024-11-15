//  ============================================================
//  test of Net
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/Net.h>

namespace test
{
    TEST_GROUP_BASE(BAS_03, TestGroupBase)
    {
         struct TestData : ComData
        {
            inline UINT8 operator[](size_t p)
            {
                return reinterpret_cast<const UINT8*>(this)[p];
            }
        };

        template <typename NUM>
        inline void byteTest(const NUM n1)
        {
            // to net & back
            ByteArrayFor<NUM> b = {0};
            Net::toN(b, n1);
            NUM n2 = 0;
            Net::toH(n2, b);
            L_CHECK_EQUAL(n1, n2);
        }

        template <typename NUM, size_t P>
        inline void comTest(const NUM n1)
        {
            // to net & back
            TestData data;
            Net::toN<P>(data, n1);
            NUM n2 = 0;
            Net::toH<P>(n2, data);
            L_CHECK_EQUAL(n1, n2);

            //  check other bytes untouched
            for (size_t i = 0; i < P; ++i)
            {
                L_CHECK_EQUAL(PARAM_UNDEF, data[i]);
            }
            for (size_t i = P + sizeof(NUM); i < sizeof(ComData); ++i)
            {
                L_CHECK_EQUAL(PARAM_UNDEF, data[i]);
            }
        }
    };

    //  test type: equivalence class test
    //  byte order conversion: byte arrays
    TEST(BAS_03, T01)
    {
        STEP(1)
        //  explicit byte test acc. to specification
        {
            const UINT32 n1 = 0x0A0B0C0D;
            ByteArrayFor<UINT32> b = {0};
            Net::toN(b, n1);
            L_CHECK_EQUAL(0x0A, b[0]);
            L_CHECK_EQUAL(0x0B, b[1]);
            L_CHECK_EQUAL(0x0C, b[2]);
            L_CHECK_EQUAL(0x0D, b[3]);
        }
        STEP(2)
        //  explicit byte test acc. to specification
        {
            const UINT16 n1 = 0x0A0B;
            ByteArrayFor<UINT16> b = {0};
            Net::toN(b, n1);
            L_CHECK_EQUAL(0x0A, b[0]);
            L_CHECK_EQUAL(0x0B, b[1]);
        }
        //  in / out tests
        STEP(3)
        byteTest<UINT32>(123456);
        STEP(4)
        byteTest<UINT16>(1234);
        STEP(5)
        byteTest<INT32>(-123456);
        STEP(6)
        byteTest<INT16>(-1234);
    }

    //  test type: equivalence class test
    //  byte order conversion: ComData
    //  in / out / untouched tests
    TEST(BAS_03, T02)
    {
        STEP(1)
        comTest<UINT32, 4>(0x0A0B0C0D);
        STEP(2)
        comTest<UINT16, 6>(0x0A0B);
        STEP(3)
        comTest<INT32, 2>(-123456);
        STEP(4)
        comTest<INT16, 4>(-1234);
    }
} // namespace
