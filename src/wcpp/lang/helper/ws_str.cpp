#include "ws_str.h"
#include <wcpp/lang/wscString.h>
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/wspr/wspr.h>



/*
**********************************************************************************************************************
*   ws_str
**********************************************************************************************************************
*/


ws_str::ws_str(void)
{
    wscString::Allocate( & m_pstr );
}


ws_str::ws_str(const ws_char * const src, ws_int len)
{
    wscString::Allocate( & m_pstr , src , len );
}


ws_str::ws_str(const ws_char * const src)
{
    wscString::Allocate( & m_pstr , src );
}


ws_str::ws_str(const ws_str & src)
{
    wsiString * ptr = src.m_pstr;
    if (ptr) {
        m_pstr = ptr;
    }
    else {
        wscString::Allocate( & m_pstr );
    }
}


ws_str::ws_str(wsiString * ptr)
{
    if (ptr) {
        m_pstr = ptr;
    }
    else {
        wscString::Allocate( & m_pstr );
    }
}


ws_str::~ws_str(void)
{
}


void ws_str::SetString(const ws_char * const buf, ws_int len)
{
    wsiString * pns = WS_NULL;
    wscString::Allocate( & pns , buf , len );
    m_pstr.Attach( pns );
}


const ws_str & ws_str::operator =(const ws_str & src)
{
    ws_ptr<wsiString> tmp( src.m_pstr );
    m_pstr.Attach( tmp.Detach() );
    return (*this);
}

/*
ws_str::operator const ws_char * const (void) const
{
    if (!m_pstr) {
        return "";
    }
    else {
        return m_pstr->GetBuffer();
    }
}
*/

ws_boolean ws_str::operator==(const ws_char * const other) const
{
    const ws_char * buf = WS_NULL;
    if (!(!m_pstr)) {
        buf = m_pstr->GetBuffer();
    }
    return ( wspr::ws_strcmp( buf, other ) == 0 );
}


ws_boolean ws_str::operator!=(const ws_char * const other) const
{
    const ws_char * buf = WS_NULL;
    if (!(!m_pstr)) {
        buf = m_pstr->GetBuffer();
    }
    return ( wspr::ws_strcmp( buf, other ) != 0 );
}


const ws_str & ws_str::operator += (const ws_char add)
{
    ws_char buf[2];
    buf[0] = add;
    buf[1] = 0;
    if (!m_pstr) {
        wscString::Allocate( &m_pstr , buf , 1 );
    }
    else {
        const ws_int oldlen = m_pstr->GetLength();
        wsiStringRW * tmp = WS_NULL;
        wscString::Allocate( &tmp , oldlen+1 , m_pstr->GetBuffer() , oldlen );
        if (tmp) {
            ws_char * rw = tmp->GetBufferRW();
            if (rw) rw[oldlen] = add;
            tmp->SetLength( oldlen + 1 );
        }
        m_pstr.Attach( tmp );
    }
    return (*this);
}


const ws_str & ws_str::operator += (wsiString * add)
{
    if (!m_pstr) {
        m_pstr = add;
    }
    else {
        wsiString * tmp = WS_NULL;
        m_pstr->Concat( &tmp , add );
        m_pstr.Attach( tmp );
    }
    return (*this);
}


const ws_str & ws_str::operator += (const ws_char * const add)
{
    if (!m_pstr) {
        wscString::Allocate( &m_pstr , add );
    }
    else {
        const ws_int oldlen = m_pstr->GetLength();
        const ws_int addlen = wspr::ws_strlen( add );
        wsiStringRW * tmp = WS_NULL;
        wscString::Allocate( &tmp , oldlen+addlen , m_pstr->GetBuffer() , oldlen );
        if (tmp) {
            ws_char * rw = tmp->GetBufferRW();
            if (rw) wspr::ws_memcpy( rw+oldlen , add , addlen );
            tmp->SetLength( oldlen + addlen );
        }
        m_pstr.Attach( tmp );
    }
    return (*this);
}


const ws_str & ws_str::operator += (const ws_str & add)
{
    if (!m_pstr) {
        m_pstr = add.m_pstr;
    }
    else {
        wsiString * tmp = WS_NULL;
        m_pstr->Concat( &tmp , add.m_pstr );
        m_pstr.Attach( tmp );
    }
    return (*this);
}


void ws_str::CopyTo(wsiString ** ret)
{
    m_pstr.CopyTo( ret );
}


ws_str::operator wsiString *(void)
{
    wsiString * ret = m_pstr;
    return ret;
}


ws_result ws_str::Trim(wsiString ** ret)
{
    if (!m_pstr) return WS_RLT_SUCCESS;
    return m_pstr->Trim(ret);
}

