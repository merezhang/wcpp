#pragma once


class wsiFile;
class wsiString;


#define WS_IID_OF_wsiFilenameFilter     \
    { 0xf83f85f, 0xc9b8, 0x469c, { 0xa6, 0x47, 0xd9, 0xa, 0x57, 0xa9, 0xad, 0x17 } }
// {0F83F85F-C9B8-469c-A647-D90A57A9AD17}


class wsiFilenameFilter : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_boolean , Accept )(wsiFile * dir , wsiString * name) = 0;
};

