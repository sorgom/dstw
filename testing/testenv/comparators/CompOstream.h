//  ============================================================
//  string collector for comparator output
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef COMPOSTREAM_H
#define COMPOSTREAM_H

#include <baselib/InstanceMacros.h>
#include <sstream>

namespace test
{
    class CompOstream
    {
    public:
        std::ostream& begin();
        inline const std::ostringstream& get() const
        {
            return mStream;
        }
        
        INSTANCE_DEC(CompOstream)

    private:
        std::ostringstream mStream;
    };

}


#endif // H_