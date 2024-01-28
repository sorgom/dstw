//  ============================================================
//  the core of static memory allocation
//  StaticArrays
//  -   act like arrays of pre-defined size
//  -   can be filled with objects at runtime
//  -   can store objects of different size classes
//      for the same interface
//  -   do not provide any overflow protection
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef STATICARRAY_H
#define STATICARRAY_H

#include <BAS/I_Array.h>
#include <BAS/Mem.h>
#include <algorithm>
#include <new>

//  ============================================================
//  StaticArray
//  keeps objects in the same order as they were added.
//  ============================================================
template <class ... Ts>
constexpr auto max_sizeof = std::max({sizeof(Ts)...});

template <class C, size_t CAP, class ... SCS>
class StaticArray : public I_Array<C, CAP>
{
public:
    inline StaticArray():
        mSize(0)
    {}

    inline void reset()
    {
        mSize = 0;
    }

    inline size_t size() const
    {
        return mSize;
    }

    inline bool hasSpace() const
    {
        return mSize < CAP;
    }

    inline bool has(size_t pos) const
    {
        return pos < mSize;
    }

    template <class T, typename ... ARGS>
    size_t newT(ARGS ... args)
    {
        static_assert(sizeof(T) <= DIM);
        new (mData[mSize]) T(args...);
        return mSize++;
    }

    template <typename ... ARGS>
    size_t newC(ARGS ... args)
    {
        new (mData[mSize]) C(args...);
        return mSize++;
    }

    template <class T>
    size_t addT(const T& obj)
    {
        static_assert(sizeof(T) <= DIM);
        Mem::cpy(mData[mSize], obj);
        return mSize++;
    }

    size_t add(const C& obj)
    {
        Mem::cpy(mData[mSize], obj);
        return mSize++;
    }

    inline C& at(size_t pos)
    {
        return *reinterpret_cast<C*>(mData[pos]);
    }

    inline const C& at(size_t pos) const
    {
        return *reinterpret_cast<const C*>(mData[pos]);
    }

    inline const C* ptr(size_t pos) const
    {
        return reinterpret_cast<const C*>(mData[pos]);
    }

    inline const C* data() const
    {
        static_assert(sizeof(C) == DIM);
        return reinterpret_cast<const C*>(mData);
    }  
    NOCOPY(StaticArray)

protected:
    inline void swap(size_t posA, size_t posB)
    {
        std::swap(mData[posA], mData[posB]);
    }

private:
    constexpr static size_t DIM = max_sizeof<C, SCS...>;
    using Segment = BYTE[DIM];
    Segment mData[CAP];
    size_t mSize;
};

//  ============================================================
//  class CRef
//  enables to store references as objects
//  ============================================================
template <class T>
class CRef
{
public:
    inline CRef(const T& obj):
        mPtr(&obj)
    {}
    inline CRef(const T* ptr):
        mPtr(ptr)
    {}
    inline const T& ref() const
    {
        return *mPtr;
    }

    NOCOPY(CRef)
    NODEF(CRef)
private:
    const T* mPtr;
};

//  ============================================================
//  StaticIndex
//  provides search for unsorted StaticArray.
//  Derived classes have to provide
//  the isGreater method for objects of their type
//  See interface I_Array
//  ============================================================

template <class T, size_t CAP>
class StaticIndex : private StaticArray<CRef<T>, CAP>
{
private:
    using BaseT = StaticArray<CRef<T>, CAP>;
public:
    inline StaticIndex(const I_Array<T, CAP>& a):
        mSrc(a)
    {}

    inline void reset()
    {
        BaseT::reset();
    }

    bool index()
    {
        BaseT::reset();
        for (size_t p = 0; p < mSrc.size(); ++p)
        {
            BaseT::newC(mSrc.ptr(p));
        }
        BaseT::sort();
        return BaseT::dupCnt() == 0;
    }
    
    inline bool isGreater(const CRef<T>& a, const CRef<T>& b) const
    {
        return isGreater(a.ref(), b.ref());
    }

    inline auto find(const T& obj) const
    {
        return BaseT::find(CRef<T>(obj));
    }

    inline const T& get(size_t pos) const
    {
        return BaseT::at(pos).ref();
    }

    inline const T& get(const PosRes& res) const
    {
        return get(res.pos);
    }

    NOCOPY(StaticIndex)
    NODEF(StaticIndex)

protected:
    const I_Array<T, CAP>& mSrc;
    virtual bool isGreater(const T& a, const T& b) const
    {
        return mSrc.isGreater(a, b);
    }

};
#endif // H_