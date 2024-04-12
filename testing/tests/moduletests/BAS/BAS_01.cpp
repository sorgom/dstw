//  ============================================================
//  test of Containers
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <BAS/Containers.h>

#include <qnd/useCout.h>

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
        inline D_no(UINT8 val, UINT16 = 0, UINT32 = 0) { ++cnt; set(val); }
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

    TEST(BAS_01, T00)
    {
        std::vector<std::unique_ptr<const D_no>> vec;
        vec.emplace_back(std::make_unique<const D_no>(22));
        const D_no* p = vec.at(0).get();
        play(p);
    }
    //  test type: equivalence class test
    //  PolyVec methods
    TEST(BAS_01, T01)
    {
        STEP(0)
        L_CHECK_EQUAL(0, D_yes::count());
        L_CHECK_EQUAL(0, D_no::count());
        L_CHECK_TRUE(sizeof(D_no) > sizeof(D_yes));
        PolyVec<Base> vec;
        // mutable reference
        PolyVec<Base>& mvec = vec;
        // const reference
        const PolyVec<Base>& cvec = vec;
        L_CHECK_EQUAL(0, cvec.size())
        
        //  reserve 30 elements
        STEP(1)
        const size_t cap = mvec.reserve(30);
        L_CHECK_TRUE(cap >= 30);
        L_CHECK_EQUAL(0, cvec.size())

        //  add 10 D_yes and 20 D_no elements
        STEP(2)
        for (UINT8 n = 0; n < 30; n += 3)
        {
            mvec.add<D_yes>();
            mvec.add<D_no>(n + 10, n + 1);
            L_CHECK_EQUAL(n + 10, cvec.at(n + 1).get());
            mvec.add<D_no>(n + 20);
            L_CHECK_EQUAL(n + 20, cvec.at(n + 2).get());
        }
        //  check size and count
        L_CHECK_EQUAL(30, cvec.size());
        L_CHECK_EQUAL(10, D_yes::count());
        L_CHECK_EQUAL(20, D_no::count());
        
        //  check derived classes answers
        STEP(3)
        SUBSTEPS()
        for (UINT8 n = 0; n < 30; n += 3)
        {
            STEP(n)
            L_CHECK_TRUE(cvec.at(n).answer());
            L_CHECK_FALSE(cvec.at(n + 1).answer());
            L_CHECK_FALSE(cvec.at(n + 2).answer());
        }
        ENDSTEPS()

        //  set mutable
        //  get const
        STEP(4)
        SUBSTEPS()
        for (UINT8 n = 0; n < 30; ++n)
        {
            STEP(n)
            mvec.at(n).set(n);
            L_CHECK_EQUAL(n, cvec.at(n).get())
        }
        ENDSTEPS()

        //  clear
        //  check size and count
        STEP(5)
        mvec.clear();
        L_CHECK_EQUAL(0, cvec.size());
        L_CHECK_EQUAL(0, D_yes::count());
        L_CHECK_EQUAL(0, D_no::count());
    }
} // namespace
