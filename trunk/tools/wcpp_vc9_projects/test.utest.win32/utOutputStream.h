#pragma once
#include <wcpp/io/wscOutputStream.h>
#include <wcpp/lang/wscString.h>


class ws_file;


class utOutputStream : public wscOutputStream
{
public:
    static const ws_char * const s_class_name;
public:
    utOutputStream(void);
    ~utOutputStream(void);
    static void Init(void);
protected:
	WS_METHOD( ws_result , Write )(ws_int b);
};

