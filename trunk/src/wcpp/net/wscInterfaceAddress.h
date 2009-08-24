#pragma once

#include "wsiInterfaceAddress.h"
#include <wcpp/lang/wscObject.h>


class wscInterfaceAddress : public wscObject , public wsiInterfaceAddress
{
public:
    wscInterfaceAddress();
    ~wscInterfaceAddress(void);
};

