//  ============================================================
//  fixed size data container
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef STATICARRAY_H
#define STATICARRAY_H

#include <baselib/ByteArrays.h>
#include <baselib/SortAndSearch.h>

#include <new>

template <class T, UINT32 CAP>
class StaticArray : 
    public ByteArray
{
public:
    inline StaticArray():
        ByteArray(mBytes, CAP, sizeof(T)),
        mData(reinterpret_cast<T*>(mBytes))
    {}

    inline UINT32 size() const
    {
        return getSize();
    }

    // getters
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

    //  adders
    inline INT32 add(const T& obj)
    {
        return addBytes(&obj, sizeof(T));
    }

private:
    BYTE mBytes[sizeof(T) * CAP];
    T* mData;

    //  Standard 8.1.1
    StaticArray(const StaticArray& o);
    StaticArray& operator=(const StaticArray& o);
};

template <class T, UINT32 CAP>
class SearchableStaticArray : 
    public I_Searchable,
    public SearchableByteArray
{
public:
    inline SearchableStaticArray():
        SearchableByteArray(mBytes, CAP + 1, sizeof(T)),
        mData(reinterpret_cast<const T*>(mBytes))
    {}

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
    inline void sort()
    {
        bSort(*this);
    }

    inline void setSearch(const T& what) const
    {
        setSearchBytes(&what, sizeof(T));
    }

    inline UINT32 search(const T& what) const
    {
        setSearch(what);
        return bSearch(*this);
    }

    inline UINT32 getSearchPos() const
    {
        return getSearchBytePos();
    }

    // getters
    inline const T& at(UINT32 pos) const
    {
        return mData[pos];
    }
    inline const T& operator [](UINT32 pos) const
    {
        return mData[pos];
    }

    //  adders
    inline INT32 add(const T& obj)
    {
        return addBytes(&obj, sizeof(T));
    }

private:
    BYTE mBytes[sizeof(T) * (CAP + 1)];
    const T* mData;

    //  Standard 8.1.1
    SearchableStaticArray(const SearchableStaticArray& o);
    SearchableStaticArray& operator=(const SearchableStaticArray& o);
};


#endif // H_