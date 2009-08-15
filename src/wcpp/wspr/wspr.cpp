#include "wspr.h"



ws_int wspr::ws_strlen(const ws_char *const str)
{
    const ws_char * end = str;
    while (*end) {
        end++;
    }
    return static_cast<ws_int>(end-str);
}


void * wspr::ws_memcpy(void *dest, const void *src, ws_int count)
{
    if (count > 0) {
        if (dest && src) {
            const ws_byte * s = static_cast<const ws_byte *>(src);
            ws_byte *       d = static_cast<ws_byte *>(dest);
            for (ws_int i=(count-1); i>=0; i--) d[i] = s[i];
        }
        else {
            WS_ASSERT(0);
        }
    }
    else if (count < 0) {
        WS_ASSERT(0);
    }
    return dest;
}


const ws_char * const wspr::ws_strchr(const ws_char * const str, const ws_int c)
{
    if (str != WS_NULL) {
        const ws_char * p = str;
        while (*p) {
            if ((*p)==c) return p;
            p++;
        }
    }
    return WS_NULL;
}


ws_int wspr::ws_strcmp(const ws_char * str1, const ws_char * str2)
{
    if ((str1==WS_NULL) || (str2==WS_NULL)) {
        WS_ASSERT(0);
        return ((ws_int)(str1 - str2));
    }
    else {
        for (;;) {
            if ((*str1) != (*str2)) {
                return (((*str1) < (*str2)) ? (-1) : (1) );
            }
            else /*((*str1) == (*str2))*/ {
                if ((*str1) == 0) {
                    return 0;
                }
            }
            str1++;
            str2++;
        }
    }
    return 0;
}


ws_boolean wspr::ws_assert(ws_boolean expression)
{
    return expression;
}


ws_int wspr::ws_memcmp(const void *buf1, const void *buf2, ws_int count)
{
    const ws_byte * p1 =(const ws_byte *) buf1;
    const ws_byte * p2 =(const ws_byte *) buf2;
    for (ws_int i=count-1; i>=0; i-- , p1++ , p2++ ) {
        if ((*p1) != (*p2)) {
            return ( ((*p1) < (*p2)) ? (-1) : (1) );
        }
    }
    return 0;
}

