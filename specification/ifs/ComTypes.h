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
constexpr auto ComNameSize = 9;

struct ComName
{
    CHAR chars[ComNameSize];
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
static_assert(ComNameSize == sizeof(ComName));

//  standard telegram size
constexpr auto ComTelegramSize = ComNameSize + 2;

//  command to field
struct ComCmdFld
{
    ComName name;
    const UINT8 cmd1;
    const UINT8 cmd2;
    inline ComCmdFld(UINT8 cmd1 = 0, UINT8 cmd2 = 0):
        cmd1(cmd1),
        cmd2(cmd2)
    {}
    NOCOPY(ComCmdFld)
};
static_assert(ComTelegramSize == sizeof(ComCmdFld));

//  state from field
struct ComFldState
{
    ComName name;
    const UINT8 state1;
    const UINT8 state2;
    inline ComFldState(UINT8 state1 = 0, UINT8 state2 = 0):
        state1(state1),
        state2(state2)
    {}
    NOCOPY(ComFldState)
};
static_assert(ComTelegramSize == sizeof(ComFldState));

//  command from GUI
struct ComGuiCmd
{
    ComName name;
    const UINT8 cmd1;
    const UINT8 cmd2;
    inline ComGuiCmd(UINT8 cmd1 = 0, UINT8 cmd2 = 0):
        cmd1(cmd1),
        cmd2(cmd2)
    {}
    NOCOPY(ComGuiCmd)
};
static_assert(ComTelegramSize == sizeof(ComGuiCmd));

//  state to GUI
struct ComStateGui
{
    ComName name;
    const UINT8 state1;
    const UINT8 state2;
    inline ComStateGui(UINT8 state1 = 0, UINT8 state2 = 0):
        state1(state1),
        state2(state2)
    {}
    NOCOPY(ComStateGui)
};
static_assert(ComTelegramSize == sizeof(ComStateGui));

#include <codebase/packEnd.h>

#endif // H_