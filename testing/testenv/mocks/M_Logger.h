//  ============================================================
//  mock for interface Logger
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef M_LOGGER_H
#define M_LOGGER_H

#include <ifs/I_Logger.h>
#include "M_Base.h"

namespace test
{
    MOCK_CLASS(Logger)
    {
    public:
        MOCK_CON(Logger)

        inline void log(E_Comp comp, E_Err err)
        {
            call("log").PARAM(comp).PARAM(err);
        }
        inline void expectLog(E_Comp comp, E_Err err) const
        {
            expect("log").PARAM(comp).PARAM(err);
        }
    };
} 

#endif // H_