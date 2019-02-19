// InfoDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "InfoDialog.h"
#include "afxdialogex.h"


// CInfoDialog �Ի���

IMPLEMENT_DYNAMIC(CInfoDialog, CDialogEx)

CInfoDialog::CInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INFO_DIALOG, pParent)
{

}

CInfoDialog::~CInfoDialog()
{
}

void CInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MONITOR, m_tab_monitor);
}


BEGIN_MESSAGE_MAP(CInfoDialog, CDialogEx)
	ON_WM_CREATE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MONITOR, &CInfoDialog::OnTcnSelchangeTabMonitor)
	ON_BN_CLICKED(IDC_BUTTON_PARSE, &CInfoDialog::OnBnClickedButtonParse)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

BOOL CInfoDialog::OnInitDialog() {
	CDialog::OnInitDialog();

	InitControlContainer();
	return TRUE;
}

// CInfoDialog ��Ϣ�������

int CInfoDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	//SetWindowText("USBCAN ���ݽ���");

	return 0;
}

void CInfoDialog::InitControlContainer() {
	m_tab_monitor.InsertItem(0, "��������");
	m_tab_monitor.InsertItem(1, "�������");
	m_tab_monitor.InsertItem(2, "λ����Ϣ");
	m_tab_monitor.InsertItem(3, "������ֵ");

	m_dlg_car.Create(IDD_TAB_CAR_DIALOG, &m_tab_monitor);
	m_dlg_driver.Create(IDD_TAB_DRIVER_DIALOG, &m_tab_monitor);
	m_dlg_position.Create(IDD_TAB_POSITION_DIALOG, &m_tab_monitor);
	m_dlg_extremum.Create(IDD_TAB_EXTREMUM_DIALOG, &m_tab_monitor);

	CRect rect;
	m_tab_monitor.GetClientRect(&rect);
	rect.top += 20;
	rect.bottom -= 5;
	rect.left += 5;
	rect.right -= 5;

	m_dlg_car.MoveWindow(&rect);
	m_dlg_driver.MoveWindow(&rect);
	m_dlg_position.MoveWindow(&rect);
	m_dlg_extremum.MoveWindow(&rect);

	m_dlg_car.ShowWindow(SW_SHOW);
	m_dlg_driver.ShowWindow(SW_HIDE);
	m_dlg_position.ShowWindow(SW_HIDE);
	m_dlg_extremum.ShowWindow(SW_HIDE);

	m_tab_monitor.SetCurSel(0);
}


void CInfoDialog::OnTcnSelchangeTabMonitor(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CDialog *p_dialogs[] = {&m_dlg_car, &m_dlg_driver, &m_dlg_position, &m_dlg_extremum};
	int len = sizeof(p_dialogs) / sizeof(CDialog *);
	int index = m_tab_monitor.GetCurSel();
	int i = 0;

	for (i = 0; i < len; i++) {
		p_dialogs[i]->ShowWindow((i == index) ? SW_SHOW : SW_HIDE);
	}
}


void CInfoDialog::OnBnClickedButtonParse()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CInfoDialog::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_p_parent_dlg->SendMessage(WM_INFO_DIALOG_CLOSE, 0, 0);
	CDialogEx::OnClose();
}
