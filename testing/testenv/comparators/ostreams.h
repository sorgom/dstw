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
//## END
#include <ostream>

#define OSTREAM_DEC(NAME) \
    std::ostream& operator << (std::ostream& os, const NAME& d);

//# OSTREAM_DEC
OSTREAM_DEC(RastaTelegram)
//# END

#endif // H_