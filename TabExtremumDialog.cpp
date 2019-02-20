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
	, m_h_v_battery_subsys_id(_T("1"))
	, m_str_h_v_battery_id(_T(""))
	, m_str_battery_v_h(_T(""))
	, m_str_l_v_battery_subsys_id(_T("1"))
	, m_str_l_v_battery_id(_T(""))
	, m_str_battery_v_l(_T(""))
	, m_h_t_battery_subsys_id(_T("1"))
	, m_str_h_t_battery_id(_T(""))
	, m_str_battery_t_h(_T(""))
	, m_str_l_t_battery_subsys_id(_T("1"))
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
	UINT ID = frame.ID;
	BYTE *data = frame.Data;
	
	if (ID == 0x18287A70) {
		/*
		最高电压电池单体代号
		0 0 8 1 0
		*/
		int val = data[0];
		m_str_h_v_battery_id.Format(_T("%d"), val);

		/*
		最低电压电池单体代号
		1 0 8 1 0
		*/
		val = data[1];
		m_str_l_v_battery_id.Format(_T("%d"), val);

		/*
		最高温度值
		2 0 8 1 -40
		*/
		val = data[2] - 40;
		m_str_battery_t_h.Format(_T("%d"), val);

		/*
		最低温度值
		3 0 8 1 -40
		*/
		val = data[3] - 40;
		m_str_battery_t_l.Format(_T("%d"), val);
	}
	else if (ID == 0x18057A70) {
		/*
		电池单体电压最高值
		6 0 8 0.01 250
		*/
		float val = data[6] * 0.01 + 250;
		m_str_battery_v_h.Format(_T("%.2f"), val);

		/*
		电池单体电压最低值
		7 0 8 0.01 250
		*/
		val = data[7] * 0.01 + 250;
		m_str_battery_v_l.Format(_T("%.2f"), val);
	}
	
	UpdateData(false);

	return 0;
}


// TabExtremumDialog 消息处理程序
