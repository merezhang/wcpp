#pragma once

#include <wcpp/lang/wscObject.h>


class wscPimapConfig : public wscObject
{
public:
    static const ws_int    MAX_PACKET_SIZE         = 4096;
    static const ws_int    DEFAULT_SERVICE_PORT    = 10217;
    static const ws_uint8  PIMAP_VERSION           = 1;
};

