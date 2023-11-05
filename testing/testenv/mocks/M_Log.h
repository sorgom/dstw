//  ============================================================
//  mock for interface Log
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef M_LOGGER_H
#define M_LOGGER_H

#include <ifs/I_Log.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(Log)
    {
    public:
        MOCK_CON(Log)

        inline void log(E_Mod mod, E_Err err)
        {
            call("log").PARAM(mod).PARAM(err);
        }
        inline void expectLog(E_Mod mod, E_Err err) const
        {
            expect("log").PARAM(mod).PARAM(err);
        }
    };
} 

#endif // H_