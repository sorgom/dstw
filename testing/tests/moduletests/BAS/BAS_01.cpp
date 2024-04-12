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
        const size_t cap = mv.reserve(30);
        L_CHECK_TRUE(cap >= 30);
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
    class KeyType
    {
    public:
        inline KeyType(int k=0) : id(k), data(0) {}
        const int id;
        const int data;
        NOCOPY(KeyType)
    };

    //  container type with key type key
    class ContType
    {
        public:
        const KeyType key;
        inline ContType(int k, int a=0) : key(k) { ++cnt; }
        inline ~ContType() { --cnt; }    
        int data[5];
        NOCOPY(ContType)
        inline static UINT32 count() { return cnt; }
    private:
        static UINT32 cnt;
    };
    UINT32 ContType::cnt = 0;

    class IndexKeyCont : public Index<const KeyType&, ContType>
    {
    protected:
        inline const KeyType& getKey(const ContType& cont) const final
        {
            return cont.key;
        }
        inline bool greater(const KeyType& a, const KeyType& b) const final
        {
            return a.id > b.id;
        }

    };

    //  test type: equivalence class test
    //  Index methods
    TEST(BAS_01, T03)
    {
        SETUP()
        IndexKeyCont ix;
        //  const reference
        const IndexKeyCont& cx = ix;
        //  mutable reference
        IndexKeyCont& mx = ix;
        L_CHECK_EQUAL(0, cx.size());
        L_CHECK_EQUAL(0, ContType::count());
        bool ok = false;

        //  index of empty container
        STEP(1)
        ok = mx.index();
        L_CHECK_TRUE(ok);

        //  reserve 30 elements
        STEP(2)
        const size_t cap = mx.reserve(30);
        L_CHECK_TRUE(cap >= 30);
        L_CHECK_EQUAL(0, cx.size());

        //  add 10 elements
        STEP(3)
        for (UINT8 n = 0; n < 10; ++n)
        {
            mx.add(10 - n);
        }
        L_CHECK_EQUAL(10, cx.size());
        L_CHECK_EQUAL(10, ContType::count());

        const KeyType key5(5);
        const KeyType key11(11);

        //  find without index
        STEP(4)
        {
            const PosRes res = cx.find(key5);
            L_CHECK_FALSE(res.valid);
        }
        //  index & find
        STEP(5)
        ok = mx.index();
        L_CHECK_TRUE(ok);
        {
            const PosRes res = cx.find(key5);
            L_CHECK_TRUE(res.valid);
        }
        //  find non existing key
        STEP(6)
        {
            const PosRes res = cx.find(key11);
            L_CHECK_FALSE(res.valid);
        }
        //  index with duplicate key
        STEP(7)
        mx.add(5);
        ok = mx.index();
        L_CHECK_FALSE(ok);
        {
            const PosRes res = cx.find(key5);
            L_CHECK_TRUE(res.valid);
        }
        //  clear
        STEP(8)
        mx.clear();
        L_CHECK_EQUAL(0, cx.size());
        L_CHECK_EQUAL(0, ContType::count());
    }

    //  test type: equivalence class test
    //  Index destructor
    TEST(BAS_01, T04)
    {
        SETUP()
        L_CHECK_EQUAL(0, ContType::count());
        STEP(1)
        {
            IndexKeyCont ix;
            for (UINT8 n = 0; n < 10; ++n)
            {
                ix.add(n, 0);
            }
            L_CHECK_EQUAL(10, ix.size());
            L_CHECK_EQUAL(10, ContType::count());
        }
        STEP(2)
        L_CHECK_EQUAL(0, ContType::count());
    }
} // namespace
