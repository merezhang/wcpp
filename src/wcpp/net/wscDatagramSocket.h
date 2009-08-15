#pragma once
#include <wcpp/lang/wscObject.h>
#include "wsiDatagramSocket.h"


class wscDatagramSocket : public wscObject , public wsiDatagramSocket
{
public:
    wscDatagramSocket(void);
    ~wscDatagramSocket(void);
};

