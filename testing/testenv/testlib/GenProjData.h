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
#include <ifs/I_SIG.h>
#include <ifs/I_LCR.h>
#include <BAS/StaticArray.h>
#include <testlib/TestLib.h>
#include <setup/capacities.h>
#include <fstream>

namespace test
{
    class DumpProjData
    {
    protected:
        static bool dump(const ProjData& data, CONST_C_STRING filename);
    private:
        inline static void write(std::ostream& os, const UINT32& n)
        {
            os.write((const char*) &n, sizeof(UINT32));
        }
        template <class T>
        static void write(std::ostream& os, const T* data, UINT32 num)
        {
            os.write((const char*) data, sizeof(T) * num);
        }    
    };

    template <
        size_t NTSW = CAPACITY_TSW, 
        size_t NSIG = CAPACITY_SIG, 
        size_t NLCR = CAPACITY_LCR, 
        size_t NSEG = CAPACITY_SEG
    >
    class GenProjData : 
        public ProjData,
        private DumpProjData
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
    
        inline const ProjTSW& tsw(size_t pos) const { return mTSWs.at(pos); }
        inline const ProjSIG& sig(size_t pos) const { return mSIGs.at(pos); }
        inline const ProjLCR& lcr(size_t pos) const { return mLCRs.at(pos); }
        inline const ProjSEG& seg(size_t pos) const { return mSEGs.at(pos); }

        inline const ElementName& tswName(size_t pos) const { return tsw(pos).name; }
        inline const ElementName& sigName(size_t pos) const { return sig(pos).name; }
        inline const ElementName& lcrName(size_t pos) const { return lcr(pos).name; }
        inline const ElementName& segName(size_t pos) const { return seg(pos).name; }

        void setSigType(size_t pos, INT32 type)
        {
            setType(mSIGs, pos, type);
        }

        void setSigType(INT32 type)
        {
            setType(mSIGs, type);
        }

        void setLcrType(size_t pos, INT32 type)
        {
            setType(mLCRs, pos, type);
        }

        void setLcrType(INT32 type)
        {
            setType(mLCRs, type);
        }

        inline bool dump(CONST_C_STRING filename) const
        {
            return DumpProjData::dump(*this, filename);
        }

    private:
        StaticArray<ProjTSW, NTSW> mTSWs;
        StaticArray<ProjSIG, NSIG> mSIGs;
        StaticArray<ProjLCR, NLCR> mLCRs;
        StaticArray<ProjSEG, NSEG> mSEGs;

        template <class T, size_t CAP>
        void preset(StaticArray<T, CAP>& array, CONST_C_STRING what)
        {
            for (size_t n = 0; n < CAP; ++n)
            {
                array.add();
                nameElement(array.at(n), CAP - n, what);
            }
        }

        template <class T, size_t CAP>
        void setType(StaticArray<T, CAP>& array, size_t pos, INT32 type)
        {
            array.at(pos).type = type;
        }

        template <class T, size_t CAP>
        void setType(StaticArray<T, CAP>& array, INT32 type)
        {
            for (size_t p = 0; p < CAP; ++p)
            {
                setType(array, p, type);
            }
        }
    };


} // namespace
#endif // H_
