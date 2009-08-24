#include "wscString.h"
#include "wsoLangService.h"
#include "wscThrowable.h"




void wscString::Allocate(wsiString ** ret)
{
    if (ret==WS_NULL) {
        WS_THROW( wseNullPointerException , "" );
    }
    if (*ret) {
        WS_THROW( wseNullPointerException , "" );
    }
    wsiStringRW * retRW = WS_NULL;
    Allocate( &retRW, 0, WS_NULL, 0 );
    *ret = retRW;
}


void wscString::Allocate(wsiString ** ret, const ws_char * const buf)
{
    if (ret==WS_NULL) {
        WS_THROW( wseNullPointerException , "" );
    }
    if (*ret) {
        WS_THROW( wseNullPointerException , "" );
    }
    const ws_int len = wspr::ws_strlen(buf);
    wsiStringRW * retRW = WS_NULL;
    Allocate( &retRW, len, buf, len );
    *ret = retRW;
}


void wscString::Allocate(wsiString ** ret, const ws_char * const buf, ws_int len)
{
    if (ret==WS_NULL) {
        WS_THROW( wseNullPointerException , "" );
    }
    if (*ret) {
        WS_THROW( wseNullPointerException , "" );
    }
    wsiStringRW * retRW = WS_NULL;
    Allocate( &retRW, len, buf, len );
    *ret = retRW;
}


ws_int wscString::Allocate(wsiStringRW ** ret, ws_int aSize, const ws_char * const buf, ws_int len)
{
    New( ret , aSize , buf , len );
    return aSize;
}


void wscString::New(wsiString ** ret)
{
    if (ret==WS_NULL) WS_THROW( wseNullPointerException , "" );
    if (*ret)         WS_THROW( wseNullPointerException , "" );
    wsiStringRW * psrw = WS_NULL;
    New( &psrw , 0 , WS_NULL , 0 );
    *ret = psrw;
}


void wscString::New(wsiString ** ret, const ws_char* const buf)
{
    if (ret==WS_NULL) WS_THROW( wseNullPointerException , "" );
    if (*ret)         WS_THROW( wseNullPointerException , "" );
    const ws_int len = wspr::ws_strlen(buf);
    wsiStringRW * psrw = WS_NULL;
    New( &psrw , len , buf , len );
    *ret = psrw;
}


void wscString::New(wsiString ** ret, const ws_char * const buf, ws_int len)
{
    if (ret==WS_NULL) WS_THROW( wseNullPointerException , "" );
    if (*ret)         WS_THROW( wseNullPointerException , "" );
    wsiStringRW * psrw = WS_NULL;
    New( &psrw , len , buf , len );
    *ret = psrw;
}


void wscString::New(wsiStringRW **ret, ws_int aSize, const ws_char *const buf, ws_int len)
{
    if (ret==WS_NULL) WS_THROW( wseNullPointerException , "" );
    if (*ret)         WS_THROW( wseNullPointerException , "" );
    wscString * pnew = WS_NULL;
    wscObjectFinal<wscString>::New( &pnew );
    (*ret) = pnew;
    pnew->InternalInit( WS_NULL , aSize );
    pnew->SetString( buf, len );
}


void wscString::GetStringService(wsiStringService ** ret)
{
    static ws_ptr<wsiStringService> cache;

    ws_int timeout = 5;
    do {
        cache.CopyTo( ret );
        if (*ret) return;
    } while ((timeout--)>0) ;

    ws_ptr<wsiLangService> ls;
    wsoLangService::GetLangService( & ls );
    ls->GetStringService( ret );
    cache = (*ret);
}




void wscString::InternalInit(wsiStringService * aStrServ, ws_int aSize)
{
    if (m_pdb) {
        WS_THROW( wseError , "wscString re-init !" );
    }
    if (aSize<0) {
        WS_THROW( wseNegativeArraySizeException , "The buffer size of the string cannot be negative !" );
    }

    ws_byte * pb = new ws_byte[ sizeof(_data_block) + aSize ];
    if (pb == WS_NULL) {
        WS_THROW( wseOutOfMemoryError , "wscString alloc a null block !" );
    }
    else {
        _data_block * pdb = (_data_block *) pb;
        pdb->buf[0] = 0;
        pdb->len    = 0;
        pdb->cap    = aSize;
        pdb->addr   = pb;
        m_pdb = pdb;
    }

    m_pStrServ = aStrServ;
}


