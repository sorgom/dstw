//  ============================================================
//  test of endianess features
//  requires C++ 2020 or above
//  ============================================================
//  created by Manfred Sorgo

#include <bit>
#if __cpp_lib_endian >= 201907L

#include <testlib/TestGroupBase.h>
#include <BAS/HN.h>

using std::endian;

static_assert(std::endian::native == std::endian::big or std::endian::native == std::endian::little);

namespace test
{

    TEST_GROUP_BASE(BAS_03, TestGroupBase)
    {
        //  swapbytes requires C++2023
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

        template<typename T>
        T adapt(const T val)
        {
            T res = val;
            if constexpr (endian::native != endian::big)
            {
                res = bswap(val);
            }
            return res;
        }
    };

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

#else
#pragma message("no c++ 2020 endianess support - tests BAS_03 skipped")
#endif