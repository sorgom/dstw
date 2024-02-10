//  ============================================================
//  the core of static memory allocation
//  StaticArrays
//  -   act like arrays of pre-defined size
//  -   can be filled with objects at runtime
//  -   can store objects of different size classes
//      derived from main class
//  -   do not provide any overflow protection
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef STATICARRAY_H
#define STATICARRAY_H

#include <BAS/I_Array.h>
#include <codebase/Mem.h>
#include <BAS/SwapBytes.h>
#include <algorithm>
#include <new>
#include <type_traits>

//  ============================================================
//  InterfaceArray
//  -   stores objects that implement an interface class
//  -   keeps objects in the same order as they were added
//  -   provides const and non const object access
//  ============================================================
template <class IC, size_t CAP, class ... DCS>
class InterfaceArray final : 
    public I_Array<IC, CAP>
{
public:
    inline InterfaceArray():
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

    //  add an object of derived class
    template <class DC, typename ... ARGS>
    size_t add(const ARGS& ... args)
    {
        static_assert(std::is_base_of_v<IC, DC>);
        static_assert(not std::is_same_v<IC, DC>);
        static_assert(sizeof(DC) <= DIM);
        new (mData[mSize]) DC(args...);
        return mSize++;
    }

    inline IC& at(size_t pos)
    {
        return *reinterpret_cast<IC*>(mData[pos]);
    }

    inline const IC& at(size_t pos) const
    {
        return *reinterpret_cast<const IC*>(mData[pos]);
    }

    NOCOPY(InterfaceArray)

private:
    constexpr static auto DIM = std::max({sizeof(IC), sizeof(DCS)...});
    using Segment = BYTE[DIM];
    Segment mData[CAP];
    size_t mSize;
};

//  ============================================================
//  ConstArray
//  - keeps objects in the same order as they were added
//  - stores objects of one class
//  - provides const object access only
//  ============================================================
template <class C, size_t CAP, class ... SCS>
class ConstArray final : 
    public I_Array<C, CAP>
{
public:
    inline ConstArray():
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

    inline size_t bytes() const
    {
        return mSize * DIM;
    }

    template <typename ... ARGS>
    size_t add(const ARGS& ... args)
    {
        new (mData[mSize]) C(args...);
        return mSize++;
    }

    inline const C& at(size_t pos) const
    {
        return *reinterpret_cast<const C*>(mData[pos]);
    }

    inline const C* data() const
    {
        return reinterpret_cast<const C*>(mData);
    } 

    NOCOPY(ConstArray)

private:
    constexpr static auto DIM = sizeof(C);
    using Segment = BYTE[DIM];
    Segment mData[CAP];
    size_t mSize;
};


//  ============================================================
//  MutableArray
//  - keeps objects in the same order as they were added
//  - stores objects of one class
//  - provides const and mutable object access
//  ============================================================
template <class C, size_t CAP, class ... SCS>
class MutableArray final : 
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

    inline size_t size() const
    {
        return mSize;
    }

    inline size_t bytes() const
    {
        return mSize * DIM;
    }

    template <typename ... ARGS>
    size_t add(const ARGS& ... args)
    {
        new (mData[mSize]) C(args...);
        return mSize++;
    }

    inline const C& at(size_t pos) const
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
//  ConstArrayIndex
//  provides search for unsorted ConstArray
//  ============================================================

template <class T, size_t CAP>
class ConstArrayIndex : private StaticArray<CRef<T>, CAP>
{
private:
    using BaseT = StaticArray<CRef<T>, CAP>;
public:
    inline ConstArrayIndex(const I_Array<T, CAP>& a):
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
            BaseT::add(mSrc.at(p));
        }
        BaseT::sort();
        return BaseT::dupCnt() == 0;
    }
    
    inline bool isGreater(const CRef<T>& a, const CRef<T>& b) const
    {
        return isGreater(a.ref(), b.ref());
    }

    inline PosRes find(const T& obj) const
    {
        return BaseT::find(CRef<T>(obj));
    }

    inline const T& get(const PosRes& res) const
    {
        return BaseT::at(res).ref();
    }

    NOCOPY(ConstArrayIndex)
    NODEF(ConstArrayIndex)

protected:
    virtual bool isGreater(const T& a, const T& b) const
    {
        return mSrc.isGreater(a, b);
    }
private:
    const I_Array<T, CAP>& mSrc;
};
#endif // H_