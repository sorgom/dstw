//  ============================================================
//  communication telegrams types
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef COMTYPES_H
#define COMTYPES_H

#include <BAS/BaseTypes.h>
#include <BAS/coding.h>
#include <BAS/Mem.h>

#include <BAS/packBegin.h>

//  Com telegrams element identifier
constexpr auto NumComNameChars = 9;
constexpr auto SI32 = sizeof(INT32);

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
constexpr auto STDTSIZE = NumComNameChars + 2 * SI32;

//  command to field
struct CmdFld
{
    ComName name;
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
    ComName name;
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
    ComName name;
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
    ComName name;
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