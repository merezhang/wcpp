// test.utest.win32View.h : Ctestutestwin32View ��Ľӿ�
//


#pragma once


class Ctestutestwin32View : public CView
{
protected: // �������л�����
	Ctestutestwin32View();
	DECLARE_DYNCREATE(Ctestutestwin32View)

// ����
public:
	Ctestutestwin32Doc* GetDocument() const;

// ����
public:

// ��д
public:
	WS_VIRTUAL void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	WS_VIRTUAL BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	WS_VIRTUAL BOOL OnPreparePrinting(CPrintInfo* pInfo);
	WS_VIRTUAL void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	WS_VIRTUAL void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	WS_VIRTUAL_DESTRUCTOR( Ctestutestwin32View );
#ifdef _DEBUG
	WS_VIRTUAL void AssertValid() const;
	WS_VIRTUAL void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // test.utest.win32View.cpp �еĵ��԰汾
inline Ctestutestwin32Doc* Ctestutestwin32View::GetDocument() const
   { return reinterpret_cast<Ctestutestwin32Doc*>(m_pDocument); }
#endif

