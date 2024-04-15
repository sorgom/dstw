//  ============================================================
//  unified proj data item
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef PROJITEM_H
#define PROJITEM_H

#include "ComTypes.h"

#include <codebase/packBegin.h>

struct ProjItem
{
    ComName name;
    UINT8 type;
};

#include <codebase/packEnd.h>

#endif // H_