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
            // 在默认临时文件目录中创建一个空文件，使用给定前缀和后缀生成其名称。 
    static void CreateTempFile(wsiString * prefix, wsiString * suffix, wsiFile * directory, wsiFile ** ret);
            // 在指定目录中创建一个新的空文件，使用给定的前缀和后缀字符串生成其名称。 
    static void ListRoots(wsiFileArray ** ret);
            // 列出可用的文件系统根。 

protected:
    WS_METHOD( ws_boolean , CanExecute       )(void);                                               // 测试应用程序是否可以执行此抽象路径名表示的文件。 
    WS_METHOD( ws_boolean , CanRead          )(void);                                               // 测试应用程序是否可以读取此抽象路径名表示的文件。 
    WS_METHOD( ws_boolean , CanWrite         )(void);                                               // 测试应用程序是否可以修改此抽象路径名表示的文件。 
    WS_METHOD( ws_int     , CompareTo        )(wsiFile * pathname);                                 // 按字母顺序比较两个抽象路径名。 
    WS_METHOD( ws_boolean , CreateNewFile    )(void);                                               // 当且仅当不存在具有此抽象路径名指定名称的文件时，不可分地创建一个新的空文件。 
    WS_METHOD( ws_boolean , Delete           )(void);                                               // 删除此抽象路径名表示的文件或目录。 
    WS_METHOD( ws_result  , DeleteOnExit     )(void);                                               // 在虚拟机终止时，请求删除此抽象路径名表示的文件或目录。 
    WS_METHOD( ws_boolean , Equals           )(wsiObject * obj);                                    // 测试此抽象路径名与给定对象是否相等。 
    WS_METHOD( ws_boolean , Exists           )(void);                                               // 测试此抽象路径名表示的文件或目录是否存在。 
    WS_METHOD( ws_result  , GetAbsoluteFile  )(wsiFile ** ret);                                     // 返回此抽象路径名的绝对路径名形式。 
    WS_METHOD( ws_result  , GetAbsolutePath  )(wsiString ** ret);                                   // 返回此抽象路径名的绝对路径名字符串。 
    WS_METHOD( ws_result  , GetCanonicalFile )(wsiFile ** ret);                                     // 返回此抽象路径名的规范形式。 
    WS_METHOD( ws_result  , GetCanonicalPath )(wsiString ** ret);                                   // 返回此抽象路径名的规范路径名字符串。 
    WS_METHOD( ws_long    , GetFreeSpace     )(void);                                               // 返回此抽象路径名指定的分区中未分配的字节数。
    WS_METHOD( ws_result  , GetName          )(wsiString ** ret);                                   // 返回由此抽象路径名表示的文件或目录的名称。 
    WS_METHOD( ws_result  , GetParent        )(wsiString ** ret);                                   // 返回此抽象路径名父目录的路径名字符串；如果此路径名没有指定父目录，则返回 null。 
    WS_METHOD( ws_result  , GetParentFile    )(wsiFile ** ret);                                     // 返回此抽象路径名父目录的抽象路径名；如果此路径名没有指定父目录，则返回 null。 
    WS_METHOD( ws_result  , GetPath          )(wsiString ** ret);                                   // 将此抽象路径名转换为一个路径名字符串。 
    WS_METHOD( ws_long    , GetTotalSpace    )(void);                                               // 返回此抽象路径名指定的分区大小。 
    WS_METHOD( ws_long    , GetUsableSpace   )(void);                                               // 返回此抽象路径名指定的分区上可用于此虚拟机的字节数。 
    WS_METHOD( ws_int     , HashCode         )(void);                                               // 计算此抽象路径名的哈希码。 
    WS_METHOD( ws_boolean , IsAbsolute       )(void);                                               // 测试此抽象路径名是否为绝对路径名。 
    WS_METHOD( ws_boolean , IsDirectory      )(void);                                               // 测试此抽象路径名表示的文件是否是一个目录。 
    WS_METHOD( ws_boolean , IsFile           )(void);                                               // 测试此抽象路径名表示的文件是否是一个标准文件。 
    WS_METHOD( ws_boolean , IsHidden         )(void);                                               // 测试此抽象路径名指定的文件是否是一个隐藏文件。 
    WS_METHOD( ws_long    , LastModified     )(void);                                               // 返回此抽象路径名表示的文件最后一次被修改的时间。 
    WS_METHOD( ws_long    , Length           )(void);                                               // 返回由此抽象路径名表示的文件的长度。 
    WS_METHOD( ws_result  , List             )(wsiStringArray ** ret);                              // 返回一个字符串数组，这些字符串指定此抽象路径名表示的目录中的文件和目录。 
    WS_METHOD( ws_result  , List             )(wsiStringArray ** ret, wsiFilenameFilter * filter);  // 返回一个字符串数组，这些字符串指定此抽象路径名表示的目录中满足指定过滤器的文件和目录。 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret);                                // 返回一个抽象路径名数组，这些路径名表示此抽象路径名表示的目录中的文件。 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret, wsiFileFilter * filter);        // 返回抽象路径名数组，这些路径名表示此抽象路径名表示的目录中满足指定过滤器的文件和目录。 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret, wsiFilenameFilter * filter);    // 返回抽象路径名数组，这些路径名表示此抽象路径名表示的目录中满足指定过滤器的文件和目录。 
    WS_METHOD( ws_boolean , Mkdir            )(void);                                               // 创建此抽象路径名指定的目录。 
    WS_METHOD( ws_boolean , Mkdirs           )(void);                                               // 创建此抽象路径名指定的目录，包括所有必需但不存在的父目录。 
    WS_METHOD( ws_boolean , RenameTo         )(wsiFile * dest);                                     // 重新命名此抽象路径名表示的文件。 
    WS_METHOD( ws_boolean , SetExecutable    )(ws_boolean executable);                              // 设置此抽象路径名所有者执行权限的一个便捷方法。 
    WS_METHOD( ws_boolean , SetExecutable    )(ws_boolean executable, ws_boolean ownerOnly);        // 设置此抽象路径名的所有者或所有用户的执行权限。 
    WS_METHOD( ws_boolean , SetLastModified  )(ws_long time);                                       // 设置此抽象路径名指定的文件或目录的最后一次修改时间。 
    WS_METHOD( ws_boolean , SetReadable      )(ws_boolean readable);                                // 设置此抽象路径名所有者读权限的一个便捷方法。 
    WS_METHOD( ws_boolean , SetReadable      )(ws_boolean readable, ws_boolean ownerOnly);          // 设置此抽象路径名的所有者或所有用户的读权限。 
    WS_METHOD( ws_boolean , SetReadOnly      )(void);                                               // 标记此抽象路径名指定的文件或目录，从而只能对其进行读操作。 
    WS_METHOD( ws_boolean , SetWritable      )(ws_boolean writable);                                // 设置此抽象路径名所有者写权限的一个便捷方法。 
    WS_METHOD( ws_boolean , SetWritable      )(ws_boolean writable, ws_boolean ownerOnly);          // 设置此抽象路径名的所有者或所有用户的写权限。 
    WS_METHOD( ws_result  , ToString         )(wsiString ** ret);                                   // 返回此抽象路径名的路径名字符串。 
    WS_METHOD( ws_result  , ToURI            )(wsiURI ** ret);                                      // 构造一个表示此抽象路径名的 file: URI。 
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

