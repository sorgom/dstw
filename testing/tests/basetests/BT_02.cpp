//  ============================================================
//  test of StackArry
//  - bSort 
//  - bSearch
//  - mappable StaticArray
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <baselib/StackArray.h>

namespace test
{

    TEST_GROUP_BASE(BT_02, TestGroupBase)
    {
        
    };

    struct Idata
    {
        INT32 m1;
        INT32 m2;
        inline Idata(INT32 i1, INT32 i2 = 0):
            m1(i1),
            m2(i2)
        {}
    };

    class IdadaArray : public StackArray<Idata, 20>
    {
    public:
        inline bool isGreater(const Idata& a, const Idata& b) const
        {
            return a.m1 > b.m1;
        }
    };

    //  test type: equivalence class test
    //  check of bSort
    TEST(BT_02, T01)
    {
    }

    
    //  test type: equivalence class test
    //  test of SearchableStaticArray
    TEST(BT_02, T03)
    {
        STEP(1)
        //  create array
        //  load 10 data
        IdadaArray a;

        L_CHECK_EQUAL(20, a.capacity())
        L_CHECK_EQUAL( 0, a.size())

        // m1 0 .. -9
        // m2 0 ..  9
        for (INT32 i = 0; i < a.capacity(); ++i)
        {
            L_CHECK_FALSE(a.isFull())
            a.add(Idata(-i, i));
        }
        L_CHECK_EQUAL(a.capacity(), a.size())
        L_CHECK_TRUE(a.isFull())

        STEP(2)
        //  test unsorted data as loaded
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const Idata& d = a[i];
            L_CHECK_EQUAL(-i, d.m1)
            L_CHECK_EQUAL( i, d.m2)
        }
        ENDSTEPS()
        
        STEP(3)
        //  apply sort()
        //  test sorted data
        a.sort();
        const INT32 of = a.size() - 1;
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const Idata& d = a[i];
            L_CHECK_EQUAL(-of + i, d.m1)
            L_CHECK_EQUAL( of - i, d.m2)
        }
        ENDSTEPS()

        STEP(4)
        //  add data
    }

    // //  test type: equivalence class test
    // //  test of SearchableStaticArray with reversed order
    // TEST(BT_02, T04)
    // {
    //     STEP(1)
    //     //  create array
    //     //  load 10 data
    //     TestArrayRev a;

    //     L_CHECK_EQUAL(20, a.capacity())
    //     L_CHECK_EQUAL( 0, a.size())

    //     // m1 0 .. -9
    //     // m2 0 ..  9
    //     for (INT32 i = 0; i < 10; ++i)
    //     {
    //         a.add(TestDataInt(-i, i));
    //     }
    //     L_CHECK_EQUAL(10, a.size())

    //     STEP(2)
    //     //  apply bSort
    //     //  test sorted data
    //     bSort(a);
    //     //  m1 0 .. -9
    //     //  m2 0 ..  9
    //     SUBSTEPS()
    //     for (INT32 i = 0; i < a.size(); ++i)
    //     {
    //         LSTEP(i)
    //         const TestDataInt& d = a[i];
    //         L_CHECK_EQUAL(-i, d.m1)
    //         L_CHECK_EQUAL( i, d.m2)
    //     }
    //     ENDSTEPS()
    // }

    // //  test type: equivalence class test
    // //  test of SearchableStaticArray using placement new on addPtr
    // TEST(BT_02, T05)
    // {
    //     STEP(1)
    //     //  create array
    //     //  load 10 data
    //     TestArray a;

    //     // m1 0 .. -9
    //     // m2 0 ..  9
    //     for (INT32 i = 0; i < 10; ++i)
    //     {
    //         new (a.addPtr()) TestDataInt(-i, i);
    //     }
    //     L_CHECK_EQUAL(10, a.size())

    //     STEP(2)
    //     //  test unsorted data as loaded
    //     SUBSTEPS()
    //     for (INT32 i = 0; i < a.size(); ++i)
    //     {
    //         LSTEP(i)
    //         const TestDataInt& d = a[i];
    //         L_CHECK_EQUAL(-i, d.m1)
    //         L_CHECK_EQUAL( i, d.m2)
    //     }
    //     ENDSTEPS()
    // }

    // //  test type: equivalence class test
    // //  test of SearchableStaticArray as map
    // TEST(BT_02, T06)
    // {
    //     STEP(1)
    //     //  create array
    //     //  load 10 data
    //     TestArray a;

    //     // m1 0 .. -9
    //     // m2 0 ..  9
    //     for (INT32 i = 0; i < 10; ++i)
    //     {
    //         new (a.addPtr()) TestDataInt(-i, i);
    //     }

    //     // sort
    //     STEP(2)
    //     a.sort();

    //     //  search elements
    //     STEP(3)
    //     const TestArray& c = a;
    //     SUBSTEPS()
    //     for (INT32 i = 0; i < c.size(); ++i)
    //     {
    //         LSTEP(i)
    //         const UINT32 p = c.search(c[i]);
    //         L_CHECK_EQUAL(i, p)
    //     }
    //     ENDSTEPS()
    // }
} // namespace
