//  ============================================================
//  ostream operators for complex data types
//  - mainly used for test comparator
//  - but also handy for tracing purposes
//  ============================================================
//  created by Manfred Sorgo

#ifndef OSTREAMS_H
#define OSTREAMS_H

#include <ifs/DataTypes.h>
#include <ostream>
#include <comparators/ostreamHelpers.h>

OSTREAM_DEC(ComData)
OSTREAM_DEC(ComAddr)
OSTREAM_DEC(ComTele)
OSTREAM_DEC(PosRes)
OSTREAM_DEC(ProjItem)
#endif // _H
