// NavigationDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "NavigationDialog.h"
#include "afxdialogex.h"
#include "ProtocolDialog.h"
#include "testDlg.h"
#include "AbovepanDialog.h"
#include "./xsc/XSCBaseDialog.h"

// NavigationDialog �Ի���

IMPLEMENT_DYNAMIC(NavigationDialog, CDialogEx)

NavigationDialog::NavigationDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NAVIGATION_DIALOG, pParent)
{

}

NavigationDialog::~NavigationDialog()
{
}

void NavigationDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NavigationDialog, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_COSTOM, &NavigationDialog::OnBnClickedButtonCostom)
	ON_BN_CLICKED(IDC_BUTTON_CAR, &NavigationDialog::OnBnClickedButtonCar)
	ON_BN_CLICKED(IDC_BUTTON_ABOVE_PAN, &NavigationDialog::OnBnClickedButtonAbovePan)
END_MESSAGE_MAP()


// NavigationDialog ��Ϣ��������


BOOL NavigationDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ����Ӷ���ĳ�ʼ��
	HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, FALSE);
	SetWindowText(_T("�������ݽ���"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void NavigationDialog::OnClose()
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	((CButton *)m_p_parent_dlg->GetDlgItem(IDC_CHECK2))->SetCheck(false);

	CDialogEx::OnClose();
}


void NavigationDialog::OnBnClickedButtonCostom()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	m_p_parent_dlg->m_haide_protocol_dialog->ShowWindow(SW_SHOW);
}


void NavigationDialog::OnBnClickedButtonCar()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	ProtocolDialog *dlg = new ProtocolDialog();
	dlg->m_p_dlg = this;
	dlg->m_group = _T("��������");
	dlg->Create(IDD_PROTOCOL_DIALOG, this);
	dlg->ShowWindow(SW_SHOW);
}


void NavigationDialog::OnBnClickedButtonAbovePan()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	CAbovepanDialog *dlg = new CAbovepanDialog();
	dlg->Create(IDD_ABOVEPAN_DIALOG, this);
	dlg->ShowWindow(SW_SHOW);

	//CXSCBaseDialog *dlg = new CXSCBaseDialog();
	//dlg->Create(IDD_XSC_BASE_DIALOG, this);
	//dlg->ShowWindow(SW_SHOW);
}