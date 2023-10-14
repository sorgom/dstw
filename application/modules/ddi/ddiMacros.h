//  ============================================================
//  pseudo member definitions
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef DDIMACROS_H
#define DDIMACROS_H

#include <ddi/ddi.h>

#define DDI_MEMB(MEMB, NAME) \
    inline static I_ ## NAME& MEMB() { return ddi::get ## NAME(); }

#define DDI_MEMB_C(MEMB, NAME) \
    inline static const I_ ## NAME& MEMB() { return ddi::get ## NAME(); }


#endif // _H