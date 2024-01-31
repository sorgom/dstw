//  ============================================================
//  test of StaticArray, StaticIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <testlib/MemStream.h>
#include <BAS/StaticArray.h>

namespace test
{

    TEST_GROUP_BASE(BAS_01, TestGroupBase) {};

    class IData
    {
    public:
        virtual INT32 get1() const = 0;
        virtual INT32 get2() const = 0;
    };

    class CData : public IData
    {
    public:
        inline INT32 get1() const { return m1; }
        inline INT32 get2() const { return m2; };
        inline CData(INT32 i1, INT32 i2 = 0):
            m1(i1),
            m2(i2)
        {}
        inline bool operator==(const CData& o) const
        {
            return m1 == o.get1() and m2 == o.get2();
        }
        NOCOPY(CData)
        NODEF(CData)
    private:    
        const INT32 m1;
        const INT32 m2;
    };

    class IDataArray : public StaticArray<IData, 20, CData>
    {
    public:
        inline bool isGreater(const IData& a, const IData& b) const
        {
            return a.get1() > b.get1();
        }
    };

    class IDataIndex : public StaticIndex<IData, 20>
    {
    public:
        inline IDataIndex(const IDataArray& a):
            StaticIndex<IData, 20>(a)
        {}
    protected:        
        inline bool isGreater(const IData& a, const IData& b) const
        {
            return a.get1() < b.get1();
        }
    };

    //  test type: equivalence class test
    //  test of StaticArray
    TEST(BAS_01, T01)
    {
        STEP(1)
        //  create array
        //  load data
        IDataArray a;

        L_CHECK_EQUAL(20, a.capacity())
        L_CHECK_EQUAL( 0, a.size())

        STEP(2)
        for (UINT16 i = 0; i < a.capacity(); ++i)
        {
            L_CHECK_TRUE(a.hasSpace())
            const size_t p = a.addT<CData>(-i, i);
            L_CHECK_EQUAL(i, p);
        }
        L_CHECK_EQUAL(a.capacity(), a.size())
        L_CHECK_FALSE(a.hasSpace())

        STEP(3)
        //  test unsorted data as loaded
        SUBSTEPS()
        for (UINT16 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const IData& d = a.at(i);
            L_CHECK_EQUAL(-i, d.get1())
            L_CHECK_EQUAL( i, d.get2())
        }
        ENDSTEPS()
        
        STEP(4)
        //  apply sort()
        //  test sorted data
        a.sort();
        const INT32 of = a.size() - 1;
        SUBSTEPS()
        for (UINT16 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const IData& d = a.at(i);
            L_CHECK_EQUAL(-of + i, d.get1())
            L_CHECK_EQUAL( of - i, d.get2())
        }
        ENDSTEPS()

        STEP(5)
        //  apply find() to const object
        const IDataArray& c = a;
        SUBSTEPS()
        for (UINT16 i = 0; i < c.size(); ++i)
        {
            LSTEP(i)
            const PosRes p = c.find(c.at(i));
            L_CHECK_EQUAL(i, p.pos)
        }
        ENDSTEPS()
    }

    //  test type: equivalence class test
    //  test of StaticArray dupCnt
    TEST(BAS_01, T02)
    {
        SETUP()
        IDataArray a;
        a.addT<CData>(1, 2);
        a.addT<CData>(2, 2);
        a.addT<CData>(1, 2);
        a.addT<CData>(2, 2);
        a.sort();
        const IDataArray& c = a;

        STEP(1)
        const size_t cnt = c.dupCnt();
        L_CHECK_EQUAL(2, cnt)
    }

    //  test type: equivalence class test
    //  test of StaticIndex
    TEST(BAS_01, T03)
    {
        SETUP()
        //  create array
        IDataArray a;
        IDataIndex ix(a);
        bool ok = false;

        STEP(1)
        //  index of empty array
        {
            ok = ix.index();
            L_CHECK_TRUE(ok)
            const CData d(1, 2);
            const PosRes f = ix.find(d);
            L_CHECK_FALSE(f.valid)
        }

        STEP(2)
        //  load data
        for (UINT16 i = 0; i < a.capacity(); ++i)
        {
            a.addT<CData>(-i, i);
        }
        L_CHECK_FALSE(a.hasSpace())

        STEP(3)
        //  index
        //  find all data in index
        ok = ix.index();
        L_CHECK_TRUE(ok)

        SUBSTEPS()
        for (UINT16 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const IData& d = a.at(i);
            const PosRes f = ix.find(d);
            L_CHECK_TRUE(f.valid)
            const IData& r = ix.get(f);
            L_CHECK_EQUAL(d.get1(), r.get1())
            L_CHECK_EQUAL(d.get2(), r.get2())
        }
        ENDSTEPS()

        STEP(4)
        //  duplicates
        a.reset();
        a.addT<CData>(1, 1);
        a.addT<CData>(1, 2);
        ok = ix.index();
        L_CHECK_FALSE(ok)
    }

    //  test type: coverage
    //  isGreater / swap
    TEST(BAS_01, T04)
    {
        IDataArray a;
        const bool res = a.isGreater(CData(1, 2), CData(2, 2));
        L_CHECK_FALSE(res)
    }


    //  test type: equivalence class test
    //  file io
    TEST(BAS_01, T05)
    {
        using CDataArray = StaticArray<CData, 20>;
        
        CDataArray a;
        STEP(1)
        for (UINT16 i = 0; i < a.capacity(); ++i)
        {
            a.add(-i, i);
        }
        STEP(2)
        CDataArray b;
        MemStream s(a.data(), a.bytes());
        b.read(s, a.size());

        STEP(3)
        L_CHECK_EQUAL(a.size(), b.size())
        for (size_t p = 0; p < a.size(); ++p)
        {
            L_CHECK_TRUE(a.at(p) == b.at(p))
        }        
    }
} // namespace
