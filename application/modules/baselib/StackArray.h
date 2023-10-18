#pragma once
#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <baselib/I_Searchable.h>
#include <baselib/Baselib.h>
#include <baselib/Mem.h>

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

    inline UINT32 size() const
    {
        return mSize;
    }

    inline bool isFull() const
    {
        return mSize >= CAP;
    }

    inline void add(const T& obj)
    {
        Mem::copy(at(mSize), obj);
        ++mSize;
        // TODO at(mSize++)
    }

    inline PTR getPtr(UINT32 pos)
    {
        return mBytes + sizeof(T) * pos;
    }

    inline CPTR getPtr(UINT32 pos) const
    {
        return mBytes + sizeof(T) * pos;
    }

    inline PTR addPtr(UINT32 pos) 
    {
        ++mSize;
        return getPtr(mSize - 1);
        // TODO return getPtr(mSize++);
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


    // void bSort()
    // {
    //     for (UINT32 n = mSize; n > 0; --n)
    //     {
    //         bool swapped = false;
    //         for (UINT32 p = 0; p < n - 1; ++p)
    //         {
    //             if (isGreater(at(p), at(p + 1)))
    //             {
    //                 swap(p, p + 1);
    //                 swapped = true;
    //             }
    //         }
    //         if (not swapped)
    //         {
    //             break;
    //         }
    //     }
    // }

    // INT32 bSearch(const T& obj) const
    // {
    //     INT32 pMin = 0;
    //     INT32 pMax = mSize - 1;
    //     INT32 res = -1;

    //     while (pMax >= pMin)
    //     {
    //         const INT32 pCur = (pMin + pMax + 1) / 2;
    //         if (isGreater(obj, at(pCur)))
    //         {
    //             pMin = pCur + 1;
    //         }
    //         else if (isGreater(at(pCur), obj))
    //         {
    //             pMax = pCur - 1;
    //         }
    //         else
    //         {
    //             res = pCur;
    //             break;
    //         }
    //     }
    //     return res;
    // }

    //  Standard 8.1.1
    StackArray(const StackArray& o);
    StackArray& operator=(const StackArray& o);
};

#endif // H_