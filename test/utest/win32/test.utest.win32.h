// test.utest.win32.h : test.utest.win32 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "TestSession.h"

// Ctestutestwin32App:
// �йش����ʵ�֣������ test.utest.win32.cpp
//

class Ctestutestwin32App : public CWinApp
{
public:
	Ctestutestwin32App();


// ��д
public:
	WS_VFUNC( BOOL , InitInstance )();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnTestRununittest();
};

extern Ctestutestwin32App theApp;
