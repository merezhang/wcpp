#pragma once

#include <wcpp/net/wsiDatagramSocket.h>
#include <wcpp/net/wsiDatagramPacket.h>
#include <net/worldscale/pimap/wsiPimapPacket.h>
#include <net/worldscale/pimap/wsiPimapCoder.h>
#include <net/worldscale/pimap/wsiPimapDecoder.h>


class TransactionContext
{
public:

    wsiDatagramSocket *  m_dgSocket;
    wsiPimapCoder     *  m_coder;
    wsiPimapDecoder   *  m_decoder;

    wsiDatagramPacket *  m_dgRequest;
    wsiDatagramPacket *  m_dgResponse;
    wsiPimapPacket    *  m_pmRequest;
    wsiPimapPacket    *  m_pmResponse;

public:
    TransactionContext(void);
    ~TransactionContext(void);
};

