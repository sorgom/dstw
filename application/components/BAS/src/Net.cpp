#include <BAS/Net.h>

const UINT16 t16 = 0x0A0B;
const bool Net::isBig = *reinterpret_cast<const UINT8*>(&t16) == 0x0A;
const size_t Net::pn20 = isBig ? 0 : 1;
const size_t Net::pn21 = isBig ? 1 : 0;

const size_t Net::pn40 = isBig ? 0 : 3;
const size_t Net::pn41 = isBig ? 1 : 2;
const size_t Net::pn42 = isBig ? 2 : 1;
const size_t Net::pn43 = isBig ? 3 : 0;
