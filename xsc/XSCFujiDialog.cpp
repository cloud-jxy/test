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
	StaticItemObj(_T("�������������"), DEFAULT_VAL, _T("0x0C000003"), 0, 0, 2,(PtrFuncToString)(&CXSCFujiDialog::OpenOrClose)),
	StaticItemObj(_T("��װ������-������ת��"), DEFAULT_VAL, _T("0x0C000003"), 1, 0, 16,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 0.125, 0),
	StaticItemObj(_T("�������-������ת��"), DEFAULT_VAL, _T("0x0CF00400"), 4, 0, 16,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 0.125, 0),
	StaticItemObj(_T("ˮ��"), DEFAULT_VAL, _T("0x18FEEE00"), 0, 0, 8,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 1, -40),
	StaticItemObj(_T("�����¶�"), DEFAULT_VAL, _T("0x18FEEE00"), 2, 0, 16,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 0.03125, -40),
	StaticItemObj(_T("����ѹ��"), DEFAULT_VAL, _T("0x18FEEF00"), 3, 0, 8,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 4, 0),
	StaticItemObj(_T("Ԥ�ȵ�״̬"), DEFAULT_VAL, _T("0x18FEE400"), 3, 0, 2,(PtrFuncToString)(&CXSCFujiDialog::YuredengToString)),
	StaticItemObj(_T("����ѹ���ź�"), DEFAULT_VAL, _T("0x18FE6800"), 3, 2, 2,(PtrFuncToString)(&CXSCFujiDialog::JiyouyaliToString)),
};

// 00��OFF-Ϩ��01��ON-������10��Error-����11�����ܻ�ȡ
CString CXSCFujiDialog::YuredengToString(double val)
{
	CString alls[] = { _T("Ϩ��"), _T("����"), _T("����"), _T("���ܻ�ȡ") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}

/*00��NOT OK-����ѹ����
01��OK - ����ѹ��������Сֵ
10��Error - �źŲ���ȷ��
11�����ܻ�ȡ*/
CString CXSCFujiDialog::JiyouyaliToString(double val)
{
	CString alls[] = { _T("����ѹ����"), _T("����ѹ��������Сֵ"), _T("�źŲ���ȷ��"), _T("���ܻ�ȡ") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}


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
