#pragma once
#include <wcpp/lang/wscObject.h>
#include "wsiInputSource.h"


class wscInputSource : public wscObject, public wsiInputSource
{
public:
    wscInputSource(void);
    ~wscInputSource(void);
};

