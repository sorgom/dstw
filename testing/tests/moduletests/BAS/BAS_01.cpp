//  ============================================================
//  test of Containers
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/Containers.h>

namespace test
{

    TEST_GROUP_BASE(BAS_01, TestGroupBase) {};

    enum : bool
    {
        YES = true,
        NO = false
    };

    class Base
    {
    public:
        virtual bool answer() const = 0;
        virtual void set(UINT8 val) = 0;
        virtual UINT8 get() const = 0;
        virtual ~Base() = default;
    };

    //  in between class with virtual methods remaining undefined
    class D_val : public Base
    {
    public:
        inline D_val() : val(0) {}
        inline UINT8 get() const final { return val; }
        inline void set(UINT8 v) final { val = v; }
    private:
        UINT8 val;
    };

    //  final class answering yes
    //  with static counter
    class D_yes : public D_val
    {
    public:
        inline D_yes() { ++cnt; }
        inline ~D_yes() { --cnt; }
        inline bool answer() const final { return YES; }
        inline static UINT32 count() { return cnt; }
        NOCOPY(D_yes)
    private:
        static UINT32 cnt;
    };
    UINT32 D_yes::cnt = 0;

    //  final class answering no
    //  with static counter
    //  and additional data
    //  requiring non default constructor
    class D_no : public D_val
    {
    public:
        inline D_no(UINT8 val, UINT16 = 0) { ++cnt; set(val); }
        inline ~D_no() { --cnt; }
        inline bool answer() const final { return NO; }
        inline static UINT32 count() { return cnt; }
        NODEF(D_no)
        NOCOPY(D_no)
    private:
        static UINT32 cnt;
        CHAR data[128];
    };
    UINT32 D_no::cnt = 0;

    //  test type: equivalence class test
    //  PolyVec methods
    TEST(BAS_01, T01)
    {
        STEP(1)
        L_CHECK_EQUAL(0, D_yes::count());
        L_CHECK_EQUAL(0, D_no::count());
        L_CHECK_TRUE(sizeof(D_no) > sizeof(D_yes));
        PolyVec<Base> vec;
        // mutable reference
        PolyVec<Base>& mv = vec;
        // const reference
        const PolyVec<Base>& cv = vec;
        L_CHECK_EQUAL(0, cv.size())

        //  reserve 30 elements
        STEP(2)
        mv.reserve(30);
        L_CHECK_EQUAL(0, cv.size())

        //  add 10 D_yes and 20 D_no elements
        STEP(3)
        for (UINT8 n = 0; n < 30; n += 3)
        {
            mv.add<D_yes>();
            mv.add<D_no>(n + 10, n + 1);
            L_CHECK_EQUAL(n + 10, cv.at(n + 1).get());
            mv.add<D_no>(n + 20);
            L_CHECK_EQUAL(n + 20, cv.at(n + 2).get());
        }
        //  check size and count
        L_CHECK_EQUAL(30, cv.size());
        L_CHECK_EQUAL(10, D_yes::count());
        L_CHECK_EQUAL(20, D_no::count());

        //  check derived classes answers
        STEP(4)
        SUBSTEPS()
        for (UINT8 n = 0; n < 30; n += 3)
        {
            STEP(n)
            L_CHECK_TRUE(cv.at(n).answer());
            L_CHECK_FALSE(cv.at(n + 1).answer());
            L_CHECK_FALSE(cv.at(n + 2).answer());
        }
        ENDSTEPS()

        //  set mutable
        //  get const
        STEP(5)
        SUBSTEPS()
        for (UINT8 n = 0; n < 30; ++n)
        {
            STEP(n)
            mv.at(n).set(n);
            L_CHECK_EQUAL(n, cv.at(n).get())
        }
        ENDSTEPS()

        STEP(6)
        mv.clear();
        L_CHECK_EQUAL(0, cv.size());
        L_CHECK_EQUAL(0, D_yes::count());
        L_CHECK_EQUAL(0, D_no::count());
    }

    //  test type: equivalence class test
    //  PolyVec destructor
    TEST(BAS_01, T02)
    {
        SETUP()
        L_CHECK_EQUAL(0, D_yes::count());
        L_CHECK_EQUAL(0, D_no::count());

        STEP(1)
        {
            PolyVec<Base> vec;
            vec.add<D_yes>();
            vec.add<D_no>(1);
            vec.add<D_no>(2);
            L_CHECK_EQUAL(1, D_yes::count());
            L_CHECK_EQUAL(2, D_no::count());
        }
        L_CHECK_EQUAL(0, D_yes::count());
        L_CHECK_EQUAL(0, D_no::count());
    }

    //  complex key type which cannot be copied
    //  with a very special operator >
    class Key
    {
    public:
        const int id;
        inline Key(int id) : id(id) {}
        inline bool operator >(const Key& b) const
        {
            return id < b.id;
        }
        NODEF(Key)
        NOCOPY(Key)
    };

