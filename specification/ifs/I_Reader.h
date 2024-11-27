//  ============================================================
//  interface Reader
//  the Reader is called at system start and shall:
//  -   clear I_Dispatcher
//  -   read proj data from binary file
//  -   distribute load to subsystems
//  -   call indexing of I_Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#ifndef I_READER_H
#define I_READER_H

#include <codebase/BaseTypes.h>
#include <ifs/DataTypes.h>
class I_Reader
{
public:
    virtual void read(CONST_C_STRING filename) = 0;
    virtual const ComSetup& getComSetup() const = 0;
};
#endif // _H
