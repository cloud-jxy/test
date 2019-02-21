#pragma once
#include "ControlCAN.h"
#include "C:\pm\API_Samples\vc6例子\test\ChartCtrl_source\ChartCtrl.h"
#include ".\ChartCtrl_source\ChartTitle.h"
#include ".\ChartCtrl_source\ChartAxisLabel.h"
#include ".\ChartCtrl_source\ChartBarSerie.h"
#include ".\ChartCtrl_source\ChartLineSerie.h"


#define V_ARRAY_LEN 180
#define WM_CHART_V (WM_USER + 2001)

// TabBatteryV 对话框

class TabBatteryV : public CDialogEx
{
	DECLARE_DYNAMIC(TabBatteryV)

public:
	TabBatteryV(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabBatteryV();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_BATTERY_VOLTAGE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	int ParseFrame(VCI_CAN_OBJ frame);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg LRESULT OnChartV(WPARAM wParam, LPARAM lParam);

	double m_x[V_ARRAY_LEN];
	double m_y[V_ARRAY_LEN];
	virtual BOOL OnInitDialog();

	void UpdateChart();
	CChartCtrl m_chart;
};
