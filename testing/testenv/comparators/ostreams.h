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
#include <ifs/DataTypes.h>
#include <ifs/ProjData.h>
//## END
#include <ostream>
#include <comparators/ostreamHelpers.h>

//# OSTREAM_DEC
OSTREAM_DEC(CmdFld)
OSTREAM_DEC(ElementName)
OSTREAM_DEC(FldState)
OSTREAM_DEC(GuiCmd)
OSTREAM_DEC(ProjData)
OSTREAM_DEC(ProjLCR)
OSTREAM_DEC(ProjSEG)
OSTREAM_DEC(ProjSIG)
OSTREAM_DEC(ProjTSW)
OSTREAM_DEC(StateGui)
//# END

#endif // H_