    //  container type with key type key and data
    //  and a static counter
    class Cont
    {
    public:
        const Key key;
        const int cdata[5];
        int vdata[5];
        inline Cont(int k, int d=0) :
            key(k),
            cdata{d, d, d, d, d},
            vdata{0, 0, 0, 0, 0}
        { ++cnt; }
        inline ~Cont() { --cnt; }
        inline static UINT32 count() { return cnt; }
        NODEF(Cont)
        NOCOPY(Cont)
    private:
        static UINT32 cnt;
    };
    UINT32 Cont::cnt = 0;

    //  class indexing by key element
    class IndexKeyCont : public Index<const Key&, Cont>
    {
    protected:
        inline const Key& getKey(const Cont& cont) const final
        {
            return cont.key;
        }
    };

    //  class indexing by 1st data element
    class IndexIntCont : public Index<int, Cont>
    {
    protected:
        inline int getKey(const Cont& cont) const final
        {
            return cont.cdata[0];
        }
    };

    //  test type: equivalence class test
    //  Index methods
    TEST(BAS_01, T03)
    {
        SETUP()
        IndexKeyCont ixk;
        IndexIntCont ixi;
        //  const references
        const IndexKeyCont& cxk = ixk;
        const IndexIntCont& cxi = ixi;
        //  mutable references
        IndexKeyCont& mxk = ixk;
        IndexIntCont& mxi = ixi;

        L_CHECK_EQUAL(0, cxk.size());
        L_CHECK_EQUAL(0, cxi.size());
        L_CHECK_EQUAL(0, Cont::count());
        bool ok = false;

        //  index of empty container
        STEP(1)
        ok = mxk.index();
        L_CHECK_TRUE(ok);
        ok = mxi.index();
        L_CHECK_TRUE(ok);

        //  reserve 30 elements
        STEP(2)
        mxk.reserve(30);
        L_CHECK_EQUAL(0, cxk.size());
        mxi.reserve(30);
        L_CHECK_EQUAL(0, cxi.size());

        //  add 10 elements
        //  keys 10 .. 1
        STEP(3)
        for (int n = 0; n < 10; ++n)
        {
            mxk.add(10 - n);
            mxi.add(0, 10 - n);
        }
        L_CHECK_EQUAL(10, cxk.size());
        L_CHECK_EQUAL(10, cxi.size());
        L_CHECK_EQUAL(20, Cont::count());

        //  find without index
        STEP(4)
        {
            const PosRes res1 = cxk.find(Key(5));
            L_CHECK_FALSE(res1.valid);
            const PosRes res2 = cxi.find(5);
            L_CHECK_FALSE(res2.valid);
        }
        //  index
        STEP(5)
        ok = mxk.index() and mxi.index();
        L_CHECK_TRUE(ok);

        //  index with duplicate key
        STEP(6)
        mxk.add(5);
        mxi.add(0, 5);
        ok = mxk.index() or mxi.index();
        L_CHECK_FALSE(ok);

        //  find even with duplicates
        STEP(7)
        SUBSTEPS()
        for (int n = 1; n < 11; ++n)
        {
            STEP(n)
            const PosRes res1 = cxk.find(Key(n));
            L_CHECK_TRUE(res1.valid);
            const Cont& c1 = cxk.at(res1);
            L_CHECK_EQUAL(n, c1.key.id);

            const PosRes res2 = cxi.find(n);
            L_CHECK_TRUE(res2.valid);
            const Cont& c2 = cxi.at(res2);
            L_CHECK_EQUAL(n, c2.cdata[0]);

            // coverage: non const at position
            Cont& c3 = mxi.at(res2.pos);
            c3.vdata[0] = 123;
        }
        ENDSTEPS()

        //  search for non existing key
        STEP(8)
        {
            const PosRes res1 = cxk.find(Key(11));
            L_CHECK_FALSE(res1.valid);
            const PosRes res2 = cxi.find(11);
            L_CHECK_FALSE(res2.valid);
        }
        //  clear
        STEP(9)
        mxk.clear();
        L_CHECK_EQUAL(0, cxk.size());
        L_CHECK_EQUAL(11, Cont::count());

        STEP(10)
        mxi.clear();
        L_CHECK_EQUAL(0, cxi.size());
        L_CHECK_EQUAL(0, Cont::count());
    }

    //  test type: equivalence class test
    //  Index destructor
    TEST(BAS_01, T04)
    {
        SETUP()
        L_CHECK_EQUAL(0, Cont::count());
        STEP(1)
        {
            IndexKeyCont ixk;
            IndexIntCont ixi;
            for (UINT8 n = 0; n < 10; ++n)
            {
                ixk.add(n, 0);
                ixi.add(0, n);
            }
            L_CHECK_EQUAL(10, ixk.size());
            L_CHECK_EQUAL(10, ixi.size());
            L_CHECK_EQUAL(20, Cont::count());
        }
        STEP(2)
        L_CHECK_EQUAL(0, Cont::count());
    }
} // namespace
