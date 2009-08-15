// ws_type.h

#ifndef __ws_type_h__
#define __ws_type_h__

#include "ws_def.h"


typedef unsigned char       ws_uint8;
typedef unsigned short      ws_uint16;
typedef unsigned long       ws_uint32;
typedef unsigned long long  ws_uint64;

typedef char                ws_int8;
typedef short               ws_int16;
typedef long                ws_int32;
typedef long long           ws_int64;




typedef ws_uint8      ws_byte;
typedef ws_uint32     ws_uint;
typedef bool          ws_boolean;

typedef ws_int8       ws_char;
typedef ws_int16      ws_short;
typedef ws_int32      ws_int;
typedef ws_int64      ws_long;

typedef float         ws_float;
typedef double        ws_double;



typedef struct _t_ws_result {
    int m_n;

    _t_ws_result(ws_int n) : m_n(n)
    {
    }

    ws_boolean operator != (ws_int n)
    {
        return (m_n != n);
    }

    ws_boolean operator == (ws_int n)
    {
        return (m_n == n);
    }

}
ws_result;





#endif // __ws_type_h__
