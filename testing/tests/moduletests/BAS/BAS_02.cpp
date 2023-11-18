//  ============================================================
//  test of SortableStackArray, StackArrayIndex
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

    class IdataSortableArray : public SortableStackArray<Idata, 20>
    {
    public:
        inline bool isGreater(const Idata& a, const Idata& b) const
        {
            return a.m1 > b.m1;
        }
    };

    typedef StackArray<Idata, 20> IdataArray;

    class IdataIndex : public StackArrayIndex<Idata, 20>
    {
    public:
        inline IdataIndex(const IdataArray& a):
            StackArrayIndex<Idata, 20>(a)
        {}
    protected:        
        inline bool isGreater(const Idata& a, const Idata& b) const
        {
            return a.m1 > b.m1;
        }
    };

    //  test type: equivalence class test
    //  test of SortableStackArray
    TEST(BAS_02, T01)
    {
        STEP(1)
        //  create array
        //  load data
        IdataSortableArray a;

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
        const IdataSortableArray& c = a;
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
    //  test of SortableStackArray dupCnt
    TEST(BAS_02, T02)
    {
        SETUP()
        IdataSortableArray a;
        a.add(Idata(1, 2));
        a.add(Idata(2, 2));
        a.add(Idata(1, 2));
        a.add(Idata(2, 2));
        a.sort();
        const IdataSortableArray& c = a;

        STEP(1)
        const UINT32 cnt = c.dupCnt();
        L_CHECK_EQUAL(2, cnt)
    }

    //  test type: equivalence class test
    //  test of StackArrayIndex
    TEST(BAS_02, T03)
    {
        SETUP()
        //  create array
        IdataArray a;
        IdataIndex ix(a);
        bool ok = false;

        STEP(1)
        //  index of empty array
        {
            ok = ix.index();
            L_CHECK_TRUE(ok)
            const Idata d(1, 2);
            const INT32 f = ix.findRef(d);
            L_CHECK_EQUAL(-1, f)
        }

        STEP(2)
        //  load data
        for (INT32 i = 0; i < a.capacity(); ++i)
        {
            a.add(Idata(-i, i));
        }
        L_CHECK_FALSE(a.hasSpace())

        STEP(3)
        //  index
        //  find all data in index
        ok = ix.index();
        L_CHECK_TRUE(ok)

        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const Idata& d = a.at(i);
            const INT32  f = ix.findRef(d);
            L_CHECK_FALSE(f < 0)
            const Idata& r = ix.getRef(f);
            L_CHECK_EQUAL(d.m1, r.m1)
            L_CHECK_EQUAL(d.m2, r.m2)
        }
        ENDSTEPS()

        STEP(4)
        //  duplicates
        a.reset();
        a.add(Idata(1, 1));
        a.add(Idata(1, 2));
        ok = ix.index();
        L_CHECK_FALSE(ok)
    }

    //  test type: coverage
    //  StackArray isGreater / swap
    TEST(BAS_02, T04)
    {
        IdataArray a;
        const bool res = a.isGreater(Idata(2, 2), Idata(1, 2));
        L_CHECK_FALSE(res)
        a.swap(0, 1);
    }
} // namespace
