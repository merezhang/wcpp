#include "wscFile.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/lang/wscString.h>
#include <wcpp/wspr/wspr.h>
#include <wcpp/wspr/ws_file.h>
#include <wcpp/lang/helper/ws_str_buffer.h>
#include <list>
#include "wsiFilenameFilter.h"
#include "wsiFileFilter.h"


/*
**************************************************************************************************************************************
*   wscFile
**************************************************************************************************************************************
*/


#if   (WS_PLATFORM == WS_PLATFORM_WIN32)
    const ws_char * const wsiFile::sPathSeparator     = ";";     //          与系统有关的路径分隔符，为了方便，它被表示为一个字符串。 
    const ws_char         wsiFile::sPathSeparatorChar = ';';     //          与系统有关的路径分隔符。 
    const ws_char * const wsiFile::sSeparator         = "\\";    //          与系统有关的默认名称分隔符，为了方便，它被表示为一个字符串。 
    const ws_char         wsiFile::sSeparatorChar     = '\\';    //          与系统有关的默认名称分隔符。 
#elif (WS_PLATFORM == WS_PLATFORM_LINUX)
    const ws_char * const wsiFile::sPathSeparator     = ":";     //          与系统有关的路径分隔符，为了方便，它被表示为一个字符串。 
    const ws_char         wsiFile::sPathSeparatorChar = ':';     //          与系统有关的路径分隔符。 
    const ws_char * const wsiFile::sSeparator         = "/";     //          与系统有关的默认名称分隔符，为了方便，它被表示为一个字符串。 
    const ws_char         wsiFile::sSeparatorChar     = '/';     //          与系统有关的默认名称分隔符。 
#else
    #error no platform.
#endif




void wscFile::New(wsiFile ** ret, wsiFile * parent, wsiString * child)
{
    if ((parent==WS_NULL) || (child==WS_NULL)) {
        WS_THROW( wseNullPointerException , "" );
    }

    ws_ptr<wsiString> parentPath;
    parent->GetCanonicalPath( & parentPath );
    ws_str_buffer mixstr;
    mixstr += parentPath;
    mixstr += sSeparatorChar;
    mixstr += child;

    NewObj<wscFile>( ret );
    wscFile * pwscFile = dynamic_cast<wscFile*>(*ret);
    pwscFile->Init( mixstr.GetBuffer() , mixstr.GetLength() );
}


void wscFile::New(wsiFile ** ret, wsiString * pathname)
{
    if (pathname==WS_NULL) {
        WS_THROW( wseNullPointerException , "" );
    }
    NewObj<wscFile>( ret );
    wscFile * pwscFile = dynamic_cast<wscFile*>(*ret);
    pwscFile->Init( pathname->GetBuffer() , pathname->GetLength() );
}


void wscFile::New(wsiFile ** ret, wsiString * parent, wsiString * child)
{
    if ((parent==WS_NULL) || (child==WS_NULL)) {
        WS_THROW( wseNullPointerException , "" );
    }

    ws_str_buffer mixstr;
    mixstr += parent;
    mixstr += sSeparatorChar;
    mixstr += child;

    NewObj<wscFile>( ret );
    wscFile * pwscFile = dynamic_cast<wscFile*>(*ret);
    pwscFile->Init( mixstr.GetBuffer() , mixstr.GetLength() );
}


void wscFile::New(wsiFile ** ret, wsiURI * uri)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


void wscFile::Init(const ws_char * const aPathStrBuf, const ws_int aPathStrLen)
{
 //   WS_THROW( wseUnsupportedOperationException , "" );

    m_file = ws_file::Open();

    const ws_char * const end = aPathStrBuf + aPathStrLen;
    const ws_char * from = aPathStrBuf;
    const ws_char * to   = aPathStrBuf;

    for (const ws_char * p=aPathStrBuf; p<=end; p++) {
        const ws_char c = (*p);
        to = p;
        if ((c=='\\') || (c=='/') || (c==0)) {
            AddSubName( from , (ws_int)(to-from) );
            to ++ ;
            from = to;
        }
    }
//    AddSubName( from , (ws_int)(to-from) );
}


void wscFile::AddSubName(const ws_char * const buf, const ws_int len)
{
    ws_str str( buf , len );
    ws_ptr<wsiString> retstr;
    str.Trim( &retstr );
    str = static_cast<wsiString*>( retstr );

    if ((str==".") || (str=="")) return;

    if (str!="..") {
        m_namelist.push_back( str );
    }
    else {
        t_namelist_item item = m_namelist.back();
        if (item=="..") {
            m_namelist.push_back( str );
        }
        else {
            m_namelist.pop_back();
        }
    }
}


wscFile::wscFile(void) : m_file(WS_NULL)
{
}


wscFile::~wscFile(void)
{
    ws_file * f = m_file;
    m_file = WS_NULL;
    if (f) delete f;
}




