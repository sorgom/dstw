//  ============================================================
//  fixed size data container
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef STATICARRAY_H
#define STATICARRAY_H

#include <baselib/ByteArrays.h>
#include <baselib/SortAndMap.h>

#include <new>

template <class T, UINT32 CAP>
class StaticArray : 
    public ByteArray
{
public:
    inline StaticArray():
        ByteArray(mBytes, CAP, sizeof(T))
    {}

    inline static UINT32 capacity()
    {
        return CAP;
    }

    inline UINT32 size() const
    {
        return getSize();
    }

    // getters
    inline const T& at(UINT32 pos) const
    {
        return *reinterpret_cast<const T*>(getPtr(pos));
    }
    inline T& at(UINT32 pos)
    {
        return *reinterpret_cast<T*>(getPtr(pos));
    }
    inline const T& operator [](UINT32 pos) const
    {
        return at(pos);
    }
    inline T& operator [](UINT32 pos)
    {
        return at(pos);
    }

    //  adders
    inline bool add(const T& obj)
    {
        return addBytes(&obj, sizeof(T));
    }


private:
    BYTE mBytes[sizeof(T) * CAP];

    //  Standard 8.1.1
    StaticArray(const StaticArray& o);
    StaticArray& operator=(const StaticArray& o);
};

template <class T, UINT32 CAP>
class StaticArrayMappable : 
    public I_Mapable,
    public ByteArrayMappable
{
public:
    inline StaticArrayMappable():
        ByteArrayMappable(mBytes, CAP + 1, sizeof(T))
    {}

    inline static UINT32 capacity()
    {
        return CAP;
    }

    //  I_Sortable
    inline UINT32 size() const
    {
        return getSize();
    }

    inline void swap(UINT32 posA, UINT32 posB)
    {
        swappBytes(posA, posB);
    }

    //  the search
    inline UINT32 search(const T& what) const
    {
        setSearchBytes(&what, sizeof(T));
        return bSearch(*this);
    }

    inline UINT32 getSearchPos() const
    {
        return getSearchBytePos();
    }

    // getters
    inline const T& at(UINT32 pos) const
    {
        return *reinterpret_cast<const T*>(getPtr(pos));
    }
    inline T& at(UINT32 pos)
    {
        return *reinterpret_cast<T*>(getPtr(pos));
    }
    inline const T& operator [](UINT32 pos) const
    {
        return at(pos);
    }
    inline T& operator [](UINT32 pos)
    {
        return at(pos);
    }

    //  adders
    inline bool add(const T& obj)
    {
        return addBytes(&obj, sizeof(T));
    }

private:
    BYTE mBytes[sizeof(T) * (CAP + 1)];

    //  Standard 8.1.1
    StaticArrayMappable(const StaticArrayMappable& o);
    StaticArrayMappable& operator=(const StaticArrayMappable& o);
};


#endif // H_