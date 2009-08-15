#pragma once
#include <wcpp/lang/wsiObject.h>
#include <wcpp/lang/wscArray.h>
#include <wcpp/lang/wsiString.h>


class wsiFile;
class wsiFileFilter;
class wsiFilenameFilter;
class wsiURI;


typedef wsiArray<wsiFile> wsiFileArray;
typedef wscArray<wsiFile> wscFileArray;


#define WS_IID_OF_wsiFile       \
    { 0xcd292375, 0xf0e9, 0x4878, { 0xac, 0x72, 0xe2, 0xd7, 0x71, 0xcf, 0x62, 0x80 } }
// {CD292375-F0E9-4878-AC72-E2D771CF6280}


#define WS_IID_OF_wsiFileArray       \
    { 0x3853d381, 0x3bbc, 0x48f9, { 0xa5, 0x4e, 0xce, 0x12, 0x41, 0x8, 0x6, 0x35 } }
// {3853D381-3BBC-48f9-A54E-CE1241080635}


class wsiFile : public wsiObject
{
public:

    static const ws_iid sIID;

    static const ws_char * const sPathSeparator;     //          ��ϵͳ�йص�·���ָ�����Ϊ�˷��㣬������ʾΪһ���ַ����� 
    static const ws_char         sPathSeparatorChar; //          ��ϵͳ�йص�·���ָ����� 
    static const ws_char * const sSeparator;         //          ��ϵͳ�йص�Ĭ�����Ʒָ�����Ϊ�˷��㣬������ʾΪһ���ַ����� 
    static const ws_char         sSeparatorChar;     //          ��ϵͳ�йص�Ĭ�����Ʒָ����� 

public:

