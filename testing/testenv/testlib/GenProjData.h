//  ============================================================
//  ProjData generator
//      presets all proj data 
//      with element names in reversed alphanumerical order
//      from capacity down to 1
//      e.g. TSW, capacity 100:
//          "TSW 100 *" .. "TSW 001 *"
//  
//      dumps data to file
// 
//      additional features
//      -   set SIG type for signal data
//      -   set LCR type for level crossing data 
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef GENPROJDATA_H
#define GENPROJDATA_H

#include <ifs/I_LCR.h>
#include <ifs/I_SIG.h>
#include <ifs/ProjTypes.h>
#include <BAS/HN.h>
#include <setup/capacities.h>
#include <testlib/TestArrays.h>
#include <testlib/TestLib.h>
#include <fstream>

namespace test
{
    template <
        size_t NTSW = CAPACITY_TSW, 
        size_t NSIG = CAPACITY_SIG, 
        size_t NLCR = CAPACITY_LCR, 
        size_t NSEG = CAPACITY_SEG
    >
    class GenProjData 
    {
    private:
        MutableArray<ProjTSW, NTSW> mTSWs;
        MutableArray<ProjSIG, NSIG> mSIGs;
        MutableArray<ProjLCR, NLCR> mLCRs;
        MutableArray<ProjSEG, NSEG> mSEGs;

    public:
        const UINT32 numTSW;
        const UINT32 numSIG;
        const UINT32 numLCR;
        const UINT32 numSEG;
        const ProjTSW* const pTSW;
        const ProjSIG* const pSIG;
        const ProjLCR* const pLCR;
        const ProjSEG* const pSEG;

        GenProjData():
            numTSW(NTSW),
            numSIG(NSIG),
            numLCR(NLCR),
            numSEG(NSEG),
            pTSW(mTSWs.data()),
            pSIG(mSIGs.data()),
            pLCR(mLCRs.data()),
            pSEG(mSEGs.data())

        {
            preset(mTSWs, "TSW");
            preset(mSIGs, "SIG");
            preset(mLCRs, "LCR");
            preset(mSEGs, "SEG");

            setSigType(SIG_TYPE_H);
            setLcrType(LCR_TYPE_LCR);
        }
    
        inline const ProjTSW& tsw(size_t pos) const { return mTSWs.at(pos); }
        inline const ProjSIG& sig(size_t pos) const { return mSIGs.at(pos); }
        inline const ProjLCR& lcr(size_t pos) const { return mLCRs.at(pos); }
        inline const ProjSEG& seg(size_t pos) const { return mSEGs.at(pos); }

        inline const ComName& tswName(size_t pos) const { return tsw(pos).name; }
        inline const ComName& sigName(size_t pos) const { return sig(pos).name; }
        inline const ComName& lcrName(size_t pos) const { return lcr(pos).name; }
        inline const ComName& segName(size_t pos) const { return seg(pos).name; }

        void setSigType(size_t pos, UINT8 type)
        {
            setType(mSIGs, pos, type);
        }

        void setSigType(UINT8 type)
        {
            setType(mSIGs, type);
        }

        void setLcrType(size_t pos, UINT8 type)
        {
            setType(mLCRs, pos, type);
        }

        void setLcrType(UINT8 type)
        {
            setType(mLCRs, type);
        }

        void dump(CONST_C_STRING filename) const
        {
            std::ofstream os(filename, std::ios::binary);
            if (os.good())
            {
                write(os, numTSW);
                write(os, numSIG);
                write(os, numLCR);
                write(os, numSEG);
                write(os, pTSW, numTSW);
                write(os, pSIG, numSIG);
                write(os, pLCR, numLCR);
                write(os, pSEG, numSEG);
            }
            os.close();
        }

        NOCOPY(GenProjData)

    private:

        template <class T, size_t CAP>
        void preset(MutableArray<T, CAP>& array, CONST_C_STRING what)
        {
            for (size_t n = 0; n < CAP; ++n)
            {
                array.add();
                nameElement(array.at(n), CAP - n, what);
            }
        }

        template <class T, size_t CAP>
        void setType(MutableArray<T, CAP>& array, size_t pos, UINT8 type)
        {
            array.at(pos).type = type;
        }

        template <class T, size_t CAP>
        void setType(MutableArray<T, CAP>& array, UINT8 type)
        {
            for (size_t p = 0; p < CAP; ++p)
            {
                setType(array, p, type);
            }
        }

        inline static void write(std::ostream& os, const UINT32 n)
        {
            const UINT32 nN = HN::toN(n);
            os.write(reinterpret_cast<const char*>(&nN), sizeof(UINT32));
        }

        template <class T>
        static void write(std::ostream& os, const T* data, UINT32 num)
        {
            os.write(reinterpret_cast<const char*>(data), sizeof(T) * num);
        }    

    };
} // namespace
#endif // H_
