//  ============================================================
//  sort and map using
//  - bubble sort
//  - b-tree search
//  ============================================================
//  see https://de.wikipedia.org/wiki/Bubblesort
//  created by Manfred Sorgo

#pragma once
#ifndef SORTANDSEARCH_H
#define SORTANDSEARCH_H

#include <baselib/BaseTypes.h> 

class I_Sortable
{
public:
    //  retrieve number of elements
    virtual UINT32 size() const = 0;

    //  element at position A is greater than element at position B
    virtual bool isGreater(UINT32 posA, UINT32 posB) const = 0;
    
    //  swap element at position A with element at position B
    virtual void swap(UINT32 posA, UINT32 posB) = 0;
};

class I_Searchable : public I_Sortable
{
public:
    //  element at position A is equal to element at position B
    virtual bool isEqual(UINT32 posA, UINT32 posB) const = 0;

    //  position of element to search for
    virtual UINT32 getSearchPos() const = 0;
};

//  apply bubble sort to sortable
void bSort(I_Sortable& obj);

INT32 bSearch(const I_Searchable& obj);

#endif // H_