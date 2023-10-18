#pragma once
#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <baselib/I_Searchable.h>
#include <baselib/Baselib.h>
#include <baselib/Mem.h>

#include <new>

template <class T, UINT32 CAP>
class StackArray : public I_Searchable<T>
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

    inline bool isFull() const
    {
        return mSize >= CAP;
    }

    inline UINT32 add(const T& obj)
    {
        Mem::copy(at(mSize), obj);
        return mSize++;
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
    inline const T& operator [](UINT32 pos) const
    {
        return mData[pos];
    }
    inline T& operator [](UINT32 pos)
    {
        return mData[pos];
    }

    inline void sort()
    {
        bSort(*this);
    }

    inline INT32 find(const T& obj) const
    {
        return bSearch(*this, obj);
    }

    inline void swap(UINT32 posA, UINT32 posB)
    {
        swapBytes(getPtr(posA), getPtr(posB), mSwap, sizeof(T));
    }

private:
    BYTE mBytes[sizeof(T) * CAP];
    BYTE mSwap[sizeof(T)];
    T* mData;
    UINT32 mSize;

    //  Standard 8.1.1
    StackArray(const StackArray& o);
    StackArray& operator=(const StackArray& o);
};

template <class T, UINT32 CAP>
class StackArrayIndex : public StackArray<Ref<T>, CAP>
{
public:
    inline StackArrayIndex(const StackArray<T, CAP>& a):
        mArray(a)
    {}

    inline bool isGreater(const Ref<T>& a, const Ref<T>& b) const
    {
        return mArray.isGreater(a.ref(), b.ref());
    }

    void adapt()
    {
        this->reset();
        for (UINT32 p = 0; p < mArray.size(); ++p)
        {
            new (this->addPtr()) Ref<T>(mArray[p]);
        }
        this->sort();
    }

    inline INT32 findRef(const T& obj) const
    {
        return this->find(Ref<T>(obj));
    }

    inline const T& getRef(UINT32 pos) const
    {
        return this->at(pos).ref();
    }

private:
    const StackArray<T, CAP>& mArray;
    //  Standard 8.1.1
    StackArrayIndex();
    StackArrayIndex(const StackArrayIndex& o);
    StackArrayIndex& operator=(const StackArrayIndex& o);
};

#endif // H_