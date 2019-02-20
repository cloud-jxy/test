// TabCarDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "TabCarDialog.h"
#include "afxdialogex.h"


// TabCarDialog 对话框

IMPLEMENT_DYNAMIC(TabCarDialog, CDialogEx)

TabCarDialog::TabCarDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_CAR_DIALOG, pParent)
	, m_str_speed(_T(""))
	, m_str_mil(_T(""))
	, m_str_v(_T(""))
	, m_str_i(_T(""))
	, m_str_journey_speedup(_T(""))
	, m_str_journy_barke(_T(""))
	, m_str_dcdc_status(_T(""))
{

}

TabCarDialog::~TabCarDialog()
{
}

void TabCarDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAR_STATUS, m_str_car_status);
	DDX_Text(pDX, IDC_EDIT_CHARGING_STATUS, m_str_charging_status);
	DDX_Text(pDX, IDC_EDIT_DRIVER_STATUS, m_str_driver_status);
	DDX_Text(pDX, IDC_EDIT_BRAKING_STATUS, m_str_braking_status);
	DDX_Text(pDX, IDC_EDIT_RUN_MODE, m_str_run_mode);
	DDX_Text(pDX, IDC_EDIT_SPEED, m_str_speed);
	DDX_Text(pDX, IDC_EDIT_GEARS, m_str_gears);
	DDX_Text(pDX, IDC_EDIT_SOC, m_str_soc);
	DDX_Text(pDX, IDC_EDIT_RESISTANCE, m_str_r);
	DDX_Text(pDX, IDC_EDIT_MIL, m_str_mil);
	DDX_Text(pDX, IDC_EDIT1_TOTAL_V, m_str_v);
	DDX_Text(pDX, IDC_EDIT1_TOTAL_I, m_str_i);
	DDX_Text(pDX, IDC_EDIT_JOURNEY_SPEEDUP, m_str_journey_speedup);
	DDX_Text(pDX, IDC_EDIT1_JOURNEY_BRAKE, m_str_journy_barke);
	DDX_Text(pDX, IDC_EDIT1_DCDC_STATUS, m_str_dcdc_status);
}


BEGIN_MESSAGE_MAP(TabCarDialog, CDialogEx)
END_MESSAGE_MAP()


int TabCarDialog::ParseFrame(VCI_CAN_OBJ frame) {
	return 0;
}

// TabCarDialog 消息处理程序
