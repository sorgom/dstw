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

//  state from field
struct FldState
{
    ElementName name;
    INT32 state1;
    INT32 state2;
};

//  command from GUI
struct GuiCmd
{
    ElementName name;
    INT32 cmd1;
    INT32 cmd2;
};

//  state to GUI
struct StateGui
{
    ElementName name;
    INT32 state1;
    INT32 state2;
};

#include <BAS/packEnd.h>

#endif // H_