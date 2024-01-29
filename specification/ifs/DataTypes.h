//  ============================================================
//  definiton of complex data types
//  - mainly communication telegrams
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef DATATYPES_H
#define DATATYPES_H

#include <BAS/BaseTypes.h>
#include <ifs/ProjData.h>

#include <BAS/packBegin.h>

//  command to field
struct CmdFld
{
    ElementName name;
    INT32 cmd1;
    INT32 cmd2;
};
static_assert(17 == sizeof(CmdFld));

//  state from field
struct FldState
{
    ElementName name;
    INT32 state1;
    INT32 state2;
};
static_assert(17 == sizeof(FldState));

//  command from GUI
struct GuiCmd
{
    ElementName name;
    INT32 cmd1;
    INT32 cmd2;
};
static_assert(17 == sizeof(GuiCmd));

//  state to GUI
struct StateGui
{
    ElementName name;
    INT32 state1;
    INT32 state2;
};
static_assert(17 == sizeof(StateGui));

#include <BAS/packEnd.h>

#endif // H_