#pragma once
#ifndef DDI_H
#define DDI_H

#define DDI_GETTER(NAME) \
    I_ ## NAME& get ## NAME() { return NAME::instance(); }




#endif // _H