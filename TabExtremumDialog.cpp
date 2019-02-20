// TabExtremumDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "TabExtremumDialog.h"
#include "afxdialogex.h"


// TabExtremumDialog 对话框

IMPLEMENT_DYNAMIC(TabExtremumDialog, CDialogEx)

TabExtremumDialog::TabExtremumDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_EXTREMUM_DIALOG, pParent)
	, m_h_v_battery_subsys_id(_T(""))
	, m_str_h_v_battery_id(_T(""))
	, m_str_battery_v_h(_T(""))
	, m_str_l_v_battery_subsys_id(_T(""))
	, m_str_l_v_battery_id(_T(""))
	, m_str_battery_v_l(_T(""))
	, m_h_t_battery_subsys_id(_T(""))
	, m_str_h_t_battery_id(_T(""))
	, m_str_battery_t_h(_T(""))
	, m_str_l_t_battery_subsys_id(_T(""))
	, m_str_l_t_battery_id(_T(""))
	, m_str_battery_t_l(_T(""))
{

}

TabExtremumDialog::~TabExtremumDialog()
{
}

void TabExtremumDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_H_V_BATTERY_SUBSYS_ID, m_h_v_battery_subsys_id);
	DDX_Text(pDX, IDC_EDIT_H_V_BATTERY_ID, m_str_h_v_battery_id);
	DDX_Text(pDX, IDC_EDIT_BATTERY_V_H, m_str_battery_v_h);
	DDX_Text(pDX, IDC_EDIT_L_V_BATTERY_SUBSYS_ID, m_str_l_v_battery_subsys_id);
	DDX_Text(pDX, IDC_EDIT_L_V_BATTERY_ID, m_str_l_v_battery_id);
	DDX_Text(pDX, IDC_EDIT_BATTERY_V_L, m_str_battery_v_l);

	DDX_Text(pDX, IDC_EDIT_H_T_BATTERY_SUBSYS_ID, m_h_t_battery_subsys_id);
	DDX_Text(pDX, IDC_EDIT_H_T_BATTERY_ID, m_str_h_t_battery_id);
	DDX_Text(pDX, IDC_EDIT_BATTERY_T_H, m_str_battery_v_h);
	DDX_Text(pDX, IDC_EDIT_L_T_BATTERY_SUBSYS_ID, m_str_l_t_battery_subsys_id);
	DDX_Text(pDX, IDC_EDIT_L_T_BATTERY_ID, m_str_l_v_battery_id);
	DDX_Text(pDX, IDC_EDIT_BATTERY_T_L, m_str_battery_t_l);
}


BEGIN_MESSAGE_MAP(TabExtremumDialog, CDialogEx)
END_MESSAGE_MAP()


int TabExtremumDialog::ParseFrame(VCI_CAN_OBJ frame) {
	return 0;
}


// TabExtremumDialog 消息处理程序
