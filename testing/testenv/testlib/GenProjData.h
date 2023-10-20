//  ============================================================
//  ProjData generator
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef GENPROJDATA_H
#define GENPROJDATA_H

#include <ifs/ProjData.h>
#include <baselib/StackArray.h>
#include <testlib/genElementName.h>

namespace test
{
    template <UINT32 NTSW, UINT32 NSIG, UINT32 NLCR, UINT32 NSEG>
    class GenProjData : public ProjData
    {
    public:
        GenProjData()
        {
            pTSW = mTSW.getData();
            pSIG = mSIG.getData();
            pLCR = mLCR.getData();
            pSEG = mSEG.getData();
            reset();
        }
        void reset()
        {
            numTSW = 0;
            numSIG = 0;
            numLCR = 0;
            numSEG = 0;
            mTSW.reset();
            mSIG.reset();
            mLCR.reset();
            mSEG.reset();
        }
        void add(const ProjTSW& obj)
        {
            addX(mTSW, numTSW, obj);
        }
        void add(const ProjSIG& obj)
        {
            addX(mSIG, numSIG, obj);
        }
        void add(const ProjLCR& obj)
        {
            addX(mLCR, numLCR, obj);
        }
        void add(const ProjSEG& obj)
        {
            addX(mSEG, numSEG, obj);
        }

        void preset()
        {
            presetX(mTSW, "TSW");
            presetX(mSIG, "SIG");
            presetX(mLCR, "LCR");
            presetX(mSEG, "SEG");
        }
    private:
        SimpleStackArray<ProjTSW, NTSW> mTSW;
        SimpleStackArray<ProjSIG, NSIG> mSIG;
        SimpleStackArray<ProjLCR, NLCR> mLCR;
        SimpleStackArray<ProjSEG, NSEG> mSEG;

        template <class T, UINT32 CAP>
        void addX(SimpleStackArray<T, CAP>& array, UINT32& num, const T& obj)
        {
            if (array.hasSpace())
            {
                array.add(obj);
                num = array.size();
            }
        }

        template <class T, UINT32 CAP>
        void presetX(SimpleStackArray<T, CAP>& array, CONST_C_STRING what)
        {
            for (UINT32 n = 0; n < CAP; ++n)
            {
                T elem = {0};
                genElementName(elem.name, CAP - n, what);
                add(elem);
            }
        }
    };
} // namespace

#endif // H_