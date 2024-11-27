//  ============================================================
//  mock for interface Log
//  ============================================================
//  created by Manfred Sorgo
#ifndef M_LOG_H
#define M_LOG_H

#include <ifs/I_Log.h>
#include "M_Base.h"
#include <testlib/NullStream.h>

namespace test
{
    class M_Log :
        public I_Log,
        private M_Base
    {
    public:
        INSTANCE_DEC(M_Log)

        inline std::ostream& log(E_Comp comp, E_Ret ret)
        {
            call("log").PARAM(comp).PARAM(ret);
            return mStream;
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
    private:
        M_Log() : M_Base("Log") {}
        NullStream mStream;
    };
}
#endif // _H
