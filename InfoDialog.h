#pragma once
#include "afxcmn.h"

#include "TabCarDialog.h"
#include "TabDriverDialog.h"
#include "TabPositionDialog.h"
#include "TabExtremumDialog.h"
#include "TabBatteryV.h"
#include "TabBatteryT.h"
#include "ControlCAN.h"


//class TabCarDialog;
//class TabDriverDialog;

// CInfoDialog 对话框

class CInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CInfoDialog)

public:
	CInfoDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInfoDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFO_DIALOG };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CTabCtrl m_tab_monitor;

private:
	void InitControlContainer();
	
public:
	CDialog *m_p_parent_dlg;

private:
	TabCarDialog m_dlg_car;
	TabDriverDialog m_dlg_driver;
	TabPositionDialog m_dlg_position;
	TabExtremumDialog m_dlg_extremum;
	TabBatteryV m_dlg_battery_v;
	TabBatteryT m_dlg_battery_t;

public:
	afx_msg void OnTcnSelchangeTabMonitor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonParse();
	afx_msg void OnClose();
	int ParseFrame(VCI_CAN_OBJ frame);
};
