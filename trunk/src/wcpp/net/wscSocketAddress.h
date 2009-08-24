#pragma once

#include "wsiSocketAddress.h"
#include <wcpp/lang/wscObject.h>


class wscSocketAddress : public wscObject , public wsiSocketAddress
{
protected:
    wscSocketAddress(void);
    ~wscSocketAddress(void);
};

