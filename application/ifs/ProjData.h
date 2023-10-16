//  ============================================================
//  projectation data types
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef PROJDATA_H
#define PROJDATA_H

#include <baselib/BaseTypes.h>


#include <baselib/packBegin.h>

struct ElementName
{
    CHAR name[16];
};

struct TrackSwitchProj
{
    ElementName name;
};

#include <baselib/packEnd.h>



#endif // H_