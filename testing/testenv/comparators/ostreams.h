//  ============================================================
//  ostream operators for complex data types
//  - mainly used for test comparator
//  - but also handy for tracing purposes
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef OSTREAMS_H
#define OSTREAMS_H

//## INCLUDES
#include <ifs/ComTypes.h>
#include <ifs/PosRes.h>
#include <ifs/ProjItem.h>
//## END
#include <ostream>
#include <comparators/ostreamHelpers.h>

//# OSTREAM_DEC
OSTREAM_DEC(ComName)
OSTREAM_DEC(ComTele)
OSTREAM_DEC(ComTeleFld)
OSTREAM_DEC(ComTeleGui)
OSTREAM_DEC(PosRes)
OSTREAM_DEC(ProjLCR)
OSTREAM_DEC(ProjSEG)
OSTREAM_DEC(ProjSIG)
OSTREAM_DEC(ProjTSW)
//# END

#endif // H_
