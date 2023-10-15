#include <testlib/CppUTest.h>
#include <testlib/TestGroupBase.h>

#include "TestClasses.h"

#include <iostream>
// #include <iomanip>
using std::cout;
// using std::setw;
using std::endl;

namespace test
{

    TEST_GROUP_BASE(BT_02, TestGroupBase)
    {
        
    };

    TEST(BT_02, T01)
    {
        UINT32 cnt = 0;
        STEP(1)
        TestSortMap<10> tsmEven;
        cnt = tsmEven.checkSort();
        cout << "swaps: " << cnt << endl;

        STEP(2)
        TestSortMap<11> tsmOdd;
        cnt = tsmOdd.checkSort();
        cout << "swaps: " << cnt << endl;
    }

    TEST(BT_02, T02)
    {
        // TestStepper::showAll();
        STEP(1)
        TestSortMap<10> tsmEven;
        tsmEven.checkSearch();

        STEP(2)
        TestSortMap<11> tsmOdd;
        tsmOdd.checkSearch();
    }

    TEST(BT_02, T03)
    {
        // TestStepper::showAll();
        STEP(1)
        TestArray a;

        L_CHECK_EQUAL(20, a.capacity())
        L_CHECK_EQUAL( 0, a.size())

        // m1 0 .. -9
        // m2 0 ..  9
        for (INT32 i = 0; i < 10; ++i)
        {
            const TestDataInt d = {-i, i};
            a.add(d);
        }
        L_CHECK_EQUAL(10, a.size())

        STEP(2)
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            STEP(i + 1)
            const TestDataInt& d = a[i];
            cout << d.m1 << ", " << d.m2 << endl;
            L_CHECK_EQUAL(-i, d.m1)
            L_CHECK_EQUAL( i, d.m2)
        }
        ENDSTEPS()
        
        STEP(3)
        bSort(a);
        // m1 -9 .. 0
        // m2  9 .. 0  
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            STEP(i + 1)
            const TestDataInt& d = a[i];
            L_CHECK_EQUAL(-9 + i, d.m1)
            L_CHECK_EQUAL( 9 - i, d.m2)
            cout << d.m1 << ", " << d.m2 << endl;
        }
        ENDSTEPS()
    }

}
