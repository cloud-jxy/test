#pragma once
#include "HTSlot.h"
#include ".\ChartCtrl_source\ChartTitle.h"
#include ".\ChartCtrl_source\ChartAxisLabel.h"
#include ".\ChartCtrl_source\ChartMyTimeAxis.h"
#include ".\ChartCtrl_source\ChartBarSerie.h"
#include ".\ChartCtrl_source\ChartLineSerie.h"
#include ".\ChartCtrl_source\ChartCtrl.h"


// CCOMHTDialog 对话框

#define CHAER_X_LEN 1000

class HTToFile {
public:

};

class CCOMHTDialog : public CDialogEx, public HTSlot
{
	DECLARE_DYNAMIC(CCOMHTDialog)

public:
	CCOMHTDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCOMHTDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COM_HT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	//void StartMonitor();
	void OnCOMRecv();
	void OnCOMRecvHT(int h, int t);
	CChartCtrl m_chart;
	virtual BOOL OnInitDialog();

	double m_x[CHAER_X_LEN];
	double m_y[CHAER_X_LEN];

	double m_oldX[CHAER_X_LEN];
	double m_oldY[CHAER_X_LEN];

	int m_count;
	int m_ArrayLen;
	long m_timeFirst;
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	//写文件
public:
	FILE *m_f;
	void writeToFile(int h, int t) {
		double val = 100 * (double)h / (double)t;
		SYSTEMTIME now;
		GetLocalTime(&now);
		char text[128] = { 0 };

		snprintf(text, 128, _T("%d-%02d-%02d %02d:%02d:%02d.%03d %d/%d %g%%\n")
			, now.wYear, now.wMonth, now.wDay,
			now.wHour, now.wMinute, now.wSecond, now.wMilliseconds
			, h, t, val);

		if (m_f == NULL) {
			openFile();
		}

		if (m_f == NULL) {
			return;
		}

		fwrite(text, 1, strlen(text), m_f);
	}

	void openFile() {
		char name[256] = { 0 };

		SYSTEMTIME now;
		GetLocalTime(&now);

		snprintf(name, 128, _T("%s%d%02d%02d_%02d%02d%02d.txt")
			, _T("com_")
			, now.wYear, now.wMonth, now.wDay,
			now.wHour, now.wMinute, now.wSecond);

		m_f = fopen(name, _T("a+"));

		if (m_f == NULL) {
			int err = GetLastError();
			TRACE("GetLastError: %d\n", err);
		}
	}
};
