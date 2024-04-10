//  ============================================================
//  test of StaticArray, StaticIndex
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/StaticArray.h>

namespace test
{

    TEST_GROUP_BASE(BAS_01, TestGroupBase) {};

    class IData
    {
    public:
        virtual const INT32& get1() const = 0;
        virtual const INT32& get2() const = 0;
    };

    class CData : public IData
    {
    public:
        inline const INT32& get1() const { return m1; }
        inline const INT32& get2() const { return m2; };
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

    using IDataArray = InterfaceArray<IData, 20, CData>;
    using CDataArray = ConstArray<CData, 20>;

    class CDataIndex : public ConstArrayIndex<INT32, CData, 20>
    {
    public:
        inline CDataIndex(const CDataArray& a):
            ConstArrayIndex<INT32, CData, 20>(a)
        {}
    protected:
        inline const INT32& getKey(const CData& d) const
        {
            return d.get1();
        }     

        inline bool isGreater(const INT32& a, const INT32& b) const
        {
            return a > b;
        }
    };

    //  test type: equivalence class test
    //  test of InterfaceArray
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
            const size_t p = a.add<CData>(-i, i);
            L_CHECK_EQUAL(i, p);
        }
        L_CHECK_EQUAL(a.capacity(), a.size())
        L_CHECK_FALSE(a.hasSpace())

        STEP(3)
        //  test data as loaded
        SUBSTEPS()
        for (UINT16 i = 0; i < a.size(); ++i)
        {
            LSTEP(i)
            const IData& d = a.at(i);
            L_CHECK_EQUAL(-i, d.get1())
            L_CHECK_EQUAL( i, d.get2())
        }
        ENDSTEPS()
    }

    //  test type: equivalence class test
    //  test of ConstArray / ConstArrayIndex
    TEST(BAS_01, T02)
    {
        SETUP()
        //  create array
        CDataArray a;
        CDataIndex ix(a);
        bool ok = false;

        STEP(1)
        //  index of empty array
        {
            ok = ix.index();
            L_CHECK_TRUE(ok)
            const CData d(1, 2);
            const PosRes f = ix.find(d.get1());
            L_CHECK_FALSE(f.valid)
        }

        STEP(2)
        //  load data
        for (UINT16 i = 0; i < a.capacity(); ++i)
        {
            L_CHECK_TRUE(a.hasSpace())
            a.add(-i, i);
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
            const CData& d = a.at(i);
            const PosRes f = ix.find(d.get1());
            L_CHECK_TRUE(f.valid)
            const CData& r = ix.at(f);
            L_CHECK_EQUAL(d.get1(), r.get1())
            L_CHECK_EQUAL(d.get2(), r.get2())
        }
        ENDSTEPS()

        STEP(4)
        //  duplicates
        a.reset();
        a.add(1, 1);
        a.add(1, 2);
        ok = ix.index();
        L_CHECK_FALSE(ok)
    }

} // namespace
