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

    static const ws_char * const sPathSeparator;     //          与系统有关的路径分隔符，为了方便，它被表示为一个字符串。 
    static const ws_char         sPathSeparatorChar; //          与系统有关的路径分隔符。 
    static const ws_char * const sSeparator;         //          与系统有关的默认名称分隔符，为了方便，它被表示为一个字符串。 
    static const ws_char         sSeparatorChar;     //          与系统有关的默认名称分隔符。 

public:

    WS_METHOD( ws_boolean , CanExecute       )(void) = 0;                                               // 测试应用程序是否可以执行此抽象路径名表示的文件。 
    WS_METHOD( ws_boolean , CanRead          )(void) = 0;                                               // 测试应用程序是否可以读取此抽象路径名表示的文件。 
    WS_METHOD( ws_boolean , CanWrite         )(void) = 0;                                               // 测试应用程序是否可以修改此抽象路径名表示的文件。 
    WS_METHOD( ws_int     , CompareTo        )(wsiFile * pathname) = 0;                                 // 按字母顺序比较两个抽象路径名。 
    WS_METHOD( ws_boolean , CreateNewFile    )(void) = 0;                                               // 当且仅当不存在具有此抽象路径名指定名称的文件时，不可分地创建一个新的空文件。 
    WS_METHOD( ws_boolean , Delete           )(void) = 0;                                               // 删除此抽象路径名表示的文件或目录。 
    WS_METHOD( ws_result  , DeleteOnExit     )(void) = 0;                                               // 在虚拟机终止时，请求删除此抽象路径名表示的文件或目录。 
    WS_METHOD( ws_boolean , Equals           )(wsiObject * obj) = 0;                                    // 测试此抽象路径名与给定对象是否相等。 
    WS_METHOD( ws_boolean , Exists           )(void) = 0;                                               // 测试此抽象路径名表示的文件或目录是否存在。 
    WS_METHOD( ws_result  , GetAbsoluteFile  )(wsiFile ** ret) = 0;                                     // 返回此抽象路径名的绝对路径名形式。 
    WS_METHOD( ws_result  , GetAbsolutePath  )(wsiString ** ret) = 0;                                   // 返回此抽象路径名的绝对路径名字符串。 
    WS_METHOD( ws_result  , GetCanonicalFile )(wsiFile ** ret) = 0;                                     // 返回此抽象路径名的规范形式。 
    WS_METHOD( ws_result  , GetCanonicalPath )(wsiString ** ret) = 0;                                   // 返回此抽象路径名的规范路径名字符串。 
    WS_METHOD( ws_long    , GetFreeSpace     )(void) = 0;                                               // 返回此抽象路径名指定的分区中未分配的字节数。
    WS_METHOD( ws_result  , GetName          )(wsiString ** ret) = 0;                                   // 返回由此抽象路径名表示的文件或目录的名称。 
    WS_METHOD( ws_result  , GetParent        )(wsiString ** ret) = 0;                                   // 返回此抽象路径名父目录的路径名字符串；如果此路径名没有指定父目录，则返回 null。 
    WS_METHOD( ws_result  , GetParentFile    )(wsiFile ** ret) = 0;                                     // 返回此抽象路径名父目录的抽象路径名；如果此路径名没有指定父目录，则返回 null。 
    WS_METHOD( ws_result  , GetPath          )(wsiString ** ret) = 0;                                   // 将此抽象路径名转换为一个路径名字符串。 
    WS_METHOD( ws_long    , GetTotalSpace    )(void) = 0;                                               // 返回此抽象路径名指定的分区大小。 
    WS_METHOD( ws_long    , GetUsableSpace   )(void) = 0;                                               // 返回此抽象路径名指定的分区上可用于此虚拟机的字节数。 
    WS_METHOD( ws_int     , HashCode         )(void) = 0;                                               // 计算此抽象路径名的哈希码。 
    WS_METHOD( ws_boolean , IsAbsolute       )(void) = 0;                                               // 测试此抽象路径名是否为绝对路径名。 
    WS_METHOD( ws_boolean , IsDirectory      )(void) = 0;                                               // 测试此抽象路径名表示的文件是否是一个目录。 
    WS_METHOD( ws_boolean , IsFile           )(void) = 0;                                               // 测试此抽象路径名表示的文件是否是一个标准文件。 
    WS_METHOD( ws_boolean , IsHidden         )(void) = 0;                                               // 测试此抽象路径名指定的文件是否是一个隐藏文件。 
    WS_METHOD( ws_long    , LastModified     )(void) = 0;                                               // 返回此抽象路径名表示的文件最后一次被修改的时间。 
    WS_METHOD( ws_long    , Length           )(void) = 0;                                               // 返回由此抽象路径名表示的文件的长度。 
    WS_METHOD( ws_result  , List             )(wsiStringArray ** ret) = 0;                              // 返回一个字符串数组，这些字符串指定此抽象路径名表示的目录中的文件和目录。 
    WS_METHOD( ws_result  , List             )(wsiStringArray ** ret, wsiFilenameFilter * filter) = 0;  // 返回一个字符串数组，这些字符串指定此抽象路径名表示的目录中满足指定过滤器的文件和目录。 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret) = 0;                                // 返回一个抽象路径名数组，这些路径名表示此抽象路径名表示的目录中的文件。 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret, wsiFileFilter * filter) = 0;        // 返回抽象路径名数组，这些路径名表示此抽象路径名表示的目录中满足指定过滤器的文件和目录。 
    WS_METHOD( ws_result  , ListFiles        )(wsiFileArray ** ret, wsiFilenameFilter * filter) = 0;    // 返回抽象路径名数组，这些路径名表示此抽象路径名表示的目录中满足指定过滤器的文件和目录。 
    WS_METHOD( ws_boolean , Mkdir            )(void) = 0;                                               // 创建此抽象路径名指定的目录。 
    WS_METHOD( ws_boolean , Mkdirs           )(void) = 0;                                               // 创建此抽象路径名指定的目录，包括所有必需但不存在的父目录。 
    WS_METHOD( ws_boolean , RenameTo         )(wsiFile * dest) = 0;                                     // 重新命名此抽象路径名表示的文件。 
    WS_METHOD( ws_boolean , SetExecutable    )(ws_boolean executable) = 0;                              // 设置此抽象路径名所有者执行权限的一个便捷方法。 
    WS_METHOD( ws_boolean , SetExecutable    )(ws_boolean executable, ws_boolean ownerOnly) = 0;        // 设置此抽象路径名的所有者或所有用户的执行权限。 
    WS_METHOD( ws_boolean , SetLastModified  )(ws_long time) = 0;                                       // 设置此抽象路径名指定的文件或目录的最后一次修改时间。 
    WS_METHOD( ws_boolean , SetReadable      )(ws_boolean readable) = 0;                                // 设置此抽象路径名所有者读权限的一个便捷方法。 
    WS_METHOD( ws_boolean , SetReadable      )(ws_boolean readable, ws_boolean ownerOnly) = 0;          // 设置此抽象路径名的所有者或所有用户的读权限。 
    WS_METHOD( ws_boolean , SetReadOnly      )(void) = 0;                                               // 标记此抽象路径名指定的文件或目录，从而只能对其进行读操作。 
    WS_METHOD( ws_boolean , SetWritable      )(ws_boolean writable) = 0;                                // 设置此抽象路径名所有者写权限的一个便捷方法。 
    WS_METHOD( ws_boolean , SetWritable      )(ws_boolean writable, ws_boolean ownerOnly) = 0;          // 设置此抽象路径名的所有者或所有用户的写权限。 
    WS_METHOD( ws_result  , ToString         )(wsiString ** ret) = 0;                                   // 返回此抽象路径名的路径名字符串。 
    WS_METHOD( ws_result  , ToURI            )(wsiURI ** ret) = 0;                                      // 构造一个表示此抽象路径名的 file: URI。 

};



