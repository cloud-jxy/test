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
	m_str_run_mode = _T("纯电");	//固定值：纯电
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
	int ID = frame.ID;
	BYTE *data = frame.Data;
	if (ID == 0x18027A70) {
		/*
		车辆状态
		起始字节7 起始位0 长度2
		0启动1熄火2异常3无效
		*/
		BYTE car_status = data[7] & 0x03;
		CString str_status[] = {_T("启动"), _T("熄火"), _T("异常"), _T("无效")};

		m_str_car_status = str_status[car_status];

		/*
		挡位信息
		1 0 2 0 0
		0：前进挡位信息；1倒挡信息；2驻车制动信号；3制动踏板信号
		*/
		BYTE val = data[1] & 0x03;
		CString str_val[] = { _T("前进挡信息"), _T("倒挡信息"), _T("驻车制动信息"), _T("制动踏板信息") };
		m_str_gears = str_val[val];

		/*
		加速踏板行程值
		2 0 8 1% 0
		*/
		val = data[2];
		m_str_journey_speedup.Format("%d", val);

		/*
		制动踏板状态
		1 2 2 0 0
		0 off;1 on
		*/
		val = (data[1] >> 2) & 0x0c;
		m_str_journy_barke.Format("%d", val);
	}
	else if (ID == 0x18047A70) {
		/*
		充电状态
		4 0 8 1% 0% (依次是起始字节 起始位 位长度 精度 偏移量，下同不再解释)
		0 停车充电， 1行驶充电 2未充电状态 3充电完成
		*/
		BYTE status = data[4] & 0xff;
		CString str_status[] = { _T("停车充电"), _T("行驶充电"), _T("未充电状态"), _T("充电完成") };

		if (status <= 3) {
			m_str_braking_status = str_status[status];
		}
		else {
			m_str_braking_status = _T("数据异常");
		}
	}
	else if (ID == 0x18037A70) {
		/*
		车速
		1 0 16 0.00390625 0
		取值范围：0-250.996km/h; 0xff00 error; 0xffff not availbale
		*/
		BYTE l = data[1];
		BYTE h = data[2];

		if (l == 0x00 && h == 0xff) {
			m_str_speed = _T("error");
		}
		else if (l == 0xff && h == 0xffff) {
			m_str_speed = _T("not availbale");
		}
		else {
			double speed = (double)0.00390625 * (l + h << 8) + 0;
			m_str_speed.Format("%.3lf", speed);
		}
	}
	else if (ID == 0x18017A70) {
		/*
			累计里程数
			0 0 32 100m 0
		*/

		// 0.1: 100m = 0.1km
		int val = (data[0] + data[1] << 8 + data[2] << 16 + data[3] << 24 ) * 0.1 + 0;
		m_str_mil.Format("%d", val);
	}
	else if (ID == 0x18057A70) {
		/*
		总电压
		2 0 16 0.1V 0
		*/
		int val = (data[2] + data[3] << 8) * 0.1 + 0;
		m_str_v.Format("%d", val);

		/*
		SOC
		1 0 8 1% 0
		*/
		val = data[1];
		m_str_soc.Format("%d", val);
	}
	else if (ID = 0x18067A70) {
		/*
		总电流
		0 0 16 1 -500
		*/
		int val = (data[0] + data[1] << 8) * 1 - 500;
		m_str_i.Format("%d", val);
	}
	else if (ID == 0x18097A70) {
		/*
		DC-DC状态
		1 2 2 0 0
		0 standby,1 work, 2 failure 3 reserved
		*/
		BYTE val = (data[1] >> 2) & 0x0c;
		CString str_val[] = { _T("待命"), _T("工作"), _T("失败"), _T("保留")};
		m_str_dcdc_status = str_val[val];
	}
	else if (ID == 0x18077A70) {
		/*
		绝缘电阻
		1 0 16 1 0
		65534 表示电阻值>65533
		65535 表述NA 无效数值
		*/
		int val = data[1] + data[2] << 8;

		if (val == 65534) {
			m_str_r = _T("大于65533");
		}
		else if (val == 65535){
			m_str_r = _T("无效数值");
		}
		else {
			m_str_r.Format("%d", val);
		}
	}

	UpdateData(false);

	return 0;
}

// TabCarDialog 消息处理程序
