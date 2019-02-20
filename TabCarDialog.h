#pragma once
#include "afxwin.h"
#include "ControlCAN.h"

// TabCarDialog 对话框

class TabCarDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabCarDialog)

public:
	TabCarDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabCarDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_CAR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_str_car_status;
	CString m_str_charging_status;
	CString m_str_driver_status;
	CString m_str_braking_status;
	CString m_str_run_mode;
	CString m_str_speed;
	CString m_str_gears;
	CString m_str_soc;
	CString m_str_r;
	CString m_str_mil;
	CString m_str_v;
	CString m_str_i;
	CString m_str_journey_speedup;
	CString m_str_journy_barke;
	CString m_str_dcdc_status;

	int ParseFrame(VCI_CAN_OBJ frame);
};
