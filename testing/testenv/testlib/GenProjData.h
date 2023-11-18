//  ============================================================
//  ProjData generator
//      presets all proj data 
//      with element names in reversed alphanumerical order
//      from capacity down to 1
//      e.g. TSW, capacity 100:
//          "TSW 100 *" .. "TSW 001 *"
//  
//      additional features
//      -   set signal type for signal data
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef GENPROJDATA_H
#define GENPROJDATA_H

#include <ifs/ProjData.h>
#include <BAS/StackArray.h>
#include <testlib/TestLib.h>
#include <setup/capacities.h>

namespace test
{
    template <
        UINT32 NTSW = CAPACITY_TSW, 
        UINT32 NSIG = CAPACITY_SIG, 
        UINT32 NLCR = CAPACITY_LCR, 
        UINT32 NSEG = CAPACITY_SEG
    >
    class GenProjData : public ProjData
    {
    public:
        GenProjData()
        {
            pTSW = mTSWs.data();
            pSIG = mSIGs.data();
            pLCR = mLCRs.data();
            pSEG = mSEGs.data();

            numTSW = NTSW;
            numSIG = NSIG;
            numLCR = NLCR;
            numSEG = NSEG;

            preset(mTSWs, "TSW");
            preset(mSIGs, "SIG");
            preset(mLCRs, "LCR");
            preset(mSEGs, "SEG");

            setSigType(SIG_TYPE_H);
            setLcrType(LCR_TYPE_LCR);
        }
    
        inline const ProjTSW& tsw(UINT32 pos) const { return mTSWs.at(pos); }
        inline const ProjSIG& sig(UINT32 pos) const { return mSIGs.at(pos); }
        inline const ProjLCR& lcr(UINT32 pos) const { return mLCRs.at(pos); }
        inline const ProjSEG& seg(UINT32 pos) const { return mSEGs.at(pos); }

        inline const ElementName& tswName(UINT32 pos) const { return tsw(pos).name; }
        inline const ElementName& sigName(UINT32 pos) const { return sig(pos).name; }
        inline const ElementName& lcrName(UINT32 pos) const { return lcr(pos).name; }
        inline const ElementName& segName(UINT32 pos) const { return seg(pos).name; }

        void setSigType(UINT32 pos, INT32 type)
        {
            setType(mSIGs, pos, type);
        }

        void setSigType(INT32 type)
        {
            setType(mSIGs, type);
        }

        void setLcrType(UINT32 pos, INT32 type)
        {
            setType(mLCRs, pos, type);
        }

        void setLcrType(INT32 type)
        {
            setType(mLCRs, type);
        }

    private:
        StackArray<ProjTSW, NTSW> mTSWs;
        StackArray<ProjSIG, NSIG> mSIGs;
        StackArray<ProjLCR, NLCR> mLCRs;
        StackArray<ProjSEG, NSEG> mSEGs;

        template <class T, UINT32 CAP>
        void preset(StackArray<T, CAP>& array, CONST_C_STRING what)
        {
            for (UINT32 n = 0; n < CAP; ++n)
            {
                T elem = {0};
                genElementName(elem.name, CAP - n, what);
                array.add(elem);
            }
        }

        template <class T, UINT32 CAP>
        void setType(StackArray<T, CAP>& array, UINT32 pos, INT32 type)
        {
            array.at(pos).type = type;
        }

        template <class T, UINT32 CAP>
        void setType(StackArray<T, CAP>& array, INT32 type)
        {
            for (UINT32 p = 0; p < CAP; ++p)
            {
                setType(array, p, type);
            }
        }
    };

} // namespace
#endif // H_
