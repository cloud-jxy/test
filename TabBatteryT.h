#pragma once
#include "ControlCAN.h"
#include ".\ChartCtrl_source\ChartCtrl.h"
#include ".\ChartCtrl_source\ChartTitle.h"
#include ".\ChartCtrl_source\ChartAxisLabel.h"
#include ".\ChartCtrl_source\ChartBarSerie.h"
#include ".\ChartCtrl_source\ChartLineSerie.h"

#define T_ARRAY_LEN 72
#define WM_CHART_T (WM_USER + 1001)

// TabBatteryT �Ի���

class TabBatteryT : public CDialogEx
{
	DECLARE_DYNAMIC(TabBatteryT)

public:
	TabBatteryT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabBatteryT();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_BATTERY_T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	int ParseFrame(VCI_CAN_OBJ frame);
	CChartCtrl m_chart;

	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	afx_msg LRESULT OnChartT(WPARAM wParam, LPARAM lParam);

	double m_x[T_ARRAY_LEN];
	double m_y[T_ARRAY_LEN];
	void UpdateChart();
};
