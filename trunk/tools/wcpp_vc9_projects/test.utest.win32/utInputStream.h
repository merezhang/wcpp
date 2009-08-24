#pragma once
#include <wcpp/io/wscInputStream.h>


class utInputStream : public wscInputStream
{
public:
    static const ws_char * const s_class_name;
public:
    utInputStream(void);
    ~utInputStream(void);
    static void Init(void);
protected:
	WS_METHOD( ws_int     , Read          )(void);
};

