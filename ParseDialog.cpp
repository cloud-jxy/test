#include "stdafx.h"
#include "ParseDialog.h"
#include <set>
#include "resource.h"
using namespace std;

set<CParseDialog *> g_listeners;

CParseDialog::CParseDialog()
{

}


CParseDialog::CParseDialog(UINT nIDTemplate, CWnd *pParent) : CDialogEx(nIDTemplate, pParent) {
	g_listeners.insert(this);
}


CParseDialog::~CParseDialog()
{
	auto search = g_listeners.find(this);
	if (search != g_listeners.end()) {
		g_listeners.erase(search);
	}
}
BEGIN_MESSAGE_MAP(CParseDialog, CDialogEx)
	ON_WM_SIZING()
	ON_WM_SIZE()
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


void CParseDialog::SetCtrlRect() {
}

int CParseDialog::ParseFrame(VCI_CAN_OBJ obj) {
	return 0;
}

void CParseDialog::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	TRACE("CParseDialog::OnSizing\n");

	// TODO: �ڴ˴������Ϣ����������
	SetCtrlRect();
}


void CParseDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (m_sizing) {
		SetCtrlRect();
		m_sizing = FALSE;
	}
}


void CParseDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnSysCommand(nID, lParam);

	if (nID == SC_MAXIMIZE || nID == SC_RESTORE) {
		SetCtrlRect();
	}
}


BOOL CParseDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, FALSE);

	SetCtrlRect();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
