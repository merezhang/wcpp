#pragma once

#include "wsiFile.h"
#include <wcpp/lang/wscObject.h>
#include <wcpp/lang/wscString.h>
#include <vector>


class ws_file;


class wscFile : public wscObject, public wsiFile
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscFile )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiFile )
    WS_IMPL_QUERY_INTERFACE_END()

public:     // profile

    typedef  wscFile   t_this_class;
    static const ws_char * const s_class_name;

public:

    static void New(wsiFile ** ret, wsiFile * parent, wsiString * child);
    static void New(wsiFile ** ret, wsiString * pathname);
    static void New(wsiFile ** ret, wsiString * parent, wsiString * child);
    static void New(wsiFile ** ret, wsiURI * uri);

protected:

    wscFile(void);
    ~wscFile(void);

public:

    static void CreateTempFile(wsiString * prefix, wsiString * suffix, wsiFile ** ret);
            // ��Ĭ����ʱ�ļ�Ŀ¼�д���һ�����ļ���ʹ�ø���ǰ׺�ͺ�׺���������ơ� 
    static void CreateTempFile(wsiString * prefix, wsiString * suffix, wsiFile * directory, wsiFile ** ret);
            // ��ָ��Ŀ¼�д���һ���µĿ��ļ���ʹ�ø�����ǰ׺�ͺ�׺�ַ������������ơ� 
    static void ListRoots(wsiFileArray ** ret);
            // �г����õ��ļ�ϵͳ���� 

