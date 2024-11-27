//  ============================================================
//  mock for interface Elem derived classes
//  ============================================================
//  created by Manfred Sorgo

#ifndef M_ELEM_H
#define M_ELEM_H

#include <ifs/I_Elem.h>
#include "M_Base.h"

namespace test
{
    class M_Elem : public I_Elem, private M_Base
    {
    public:
        inline M_Elem(const CONST_C_STRING name = "Elem") : M_Base(name) {}

        inline void fromFld(const ComData& data) override
        {
            call("fromFld").TPARAM(ComData, data);
        }
        inline void expectFromFld(const ComData& data) const
        {
            expect("fromFld").TPARAM(ComData, data);
        }

        inline void fromGui(const ComData& data) override
        {
            call("fromGui").TPARAM(ComData, data);
        }
        inline void expectFromGui(const ComData& data) const
        {
            expect("fromGui").TPARAM(ComData, data);
        }

        inline void toGui() const override
        {
            call("toGui");
        }
        inline void expectToGui() const
        {
            expect("toGui");
        }
        inline void expectToGui(UINT16 num) const
        {
            expect(num, "toGui");
        }
    };

    // mock TSW
    class M_TSW : public M_Elem
    {
    public:
        INSTANCE_DEC(M_TSW)
    private:
        inline M_TSW() : M_Elem("TSW") {}
    };

    // mock SIG
    class M_SIG : public M_Elem
    {
    public:
        INSTANCE_DEC(M_SIG)
    private:
        inline M_SIG() : M_Elem("SIG") {}
    };

    // mock LCR
    class M_LCR : public M_Elem
    {
    public:
        INSTANCE_DEC(M_LCR)
    private:
        inline M_LCR() : M_Elem("LCR") {}
    };

} // namespace
#endif // _H
