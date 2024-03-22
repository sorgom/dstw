#include <BAS/HN.h>

const UINT32 HN::checkNum = 0xF80000E7u;
const bool HN::isLittle = *reinterpret_cast<const uint8_t*>(&HN::checkNum) == 0xE7;

const HN::Adapt32 HN::keep32 = [](const UINT32 val) { return val; };
const HN::Adapt32 HN::chng32 = [](const UINT32 val) 
    {
        return (val << 24) bitor ((val << 8) bitand 0x00FF0000u)
            bitor ((val >> 8) bitand 0x0000FF00u) bitor (val >> 24);
    };

const HN::Adapt32 HN::adapt32 = isLittle ? HN::chng32 : HN::keep32;

const HN::Adapt16 HN::keep16 = [](const UINT16 val) { return val; };
const HN::Adapt16 HN::chng16 = [](const UINT16 val) -> UINT16
    {
        return (val >> 8) bitor (val << 8);
    };

const HN::Adapt16 HN::adapt16 = isLittle ? HN::chng16 : HN::keep16;
