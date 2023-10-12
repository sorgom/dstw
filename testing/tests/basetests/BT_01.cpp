#include <testlib/CppUTest.h>
#include <testlib/TestGroupBase.h>

#include "TestPack.h"
//  General System Testing

#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;
using std::endl;

namespace test
{

    TEST_GROUP_BASE(BT_01, TestGroupBase)
    {
        
    };

#define SIZEOUT(TYPE) \
    cout << setw(4) << sizeof(TYPE) << " : " << #TYPE << endl;

    //  integer sizes (info)
    TEST(BT_01, T01)
    {
        cout << endl << "unsigned" << endl;
        SIZEOUT(unsigned char)
        SIZEOUT(unsigned short)
        SIZEOUT(unsigned)
        SIZEOUT(unsigned long)
        cout << endl << "signed" << endl;
        SIZEOUT(char)
        SIZEOUT(short)
        SIZEOUT(int)
        SIZEOUT(long int)
        cout << endl << "baselib unsigned" << endl;
        SIZEOUT(UINT8)
        SIZEOUT(UINT16)
        SIZEOUT(UINT32)
        SIZEOUT(UINT64)
        cout << endl << "baselib signed" << endl;
        SIZEOUT(CHAR)
        SIZEOUT(INT8)
        SIZEOUT(INT16)
        SIZEOUT(INT32)
        SIZEOUT(INT64)
    }

#define S_CHECK(SIZE, TYPE) \
    L_CHECK_EQUAL(SIZE, sizeof(TYPE))    
    
    //  integer sizes (check)
    TEST(BT_01, T02)
    {
        STEP(1)
        S_CHECK(1, UINT8)
        S_CHECK(2, UINT16)
        S_CHECK(4, UINT32)
        S_CHECK(8, UINT64)

        STEP(2)
        S_CHECK(1, INT8)
        S_CHECK(2, INT16)
        S_CHECK(4, INT32)
        S_CHECK(8, INT64)

        STEP(3)
        S_CHECK(1, BYTE)
        S_CHECK(1, CHAR)
    }

    //  Test of pack 
    TEST(BT_01, T03)
    {
        STEP(1)
        CHECK_EQUAL(8, sizeof(Unpacked));

        STEP(2)
        CHECK_EQUAL(5, sizeof(Packed));
    }
}
