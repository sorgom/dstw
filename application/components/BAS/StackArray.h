//  ============================================================
//  the core of static memory allocation
//  StackArrays
//  -   act like arrays of pre-defined size
//  -   can be filled with objects at runtime
//  -   do not provide any overflow protection
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <BAS/I_Array.h>
#include <BAS/coding.h>
#include <BAS/Mem.h>

//  ============================================================
//  StackArray
//  keeps objects in the same order as they were added.
//  ============================================================
template <class T, UINT32 CAP>
class StackArray : public I_Array<T>
{
public:
    inline StackArray():
        mData(reinterpret_cast<T*>(mBytes)),
        mSize(0)
    {}

    inline static UINT32 capacity()
    {
        return CAP;
    }

    inline void reset()
    {
        mSize = 0;
    }

    inline UINT32 size() const
    {
        return mSize;
    }

    inline bool hasSpace() const
    {
        return mSize < CAP;
    }

    inline bool has(UINT32 pos) const
    {
        return pos < mSize;
    }

    inline UINT32 add(const T& obj)
    {
        Mem::cpy(at(mSize), obj);
        return mSize++;
    }

    inline const T* data() const
    {
        return mData;
    }

    inline const T& at(UINT32 pos) const
    {
        return mData[pos];
    }

    inline T& at(UINT32 pos)
    {
        return mData[pos];
    }

protected:
    inline PTR getPtr(UINT32 pos)
    {
        return mData + pos;
    }

private:
    BYTE mBytes[sizeof(T) * CAP];
    T* mData;
    UINT32 mSize;

    NOCOPY(StackArray)
};

//  provides static byte swapping for template based classes
class SwapBytes
{
protected:
    static void swapBytes(PTR pA, PTR pB, PTR pS, UINT32 size);
};

//  ============================================================
//  SortableStackArray
//  -   can be sorted
//  -   can search for elements
//  Derived classes have to provide
//  the isGreater method for objects of their type
//  See interface I_Array
//  ============================================================
template <class T, UINT32 CAP>
class SortableStackArray : 
    public StackArray<T, CAP>,
    private SwapBytes
{
public:
    inline SortableStackArray()
    {}

    inline void sort()
    {
        bSort(*this);
    }

    inline INT32 find(const T& obj) const
    {
        return bSearch(*this, obj);
    }

    inline UINT32 dupCnt() const
    {
        return ::dupCnt(*this);
    }

    inline void swap(UINT32 posA, UINT32 posB)
    {
        swapBytes(this->getPtr(posA), this->getPtr(posB), mSwap, sizeof(T));
    }

private:
    BYTE mSwap[sizeof(T)];

    NOCOPY(SortableStackArray)
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
        mRef(obj)
    {}
    inline const T& ref() const
    {
        return mRef;
    }
private:
    const T& mRef;

    NOCOPY(CRef)
    CRef();
};

//  ============================================================
//  StackArrayIndex
//  provides search for unsorted StackArray.
//  Derived classes have to provide
//  the isGreater method for objects of their type
//  See interface I_Array
//  ============================================================

template <class T, UINT32 CAP>
class StackArrayIndex : private SortableStackArray<CRef<T>, CAP>
{
public:
    inline StackArrayIndex(const StackArray<T, CAP>& a):
        mArray(a)
    {}

    inline void reset()
    {
        SortableStackArray<CRef<T>, CAP>::reset();
    }

    bool index()
    {
        this->reset();
        for (UINT32 p = 0; p < mArray.size(); ++p)
        {
            this->add(CRef<T>(mArray.at(p)));
        }
        this->sort();
        return this->dupCnt() == 0;
    }
    
    inline bool isGreater(const CRef<T>& a, const CRef<T>& b) const
    {
        return isGreater(a.ref(), b.ref());
    }

    inline INT32 findRef(const T& obj) const
    {
        return this->find(CRef<T>(obj));
    }

    inline const T& getRef(UINT32 pos) const
    {
        return this->at(pos).ref();
    }

protected:
    virtual bool isGreater(const T& a, const T& b) const = 0;

private:
    const StackArray<T, CAP>& mArray;

    NOCOPY(StackArrayIndex)
    StackArrayIndex();
};

#endif // H_