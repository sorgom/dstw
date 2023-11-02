#pragma once
#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <baselib/I_Searchable.h>
#include <baselib/coding.h>
#include <baselib/Mem.h>


template <class T, UINT32 CAP>
class BaseStackArray : public I_Searchable<T>
{
public:
    inline BaseStackArray():
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

    inline const T* getData() const
    {
        return mData;
    }

    inline PTR getPtr(UINT32 pos)
    {
        return mBytes + sizeof(T) * pos;
    }

    inline CPTR getPtr(UINT32 pos) const
    {
        return mBytes + sizeof(T) * pos;
    }

    inline PTR addPtr() 
    {
        return getPtr(mSize++);
    }

    inline const T& at(UINT32 pos) const
    {
        return mData[pos];
    }

    inline T& at(UINT32 pos)
    {
        return mData[pos];
    }

private:
    BYTE mBytes[sizeof(T) * CAP];
    T* mData;
    UINT32 mSize;

    NOCOPY(BaseStackArray)
};

class SwapBytes
{
protected:
    static void swapBytes(PTR pA, PTR pB, PTR pS, UINT32 size);
};

template <class T, UINT32 CAP>
class StackArray : 
    public BaseStackArray<T, CAP>,
    private SwapBytes
{
public:
    inline StackArray()
    {}

    inline void sort()
    {
        bSort(*this);
    }

    inline UINT32 dupCnt() const
    {
        return dupCnt(*this);
    }

    inline INT32 find(const T& obj) const
    {
        return bSearch(*this, obj);
    }

    inline void swap(UINT32 posA, UINT32 posB)
    {
        swapBytes(this->getPtr(posA), this->getPtr(posB), mSwap, sizeof(T));
    }

private:
    BYTE mSwap[sizeof(T)];

    NOCOPY(StackArray)
};

template <class T, UINT32 CAP>
class SimpleStackArray : public BaseStackArray<T, CAP>
{
public:
    inline SimpleStackArray()
    {}
    
    inline bool isGreater(const T& a, const T& b) const
    {
        return false;
    }

    inline void swap(UINT32 posA, UINT32 posB) {}

    NOCOPY(SimpleStackArray)
};

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
private:
    const T* mPtr;

    NOCOPY(CRef)
    CRef();
};

template <class T, UINT32 CAP>
class StackArrayIndex : public StackArray<CRef<T>, CAP>
{
public:
    inline StackArrayIndex(const SimpleStackArray<T, CAP>& a):
        mArray(a)
    {}

    void adapt()
    {
        this->reset();
        for (UINT32 p = 0; p < mArray.size(); ++p)
        {
            this->add(CRef<T>(mArray.at(p)));
        }
        this->sort();
    }

    inline INT32 findRef(const T& obj) const
    {
        return this->find(CRef<T>(obj));
    }

    inline const T& getRef(UINT32 pos) const
    {
        return this->at(pos).ref();
    }

private:
    const SimpleStackArray<T, CAP>& mArray;

    NOCOPY(StackArrayIndex)
    StackArrayIndex();
};

#endif // H_