//  ============================================================
//  communication telegram types
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef COMTYPES_H
#define COMTYPES_H

#include <codebase/BaseTypes.h>
#include <codebase/nocopy.h>
#include <codebase/Mem.h>

#include <codebase/packBegin.h>

//  Com telegrams element identifier
constexpr auto NumComNameChars = 9;
constexpr auto SU8 = sizeof(UINT8);

struct ComName
{
    CHAR chars[NumComNameChars];
    inline ComName()
    {
        Mem::set(chars);
    }
    inline ComName(const ComName& src)
    {
        Mem::cpy(chars, src.chars);
    }
    inline void operator=(const ComName& src)
    {
        Mem::cpy(chars, src.chars);
    }
};
static_assert(NumComNameChars == sizeof(ComName));

//  standard telegram size
constexpr auto STDTSIZE = NumComNameChars + 2 * SU8;

//  command to field
struct CmdFld
{
    ComName name;
    const UINT8 cmd1;
    const UINT8 cmd2;
    inline CmdFld(UINT8 cmd1 = 0, UINT8 cmd2 = 0):
        cmd1(cmd1),
        cmd2(cmd2)
    {}
    NOCOPY(CmdFld)
};
static_assert(STDTSIZE == sizeof(CmdFld));

//  state from field
struct FldState
{
    ComName name;
    const UINT8 state1;
    const UINT8 state2;
    inline FldState(UINT8 state1 = 0, UINT8 state2 = 0):
        state1(state1),
        state2(state2)
    {}
    NOCOPY(FldState)
};
static_assert(STDTSIZE == sizeof(FldState));

//  command from GUI
struct GuiCmd
{
    ComName name;
    const UINT8 cmd1;
    const UINT8 cmd2;
    inline GuiCmd(UINT8 cmd1 = 0, UINT8 cmd2 = 0):
        cmd1(cmd1),
        cmd2(cmd2)
    {}
    NOCOPY(GuiCmd)
};
static_assert(STDTSIZE == sizeof(GuiCmd));

//  state to GUI
struct StateGui
{
    ComName name;
    const UINT8 state1;
    const UINT8 state2;
    inline StateGui(UINT8 state1 = 0, UINT8 state2 = 0):
        state1(state1),
        state2(state2)
    {}
    NOCOPY(StateGui)
};
static_assert(STDTSIZE == sizeof(StateGui));

#include <codebase/packEnd.h>

#endif // H_