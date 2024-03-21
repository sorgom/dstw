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
        inline E_Err maxerr() const
        {
            return static_cast<E_Err>(call("maxerr").RETURN_DEF_UNSIGNED(NO_ERR));
        }
        inline void expectMaxerr(E_Err ret = NO_ERR) const
        {
            expect("maxerr").AND_RETURN(ret);
        }
    };
} 

#endif // H_