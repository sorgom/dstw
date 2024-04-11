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

        class Base
        {
        public:
            virtual bool answer() const = 0;
            virtual void set(UINT8 val) = 0;
            virtual UINT8 get() const = 0;
            virtual ~Base() = default;
        };

        class D_val : public Base
        {
        public:
            inline D_val() : val(0) {}
            inline UINT8 get() const { return val; }
            inline void set(UINT8 val) { this->val = val; }
        private:
            UINT8 val;
        };

        class D_yes : public D_val
        {
        public:
            inline D_yes() { ++cnt; }
            inline ~D_yes() { --cnt; }
            inline bool answer() const override { return true; }
            inline static UINT32 count() { return cnt; }
        private:
            static UINT32 cnt;
        };
        UINT32 D_yes::cnt = 0;

        class D_no : public D_val
        {
        public:
            inline D_no(UINT8 val, UINT16, UINT32)  : val(val) { ++cnt; }
            inline ~D_no() { --cnt; }
            inline bool answer() const override { return false; }
            inline static UINT32 count() { return cnt; }
            UINT8 val;

            NODEF(D_no)
        private:
            static UINT32 cnt;
            CHAR reasons[128];
        };
        UINT32 D_no::cnt = 0;

    // TODO: implement test cases for Containers
    TEST(BAS_01, T01)
    {
        STEP(0)
        L_CHECK_EQUAL(0, D_yes::count());
        L_CHECK_EQUAL(0, D_no::count());
        L_CHECK_TRUE(sizeof(D_no) > sizeof(D_yes));
        PolyVec<Base> vec;

        STEP(1)
        for (UINT8 n = 0; n < 10; ++n)
        {
            vec.add<D_yes>();
            vec.add<D_no>(n, n + 1, n + 2);
        }
        L_CHECK_EQUAL(20, vec.size());
        L_CHECK_EQUAL(10, D_yes::count());
        L_CHECK_EQUAL(10, D_no::count());
        
        STEP(2)
        SUBSTEPS()
        for (UINT8 n = 0; n < 10; n += 2)
        {
            STEP(n)
            L_CHECK_TRUE(vec.at(n).answer());
            L_CHECK_FALSE(vec.at(n + 1).answer());
        }
        ENDSTEPS()

        STEP(3)
        vec.clear();
        L_CHECK_EQUAL(0, vec.size());
        L_CHECK_EQUAL(0, D_yes::count());
        L_CHECK_EQUAL(0, D_no::count());
    }
} // namespace
