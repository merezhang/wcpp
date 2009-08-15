// test.utest.win32View.cpp : Ctestutestwin32View 类的实现
//

#include "stdafx.h"
#include "test.utest.win32.h"

#include "test.utest.win32Doc.h"
#include "test.utest.win32View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctestutestwin32View

IMPLEMENT_DYNCREATE(Ctestutestwin32View, CView)

BEGIN_MESSAGE_MAP(Ctestutestwin32View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Ctestutestwin32View 构造/析构

Ctestutestwin32View::Ctestutestwin32View()
{
	// TODO: 在此处添加构造代码

}

Ctestutestwin32View::~Ctestutestwin32View()
{
}

BOOL Ctestutestwin32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctestutestwin32View 绘制

void Ctestutestwin32View::OnDraw(CDC* /*pDC*/)
{
	Ctestutestwin32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Ctestutestwin32View 打印

BOOL Ctestutestwin32View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ctestutestwin32View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ctestutestwin32View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// Ctestutestwin32View 诊断

#ifdef _DEBUG
void Ctestutestwin32View::AssertValid() const
{
	CView::AssertValid();
}

void Ctestutestwin32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctestutestwin32Doc* Ctestutestwin32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctestutestwin32Doc)));
	return (Ctestutestwin32Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctestutestwin32View 消息处理程序