protected:
    WS_METHOD( ws_boolean , CanExecute       )(void);                                               // ����Ӧ�ó����Ƿ����ִ�д˳���·������ʾ���ļ��� 
    WS_METHOD( ws_boolean , CanRead          )(void);                                               // ����Ӧ�ó����Ƿ���Զ�ȡ�˳���·������ʾ���ļ��� 
    WS_METHOD( ws_boolean , CanWrite         )(void);                                               // ����Ӧ�ó����Ƿ�����޸Ĵ˳���·������ʾ���ļ��� 
    WS_METHOD( ws_int     , CompareTo        )(wsiFile * pathname);                                 // ����ĸ˳��Ƚ���������·������ 
    WS_METHOD( ws_boolean , CreateNewFile    )(void);                                               // ���ҽ��������ھ��д˳���·����ָ�����Ƶ��ļ�ʱ�����ɷֵش���һ���µĿ��ļ��� 
    WS_METHOD( ws_boolean , Delete           )(void);                                               // ɾ���˳���·������ʾ���ļ���Ŀ¼�� 
    WS_METHOD( ws_result  , DeleteOnExit     )(void);                                               // ���������ֹʱ������ɾ���˳���·������ʾ���ļ���Ŀ¼�� 
    WS_METHOD( ws_boolean , Equals           )(wsiObject * obj);                                    // ���Դ˳���·��������������Ƿ���ȡ� 
    WS_METHOD( ws_boolean , Exists           )(void);                                               // ���Դ˳���·������ʾ���ļ���Ŀ¼�Ƿ���ڡ� 
    WS_METHOD( ws_result  , GetAbsoluteFile  )(wsiFile ** ret);                                     // ���ش˳���·�����ľ���·������ʽ�� 
    WS_METHOD( ws_result  , GetAbsolutePath  )(wsiString ** ret);                                   // ���ش˳���·�����ľ���·�����ַ����� 
    WS_METHOD( ws_result  , GetCanonicalFile )(wsiFile ** ret);                                     // ���ش˳���·�����Ĺ淶��ʽ�� 
    WS_METHOD( ws_result  , GetCanonicalPath )(wsiString ** ret);                                   // ���ش˳���·�����Ĺ淶·�����ַ����� 
    WS_METHOD( ws_long    , GetFreeSpace     )(void);                                               // ���ش˳���·����ָ���ķ�����δ������ֽ�����
    WS_METHOD( ws_result  , GetName          )(wsiString ** ret);                                   // �����ɴ˳���·������ʾ���ļ���Ŀ¼�����ơ� 
    WS_METHOD( ws_result  , GetParent        )(wsiString ** ret);                                   // ���ش˳���·������Ŀ¼��·�����ַ����������·����û��ָ����Ŀ¼���򷵻� null�� 
    WS_METHOD( ws_result  , GetParentFile    )(wsiFile ** ret);                                     // ���ش˳���·������Ŀ¼�ĳ���·�����������·����û��ָ����Ŀ¼���򷵻� null�� 
    WS_METHOD( ws_result  , GetPath          )(wsiString ** ret);                                   // ���˳���·����ת��Ϊһ��·�����ַ����� 
    WS_METHOD( ws_long    , GetTotalSpace    )(void);                                               // ���ش˳���·����ָ���ķ�����С�� 
    WS_METHOD( ws_long    , GetUsableSpace   )(void);                                               // ���ش˳���·����ָ���ķ����Ͽ����ڴ���������ֽ����� 
    WS_METHOD( ws_int     , HashCode         )(void);                                               // ����˳���·�����Ĺ�ϣ�롣 
    WS_METHOD( ws_boolean , IsAbsolute       )(void);                                               // ���Դ˳���·�����Ƿ�Ϊ����·������ 
    WS_METHOD( ws_boolean , IsDirectory      )(void);                                               // ���Դ˳���·������ʾ���ļ��Ƿ���һ��Ŀ¼�� 
    WS_METHOD( ws_boolean , IsFile           )(void);                                               // ���Դ˳���·������ʾ���ļ��Ƿ���һ����׼�ļ��� 
    WS_METHOD( ws_boolean , IsHidden         )(void);                                               // ���Դ˳���·����ָ�����ļ��Ƿ���һ�������ļ��� 
    WS_METHOD( ws_long    , LastModified     )(void);                                               // ���ش˳���·������ʾ���ļ����һ�α��޸ĵ�ʱ�䡣 
    WS_METHOD( ws_long    , Length           )(void);                                               // �����ɴ˳���·������ʾ���ļ��ĳ��ȡ� 
    WS_METHOD( ws_result  , List             )(wsiStringArray ** ret);                              // ����һ���ַ������飬��Щ�ַ���ָ���˳���·������ʾ��Ŀ¼�е��ļ���Ŀ¼�� 
    WS_METHOD( ws_result  , List             )(wsiStringArray ** ret, wsiFilenameFilter * filter);  // ����һ���ַ������飬��Щ�ַ���ָ���˳���·������ʾ��Ŀ¼������ָ�����������ļ���Ŀ¼�� 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret);                                // ����һ������·�������飬��Щ·������ʾ�˳���·������ʾ��Ŀ¼�е��ļ��� 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret, wsiFileFilter * filter);        // ���س���·�������飬��Щ·������ʾ�˳���·������ʾ��Ŀ¼������ָ�����������ļ���Ŀ¼�� 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret, wsiFilenameFilter * filter);    // ���س���·�������飬��Щ·������ʾ�˳���·������ʾ��Ŀ¼������ָ�����������ļ���Ŀ¼�� 
    WS_METHOD( ws_boolean , Mkdir            )(void);                                               // �����˳���·����ָ����Ŀ¼�� 
    WS_METHOD( ws_boolean , Mkdirs           )(void);                                               // �����˳���·����ָ����Ŀ¼���������б��赫�����ڵĸ�Ŀ¼�� 
    WS_METHOD( ws_boolean , RenameTo         )(wsiFile * dest);                                     // ���������˳���·������ʾ���ļ��� 
    WS_METHOD( ws_boolean , SetExecutable    )(ws_boolean executable);                              // ���ô˳���·����������ִ��Ȩ�޵�һ����ݷ����� 
    WS_METHOD( ws_boolean , SetExecutable    )(ws_boolean executable, ws_boolean ownerOnly);        // ���ô˳���·�����������߻������û���ִ��Ȩ�ޡ� 
    WS_METHOD( ws_boolean , SetLastModified  )(ws_long time);                                       // ���ô˳���·����ָ�����ļ���Ŀ¼�����һ���޸�ʱ�䡣 
    WS_METHOD( ws_boolean , SetReadable      )(ws_boolean readable);                                // ���ô˳���·���������߶�Ȩ�޵�һ����ݷ����� 
    WS_METHOD( ws_boolean , SetReadable      )(ws_boolean readable, ws_boolean ownerOnly);          // ���ô˳���·�����������߻������û��Ķ�Ȩ�ޡ� 
    WS_METHOD( ws_boolean , SetReadOnly      )(void);                                               // ��Ǵ˳���·����ָ�����ļ���Ŀ¼���Ӷ�ֻ�ܶ�����ж������� 
    WS_METHOD( ws_boolean , SetWritable      )(ws_boolean writable);                                // ���ô˳���·����������дȨ�޵�һ����ݷ����� 
    WS_METHOD( ws_boolean , SetWritable      )(ws_boolean writable, ws_boolean ownerOnly);          // ���ô˳���·�����������߻������û���дȨ�ޡ� 
    WS_METHOD( ws_result  , ToString         )(wsiString ** ret);                                   // ���ش˳���·������·�����ַ����� 
    WS_METHOD( ws_result  , ToURI            )(wsiURI ** ret);                                      // ����һ����ʾ�˳���·������ file: URI�� 
private:
    void Init(const ws_char * const aPathStrBuf, const ws_int aPathStrLen);
    void AddSubName(const ws_char * const buf, const ws_int len);
    ws_result InternalListFiles(wsiFileArray ** ret, wsiFilenameFilter * aFNF , wsiFileFilter * aFF );

private:
    
    ws_file * m_file;

    typedef ws_str                       t_namelist_item;
    typedef std::vector<t_namelist_item> t_namelist;

    t_namelist m_namelist;

};