wscString::wscString(void) : m_pdb(WS_NULL)
{
}


wscString::~wscString(void)
{
    _data_block * const pdb = m_pdb;
    m_pdb = WS_NULL;
    if (pdb) {
        ws_byte * const pb = ((ws_byte*)pdb);
        if (pb != pdb->addr) {
            WS_THROW( wseError , "wscString::~wscString() {pb != pdb->pbytes}" );
        }
        delete []pb;
    }
}





ws_char     wscString::CharAt(ws_int index) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return 0;
}


ws_int      wscString::CodePointAt(ws_int index) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return 0;
}


ws_int      wscString::CodePointBefore(ws_int index) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return 0;
}


ws_int      wscString::CodePointCount(ws_int beginIndex, ws_int endIndex) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return 0;
}


ws_int      wscString::CompareTo(wsiString * anotherString) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_int      wscString::CompareToIgnoreCase(wsiString * str) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_result wscString::Concat(wsiString ** ret, wsiString * str) const
{
    ws_ptr<wsiString> strAdd (str);
    const ws_int len1 = GetLength();
    const ws_int len2 = strAdd->GetLength();
    const ws_char * const buf1 = GetBuffer();
    const ws_char * const buf2 = strAdd->GetBuffer();

    ws_ptr<wsiStringService> strServ;
    wscString::GetStringService( &strServ );
    ws_ptr<wsiStringRW> strRW;
    strServ->AllocateString( &strRW , len1+len2 , buf1 , len1 );
    ws_char * const buf = strRW->GetBufferRW();
    wspr::ws_memcpy( buf+len1 , buf2 , len2 );
    strRW->SetLength( len1 + len2 );

    ws_ptr<wsiString> pstr( strRW );
    pstr.CopyTo( ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_boolean  wscString::Contains(wsiCharSequence * s) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_boolean  wscString::ContentEquals(wsiCharSequence * cs) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_boolean  wscString::ContentEquals(wsiStringBuffer * sb) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_boolean  wscString::EndsWith(wsiString * suffix) const
{
    WS_ASSERT( m_pdb != WS_NULL );
    if (suffix==WS_NULL) {
        return WS_FALSE;
    }
    const ws_char * const  target_buf = m_pdb->buf;
    const ws_int           target_len = m_pdb->len;
    const ws_char * const  suffix_buf = suffix->GetBuffer();
    const ws_int           suffix_len = suffix->GetLength();
    if ( suffix_len <= target_len ) {
        return (   wspr::ws_memcmp( target_buf+(target_len-suffix_len) , suffix_buf , suffix_len ) ==0  );
    }
    else {
        return WS_FALSE;
    }
}


ws_boolean  wscString::Equals(wsiObject * anObject) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_boolean  wscString::EqualsIgnoreCase(wsiString * anotherString) const
{
    if (anotherString==WS_NULL) return WS_FALSE;
    const ws_char * const anBuf = anotherString->GetBuffer();
    const ws_int          anLen = anotherString->GetLength();
    const ws_char * const myBuf = GetBuffer();
    const ws_int          myLen = GetLength();
    if ((anBuf==WS_NULL) || (myBuf==WS_NULL) || (myLen<0) || (anLen<0)) {
        return WS_FALSE;
    }
    if (myLen != anLen) {
        return WS_FALSE;
    }
    for ( ws_int i=(anLen-1); i>=0 ; i-- ) {
        int c1 = anBuf[i];
        int c2 = myBuf[i];
        if (('A'<=c1) && (c1<='Z')) c1 = (c1 - 'A' + 'a');
        if (('A'<=c2) && (c2<='Z')) c2 = (c2 - 'A' + 'a');
        if (c1 != c2) return WS_FALSE;
    }
    return WS_TRUE;
}


ws_result        wscString::GetBytes(wsiByteArray ** ret) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::GetBytes(wsiByteArray ** ret, wsiCharset * charset) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::GetBytes(wsiByteArray ** ret, wsiString * charsetName) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::GetChars(ws_int srcBegin, ws_int srcEnd, ws_char * dst, ws_int dstSize) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_int      wscString::HashCode(void) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_int      wscString::IndexOf(ws_int ch) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_int      wscString::IndexOf(ws_int ch, ws_int fromIndex) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_int      wscString::IndexOf(wsiString * str) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_int      wscString::IndexOf(wsiString * str, ws_int fromIndex) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_result        wscString::Intern(wsiString ** ret) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_boolean  wscString::IsEmpty(void) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_int      wscString::LastIndexOf(ws_int ch) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_int      wscString::LastIndexOf(ws_int ch, ws_int fromIndex) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_int      wscString::LastIndexOf(wsiString * str) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_int      wscString::LastIndexOf(wsiString * str, ws_int fromIndex) const 
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_int wscString::Length(void) const
{
    if (m_pdb) {
        return m_pdb->len;
    }
    else {
        WS_THROW( wseIllegalStateException , "" );
        return 0;
    }
}


ws_boolean  wscString::Matches(wsiString * regex) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_int      wscString::OffsetByCodePoints(ws_int index, ws_int codePointOffset) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return -1;
}


ws_boolean  wscString::RegionMatches(ws_boolean ignoreCase, ws_int toffset, wsiString * other, ws_int ooffset, ws_int len) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_boolean  wscString::RegionMatches(ws_int toffset, wsiString * other, ws_int ooffset, ws_int len) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_result        wscString::Replace(wsiString ** ret, ws_char oldChar, ws_char newChar) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::Replace(wsiString ** ret, wsiCharSequence * target, wsiCharSequence * replacement) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::ReplaceAll(wsiString ** ret, wsiString * regex, wsiString * replacement) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::ReplaceFirst(wsiString ** ret, wsiString * regex, wsiString * replacement) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::Split(wsiStringArray ** ret, wsiString * regex) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::Split(wsiStringArray ** ret, wsiString * regex, ws_int limit) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_boolean  wscString::StartsWith(wsiString * prefix) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_boolean  wscString::StartsWith(wsiString * prefix, ws_int toffset) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return WS_FALSE;
}


