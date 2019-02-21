#pragma once
#include "ControlCAN.h"

// TabExtremumDialog 对话框

class TabExtremumDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabExtremumDialog)

public:
	TabExtremumDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabExtremumDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_EXTREMUM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_h_v_battery_subsys_id;
	CString m_str_h_v_battery_id;
	CString m_str_battery_v_h;
	CString m_str_l_v_battery_subsys_id;
	CString m_str_l_v_battery_id;
	CString m_str_battery_v_l;

	CString m_h_t_battery_subsys_id;
	CString m_str_h_t_battery_id;
	CString m_str_battery_t_h;
	CString m_str_l_t_battery_subsys_id;
	CString m_str_l_t_battery_id;
	CString m_str_battery_t_l;

	int ParseFrame(VCI_CAN_OBJ frame);

	CDialogEx *m_p_parent_dlg;
};
