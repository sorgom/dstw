//  ============================================================
//  container collection
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <BAS/coding.h>
#include <ifs/PosRes.h>

#include <memory>
#include <type_traits>
#include <utility>
#include <vector>
#include <algorithm>


//  ============================================================
//  class PolyVec allows to store polymorphic objects
//  derived from interface class IF
//  ============================================================
template <typename IF>
class PolyVec 
{
public:
    template <typename T, typename... Args>
    void add(Args&&... args) 
    {
        static_assert(std::is_base_of<IF, T>::value);
        mData.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

    size_t size() const { return mData.size(); }

    const IF& at(size_t pos) const { return *mData.at(pos); }

    IF& at(size_t pos) { return *mData.at(pos); }

    inline void clear() { mData.clear(); }

    //  reserve memory for size objects
    //  returns the new capacity
    size_t reserve(size_t size) { 
        mData.reserve(size); 
        return mData.capacity(); 
    }

private:
    std::vector<std::unique_ptr<IF>> mData;    
};

//  ============================================================
//  class Index allows to 
//  - store const CONT objects with KEY type member
//    in the order that the were added
//  - index and find objects by KEY type
//  requires operator > (KEY a, KEY b) to be defined
//  ============================================================
template <typename KEY, typename CONT>
class Index
{
protected:
    //  get key type from container type
    virtual KEY getKey(const CONT&) const = 0;

public:
    void clear()
    {
        mData.clear();
        mIdx.clear();
    }

    inline size_t size() const
    {
        return mData.size();
    }

    size_t reserve(size_t size)
    {
        mData.reserve(size);
        mIdx.reserve(size);
        return std::min(mData.capacity(), mIdx.capacity());
    }

    //  get data by storage position
    inline const CONT& at(size_t pos) const
    {
        return *mData.at(pos);
    }

    //  get data by search result (i.e. index) position
    inline const CONT& at(const PosRes& res) const
    {
        return *mIdx.at(res.pos);
    }

    template <typename... Args>
    void add(Args&&... args)
    {
        mData.emplace_back(std::make_unique<const CONT>(std::forward<Args>(args)...));
    }

    //  index data by key after storage finished
    //  returns false if duplicates found
    //  but finishes anyway
    bool index()
    {
        mIdx.clear();
        for (const auto& p : mData)
        {
            mIdx.push_back(p.get());
        }
        sort();
        return dupCnt() == 0;
    }
    //  find data by key
    //  requires that index() has been called once before
    const PosRes find(KEY key) const
    {
        bool found = false;
        size_t pos = 0;
        int left = 0;
        int right = mIdx.size() - 1;
        while ((left <= right) and (not found))
        {
            const int mid = left + (right - left) / 2;
            const KEY km = getKey(*mIdx[mid]);
            if (key > km)
            {
                left = mid + 1;
            }
            else if (km > key)
            {
                right = mid - 1;
            }
            else
            {
                found = true;
                pos = mid;
            }
        }
        return PosRes{pos, found};
    }
private:
    //  data storage
    //  unique_ptr enables to store const objects that cannot be copied
    std::vector<std::unique_ptr<const CONT>> mData;
    //  index storage
    std::vector<const CONT*> mIdx;

    inline bool gt(size_t a, size_t b) const
    {
        return getKey(*mIdx[a]) > getKey(*mIdx[b]);
    }

    void sort()
    {
        bool swapped = true;
        for (size_t n = mIdx.size(); swapped and n > 1; --n)
        {
            swapped = false;
            for (size_t a = 0, b = 1; b < n; ++a, ++b)
            {
                if (gt(a, b))
                {
                    const CONT* t = mIdx[a];
                    mIdx[a] = mIdx[b];
                    mIdx[b] = t;
                    swapped = true;
                }
            }
        }
    }
    size_t dupCnt()
    {
        size_t dups = 0;
        for (size_t a = 0, b = 1; b < mIdx.size(); ++a, ++b)
        {
        	if (not gt(b, a))
            {
                ++dups;
            }
        }
        return dups;
    }
};

#endif // _H