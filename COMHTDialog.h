#pragma once
#include "HTSlot.h"
#include ".\ChartCtrl_source\ChartTitle.h"
#include ".\ChartCtrl_source\ChartAxisLabel.h"
#include ".\ChartCtrl_source\ChartDateTimeAxis.h"
#include ".\ChartCtrl_source\ChartBarSerie.h"
#include ".\ChartCtrl_source\ChartLineSerie.h"
#include ".\ChartCtrl_source\ChartCtrl.h"


// CCOMHTDialog �Ի���

class CCOMHTDialog : public CDialogEx, public HTSlot
{
	DECLARE_DYNAMIC(CCOMHTDialog)

public:
	CCOMHTDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCOMHTDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COM_HT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	//void StartMonitor();
	void OnCOMRecv();
	void OnCOMRecvHT(int h, int t);
	CChartCtrl m_chart;
	virtual BOOL OnInitDialog();

	double *m_x;
	double *m_y;
	int m_count;
	int m_ArrayLen;
	long m_timeFirst;
};
