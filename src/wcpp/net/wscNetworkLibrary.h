#pragma once

#include <wcpp/wspr/ws_id.h>
#include <wcpp/wscom/wscFactory.h>


class wsiNetwork;


#define WS_ClassName_OF_wscNetworkLibrary		"wcpp.net.wscNetworkLibrary"
#define WS_ContractID_OF_wscNetworkLibrary		"@worldscale.net/network;1"
#define WS_CID_OF_wscNetworkLibrary		\
	{ 0x379c9069, 0x554a, 0x41bb, { 0x97, 0xad, 0x7f, 0x92, 0x9a, 0x19, 0xaf, 0x3a } }
// {379C9069-554A-41bb-97AD-7F929A19AF3A}


class wscNetworkLibrary
{
public:

    class t_factory : public wscFactory
    {
    public:
        static const ws_char * const s_class_name;
    public:
        t_factory(void);
        ~t_factory(void);
    };

public:
    static const ws_cid sCID;
    static const ws_char * const sContractID;
    static const ws_char * const s_class_name;
public:
    static void GetNetwork(wsiNetwork ** ret);
};



