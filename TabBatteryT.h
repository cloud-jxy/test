#pragma once
#include "ControlCAN.h"
#include ".\ChartCtrl_source\ChartCtrl.h"
#include ".\ChartCtrl_source\ChartTitle.h"
#include ".\ChartCtrl_source\ChartAxisLabel.h"
#include ".\ChartCtrl_source\ChartBarSerie.h"
#include ".\ChartCtrl_source\ChartLineSerie.h"

// TabBatteryT 对话框

class TabBatteryT : public CDialogEx
{
	DECLARE_DYNAMIC(TabBatteryT)

public:
	TabBatteryT(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabBatteryT();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_BATTERY_T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	int ParseFrame(VCI_CAN_OBJ frame);
	CChartCtrl m_chart;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
