//  ============================================================
//  mock for interface I_Reader
//  ============================================================
//  created by Manfred Sorgo

#ifndef M_READER_H
#define M_READER_H

#include <ifs/I_Reader.h>
#include "M_Base.h"
#include <testlib/testValues.h>

namespace test
{
    class M_Reader : public I_Reader, private M_Base
    {
    public:
        INSTANCE_DEC(M_Reader)

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

    private:
        M_Reader() : M_Base("Reader") {}
        const ComSetup setup = { tcpPortFld, tcpPortGui, tcpPortCtrl, tcpTimeout };
    };
} // namespace
#endif // _H
