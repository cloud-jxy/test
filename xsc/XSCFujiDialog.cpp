// ./xsc/XSCFujiDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XSCFujiDialog.h"
#include "afxdialogex.h"
#include "../resource.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

static StaticItemObj g_xscFuji[] = {
	StaticItemObj(_T("�������������"), DEFAULT_VAL, _T("0x0C000003"), 0, 0, 2, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("������ת�٣���λ��"), DEFAULT_VAL, _T("0x0C000003"), 1, 0, 8, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("������ת�٣���λ��"), DEFAULT_VAL, _T("0x0C000003"), 2, 0, 8, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("������ת��"), DEFAULT_VAL, _T("0x0CF00400"), 4, 0, 16, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("ˮ��"), DEFAULT_VAL, _T("0x18FEEE00"), 0, 0, 8, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("�����¶�"), DEFAULT_VAL, _T("0x18FEEE00"), 2, 0, 16, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("����ѹ��"), DEFAULT_VAL, _T("0x18FEEF00"), 3, 0, 8, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("Ԥ�ȵ�״̬"), DEFAULT_VAL, _T("0x18FEE400"), 3, 0, 2, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("����ѹ���ź�"), DEFAULT_VAL, _T("0x18FE6800"), 3, 2, 2, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
};


// CXSCFujiDialog �Ի���

IMPLEMENT_DYNAMIC(CXSCFujiDialog, CMyTabDialog)

CXSCFujiDialog::CXSCFujiDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscFuji;
	m_objCount = sizeof(g_xscFuji) / sizeof(g_xscFuji[0]);
	m_leftW = 175;
	m_rightW = 100;
}

CXSCFujiDialog::~CXSCFujiDialog()
{
}

void CXSCFujiDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCFujiDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCFujiDialog ��Ϣ�������
