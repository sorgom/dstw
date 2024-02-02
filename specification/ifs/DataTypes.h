//  ============================================================
//  definiton of complex data types
//  - mainly communication telegrams
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef DATATYPES_H
#define DATATYPES_H

#include <BAS/BaseTypes.h>
#include <BAS/coding.h>
#include <ifs/ProjData.h>

#include <BAS/packBegin.h>

//  standard telegram size
constexpr auto STDTSIZE = NumElementNameChars + 2 * SI32;

//  command to field
struct CmdFld
{
    ElementName name;
    const INT32 cmd1;
    const INT32 cmd2;
    inline CmdFld(INT32 cmd1 = 0, INT32 cmd2 = 0):
        cmd1(cmd1),
        cmd2(cmd2)
    {}
    NOCOPY(CmdFld)
};
static_assert(STDTSIZE == sizeof(CmdFld));

//  state from field
struct FldState
{
    ElementName name;
    const INT32 state1;
    const INT32 state2;
    inline FldState(INT32 state1 = 0, INT32 state2 = 0):
        state1(state1),
        state2(state2)
    {}
    NOCOPY(FldState)
};
static_assert(STDTSIZE == sizeof(FldState));

//  command from GUI
struct GuiCmd
{
    ElementName name;
    const INT32 cmd1;
    const INT32 cmd2;
    inline GuiCmd(INT32 cmd1 = 0, INT32 cmd2 = 0):
        cmd1(cmd1),
        cmd2(cmd2)
    {}
    NOCOPY(GuiCmd)
};
static_assert(STDTSIZE == sizeof(GuiCmd));

//  state to GUI
struct StateGui
{
    ElementName name;
    const INT32 state1;
    const INT32 state2;
    inline StateGui(INT32 state1 = 0, INT32 state2 = 0):
        state1(state1),
        state2(state2)
    {}
    NOCOPY(StateGui)
};
static_assert(STDTSIZE == sizeof(StateGui));

#include <BAS/packEnd.h>

#endif // H_