#pragma once
#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <BAS/coding.h>
#include <ifs/PosRes.h>

#include <memory>
#include <type_traits>
#include <utility>
#include <vector>

template <typename IF>
class PolyVec 
{
public:
    template <typename T, typename... Args>
    void add(Args&&... args) 
    {
        static_assert(std::is_base_of<IF, T>::value);
        mData.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

    template <typename T>
    PolyVec operator <<(T&& elem) 
    {
        static_assert(std::is_base_of<IF, T>::value);
        mData.push_back(std::make_unique<T>(elem));
        return *this;
    }

    size_t size() const { return mData.size(); }

    const IF& at(size_t index) const { return *mData.at(index); }

    IF& at(size_t index) { return *mData.at(index); }

    inline void clear() { mData.clear(); }

protected:    
    inline const std::vector<std::unique_ptr<IF>>& data() const { return mData; }
private:
    std::vector<std::unique_ptr<IF>> mData;    
};

template <typename KEY, typename CONT>
class Index
{
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

    //  get data by data position
    inline const CONT& at(size_t pos) const
    {
        return mData[pos];
    }

    //  get data by search result
    inline const CONT& at(const PosRes& res) const
    {
        return *mIdx[res.pos];
    }

    void add(const CONT&& cont)
    {
        mData.push_back(std::move(cont));
    }
    Index& operator <<(const CONT&& cont)
    {
        add(std::move(cont));
        return *this;
    }

    bool index()
    {
        mIdx.clear();
        for (const CONT& cont : mData)
        {
            mIdx.push_back(&cont);
        }
        sort();
        return dupCnt() == 0;
    }
    PosRes find(const KEY& key) const
    {
        bool valid = false;
        size_t pos = 0;
        int left = 0;
        int right = mIdx.size() - 1;
        while ((left <= right) and (not valid))
        {
            const int mid = left + (right - left) / 2;

            if (greater(key, getKey(*mIdx[mid])))
            {
                left = mid + 1;
            }
            else if (greater(getKey(*mIdx[mid]), key))
            {
                right = mid - 1;
            }
            else
            {
                valid = true;
                pos = mid;
            }
        }
        return PosRes{pos, valid};
    }
protected:
    //  definition key a is greater than key b
    virtual bool greater(const KEY& a, const KEY& b) const = 0;
    //  get key type from container type
    virtual const KEY& getKey(const CONT&) const = 0;
private:
    std::vector<CONT> mData;
    std::vector<const CONT*> mIdx;

    inline bool gt(size_t a, size_t b) const
    {
        return greater(getKey(*mIdx[a]), getKey(*mIdx[b]));
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