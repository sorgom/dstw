//  ============================================================
//  test of StackArray, StackArrayIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/StackArray.h>

namespace test
{

    TEST_GROUP_BASE(BAS_02, TestGroupBase) {};

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

    typedef SimpleStackArray<Idata, 20> IdataSimpleArray;

    class IdataIndex : public StackArrayIndex<Idata, 20>
    {
    public:
        inline IdataIndex(const IdataSimpleArray& a):
            StackArrayIndex<Idata, 20>(a)
        {}
        inline bool isGreater(const Idata& a, const Idata& b) const
        {
            return a.m1 > b.m1;
        }
    };

    //  test type: equivalence class test
    //  test of StackArray
    TEST(BAS_02, T01)
    {
        STEP(1)
        //  create array
        //  load data
        IdataArray a;

        L_CHECK_EQUAL(20, a.capacity())
        L_CHECK_EQUAL( 0, a.size())

        STEP(2)
        for (INT32 i = 0; i < a.capacity(); ++i)
        {
            L_CHECK_TRUE(a.hasSpace())
            const UINT32 p = a.add(Idata(-i, i));
            L_CHECK_EQUAL(i, p);
        }
        L_CHECK_EQUAL(a.capacity(), a.size())
        L_CHECK_FALSE(a.hasSpace())

        STEP(3)
        //  test unsorted data as loaded
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const Idata& d = a.at(i);
            L_CHECK_EQUAL(-i, d.m1)
            L_CHECK_EQUAL( i, d.m2)
        }
        ENDSTEPS()
        
        STEP(4)
        //  apply sort()
        //  test sorted data
        a.sort();
        const INT32 of = a.size() - 1;
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const Idata& d = a.at(i);
            L_CHECK_EQUAL(-of + i, d.m1)
            L_CHECK_EQUAL( of - i, d.m2)
        }
        ENDSTEPS()

        STEP(5)
        //  apply find() to const object
        const IdataArray& c = a;
        SUBSTEPS()
        for (INT32 i = 0; i < c.size(); ++i)
        {
            LSTEP(i)
            const INT32 p = c.find(c.at(i));
            L_CHECK_EQUAL(i, p)
        }
        ENDSTEPS()
    }

    //  test type: equivalence class test
    //  test of StackArray dupCnt
    TEST(BAS_02, T02)
    {
        SETUP()
        IdataArray a;
        a.add(Idata(1, 2));
        a.add(Idata(2, 2));
        a.add(Idata(1, 2));
        a.add(Idata(2, 2));
        a.sort();
        const IdataArray& c = a;

        STEP(1)
        const UINT32 cnt = c.dupCnt();
        L_CHECK_EQUAL(2, cnt)
    }

    //  test type: equivalence class test
    //  test of StackArrayIndex
    TEST(BAS_02, T03)
    {
        STEP(1)
        //  create array
        //  load data
        IdataSimpleArray a;
        IdataIndex ix(a);
        L_CHECK_EQUAL(a.capacity(), ix.capacity())

        for (INT32 i = 0; i < a.capacity(); ++i)
        {
            a.add(Idata(-i, i));
        }
        L_CHECK_FALSE(a.hasSpace())

        STEP(2)
        //  index index
        //  find all data in index
        ix.index();
        L_CHECK_FALSE(ix.hasSpace())
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const Idata& d = a.at(i);
            const INT32  f = ix.findRef(d);
            const Idata& r = ix.getRef(f);
            L_CHECK_EQUAL(d.m1, r.m1)
            L_CHECK_EQUAL(d.m2, r.m2)
        }
        ENDSTEPS()
    }
    //  test type: coverage
    //  SimpleStackArray isGreater / swap
    TEST(BAS_02, T04)
    {
        IdataSimpleArray a;
        const bool res = a.isGreater(Idata(2, 2), Idata(1, 2));
        L_CHECK_FALSE(res)
        a.swap(0, 1);
    }
} // namespace
