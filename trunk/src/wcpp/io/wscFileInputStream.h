#pragma once

#include "wsiFileInputStream.h"
#include "wscInputStream.h"


class wsiFile;
class wsiFileDescriptor;
class ws_file;


class wscFileInputStream : public wscInputStream, public wsiFileInputStream
{
public:
    typedef wscInputStream          t_super_class;
    static const ws_char * const    s_class_name;
private:
    ws_file * m_file;
private:
    ws_int _realRead(void * b, ws_int len);
protected:
    wscFileInputStream(wsiFile * file);
    wscFileInputStream(wsiFileDescriptor * fdObj);
    wscFileInputStream(wsiString * name);
    ~wscFileInputStream(void);
protected:
    WS_METHOD( ws_result  , Mark          )(ws_int readlimit)                  { return t_super_class::Mark(readlimit); }
    WS_METHOD( ws_boolean , MarkSupported )(void)                              { return t_super_class::MarkSupported(); }
    WS_METHOD( ws_result  , Reset         )(void)                              { return t_super_class::Reset();         }
protected:
    WS_METHOD( ws_int    , Available  )(void);
    WS_METHOD( ws_result , Close      )(void);
    WS_METHOD( ws_result , GetChannel )(wsiFileChannel ** ret);
    WS_METHOD( ws_result , GetFD      )(wsiFileDescriptor ** ret);
    WS_METHOD( ws_int    , Read       )(void);
    WS_METHOD( ws_int    , Read       )(void * b, ws_int len);
    WS_METHOD( ws_long   , Skip       )(ws_long n);
protected:
    WS_METHOD( ws_result , Finalize   )(void);
};



