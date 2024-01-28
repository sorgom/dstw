//  ============================================================
//  test of StaticArray, StaticIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/StaticArray.h>

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

    class IdataArray : public StaticArray<Idata, 20>
    {
    public:
        inline bool isGreater(const Idata& a, const Idata& b) const
        {
            return a.m1 > b.m1;
        }
    };

    class IdataIndex : public StaticIndex<Idata, 20>
    {
    public:
        inline IdataIndex(const IdataArray& a):
            StaticIndex<Idata, 20>(a)
        {}
    protected:        
        inline bool isGreater(const Idata& a, const Idata& b) const
        {
            return a.m1 < b.m1;
        }
    };

    //  test type: equivalence class test
    //  test of StaticArray
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
            const size_t p = a.add(Idata(-i, i));
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
            const PosRes p = c.find(c.at(i));
            L_CHECK_EQUAL(i, p.pos)
        }
        ENDSTEPS()
    }

    //  test type: equivalence class test
    //  test of StaticArray dupCnt
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
        const size_t cnt = c.dupCnt();
        L_CHECK_EQUAL(2, cnt)
    }

    //  test type: equivalence class test
    //  test of StaticIndex
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
            const PosRes f = ix.find(d);
            L_CHECK_FALSE(f.valid)
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
            const PosRes  f = ix.find(d);
            L_CHECK_TRUE(f.valid)
            const Idata& r = ix.get(f);
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
    //   isGreater / swap
    TEST(BAS_02, T04)
    {
        IdataArray a;
        const bool res = a.isGreater(Idata(1, 2), Idata(2, 2));
        L_CHECK_FALSE(res)
    }
} // namespace