ws_boolean wscFile::CanExecute(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::CanRead(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::CanWrite(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_int     wscFile::CompareTo(wsiFile * pathname) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::CreateNewFile(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::Delete(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_result       wscFile::DeleteOnExit(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::Equals(wsiObject * obj) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::Exists(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_result       wscFile::GetAbsoluteFile(wsiFile ** ret) { WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result wscFile::GetAbsolutePath(wsiString ** ret)
{
    ws_ptr<wsiString> pPath;
    GetPath( & pPath );
    pPath.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


ws_result       wscFile::GetCanonicalFile(wsiFile ** ret) { WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result wscFile::GetCanonicalPath(wsiString ** ret)
{
    ws_ptr<wsiString> aPath;
    GetAbsolutePath( & aPath );
    aPath.CopyTo( ret );
    return ws_result( WS_RLT_SUCCESS );
}


ws_long    wscFile::GetFreeSpace(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_result       wscFile::GetName(wsiString ** ret) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_result       wscFile::GetParent(wsiString ** ret) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_result       wscFile::GetParentFile(wsiFile ** ret) { WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result wscFile::GetPath(wsiString ** ret)
{
    ws_str_buffer str;
    for (t_namelist::iterator iter = m_namelist.begin(); iter != m_namelist.end(); iter++) {
        if (iter != m_namelist.begin()) {
            str += sSeparator;
        }
        str += static_cast<wsiString*>(*iter);
    }
    ws_ptr<wsiString> tmp(str);
    tmp.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


ws_long    wscFile::GetTotalSpace(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_long    wscFile::GetUsableSpace(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_int     wscFile::HashCode(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::IsAbsolute(void) { WS_THROW( wseUnsupportedOperationException , "" ); }


ws_boolean wscFile::IsDirectory(void)
{
    ws_ptr<wsiString> str;
    GetPath( &str );
    const ws_uint32 rlt = m_file->GetFileFlag( str->GetBuffer() , m_file->ff_IsDirectory );
    if (rlt == m_file->ff_ReturnFalse) {
        return WS_FALSE;
    }
    else {
        return ((rlt & m_file->ff_IsDirectory) ? WS_TRUE : WS_FALSE );
    }
}


ws_boolean wscFile::IsFile(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::IsHidden(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_long    wscFile::LastModified(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_long    wscFile::Length(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_result       wscFile::List(wsiStringArray ** ret) { WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result wscFile::List(wsiStringArray ** ret, wsiFilenameFilter * filter)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscFile::ListFiles(wsiFileArray ** ret)
{
    return InternalListFiles( ret , WS_NULL , WS_NULL );
}


ws_result wscFile::ListFiles(wsiFileArray ** ret, wsiFileFilter * filter)
{
    return InternalListFiles( ret , WS_NULL , filter );
}


ws_result wscFile::ListFiles(wsiFileArray ** ret, wsiFilenameFilter * filter)
{
    return InternalListFiles( ret , filter , WS_NULL );
}


ws_result wscFile::InternalListFiles(wsiFileArray ** ret, wsiFilenameFilter * aFNF, wsiFileFilter * aFF)
{
    if (!IsDirectory()) {
        return WS_RLT_FAILED;
    }

    ws_ptr<wsiString> dirpath;
    ws_result rlt = GetCanonicalPath( & dirpath );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    WS_ASSERT( m_file != WS_NULL );
    ws_file_enumerator * pEnum = m_file->EnumerateFiles( dirpath->GetBuffer() );
    std::auto_ptr<ws_file_enumerator> auto_pEnum( pEnum );
    if (pEnum==WS_NULL) return WS_RLT_ILLEGAL_STATE;

    struct t_tmplist_item {
        ws_ptr<wsiString> m_ptr;
    };
    typedef  std::list< t_tmplist_item > t_tmplist;
    t_tmplist  tmplist;

    ws_str_buffer strbuf;
    for ( ; pEnum->HasMore() ; pEnum->Next() ) {

        ws_int bufsize = strbuf.GetBufferSize();
        ws_int cb = pEnum->GetName( strbuf.GetBufferRW() , bufsize );
        if (bufsize < cb) {
            bufsize = cb * 2;
            bufsize = strbuf.ExtendBufferSize( bufsize );
            cb = pEnum->GetName( strbuf.GetBufferRW() , bufsize );
        }
        strbuf.SetLength( cb );

        if ((strbuf!=".") && (strbuf!="..")) {
            t_tmplist_item item;
            wscString::Allocate( & (item.m_ptr) , strbuf.GetBuffer() , strbuf.GetLength() );
            tmplist.push_back( item );
        }
    }

    ws_ptr< wsiArray<wsiFile> > fileArray;
    NewObj< wscArray<wsiFile> >( & fileArray , (ws_int)(tmplist.size()) );
    ws_int index = 0;

    for (t_tmplist::iterator iter=tmplist.begin(); iter!=tmplist.end(); iter++) {
        t_tmplist_item item = (*iter);

        ws_ptr<wsiFile> newfile;
        wscFile::New( &newfile , this , item.m_ptr );

        ws_boolean acceptFNF = WS_TRUE;
        if (aFNF) {
            acceptFNF = aFNF->Accept( this , item.m_ptr );
        }

        ws_boolean acceptFF = WS_TRUE;
        if (aFF) {
            acceptFF = aFF->Accept( newfile );
        }

        if (acceptFF && acceptFNF) {
            fileArray->PutItem( index++ , newfile );
        }
    }

    fileArray.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


ws_boolean wscFile::Mkdir(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::Mkdirs(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::RenameTo(wsiFile * dest) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::SetExecutable(ws_boolean executable) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::SetExecutable(ws_boolean executable, ws_boolean ownerOnly) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::SetLastModified(ws_long time) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::SetReadable(ws_boolean readable) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::SetReadable(ws_boolean readable, ws_boolean ownerOnly) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::SetReadOnly(void) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::SetWritable(ws_boolean writable) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_boolean wscFile::SetWritable(ws_boolean writable, ws_boolean ownerOnly) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_result       wscFile::ToString(wsiString ** ret) { WS_THROW( wseUnsupportedOperationException , "" ); }

ws_result       wscFile::ToURI(wsiURI ** ret) { WS_THROW( wseUnsupportedOperationException , "" ); }



