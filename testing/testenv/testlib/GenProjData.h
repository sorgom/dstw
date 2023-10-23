//  ============================================================
//  ProjData generator
//  pesets all proj data 
//  with element names in reversed alphanumerical order
//  from capacity down to 1
//  e.g. TSW, capacity 100:
//  "*TSW 100 *******" .. "*TSW 001 *******"
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef GENPROJDATA_H
#define GENPROJDATA_H

#include <ifs/ProjData.h>
#include <baselib/StackArray.h>
#include <testlib/genElementName.h>
#include <setup/capacities.h>

namespace test
{
    template <UINT32 NTSW = CAPACITY_TSW, UINT32 NSIG = CAPACITY_SIG, UINT32 NLCR = CAPACITY_LCR, UINT32 NSEG = CAPACITY_SEG>
    class GenProjData : public ProjData
    {
    public:
        GenProjData()
        {
            pTSW = mTSW.getData();
            pSIG = mSIG.getData();
            pLCR = mLCR.getData();
            pSEG = mSEG.getData();

            numTSW = NTSW;
            numSIG = NSIG;
            numLCR = NLCR;
            numSEG = NSEG;

            preset(mTSW, "TSW");
            preset(mSIG, "SIG");
            preset(mLCR, "LCR");
            preset(mSEG, "SEG");
        }
    
    private:
        SimpleStackArray<ProjTSW, NTSW> mTSW;
        SimpleStackArray<ProjSIG, NSIG> mSIG;
        SimpleStackArray<ProjLCR, NLCR> mLCR;
        SimpleStackArray<ProjSEG, NSEG> mSEG;

        template <class T, UINT32 CAP>
        void preset(SimpleStackArray<T, CAP>& array, CONST_C_STRING what)
        {
            for (UINT32 n = 0; n < CAP; ++n)
            {
                T elem = {0};
                genElementName(elem.name, CAP - n, what);
                array.add(elem);
            }
        }
    };
} // namespace

#endif // H_