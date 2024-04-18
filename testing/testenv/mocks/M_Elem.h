//  ============================================================
//  mock for interface Elem
//  ============================================================
//  created by Manfred Sorgo

#pragma once
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

        inline void fromFld(const ComData& data)
        {
            call("fromFld").TPARAM(ComData, data);
        }
        inline void expectFromFld(ComData& data) const
        {
            expect("fromFld").TPARAM(ComData, data);
        }

        inline void fromGui(const ComData& data)
        {
            call("fromGui").TPARAM(ComData, data);
        }
        inline void expectFrom(const ComData& data) const
        {
            expect("fromGui").TPARAM(ComData, data);
        }
        
        inline UINT8 type() const { return 0; }
    };

    class M_TSW : public M_Elem
    {
    public:
        inline M_TSW() : M_Elem("TSW") {}
        IL_INSTANCE_DEC(M_TSW)
    };

    class M_SIG : public M_Elem
    {
    public:
        inline M_SIG() : M_Elem("SIG") {}
        IL_INSTANCE_DEC(M_SIG)
    };

    class M_LCR : public M_Elem
    {
    public:
        inline M_LCR() : M_Elem("LCR") {}
        IL_INSTANCE_DEC(M_LCR)
    };
    
} // namespace



#endif // _H