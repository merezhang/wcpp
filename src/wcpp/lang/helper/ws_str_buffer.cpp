#include "ws_str_buffer.h"
#include <wcpp/lang/wscString.h>


ws_str_buffer::ws_str_buffer(void)
{
}


ws_str_buffer::~ws_str_buffer(void)
{
}


const ws_str_buffer & ws_str_buffer::operator +=(ws_char chr)
{
    ws_ptr<wsiStringRW> tmp;
    tmp.Attach( m_pstr.Detach() );

    if (!tmp) {
        ws_char buf[] = { chr , 0 };
        wscString::Allocate( &tmp , 256 , buf , 1 );
    }
    else {
        const ws_int oldcap = tmp->GetBufferSize();
        const ws_int oldlen = tmp->GetLength();
        WS_ASSERT( oldlen <= oldcap );
        if (oldlen==oldcap) {
            ws_ptr<wsiStringRW> pnew;
            wscString::Allocate( &pnew , WS_MAX((oldlen*2),256) , tmp->GetBuffer() , oldlen );
            tmp = pnew;
        }
        ws_char * rwbuf = tmp->GetBufferRW();
        WS_ASSERT( rwbuf != WS_NULL );
        rwbuf[oldlen] = chr;
        tmp->SetLength( oldlen + 1 );
    }

    m_pstr.Attach( tmp.Detach() );
    return (*this);
}


ws_int ws_str_buffer::ExtendBufferSize(ws_int newSize)
{
    if (newSize < 16) newSize = 16;
    ws_ptr<wsiStringRW> tmp;
    tmp.Attach( m_pstr.Detach() );
    if (!tmp) {
        wscString::Allocate( &tmp, newSize, WS_NULL, 0 );
    }
    else {
        const ws_int oldSize = tmp->GetBufferSize();
        if (oldSize < newSize) {
            ws_ptr<wsiStringRW> newBuf;
            wscString::Allocate( &newBuf , newSize , tmp->GetBuffer() , tmp->GetLength() );
            tmp.Attach( newBuf.Detach() );
        }
    }
    m_pstr.Attach( tmp.Detach() );
    return newSize;
}


ws_int ws_str_buffer::SetLength(ws_int newLength)
{
    ws_ptr<wsiStringRW> tmp;
    tmp.Attach( m_pstr.Detach() );
    if (!tmp) return 0;
    ws_int ret = tmp->SetLength(newLength);
    m_pstr.Attach( tmp.Detach() );
    return ret;
}


ws_str_buffer::operator const ws_char * const (void)
{
    wsiStringRW * tmp = m_pstr;
    if (!tmp) return WS_NULL;
    else      return tmp->GetBuffer();
}


ws_int ws_str_buffer::GetLength(void) const
{
    wsiString * p = m_pstr;
    if (p) {
        return p->GetLength();
    }
    else {
        return 0;
    }
}


ws_char * ws_str_buffer::GetBufferRW(void)
{
    wsiStringRW * pstr = m_pstr;
    if (pstr) {
        return pstr->GetBufferRW();
    }
    else {
        return WS_NULL;
    }
}


const ws_char * ws_str_buffer::GetBuffer() const
{
    wsiString * p = m_pstr;
    if (p) {
        return p->GetBuffer();
    }
    else {
        return 0;
    }
}


ws_int ws_str_buffer::GetBufferSize(void) const
{
    wsiStringRW * p = m_pstr;
    if (p) {
        return p->GetBufferSize();
    }
    else {
        return 0;
    }
}


ws_str_buffer const & ws_str_buffer::operator+=(wsiString * src)
{
    if (src) AddString( src->GetBuffer() , src->GetLength() );
    return (*this);
}


ws_str_buffer::operator wsiStringRW *(void)
{
    wsiStringRW * ret = m_pstr;
    return ret;
}


const ws_str_buffer & ws_str_buffer::operator +=(const ws_char * const src)
{
    if (src) {
        ws_int len = wspr::ws_strlen( src );
        AddString( src , len );
    }
    return (*this);
}


void ws_str_buffer::AddString(const ws_char *const buf, ws_int addlen)
{
    if (!m_pstr) {
        ws_int sz = addlen * 2;
        sz = WS_MAX( sz , 32 );
        wscString::Allocate( &m_pstr , sz , buf , addlen );
    }
    else {
        const ws_int oldsize = m_pstr->GetBufferSize();
        const ws_int oldlen = m_pstr->GetLength();
        if ((oldlen + addlen) <= oldsize) {
            ws_char * rw = m_pstr->GetBufferRW();
            wspr::ws_memcpy( rw + oldlen , buf , addlen );
            m_pstr->SetLength( oldlen + addlen );
        }
        else {
            ws_int newsize = (oldlen + addlen) * 2;
            newsize = WS_MAX( newsize , 32 );
            ws_ptr<wsiStringRW> newbuf;
            wscString::Allocate( &newbuf , newsize , m_pstr->GetBuffer() , oldlen );
            if (!newbuf) return;
            ws_char * rw = newbuf->GetBufferRW();
            wspr::ws_memcpy( rw+oldlen , buf , addlen );
            newbuf->SetLength( oldlen + addlen );
            m_pstr.Attach( newbuf.Detach() );
        }
    }
}


bool ws_str_buffer::operator != (const ws_char * const str) const
{
    if (!m_pstr) {
        return true;
    }
    else {
        const ws_char * const buf = m_pstr->GetBuffer();
        return ( wspr::ws_strcmp(str,buf) != 0 );
    }
}

