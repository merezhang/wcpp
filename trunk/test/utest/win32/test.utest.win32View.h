// test.utest.win32View.h : Ctestutestwin32View 类的接口
//


#pragma once


class Ctestutestwin32View : public CView
{
protected: // 仅从序列化创建
	Ctestutestwin32View();
	DECLARE_DYNCREATE(Ctestutestwin32View)

// 属性
public:
	Ctestutestwin32Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	WS_VIRTUAL void OnDraw(CDC* pDC);  // 重写以绘制该视图
	WS_VIRTUAL BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	WS_VIRTUAL BOOL OnPreparePrinting(CPrintInfo* pInfo);
	WS_VIRTUAL void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	WS_VIRTUAL void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	WS_VIRTUAL_DESTRUCTOR( Ctestutestwin32View );
#ifdef _DEBUG
	WS_VIRTUAL void AssertValid() const;
	WS_VIRTUAL void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // test.utest.win32View.cpp 中的调试版本
inline Ctestutestwin32Doc* Ctestutestwin32View::GetDocument() const
   { return reinterpret_cast<Ctestutestwin32Doc*>(m_pDocument); }
#endif

