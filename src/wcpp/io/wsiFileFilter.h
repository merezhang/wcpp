#pragma once


class wsiFileFilter : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_boolean , Accept )(wsiFile * pathname) = 0;
};

