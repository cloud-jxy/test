
// MyStaticItem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyStaticItemApp: 
// �йش����ʵ�֣������ MyStaticItem.cpp
//

class CMyStaticItemApp : public CWinApp
{
public:
	CMyStaticItemApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyStaticItemApp theApp;