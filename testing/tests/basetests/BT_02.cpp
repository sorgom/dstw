//  ============================================================
//  test of StackArry, StackArrayIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <baselib/StackArray.h>

#include <qnd/useCout.h>

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

    class IdataArray : public StackArray<Idata, 20>
    {
    public:
        inline bool isGreater(const Idata& a, const Idata& b) const
        {
            return a.m1 > b.m1;
        }
    };
    typedef StackArrayIndex<Idata, 20> IdataIndex;

    //  test type: equivalence class test
    //  test of StackArray: with ad()
    TEST(BT_02, T01)
    {
        STEP(1)
        //  create array
        //  load data
        IdataArray a;

        L_CHECK_EQUAL(20, a.capacity())
        L_CHECK_EQUAL( 0, a.size())

        for (INT32 i = 0; i < a.capacity(); ++i)
        {
            L_CHECK_FALSE(a.isFull())
            const UINT32 p = a.add(Idata(-i, i));
            L_CHECK_EQUAL(i, p);
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
        //  apply find() to const object
        const IdataArray& c = a;
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const INT32 p = c.find(c[i]);
            L_CHECK_EQUAL(i, p)
        }
        ENDSTEPS()
    }

    //  test type: equivalence class test
    //  test of StackArray: with placement new
    TEST(BT_02, T02)
    {
        STEP(1)
        IdataArray a;

        for (INT32 i = 0; i < a.capacity(); ++i)
        {
            L_CHECK_FALSE(a.isFull())
            new (a.addPtr()) Idata(-i, i);
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
    }

    //  test type: equivalence class test
    //  test of StackArrayIndex
    TEST(BT_02, T03)
    {
        STEP(1)
        //  create array
        //  load data
        IdataArray a;
        IdataIndex ix(a);
        L_CHECK_EQUAL(a.capacity(), ix.capacity())

        for (INT32 i = 0; i < a.capacity(); ++i)
        {
            a.add(Idata(-i, i));
        }
        L_CHECK_TRUE(a.isFull())

        STEP(2)
        //  adapt index
        //  find all data in index
        ix.adapt();
        L_CHECK_TRUE(ix.isFull())
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const Idata& d = a[i];
            const INT32  f = ix.findRef(d);
            const Idata& r = ix.getRef(f);
            L_CHECK_EQUAL(d.m1, r.m1)
            L_CHECK_EQUAL(d.m2, r.m2)
        }
        ENDSTEPS()
    }
    //  test type: equivalence class test
    //  test of NtpArray / NtpIndex
    TEST(BT_02, T04)
    {

    }
} // namespace
