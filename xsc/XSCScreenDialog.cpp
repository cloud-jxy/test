// ./xsc/XSCScreenDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "../test.h"
#include "XSCScreenDialog.h"
#include "afxdialogex.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"
#include "../MyTabDialog.h"

#define DEFAULT_VAL _T("")


StaticItemObj g_xscScreen[] = {
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18F40100"), 0, 0, 1),
	StaticItemObj(_T("���彵"), DEFAULT_VAL, _T("0x18F40100"), 0, 1, 1),
	StaticItemObj(_T("���ſ�"), DEFAULT_VAL, _T("0x18F40100"), 0, 2, 1),
	StaticItemObj(_T("���Ź�"), DEFAULT_VAL, _T("0x18F40100"), 0, 3, 1),
	StaticItemObj(_T("���ڳ�ˮ"), DEFAULT_VAL, _T("0x18F40100"), 0, 4, 1),
	StaticItemObj(_T("��ˮ"), DEFAULT_VAL, _T("0x18F40100"), 0, 5, 1),
	StaticItemObj(_T("ϴɨ"), DEFAULT_VAL, _T("0x18F40100"), 0, 6, 1),
	StaticItemObj(_T("��ɨ"), DEFAULT_VAL, _T("0x18F40100"), 0, 7, 1),
	StaticItemObj(_T("��������"), DEFAULT_VAL, _T("0x18F40100"), 1, 0, 1),
	StaticItemObj(_T("����ҵ"), DEFAULT_VAL, _T("0x18F40100"), 1, 1, 1),
	StaticItemObj(_T("ȫ��ҵ"), DEFAULT_VAL, _T("0x18F40100"), 1, 2, 1),
	StaticItemObj(_T("����ҵ"), DEFAULT_VAL, _T("0x18F40100"), 1, 3, 1),
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18F40100"), 1, 4, 1),
	StaticItemObj(_T("�ͱ�"), DEFAULT_VAL, _T("0x18F40100"), 1, 5, 1),
	StaticItemObj(_T("ˮ��"), DEFAULT_VAL, _T("0x18F40100"), 1, 6, 1),
	StaticItemObj(_T("���ڹ���"), DEFAULT_VAL, _T("0x18F40100"), 1, 7, 1),
	StaticItemObj(_T("���忪"), DEFAULT_VAL, _T("0x18F40100"), 2, 0, 1),
	StaticItemObj(_T("�ϸǿ�"), DEFAULT_VAL, _T("0x18F40100"), 2, 1, 1),
	StaticItemObj(_T("������ת��"), DEFAULT_VAL, _T("0x18F40103"), 0, 0, 16),
	StaticItemObj(_T("ɨˢת��"), DEFAULT_VAL, _T("0x18F40103"), 2, 0, 8)
};

// CXSCScreenDialog �Ի���

IMPLEMENT_DYNAMIC(CXSCScreenDialog, CMyTabDialog)

CXSCScreenDialog::CXSCScreenDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_XSCSCREENDIALOG, pParent)
{
	m_objs = g_xscScreen;
	m_objCount = sizeof(g_xscScreen) / sizeof(g_xscScreen[0]);
	m_leftW = 175;
	m_rightW = 100;
}

CXSCScreenDialog::~CXSCScreenDialog()
{
}

void CXSCScreenDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCScreenDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCScreenDialog ��Ϣ�������
