//  ============================================================
//  test classes
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTCLASSES_H
#define TESTCLASSES_H

#include <baselib/SortAndSearch.h>
#include <baselib/StaticArrays.h>

namespace test
{
    template<UINT32 S>
    class TestSortMap : public I_Searchable
    {
    public:
        inline TestSortMap()
        {
            init();
        }
        inline UINT32 size() const
        {
            return S;
        } 
        inline UINT32 getSearchPos() const
        {
            return S;
        }
        inline bool isGreater(UINT32 posA, UINT32 posB) const
        {
            return mData[posA] > mData[posB];
        }
        inline bool isEqual(UINT32 posA, UINT32 posB) const
        {
            return mData[posA] == mData[posB];
        }
        inline void swap(UINT32 posA, UINT32 posB)
        {
            mData[S]    = mData[posB];
            mData[posB] = mData[posA];
            mData[posA] = mData[S];
            ++mCnt;
        }

        //  even numbers 0 -2 -4 -8
        //  odd  numbers 1  3  5
        inline void init()
        {
            INT32 sig = 1;
            for (INT32 i = 0; i < S; ++i)
            {
                sig = sig * -1;
                mData[i] = i * sig;
            }
        }
        inline UINT32 checkSort()
        {
            mCnt = 0;
            bSort(*this);
            SUBSTEPS()
            for (UINT32 n = 0; n < S - 1; ++n)
            {
                STEP(n + 1)
                CHECK_TRUE(mData[n] < mData[n + 1]);
            }
            ENDSTEPS()
            return mCnt;
        }

        void checkSearch()
        {
            bSort(*this);
            SUBSTEPS()
            for (UINT32 n = 0; n < S; ++n)
            {
                STEP(n + 1)
                mData[S] = mData[n];
                const INT32 p = bSearch(*this);
                CHECK_EQUAL(n, p);
            }
            ENDSTEPS()
        }

        INT32 mData[S + 1];
        UINT32 mCnt;        
    };

    struct TestDataInt
    {
        INT32 m1;
        INT32 m2;
        inline TestDataInt(const INT32 m1, const INT32 m2):
            m1(m1),
            m2(m2)
        {}
        inline TestDataInt(const TestDataInt& o):
            m1(o.m1),
            m2(o.m2)
        {}

    };

    //  test array with ascending order of 1st data member
    class TestArray : public SearchableStaticArray<TestDataInt, 20>
    {
    public:
        inline virtual bool isGreater(UINT32 posA, UINT32 posB) const
        {
            return at(posA).m1 > at(posB).m1;
        }
        inline bool isEqual(UINT32 posA, UINT32 posB) const
        {
            return at(posA).m1 == at(posB).m1;
        }
    };

    //  test array with descending order of 1st data member
    class TestArrayRev : public TestArray
    {
    public:
        inline virtual bool isGreater(UINT32 posA, UINT32 posB) const
        {
            return at(posA).m1 < at(posB).m1;
        }
    };

} // namespace


#endif // H_