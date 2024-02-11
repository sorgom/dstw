//  ============================================================
//  array types for test issues 
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TESTARRAYS_H
#define TESTARRAYS_H

#include <BAS/I_Array.h>
#include <new>

namespace test
{
    //  ============================================================
    //  MutableArray
    //  - keeps objects in the same order as they were added
    //  - stores objects of one class
    //  - provides const and mutable object access
    //  - provides C style array access to data
    //  ============================================================
    template <class C, size_t CAP>
    class MutableArray : 
        public I_Array<C, CAP>
    {
    public:
        inline MutableArray():
            mSize(0)
        {}

        inline void reset()
        {
            mSize = 0;
        }

        inline size_t size() const final
        {
            return mSize;
        }

        template <typename ... ARGS>
        size_t add(const ARGS& ... args)
        {
            new (mData[mSize]) C(args...);
            return mSize++;
        }

        inline const C& at(size_t pos) const final
        {
            return *reinterpret_cast<const C*>(mData[pos]);
        }

        inline C& at(size_t pos)
        {
            return *reinterpret_cast<C*>(mData[pos]);
        }

        inline const C* data() const
        {
            return reinterpret_cast<const C*>(mData);
        } 

        NOCOPY(MutableArray)

    private:
        constexpr static auto DIM = sizeof(C);
        using Segment = BYTE[DIM];
        Segment mData[CAP];
        size_t mSize;
    };
} // namespace
#endif // H_
