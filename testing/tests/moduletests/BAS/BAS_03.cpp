//  ============================================================
//  test of endianess dependent features
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/HN.h>
#include <type_traits>

namespace test
{
    class TestGroup03 : public TestGroupBase
    {
    protected:
        TestGroup03():
            checkVal(0xFB0000EAu),
            firstByte(*reinterpret_cast<const UINT8*>(&checkVal)),
            isBig(firstByte == 0xFB),
            isLittle(firstByte == 0xEA)
        {
        }

        void setup()
        {
            CHECK_TRUE((isBig or isLittle));
        }

        template<typename T>
        T adapt(const T val)
        {
            static_assert(std::is_integral<T>::value);
            return isLittle ? bswap(val) : val;
        }

    private:
        const UINT32 checkVal;
        const BYTE firstByte;
        const bool isBig;
        const bool isLittle;

        template<typename T>
        T bswap(const T val)
        {
            union 
            {
                T v;
                BYTE b[sizeof(T)]; 
            } a, b;
            a.v = val;
            for (size_t n = 0; n < sizeof(T); ++n)
            {
                b.b[sizeof(T) - 1 - n] = a.b[n];
            }
            return b.v;
        }
    };

    TEST_GROUP_BASE(BAS_03, TestGroup03) {};

    //  test type: equivalence class test
    TEST(BAS_03, T01)
    {
        STEP(1)
        {
            const UINT32 h = 0xAABBCCDDu;
            const UINT32 n = HN::toN(h);
            const UINT32 x = adapt(h);
            CHECK_EQUAL(x, n);
        }

        STEP(2)
        {
            const UINT32 n = 0xAABBCCDDu;
            const UINT32 h = HN::toH(n);
            const UINT32 x = adapt(n);
            CHECK_EQUAL(x, h);
        }

        STEP(3)
        {
            const UINT16 h = 0xAADD;
            const UINT16 n = HN::toN(h);
            const UINT16 x = adapt(h);
            CHECK_EQUAL(x, n);
        }

        STEP(4)
        {
            const UINT16 n = 0xAADD;
            const UINT16 h = HN::toH(n);
            const UINT16 x = adapt(n);
            CHECK_EQUAL(x, h);
        }
    }

} // namespace

