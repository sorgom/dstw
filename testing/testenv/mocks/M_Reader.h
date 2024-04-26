//  ============================================================
//  mock for interface I_Reader
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <ifs/I_Reader.h>
#include "M_Base.h"
#include <testlib/testValues.h>

namespace test
{
    class M_Reader : public I_Reader, private M_Base
    {
    public:
        inline M_Reader() : M_Base("Reader") {}
        INSTANCE_DEC(M_Reader)

        const ComSetup setup = { tcpPortFld, tcpPortGui, tcpPortCtrl, tcpTimeout };


        inline void read(CONST_C_STRING filename) override
        {
            call("read");
        }
        inline void expectRead() const
        {
            expect("read");
        }

        inline const ComSetup& getComSetup() const override
        {
            call("getComSetup");
            return setup;
        }
        inline void expectGetComSetup() const
        {
            expect("getComSetup");
        }

      };
} // namespace
