// XSCBaseDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "../test.h"
#include "XSCBaseDialog.h"
#include "afxdialogex.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

static StaticItemObj g_xscBase[] = {
	StaticItemObj(_T("ϵ��"), DEFAULT_VAL, _T("0x18f40000"), 0, 0, 2),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18f40000"), 0, 2, 6),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18f40000"), 2, 0, 8),
	StaticItemObj(_T("��������"), DEFAULT_VAL, _T("0x18f40000"), 3, 0, 8),
	StaticItemObj(_T("��ʾ��"), DEFAULT_VAL, _T("0x18f40000"), 4, 0, 4),
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18f40000"), 4, 4, 4),
	StaticItemObj(_T("ģ��1"), DEFAULT_VAL, _T("0x18f40000"), 5, 0, 4),
	StaticItemObj(_T("ģ��2"), DEFAULT_VAL, _T("0x18f40000"), 5, 4, 4),
	StaticItemObj(_T("����������"), DEFAULT_VAL, _T("0x18f40000"), 6, 0, 4),
	StaticItemObj(_T("ң��"), DEFAULT_VAL, _T("0x18f40000"), 6, 4, 4),
	StaticItemObj(_T("���"), DEFAULT_VAL, _T("0x18f40000"), 7, 0, 8),
	StaticItemObj(_T("��ʾ������汾��"), DEFAULT_VAL, _T("0x18f40003"), 0, 0, 16),
	StaticItemObj(_T("����������汾��"), DEFAULT_VAL, _T("0x18f40003"), 2, 0, 16),
	StaticItemObj(_T("��ʾ���������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 0, 1),
	StaticItemObj(_T("��ʾ����ģ��1ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 1, 1),
	StaticItemObj(_T("��ʾ����ģ��2ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 2, 1),
	StaticItemObj(_T("��ʾ��������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 3, 1),
	StaticItemObj(_T("��ʾ����ң��ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 4, 1),
	StaticItemObj(_T("��ʾ���븱������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 5, 1),
	StaticItemObj(_T("��ʾ���복���ն�ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 6, 1),
	StaticItemObj(_T("��ʾ�������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 7, 1),
	StaticItemObj(_T("��������ģ��1ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 0, 1),
	StaticItemObj(_T("��������ģ��2ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 1, 1),
	StaticItemObj(_T("������������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 2, 1),
	StaticItemObj(_T("��������ң��ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 3, 1),
	StaticItemObj(_T("�������븱������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 4, 1),
	StaticItemObj(_T("�������복���ն�ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 5, 1),
	StaticItemObj(_T("�����������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 6, 1)
};


// CXSCBaseDialog �Ի���

IMPLEMENT_DYNAMIC(CXSCBaseDialog, CMyTabDialog)

CXSCBaseDialog::CXSCBaseDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscBase;
	m_objCount = sizeof(g_xscBase) / sizeof(g_xscBase[0]);
	m_leftW = 175;
	m_rightW = 100;
}

CXSCBaseDialog::~CXSCBaseDialog()
{
}

void CXSCBaseDialog::DoDataExchange(CDataExchange* pDX)
{
	CMyTabDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCBaseDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCBaseDialog ��Ϣ�������


BOOL CXSCBaseDialog::OnInitDialog()
{
	CMyTabDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