ws_result        wscString::SubSequence(wsiCharSequence ** ret, ws_int beginIndex, ws_int endIndex) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::Substring(wsiString ** ret, ws_int beginIndex) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::Substring(wsiString ** ret, ws_int beginIndex, ws_int endIndex) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::ToCharArray(wsiCharArray ** ret) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result wscString::ToLowerCase(wsiString ** ret) const
{
    if (ret==WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }
    if (*ret) {
        return WS_RLT_NULL_POINTER;
    }
    WS_ASSERT( m_pdb != WS_NULL );
    const ws_char * const buf = m_pdb->buf;
    const ws_int len = m_pdb->len;
    ws_ptr<wsiStringRW> tmp;
    wscString::Allocate( &tmp , len , buf , len );
    ws_char * rw = tmp->GetBufferRW();
    for (ws_int i=(len-1); i>=0; i--) {
        const ws_char c = rw[i];
        if (('A' <= c) && (c <= 'Z')) {
            rw[i] = (c - 'A') + 'a';
        }
    }
    *ret = tmp.Detach();
    return WS_RLT_SUCCESS;
}


ws_result        wscString::ToLowerCase(wsiString ** ret, wsiLocale * locale) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result        wscString::ToString(wsiString ** ret) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result wscString::ToUpperCase(wsiString ** ret) const
{
    if (ret==WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }
    if (*ret) {
        return WS_RLT_NULL_POINTER;
    }
    WS_ASSERT( m_pdb != WS_NULL );
    const ws_char * const buf = m_pdb->buf;
    const ws_int len = m_pdb->len;
    ws_ptr<wsiStringRW> tmp;
    wscString::Allocate( &tmp , len , buf , len );
    ws_char * rw = tmp->GetBufferRW();
    for (ws_int i=(len-1); i>=0; i--) {
        const ws_char c = rw[i];
        if (('a' <= c) && (c <= 'z')) {
            rw[i] = (c - 'a') + 'A';
        }
    }
    *ret = tmp.Detach();
    return WS_RLT_SUCCESS;
}


ws_result        wscString::ToUpperCase(wsiString ** ret, wsiLocale * locale) const
{
    WS_THROW( wseUnsupportedOperationException,"");
    return ws_result( WS_RLT_UNSUPPORTED_OPERATION );
}


