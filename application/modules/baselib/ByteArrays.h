//  ============================================================
//  byte handling for fixed size data container
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef BYTEARRAYS_H
#define BYTEARRAYS_H

#include <baselib/BaseTypes.h> 

class ByteArray
{
public:
    PTR getPtr(UINT32 pos) const;
    PTR addPtr();
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

    bool addBytes(CPTR ptr, UINT32 bytes);
    UINT32 getSize() const;
    bool okPos(UINT32 posA, UINT32 posB) const;

    BYTE* const mBytes;
    const UINT32 mCap;
    const UINT32 mStep;
    UINT32 mSize;

    inline virtual bool isRef(const UINT32 pos) const
    {
        return false;
    }

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
    
    UINT32 getSearchBytePos() const; 
    void setSearchBytes(CPTR ptr, UINT32 bytes) const;

    inline bool isRef(const UINT32 pos) const
    {
        return mCap == pos;
    }

private:
    //  Standard 8.1.1
    ByteArrayMappable();
    ByteArrayMappable(const ByteArrayMappable& o);
    ByteArrayMappable& operator=(const ByteArrayMappable& o);
};


#endif // H_