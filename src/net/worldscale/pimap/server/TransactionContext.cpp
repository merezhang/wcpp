#include "TransactionContext.h"


TransactionContext::TransactionContext(void)
:   m_coder      ( WS_NULL ) ,
    m_decoder    ( WS_NULL ) ,
    m_dgRequest  ( WS_NULL ) ,
    m_dgResponse ( WS_NULL ) ,
    m_dgSocket   ( WS_NULL ) , 
    m_pmRequest  ( WS_NULL ) ,
    m_pmResponse ( WS_NULL )
{
}


TransactionContext::~TransactionContext(void)
{
}

