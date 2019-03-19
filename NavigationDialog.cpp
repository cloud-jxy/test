// NavigationDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "NavigationDialog.h"
#include "afxdialogex.h"
#include "ProtocolDialog.h"
#include "testDlg.h"
#include "AbovepanDialog.h"
#include "./xsc/XSCBaseDialog.h"

// NavigationDialog 对话框

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


// NavigationDialog 消息处理程序


BOOL NavigationDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, FALSE);
	SetWindowText(_T("海德数据解析"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void NavigationDialog::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	((CButton *)m_p_parent_dlg->GetDlgItem(IDC_CHECK2))->SetCheck(false);

	CDialogEx::OnClose();
}


void NavigationDialog::OnBnClickedButtonCostom()
{
	// TODO: 在此添加控件通知处理程序代码
	m_p_parent_dlg->m_haide_protocol_dialog->ShowWindow(SW_SHOW);
}


void NavigationDialog::OnBnClickedButtonCar()
{
	// TODO: 在此添加控件通知处理程序代码
	ProtocolDialog *dlg = new ProtocolDialog();
	dlg->m_p_dlg = this;
	dlg->m_group = _T("车辆管理");
	dlg->Create(IDD_PROTOCOL_DIALOG, this);
	dlg->ShowWindow(SW_SHOW);
}


void NavigationDialog::OnBnClickedButtonAbovePan()
{
	// TODO: 在此添加控件通知处理程序代码
	if (0) {
		// 模态
		CAbovepanDialog dlg;
		//dlg.Create(IDD_ABOVEPAN_DIALOG, this);

		ShowWindow(SW_HIDE);
		dlg.DoModal();
		ShowWindow(SW_SHOW);
	}
	else {
		// 非模态
		if (m_abovepanDlg == NULL) {
			m_abovepanDlg = new CAbovepanDialog();
			m_abovepanDlg->Create(IDD_ABOVEPAN_DIALOG, this);
		}
		m_abovepanDlg->ShowWindow(SW_SHOW);

		/*CAbovepanDialog *dlg = new CAbovepanDialog();
		dlg->Create(IDD_ABOVEPAN_DIALOG, this);
		dlg->ShowWindow(SW_SHOW);*/

	}
}
