#pragma once

#include <wcpp/wspr/ws_id.h>


class wsiLangService;


#define WS_ContractID_OF_wsoLangService        "@worldscale.net/langservice;1"
#define WS_CID_OF_wsoLangService        \
    { 0x73f14971, 0xa37a, 0x4d9c, { 0xa3, 0xab, 0x88, 0x81, 0x69, 0xd2, 0x3a, 0x51 } }
// {73F14971-A37A-4d9c-A3AB-888169D23A51}


class wsoLangService
{
public:
    static const ws_cid sCID;
    static const ws_char * const sContractID;
public:
    static void GetLangService(wsiLangService ** ret);
};