    WS_METHOD( ws_boolean , CanExecute       )(void) = 0;                                               // ����Ӧ�ó����Ƿ����ִ�д˳���·������ʾ���ļ��� 
    WS_METHOD( ws_boolean , CanRead          )(void) = 0;                                               // ����Ӧ�ó����Ƿ���Զ�ȡ�˳���·������ʾ���ļ��� 
    WS_METHOD( ws_boolean , CanWrite         )(void) = 0;                                               // ����Ӧ�ó����Ƿ�����޸Ĵ˳���·������ʾ���ļ��� 
    WS_METHOD( ws_int     , CompareTo        )(wsiFile * pathname) = 0;                                 // ����ĸ˳��Ƚ���������·������ 
    WS_METHOD( ws_boolean , CreateNewFile    )(void) = 0;                                               // ���ҽ��������ھ��д˳���·����ָ�����Ƶ��ļ�ʱ�����ɷֵش���һ���µĿ��ļ��� 
    WS_METHOD( ws_boolean , Delete           )(void) = 0;                                               // ɾ���˳���·������ʾ���ļ���Ŀ¼�� 
    WS_METHOD( ws_result  , DeleteOnExit     )(void) = 0;                                               // ���������ֹʱ������ɾ���˳���·������ʾ���ļ���Ŀ¼�� 
    WS_METHOD( ws_boolean , Equals           )(wsiObject * obj) = 0;                                    // ���Դ˳���·��������������Ƿ���ȡ� 
    WS_METHOD( ws_boolean , Exists           )(void) = 0;                                               // ���Դ˳���·������ʾ���ļ���Ŀ¼�Ƿ���ڡ� 
    WS_METHOD( ws_result  , GetAbsoluteFile  )(wsiFile ** ret) = 0;                                     // ���ش˳���·�����ľ���·������ʽ�� 
    WS_METHOD( ws_result  , GetAbsolutePath  )(wsiString ** ret) = 0;                                   // ���ش˳���·�����ľ���·�����ַ����� 
    WS_METHOD( ws_result  , GetCanonicalFile )(wsiFile ** ret) = 0;                                     // ���ش˳���·�����Ĺ淶��ʽ�� 
    WS_METHOD( ws_result  , GetCanonicalPath )(wsiString ** ret) = 0;                                   // ���ش˳���·�����Ĺ淶·�����ַ����� 
    WS_METHOD( ws_long    , GetFreeSpace     )(void) = 0;                                               // ���ش˳���·����ָ���ķ�����δ������ֽ�����
    WS_METHOD( ws_result  , GetName          )(wsiString ** ret) = 0;                                   // �����ɴ˳���·������ʾ���ļ���Ŀ¼�����ơ� 
    WS_METHOD( ws_result  , GetParent        )(wsiString ** ret) = 0;                                   // ���ش˳���·������Ŀ¼��·�����ַ����������·����û��ָ����Ŀ¼���򷵻� null�� 
    WS_METHOD( ws_result  , GetParentFile    )(wsiFile ** ret) = 0;                                     // ���ش˳���·������Ŀ¼�ĳ���·�����������·����û��ָ����Ŀ¼���򷵻� null�� 
    WS_METHOD( ws_result  , GetPath          )(wsiString ** ret) = 0;                                   // ���˳���·����ת��Ϊһ��·�����ַ����� 
    WS_METHOD( ws_long    , GetTotalSpace    )(void) = 0;                                               // ���ش˳���·����ָ���ķ�����С�� 
    WS_METHOD( ws_long    , GetUsableSpace   )(void) = 0;                                               // ���ش˳���·����ָ���ķ����Ͽ����ڴ���������ֽ����� 
    WS_METHOD( ws_int     , HashCode         )(void) = 0;                                               // ����˳���·�����Ĺ�ϣ�롣 
    WS_METHOD( ws_boolean , IsAbsolute       )(void) = 0;                                               // ���Դ˳���·�����Ƿ�Ϊ����·������ 
    WS_METHOD( ws_boolean , IsDirectory      )(void) = 0;                                               // ���Դ˳���·������ʾ���ļ��Ƿ���һ��Ŀ¼�� 
    WS_METHOD( ws_boolean , IsFile           )(void) = 0;                                               // ���Դ˳���·������ʾ���ļ��Ƿ���һ����׼�ļ��� 
    WS_METHOD( ws_boolean , IsHidden         )(void) = 0;                                               // ���Դ˳���·����ָ�����ļ��Ƿ���һ�������ļ��� 
    WS_METHOD( ws_long    , LastModified     )(void) = 0;                                               // ���ش˳���·������ʾ���ļ����һ�α��޸ĵ�ʱ�䡣 
    WS_METHOD( ws_long    , Length           )(void) = 0;                                               // �����ɴ˳���·������ʾ���ļ��ĳ��ȡ� 
    WS_METHOD( ws_result  , List             )(wsiStringArray ** ret) = 0;                              // ����һ���ַ������飬��Щ�ַ���ָ���˳���·������ʾ��Ŀ¼�е��ļ���Ŀ¼�� 
    WS_METHOD( ws_result  , List             )(wsiStringArray ** ret, wsiFilenameFilter * filter) = 0;  // ����һ���ַ������飬��Щ�ַ���ָ���˳���·������ʾ��Ŀ¼������ָ�����������ļ���Ŀ¼�� 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret) = 0;                                // ����һ������·�������飬��Щ·������ʾ�˳���·������ʾ��Ŀ¼�е��ļ��� 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret, wsiFileFilter * filter) = 0;        // ���س���·�������飬��Щ·������ʾ�˳���·������ʾ��Ŀ¼������ָ�����������ļ���Ŀ¼�� 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret, wsiFilenameFilter * filter) = 0;    // ���س���·�������飬��Щ·������ʾ�˳���·������ʾ��Ŀ¼������ָ�����������ļ���Ŀ¼�� 
    WS_METHOD( ws_boolean , Mkdir            )(void) = 0;                                               // �����˳���·����ָ����Ŀ¼�� 
    WS_METHOD( ws_boolean , Mkdirs           )(void) = 0;                                               // �����˳���·����ָ����Ŀ¼���������б��赫�����ڵĸ�Ŀ¼�� 
    WS_METHOD( ws_boolean , RenameTo         )(wsiFile * dest) = 0;                                     // ���������˳���·������ʾ���ļ��� 
    WS_METHOD( ws_boolean , SetExecutable    )(ws_boolean executable) = 0;                              // ���ô˳���·����������ִ��Ȩ�޵�һ����ݷ����� 
    WS_METHOD( ws_boolean , SetExecutable    )(ws_boolean executable, ws_boolean ownerOnly) = 0;        // ���ô˳���·�����������߻������û���ִ��Ȩ�ޡ� 
    WS_METHOD( ws_boolean , SetLastModified  )(ws_long time) = 0;                                       // ���ô˳���·����ָ�����ļ���Ŀ¼�����һ���޸�ʱ�䡣 
    WS_METHOD( ws_boolean , SetReadable      )(ws_boolean readable) = 0;                                // ���ô˳���·���������߶�Ȩ�޵�һ����ݷ����� 
    WS_METHOD( ws_boolean , SetReadable      )(ws_boolean readable, ws_boolean ownerOnly) = 0;          // ���ô˳���·�����������߻������û��Ķ�Ȩ�ޡ� 
    WS_METHOD( ws_boolean , SetReadOnly      )(void) = 0;                                               // ��Ǵ˳���·����ָ�����ļ���Ŀ¼���Ӷ�ֻ�ܶ�����ж������� 
    WS_METHOD( ws_boolean , SetWritable      )(ws_boolean writable) = 0;                                // ���ô˳���·����������дȨ�޵�һ����ݷ����� 
    WS_METHOD( ws_boolean , SetWritable      )(ws_boolean writable, ws_boolean ownerOnly) = 0;          // ���ô˳���·�����������߻������û���дȨ�ޡ� 
    WS_METHOD( ws_result  , ToString         )(wsiString ** ret) = 0;                                   // ���ش˳���·������·�����ַ����� 
    WS_METHOD( ws_result  , ToURI            )(wsiURI ** ret) = 0;                                      // ����һ����ʾ�˳���·������ file: URI�� 

};



