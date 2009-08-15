// test.utest.win32Doc.cpp : Ctestutestwin32Doc 类的实现
//

#include "stdafx.h"
#include "test.utest.win32.h"

#include "test.utest.win32Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctestutestwin32Doc

IMPLEMENT_DYNCREATE(Ctestutestwin32Doc, CDocument)

BEGIN_MESSAGE_MAP(Ctestutestwin32Doc, CDocument)
END_MESSAGE_MAP()


// Ctestutestwin32Doc 构造/析构

Ctestutestwin32Doc::Ctestutestwin32Doc()
{
	// TODO: 在此添加一次性构造代码

}

Ctestutestwin32Doc::~Ctestutestwin32Doc()
{
}

BOOL Ctestutestwin32Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// Ctestutestwin32Doc 序列化

void Ctestutestwin32Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// Ctestutestwin32Doc 诊断

#ifdef _DEBUG
void Ctestutestwin32Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Ctestutestwin32Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Ctestutestwin32Doc 命令
