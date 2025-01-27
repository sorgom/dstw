//  ============================================================
//  class TSW implements a track switch element
//  state of implementation:
//  - WU command from GUI
//  - all states from field, forwarding to GUI
//  ============================================================
//  created by Manfred Sorgo

#ifndef TSW_H
#define TSW_H

#include <ifs/values.h>
#include <ifs/I_Elem.h>
#include <BAS/coding.h>

class TSW : public I_Elem
{
public:
    inline TSW(size_t id):
        mId(id),
        mState(TSW_STATE_UNDEF)
    {}

    void toGui() const override;
    void fromFld(const ComData& data) override;
    void fromGui(const ComData& data) override;

    NOCOPY(TSW)
    NODEF(TSW)
private:
    const size_t mId;
    UINT8 mState;

    void wu();
    void swLeft();
    void swRight();
    void chgState(UINT8 state);
    void toFld(UINT8 state) const;
};
#endif // _H
