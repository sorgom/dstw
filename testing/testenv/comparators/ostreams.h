#pragma once
#ifndef OSTREAMS_H
#define OSTREAMS_H

//## INCLUDES
#include <ifs/DataTypes.h>
//## END
#include <ostream>

#define STREAM_DEC(NAME) \
    std::ostream& operator << (std::ostream& os, const NAME& d);

//# STREAM_DEC
STREAM_DEC(SignalData)
STREAM_DEC(TrackSwitchData)
//# END

#endif // H_