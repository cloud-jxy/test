// COMHTDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "COMHTDialog.h"
#include "afxdialogex.h" 


using namespace itas109;
using namespace std;

// CCOMHTDialog 对话框

IMPLEMENT_DYNAMIC(CCOMHTDialog, CDialogEx)

CCOMHTDialog::CCOMHTDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COM_HT_DIALOG, pParent)
{
	m_count = 0;
	m_ArrayLen = CHAER_X_LEN;
	m_f = NULL;
}

CCOMHTDialog::~CCOMHTDialog()
{
	//free(m_x);
	//free(m_y);
	KillTimer(1);
	if (m_f) {
		fclose(m_f);
	}
}

void CCOMHTDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_chart);
}


BEGIN_MESSAGE_MAP(CCOMHTDialog, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CCOMHTDialog 消息处理程序

void CCOMHTDialog::OnCOMRecvHT(int h, int t) {
	HTSlot::OnCOMRecvHT(h, t);
	int index = m_count;
	int dataLen = m_count + 1;

	long ms = GetTickCount();	//系统启动至今的毫秒数

	if (m_count == 0) {
		m_timeFirst = ms;
	}

	m_count++;
	if (m_count > m_ArrayLen) {
		memcpy(m_oldX, m_x, sizeof(double) * m_ArrayLen);
		memcpy(m_oldY, m_y, sizeof(double) * m_ArrayLen);

		memcpy(m_x, m_oldX + 1, sizeof(double) * (m_ArrayLen - 1));
		memcpy(m_y, m_oldY + 1, sizeof(double) * (m_ArrayLen - 1));

		index = m_ArrayLen - 1;
		dataLen = m_ArrayLen;
	}

	double diff = ms - m_timeFirst;
	m_x[index] = diff / 1000;
	m_y[index] = 100 * (double)h / (double)t;

	writeToFile(h, t);
}


void CCOMHTDialog::OnCOMRecv() {
	HTSlot::OnCOMRecv();

}


BOOL CCOMHTDialog::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  在此添加额外的初始化
	HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, FALSE);

	// 设置chart
	CChartMyTimeAxis *pBottomAxis = m_chart.CreateMyTimeAxis(CChartCtrl::BottomAxis);
	pBottomAxis->SetAutomatic(true);
	pBottomAxis->SetTickIncrement(false, 1);
	pBottomAxis->GetLabel()->SetText(_T("时间（秒）"));

	CChartStandardAxis *pLeftAxis = m_chart.CreateStandardAxis(CChartCtrl::LeftAxis);
	pLeftAxis->SetMinMax(0, 100);
	pLeftAxis->SetAutomatic(false);
	pLeftAxis->GetLabel()->SetText(_T("电压百分比"));
	//pLeftAxis->SetAutomaticMode(CChartAxis::FullAutomatic);

	//m_chart.GetTitle()->AddString(_T("电压"));

	SetTimer(1, 100, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCOMHTDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1) {

		//WriteToFile();

		if (m_count == 0) {
			return;
		}

		// 刷新chart
		m_chart.EnableRefresh(false);
		m_chart.RemoveAllSeries();

		CChartLineSerie *pLineSerie = m_chart.CreateLineSerie();
		pLineSerie->SetSeriesOrdering(poXOrdering);
		pLineSerie->AddPoints(m_x, m_y, (m_count > CHAER_X_LEN) ? CHAER_X_LEN : m_count);

		m_chart.GetLegend()->SetVisible(true);
		m_chart.EnableRefresh(true);
	}

	__super::OnTimer(nIDEvent);
}
