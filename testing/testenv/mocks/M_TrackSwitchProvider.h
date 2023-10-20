//  ============================================================
//  mock for interface TrackSwitchProvider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_TRACKSWITCHPROVIDER_H
#define M_TRACKSWITCHPROVIDER_H

#include <ifs/I_TrackSwitchProvider.h>
#include <setup/capacities.h>
#include "M_Base.h"
#include "M_TrackSwitch.h"

namespace test
{
    MOCK_CLASS(TrackSwitchProvider)
    {
    public:
        MOCK_CON(TrackSwitchProvider)

        inline void reset()
        {
            call("reset");
        }
        inline void expectReset() const
        {
            expect("reset");
        }

        inline UINT32 size() const
        {
            return mSize;
        }
        inline void setSize(UINT32 val)
        {
            mSize = val;
        }

        inline UINT32 capacity() const
        {
            return mCapacity;
        }
        inline void setCapacity(UINT32 val)
        {
            mCapacity = val;
        }

        inline void add(UINT32 id)
        {
            call("add").PARAM(id);
        } 
        inline void expectAdd(UINT32 id) 
        {
            expect("add").PARAM(id);
        } 
        inline void expectNumAdd(UINT16 num) 
        {
            expect(num, "add").IGNORE();
        }

        inline I_TrackSwitch& at(UINT32 pos)
        {
            return M_TrackSwitch::instance();
        }
    private:
        UINT32 mSize;
        UINT32 mCapacity;
    };
}
#endif // H_