ws_result wscString::Trim(wsiString ** ret) const
{
    if (m_pdb==WS_NULL) {
        WS_THROW( wseIllegalStateException , "" );
    }
    if (ret==WS_NULL) {
        WS_THROW( wseNullPointerException , "" );
    }
    if (*ret) {
        WS_THROW( wseIllegalStateException , "" );
    }

    const ws_char * const pSrcHead = m_pdb->buf;
    const ws_char * const pSrcTail = m_pdb->buf + m_pdb->len;
    const ws_char * from = pSrcHead;
    const ws_char * to   = pSrcTail;
    while (from < pSrcTail) {
        if ((*from) > ' ') break;
        from ++ ;
    }
    while (pSrcHead <= to) {
        if ((*to) > ' ') break;
        to -- ;
    }
    if (from <= to) {
        ws_str str( from , (ws_int)((to - from)+1) );
        str.CopyTo( ret );
    }
    else {
        ws_str str( "" );
        str.CopyTo( ret );
    }
    return ws_result( WS_RLT_SUCCESS );
}






const ws_char * const   wscString::GetBuffer(void) const
{
    if (m_pdb) {
        return m_pdb->buf;
    }
    else {
        WS_THROW( wseIllegalStateException , "" );
        return WS_NULL;
    }
}


ws_int wscString::GetLength(void) const
{
    if (m_pdb) {
        return m_pdb->len;
    }
    else {
        WS_THROW( wseIllegalStateException , "" );
        return 0;
    }
}




ws_char* wscString::GetBufferRW(void)
{
    if (m_pdb) {
        return m_pdb->buf;
    }
    else {
        WS_THROW( wseIllegalStateException , "" );
        return WS_NULL;
    }
}


ws_int   wscString::GetBufferSize(void) const
{
    if (m_pdb) {
        return m_pdb->cap;
    }
    else {
        WS_THROW( wseIllegalStateException , "" );
        return 0;
    }
}


ws_int wscString::SetLength(ws_int newLength)
{
    if (m_pdb) {
        const ws_int nlen = WS_MIN( newLength , m_pdb->cap );
        m_pdb->len = nlen;
        m_pdb->buf[nlen] = 0;
        return nlen;
    }
    else {
        return 0;
    }
}


ws_int   wscString::SetString(const ws_char * const buf, ws_int newLength)
{
    if (newLength < 0) {
        WS_THROW( wseStringIndexOutOfBoundsException , "" );
    }

    if (m_pdb) {
        const ws_int len = WS_MIN( newLength , m_pdb->cap );
        wspr::ws_memcpy( m_pdb->buf , buf , len );
        m_pdb->len = len;
        m_pdb->buf[len] = 0;
        if (len == newLength) return len;
    }
    else {
        WS_THROW( wseIllegalAccessException , "" );
    }

    WS_THROW( wseStringIndexOutOfBoundsException , "" );

    return 0;
}


ws_boolean wscString::InternalEquals(wsiObject * obj)
{
    if (obj==WS_NULL) return WS_FALSE;
    ws_ptr<wsiString> objstr;
    ws_result rlt = obj->QueryInterface( objstr.GetIID() , (void**)(&objstr) );
    if (rlt != WS_RLT_SUCCESS) return WS_FALSE;
    const ws_char * const anBuf = objstr->GetBuffer();
    const ws_int          anLen = objstr->GetLength();
    const ws_char * const myBuf = GetBuffer();
    const ws_int          myLen = GetLength();
    if ((anBuf==WS_NULL) || (myBuf==WS_NULL) || (myLen<0) || (anLen<0)) {
        return WS_FALSE;
    }
    if (myLen != anLen) {
        return WS_FALSE;
    }
    for ( ws_int i=(anLen-1); i>=0 ; i-- ) {
        int c1 = anBuf[i];
        int c2 = myBuf[i];
        if (c1 != c2) return WS_FALSE;
    }
    return WS_TRUE;
}


ws_int wscString::InternalHashCode(void)
{
    if (m_pdb==WS_NULL) {
        return 0;
    }
    else {
        const ws_byte * const buf = (const ws_byte* const)(m_pdb->buf);
        ws_byte sum[4] = {0,0,0,0};
        for (ws_int i=m_pdb->len; i>=0; i--) {
            sum[i % 4] ^= buf[i];
        }
        ws_uint32 ret = sum[0];
        ret <<= 8;      ret |= sum[1];
        ret <<= 8;      ret |= sum[2];
        ret <<= 8;      ret |= sum[3];
        return ret;
    }
}

