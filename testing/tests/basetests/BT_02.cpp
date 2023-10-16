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

    //  test type: equivalence class test
    //  check of bSort
    TEST(BT_02, T01)
    {
        UINT32 cnt = 0;
        STEP(1)
        TestSortMap<10> tsmEven;
        cnt = tsmEven.checkSort();

        STEP(2)
        TestSortMap<11> tsmOdd;
        cnt = tsmOdd.checkSort();
    }

    //  test type: equivalence class test
    //  check of bSearch
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

    //  test type: equivalence class test
    //  test of StaticArrayMappable
    TEST(BT_02, T03)
    {
        // TestStepper::showAll();
        STEP(1)
        //  create array
        //  load 10 data
        TestArray a;

        L_CHECK_EQUAL(20, a.capacity())
        L_CHECK_EQUAL( 0, a.size())

        // m1 0 .. -9
        // m2 0 ..  9
        for (INT32 i = 0; i < 10; ++i)
        {
            a.add(TestDataInt(-i, i));
        }
        L_CHECK_EQUAL(10, a.size())

        STEP(2)
        //  test unsorted data as loaded
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            STEP(i + 1)
            const TestDataInt& d = a[i];
            L_CHECK_EQUAL(-i, d.m1)
            L_CHECK_EQUAL( i, d.m2)
        }
        ENDSTEPS()
        
        STEP(3)
        //  apply bSort
        //  test sorted data
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
        }
        ENDSTEPS()
    }

    //  test type: equivalence class test
    //  test of StaticArrayMappable with reversed order
    TEST(BT_02, T04)
    {
        STEP(1)
        //  create array
        //  load 10 data
        TestArrayRev a;

        L_CHECK_EQUAL(20, a.capacity())
        L_CHECK_EQUAL( 0, a.size())

        // m1 0 .. -9
        // m2 0 ..  9
        for (INT32 i = 0; i < 10; ++i)
        {
            a.add(TestDataInt(-i, i));
        }
        L_CHECK_EQUAL(10, a.size())

        STEP(2)
        //  apply bSort
        //  test sorted data
        bSort(a);
        //  m1 0 .. -9
        //  m2 0 ..  9
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            STEP(i + 1)
            const TestDataInt& d = a[i];
            L_CHECK_EQUAL(-i, d.m1)
            L_CHECK_EQUAL( i, d.m2)
        }
        ENDSTEPS()
    }

    //  test type: equivalence class test
    //  test of StaticArrayMappable using placement new on addPtr
    TEST(BT_02, T05)
    {
        // TestStepper::showAll();
        STEP(1)
        //  create array
        //  load 10 data
        TestArray a;

        // m1 0 .. -9
        // m2 0 ..  9
        for (INT32 i = 0; i < 10; ++i)
        {
            new (a.addPtr()) TestDataInt(-i, i);
        }
        L_CHECK_EQUAL(10, a.size())

        STEP(2)
        //  test unsorted data as loaded
        SUBSTEPS()
        for (INT32 i = 0; i < a.size(); ++i)
        {
            STEP(i + 1)
            const TestDataInt& d = a[i];
            L_CHECK_EQUAL(-i, d.m1)
            L_CHECK_EQUAL( i, d.m2)
        }
        ENDSTEPS()
    }

    //  test type: equivalence class test
    //  test of StaticArrayMappable as map
    TEST(BT_02, T06)
    {
        // TestStepper::showAll();
        STEP(1)
        //  create array
        //  load 10 data
        TestArray a;

        // m1 0 .. -9
        // m2 0 ..  9
        for (INT32 i = 0; i < 10; ++i)
        {
            new (a.addPtr()) TestDataInt(-i, i);
        }

        // sort
        STEP(2)
        bSort(a);

        //  search elements
        STEP(3)
        const TestArray& c = a;
        SUBSTEPS()
        for (INT32 i = 0; i < c.size(); ++i)
        {
            STEP(i + 1)
            // const TestDataInt& d = c[i];
            // const TestDataInt ds(d);
            // c.setSearch(c[i]);
            // const UINT32 p = bSearch(c);
            const UINT32 p = c.search(c[i]);
            L_CHECK_EQUAL(i, p)
        }
        ENDSTEPS()
    }
} // namespace
