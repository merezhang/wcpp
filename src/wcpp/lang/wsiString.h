#pragma once

#include "wsiObject.h"
#include "wsiArray.h"




class wsiCharSequence;
class wsiStringBuffer;
// class wsiByteArray;
class wsiCharset;
// class wsiCharArray;
class wsiLocale;

typedef    wsiArray<wsiString>    wsiStringArray;



#define WS_IID_OF_wsiString     \
    { 0x5e93f255, 0x1df4, 0x4257, { 0xab, 0x63, 0xb2, 0x97, 0xd0, 0xa0, 0x86, 0x78 } }
// {5E93F255-1DF4-4257-AB63-B297D0A08678}


#define WS_IID_OF_wsiStringRW     \
    { 0x7d62e29c, 0xed7f, 0x41cd, { 0x96, 0x60, 0x80, 0xe1, 0xea, 0x95, 0x8, 0x77 } }
// {7D62E29C-ED7F-41cd-9660-80E1EA950877}




class wsiString : public wsiObject
{
public:
	static const ws_iid sIID;
public:
    WS_METHOD( ws_char    , CharAt              )(ws_int index) const = 0;               // ����ָ���������� ws_char ֵ�� 
    WS_METHOD( ws_int     , CodePointAt         )(ws_int index) const = 0;          // ����ָ�����������ַ���Unicode ����㣩�� 
    WS_METHOD( ws_int     , CodePointBefore     )(ws_int index) const = 0;      // ����ָ������֮ǰ���ַ���Unicode ����㣩�� 
    WS_METHOD( ws_int     , CodePointCount      )(ws_int beginIndex, ws_int endIndex) const = 0;     // ���ش� String ��ָ���ı���Χ�е� Unicode ��������� 
    WS_METHOD( ws_int     , CompareTo           )(wsiString * anotherString) const = 0;                  // ���ֵ�˳��Ƚ������ַ����� 
    WS_METHOD( ws_int     , CompareToIgnoreCase )(wsiString * str) const = 0;                  // ���ֵ�˳��Ƚ������ַ����������Ǵ�Сд�� 
    WS_METHOD( ws_result  , Concat              )(wsiString ** ret, wsiString * str) const = 0;             // ��ָ���ַ������ӵ����ַ����Ľ�β�� 
    WS_METHOD( ws_boolean , Contains            )(wsiCharSequence * s) const = 0;          // ���ҽ������ַ�������ָ���� ws_char ֵ����ʱ������ true�� 
    WS_METHOD( ws_boolean , ContentEquals       )(wsiCharSequence * cs) const = 0;    // �����ַ�����ָ���� CharSequence �Ƚϡ� 
    WS_METHOD( ws_boolean , ContentEquals       )(wsiStringBuffer * sb) const = 0;    // �����ַ�����ָ���� StringBuffer �Ƚϡ� 
    WS_METHOD( ws_boolean , EndsWith            )(wsiString * suffix) const = 0;          // ���Դ��ַ����Ƿ���ָ���ĺ�׺������ 
    WS_METHOD( ws_boolean , Equals              )(wsiObject * anObject) const = 0;           // �����ַ�����ָ���Ķ���Ƚϡ� 
    WS_METHOD( ws_boolean , EqualsIgnoreCase    )(wsiString * anotherString) const = 0;                   // ���� wsiString * ����һ�� wsiString * �Ƚϣ������Ǵ�Сд�� 
    WS_METHOD( ws_result  , GetBytes            )(wsiByteArray ** ret) const = 0;                                  // ʹ��ƽ̨��Ĭ���ַ������� wsiString * ����Ϊ byte ���У���������洢��һ���µ� byte �����С� 
    WS_METHOD( ws_result  , GetBytes            )(wsiByteArray ** ret, wsiCharset * charset) const = 0;            // ʹ�ø����� charset ���� wsiString * ���뵽 byte ���У���������洢���µ� byte ���顣 
    WS_METHOD( ws_result  , GetBytes            )(wsiByteArray ** ret, wsiString * charsetName) const = 0;        // ʹ��ָ�����ַ������� wsiString * ����Ϊ byte ���У���������洢��һ���µ� byte �����С� 
    WS_METHOD( ws_result  , GetChars            )(ws_int srcBegin, ws_int srcEnd, ws_char * dst, ws_int dstSize) const = 0;    // ���ַ��Ӵ��ַ������Ƶ�Ŀ���ַ����顣 
    WS_METHOD( ws_int     , HashCode            )(void) const = 0;                                 // ���ش��ַ����Ĺ�ϣ�롣 
    WS_METHOD( ws_int     , IndexOf             )(ws_int ch) const = 0;                             // ����ָ���ַ��ڴ��ַ����е�һ�γ��ִ��������� 
    WS_METHOD( ws_int     , IndexOf             )(ws_int ch, ws_int fromIndex) const = 0;           // �����ڴ��ַ����е�һ�γ���ָ���ַ�������������ָ����������ʼ������ 
    WS_METHOD( ws_int     , IndexOf             )(wsiString * str) const = 0;                      // ����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ��������� 
    WS_METHOD( ws_int     , IndexOf             )(wsiString * str, ws_int fromIndex) const = 0;    // ����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ�����������ָ����������ʼ�� 
    WS_METHOD( ws_result  , Intern              )(wsiString ** ret) const = 0;                       // �����ַ�������Ĺ淶����ʾ��ʽ�� 
    WS_METHOD( ws_boolean , IsEmpty             )(void) const = 0;                                  // ���ҽ��� length() Ϊ 0 ʱ���� true�� 
    WS_METHOD( ws_int     , LastIndexOf         )(ws_int ch) const = 0;                         // ����ָ���ַ��ڴ��ַ��������һ�γ��ִ��������� 
    WS_METHOD( ws_int     , LastIndexOf         )(ws_int ch, ws_int fromIndex) const = 0;       // ����ָ���ַ��ڴ��ַ��������һ�γ��ִ�����������ָ������������ʼ���з��������� 
    WS_METHOD( ws_int     , LastIndexOf         )(wsiString * str) const = 0;                  // ����ָ�����ַ����ڴ��ַ��������ұ߳��ִ��������� 
    WS_METHOD( ws_int     , LastIndexOf         )(wsiString * str, ws_int fromIndex) const = 0;                // ����ָ�����ַ����ڴ��ַ��������һ�γ��ִ�����������ָ����������ʼ���������� 
    WS_METHOD( ws_int     , Length              )(void) const = 0;                                                   // ���ش��ַ����ĳ��ȡ� 
    WS_METHOD( ws_boolean , Matches             )(wsiString * regex) const = 0;                                    // ��֪���ַ����Ƿ�ƥ�������������ʽ�� 
    WS_METHOD( ws_int     , OffsetByCodePoints  )(ws_int index, ws_int codePointOffset) const = 0;       // ���ش� wsiString * �дӸ����� index ��ƫ�� codePointOffset �������������� 
    WS_METHOD( ws_boolean , RegionMatches       )(ws_boolean ignoreCase, ws_int toffset, wsiString * other, ws_int ooffset, ws_int len) const = 0;    // ���������ַ��������Ƿ���ȡ� 
    WS_METHOD( ws_boolean , RegionMatches       )(ws_int toffset, wsiString * other, ws_int ooffset, ws_int len) const = 0;          // ���������ַ��������Ƿ���ȡ� 
    WS_METHOD( ws_result  , Replace             )(wsiString ** ret, ws_char oldChar, ws_char newChar) const = 0;                            // ����һ���µ��ַ���������ͨ���� newChar �滻���ַ����г��ֵ����� oldChar �õ��ġ� 
    WS_METHOD( ws_result  , Replace             )(wsiString ** ret, wsiCharSequence * target, wsiCharSequence * replacement) const = 0;     // ʹ��ָ��������ֵ�滻�����滻���ַ�������ƥ������ֵĿ�����е����ַ����� 
    WS_METHOD( ws_result  , ReplaceAll          )(wsiString ** ret, wsiString * regex, wsiString * replacement) const = 0;             // ʹ�ø����� replacement �滻���ַ�������ƥ�������������ʽ�����ַ����� 
    WS_METHOD( ws_result  , ReplaceFirst        )(wsiString ** ret, wsiString * regex, wsiString * replacement) const = 0;           // ʹ�ø����� replacement �滻���ַ���ƥ�������������ʽ�ĵ�һ�����ַ����� 
    WS_METHOD( ws_result  , Split               )(wsiStringArray ** ret, wsiString * regex) const = 0;                           // ���ݸ���������ʽ��ƥ���ִ��ַ����� 
    WS_METHOD( ws_result  , Split               )(wsiStringArray ** ret, wsiString * regex, ws_int limit) const = 0;             // ����ƥ�������������ʽ����ִ��ַ����� 
    WS_METHOD( ws_boolean , StartsWith          )(wsiString * prefix) const = 0;                                            // ���Դ��ַ����Ƿ���ָ����ǰ׺��ʼ�� 
    WS_METHOD( ws_boolean , StartsWith          )(wsiString * prefix, ws_int toffset) const = 0;                            // ���Դ��ַ�����ָ��������ʼ�����ַ����Ƿ���ָ��ǰ׺��ʼ�� 
    WS_METHOD( ws_result  , SubSequence         )(wsiCharSequence ** ret, ws_int beginIndex, ws_int endIndex) const = 0;    // ����һ���µ��ַ����У����Ǵ����е�һ�������С� 
    WS_METHOD( ws_result  , Substring           )(wsiString ** ret, ws_int beginIndex) const = 0;                             // ����һ���µ��ַ��������Ǵ��ַ�����һ�����ַ����� 
    WS_METHOD( ws_result  , Substring           )(wsiString ** ret, ws_int beginIndex, ws_int endIndex) const = 0;            // ����һ�����ַ��������Ǵ��ַ�����һ�����ַ����� 
    WS_METHOD( ws_result  , ToCharArray         )(wsiCharArray ** ret) const = 0;                           // �����ַ���ת��Ϊһ���µ��ַ����顣 
    WS_METHOD( ws_result  , ToLowerCase         )(wsiString ** ret) const = 0;                              // ʹ��Ĭ�����Ի����Ĺ��򽫴� wsiString * �е������ַ���ת��ΪСд�� 
    WS_METHOD( ws_result  , ToLowerCase         )(wsiString ** ret, wsiLocale * locale) const = 0;          // ʹ�ø��� Locale �Ĺ��򽫴� wsiString * �е������ַ���ת��ΪСд�� 
    WS_METHOD( ws_result  , ToString            )(wsiString ** ret) const = 0;                                 // ���ش˶��������Ѿ���һ���ַ��������� 
    WS_METHOD( ws_result  , ToUpperCase         )(wsiString ** ret) const = 0;                              // ʹ��Ĭ�����Ի����Ĺ��򽫴� wsiString * �е������ַ���ת��Ϊ��д�� 
    WS_METHOD( ws_result  , ToUpperCase         )(wsiString ** ret, wsiLocale * locale) const = 0;          // ʹ�ø��� Locale �Ĺ��򽫴� wsiString * �е������ַ���ת��Ϊ��д�� 
    WS_METHOD( ws_result  , Trim                )(wsiString ** ret) const = 0;                                     // �����ַ����ĸ���������ǰ���հ׺�β���հס� 
public:     // extends wsiString
    WS_METHOD( const ws_char * const , GetBuffer )(void) const = 0;
    WS_METHOD( ws_int                , GetLength )(void) const = 0;
};




class wsiStringRW : public wsiString
{
public:
	static const ws_iid sIID;
public:
    WS_METHOD( ws_char * , GetBufferRW   )(void) = 0;
    WS_METHOD( ws_int    , GetBufferSize )(void) const = 0;
    WS_METHOD( ws_int    , SetLength     )(ws_int newLength) = 0;
    WS_METHOD( ws_int    , SetString     )(const ws_char * const buf, ws_int len) = 0;
};



