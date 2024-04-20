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
    class M_Log : 
        public I_Log,
        protected M_Base
    {
    public:
        M_Log() :
            M_Base("Log")
        {}

        inline void log(E_Comp comp, E_Ret ret)
        {
            call("log").PARAM(comp).PARAM(ret);
        }
        inline void expectLog(E_Comp comp, E_Ret ret) const
        {
            expect("log").PARAM(comp).PARAM(ret);
        }
        inline E_Ret maxerr() const
        {
            return static_cast<E_Ret>(call("maxerr").RETURN_DEF_UNSIGNED(RET_NO_ERR));
        }
        inline void expectMaxerr(E_Ret ret = RET_NO_ERR) const
        {
            expect("maxerr").AND_RETURN(ret);
        }

        INSTANCE_DEC(M_Log)
    };
} 

#endif // H_