#pragma once
#ifndef OSTREAMS_H
#define OSTREAMS_H

#include <ifs/DataTypes.h>
#include <ostream>

#define STREAM_DEC(NAME) \
    std::ostream& operator << (std::ostream& os, const NAME& d);

STREAM_DEC(TrackSwitchData)

#endif // H_