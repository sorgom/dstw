//  ============================================================
//  interface Reader
//  the Reader is called at system start and shall:
//  -   reset I_Dispatcher
//  -   read proj data from binary file
//  -   distribute load to subsystems
//  -   call indexing of I_Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef I_READER_H
#define I_READER_H

#include <BAS/BaseTypes.h>

class I_Reader
{
public:
    virtual void read(CONST_C_STRING filename) const = 0;
};

#endif // H_