#pragma once

#include "wscOutputStream.h"
#include "wsiFileOutputStream.h"


class wsiFile;
class wsiFileDescriptor;
class ws_file;


class wscFileOutputStream : public wscOutputStream , public wsiFileOutputStream
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscFileOutputStream )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiFileOutputStream )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:
    ws_file * m_file;
private:
    ws_result realClose(void);
    ws_result realOpen(const ws_char * const filename);
protected:
    wscFileOutputStream(wsiFile * file);
    wscFileOutputStream(wsiFile * file, ws_boolean append);
    wscFileOutputStream(wsiFileDescriptor * fdObj);
    wscFileOutputStream(wsiString * name);
    wscFileOutputStream(wsiString * name, ws_boolean append);
    ~wscFileOutputStream(void);
protected:
    WS_METHOD( ws_result , Close      )(void);
    WS_METHOD( ws_result , GetChannel )(wsiFileChannel ** ret);
    WS_METHOD( ws_result , GetFD      )(wsiFileDescriptor ** ret);
    WS_METHOD( ws_result , Write      )(const void * b, ws_int cb);
    WS_METHOD( ws_result , Write      )(ws_int b);
    WS_METHOD( ws_result , Flush      )(void);
protected:
    WS_METHOD( ws_result , Finalize )(void);
};


