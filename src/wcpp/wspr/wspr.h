#pragma once

#include "ws_def.h"
#include "ws_type.h"
#include "ws_id.h"
#include <string>


class wspr
{
public:

    static ws_int                ws_strlen(const ws_char * str);
    static const ws_char * const ws_strchr(const ws_char * str, ws_int c);
    static ws_int                ws_strcmp(const ws_char * str1, const ws_char * str2);

    static void * ws_memcpy(void *dest, const void *src, ws_int count);
    static ws_int ws_memcmp(const void * buf1, const void * buf2, ws_int count);

    static ws_boolean ws_assert( ws_boolean expression );
};

