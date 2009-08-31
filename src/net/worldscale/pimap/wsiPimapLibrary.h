#pragma once

#include <wcpp/wspr/ws_type.h>
#include <wcpp/lang/wsiObject.h>


class wsiString;


#define WS_IID_OF_wsiPimapServer        \
    { 0x4caba3ae, 0x2823, 0x40b4, { 0xb1, 0x9a, 0x89, 0x16, 0xf0, 0x33, 0xbb, 0x3e } }
// {4CABA3AE-2823-40b4-B19A-8916F033BB3E}


class wsiPimapServer : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , Start )(ws_int nPort) = 0;
    WS_METHOD( ws_result , Stop  )(void) = 0;
};


#define WS_IID_OF_wsiPimapClient        \
    { 0x9c5b017c, 0xa98d, 0x4c77, { 0x82, 0x7b, 0x80, 0x21, 0xef, 0x97, 0xec, 0x8e } }
// {9C5B017C-A98D-4c77-827B-8021EF97EC8E}


class wsiPimapClient : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , Login  )(wsiString * aUserName, wsiString * aPassword, wsiString * aServerAddr, ws_int aPort) = 0;
    WS_METHOD( ws_result , Logout )(void) = 0;
    WS_METHOD( ws_result , Close  )(void) = 0;
};


#define WS_IID_OF_wsiPimapLibrary       \
    { 0x796ee575, 0xce27, 0x4caf, { 0x98, 0x4f, 0x42, 0xa, 0x88, 0x74, 0x39, 0xc8 } }
// {796EE575-CE27-4caf-984F-420A887439C8}


class wsiPimapLibrary : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , CreateServer )(wsiPimapServer ** ret) = 0;
    WS_METHOD( ws_result , CreateClient )(wsiPimapClient ** ret) = 0;
};

