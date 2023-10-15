//  ============================================================
//  fixed size data container
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef STATICARRAY_H
#define STATICARRAY_H

#include <baselib/BaseTypes.h> 
#include <baselib/SortAndMap.h>

#include <new>

class ByteArray
{
public:
    PTR getPtr(UINT32 pos) const;
    PTR addPtr();
    bool addBytes(CPTR ptr, UINT32 bytes);
    void reset();

protected:
    inline ByteArray(
        BYTE* const bytes,
        const UINT32 cap,
        const UINT32 step
    ):
        mBytes(bytes),
        mCap(cap),
        mStep(step),
        mSize(0)
    {}

    UINT32 getSize() const;
    bool okPos(UINT32 posA, UINT32 posB) const;

    BYTE* const mBytes;
    const UINT32 mCap;
    const UINT32 mStep;
    UINT32 mSize;

    inline void pass() const {}

private:
    //  Standard 8.1.1
    ByteArray();
    ByteArray(const ByteArray& o);
    ByteArray& operator=(const ByteArray& o);
};

class ByteArrayMappable : public ByteArray
{
protected:
    inline ByteArrayMappable(
        BYTE* const bytes,
        const UINT32 cap,
        const UINT32 step
    ):
        ByteArray(bytes, cap - 1, step)
    {}

    void swappBytes(UINT32 posA, UINT32 posB) const;
    void setSearchBytes(CPTR ptr, UINT32 bytes);
    UINT32 getSearchBytePos() const; 

private:
    //  Standard 8.1.1
    ByteArrayMappable();
    ByteArrayMappable(const ByteArrayMappable& o);
    ByteArrayMappable& operator=(const ByteArrayMappable& o);
};

template <class T, UINT32 CAP>
class StaticArray : 
    public I_Mapable,
    private ByteArray
{
public:
    inline StaticArray():
        ByteArray(mBytes, CAP, sizeof(T))
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

    inline virtual bool isGreater(UINT32 posA, UINT32 posB) const
    {
        return isGreaterBytes(posA, posB);
    }

    inline virtual void swap(UINT32 posA, UINT32 posB)
    {
        swappBytes(posA, posB);
    }
    //  I_Mapable
    inline virtual bool isEqual(UINT32 posA, UINT32 posB) const
    {
        return isEqualBytes(posA, posB);
    }

    //  search initialization
    inline void setSearch(const T& what)
    {
        setSearchBytes(&what, sizeof(T));
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
    StaticArray(const StaticArray& o);
    StaticArray& operator=(const StaticArray& o);
};



#endif // H_