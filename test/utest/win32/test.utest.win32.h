// test.utest.win32.h : test.utest.win32 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号
#include "TestSession.h"

// Ctestutestwin32App:
// 有关此类的实现，请参阅 test.utest.win32.cpp
//

class Ctestutestwin32App : public CWinApp
{
public:
	Ctestutestwin32App();


// 重写
public:
	WS_VFUNC( BOOL , InitInstance )();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnTestRununittest();
};

extern Ctestutestwin32App theApp;
