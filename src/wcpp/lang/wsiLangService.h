#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiRunnable;
class wsiThread;
class wsiCString;
class wsiRuntime;
class wsiPrintStream;
class wsiInputStream;
class wsiString;
class wsiStringRW;


#define WS_IID_OF_wsiLangService		\
	{ 0x7c0fd2cd, 0xba82, 0x46e4, { 0xb7, 0x2f, 0xeb, 0xc1, 0xbb, 0xc6, 0x1a, 0x59 } }
// {7C0FD2CD-BA82-46e4-B72F-EBC1BBC61A59}


#define WS_IID_OF_wsiRuntimeService      \
    { 0x30888d56, 0x5f3b, 0x4ad1, { 0x9c, 0xc7, 0x3a, 0x4e, 0x18, 0x74, 0xad, 0xfc } }
// {30888D56-5F3B-4ad1-9CC7-3A4E1874ADFC}


#define WS_IID_OF_wsiSystemService      \
    { 0xbebc0155, 0xe686, 0x43e3, { 0x82, 0x28, 0x5e, 0x0, 0xd8, 0x61, 0xe6, 0x74 } }
// {BEBC0155-E686-43e3-8228-5E00D861E674}


#define WS_IID_OF_wsiThreadService      \
    { 0x84d15923, 0xbc20, 0x4979, { 0x86, 0xdb, 0xc3, 0x2c, 0xaf, 0x38, 0xed, 0x74 } }
// {84D15923-BC20-4979-86DB-C32CAF38ED74}


#define WS_IID_OF_wsiStringService      \
    { 0xb983aec6, 0xc54f, 0x4586, { 0x9e, 0xb1, 0x1c, 0xf0, 0xc9, 0xc0, 0xd9, 0x38 } }
// {B983AEC6-C54F-4586-9EB1-1CF0C9C0D938}




class wsiRuntimeService : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , GetRuntime )(wsiRuntime ** ret) = 0;
};


class wsiSystemService : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , GetErr )(wsiPrintStream ** ret) = 0;
    WS_METHOD( ws_result , GetIn  )(wsiInputStream ** ret) = 0;
    WS_METHOD( ws_result , GetOut )(wsiPrintStream ** ret) = 0;
    WS_METHOD( ws_result , SetErr )(wsiPrintStream * aPrintStream) = 0;
    WS_METHOD( ws_result , SetIn  )(wsiInputStream * aInputStream) = 0;
    WS_METHOD( ws_result , SetOut )(wsiPrintStream * aPrintStream) = 0;
};


class wsiThreadService : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , NewThread )(wsiRunnable * target, wsiString * name, wsiThread ** ret) = 0;
    WS_METHOD( ws_result , Sleep     )(ws_long millis) = 0;
};


class wsiStringService : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_int    , AllocateString )( wsiStringRW ** ret, ws_int size, const ws_char * const buf, ws_int len ) = 0;
    WS_METHOD( ws_result , RecycleString  )( wsiStringRW * obj ) = 0;
};


class wsiLangService : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , GetRuntimeService )(wsiRuntimeService ** ret) = 0;
    WS_METHOD( ws_result , GetSystemService  )(wsiSystemService ** ret) = 0;
    WS_METHOD( ws_result , GetThreadService  )(wsiThreadService ** ret) = 0;
    WS_METHOD( ws_result , GetStringService  )(wsiStringService ** ret) = 0;
};



