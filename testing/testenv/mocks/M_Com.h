//  ============================================================
//  mock for interface I_Com
//  ============================================================
//  created by Manfred Sorgo

#ifndef M_COM_H
#define M_COM_H

#include <ifs/I_Com.h>
#include "M_Base.h"

namespace test
{
    class M_Com : public I_Com, private M_Base
    {
    public:
        INSTANCE_DEC(M_Com)
        NOCOPY(M_Com)

        inline void run() override
        {
            call("run");
        }
        inline void expectRun() const
        {
            expect("run");
        }

        inline void stop() override
        {
            call("stop");
        }
        inline void expectStop() const
        {
            expect("stop");
        }

        inline void toFld(const ComTele& tele) const
        {
            call("toFld").TPARAM(ComTele, tele);
        }
        inline void expectToFld(const ComTele& tele) const
        {
            expect("toFld").TPARAM(ComTele, tele);
        }

        inline void toGui(const ComTele& tele) const
        {
            call("toGui").TPARAM(ComTele, tele);
        }
        inline void expectToGui(const ComTele& tele) const
        {
            expect("toGui").TPARAM(ComTele, tele);
        }
    private:
        inline M_Com() : M_Base("Com") {}
    };
} // namespace
#endif // _H
