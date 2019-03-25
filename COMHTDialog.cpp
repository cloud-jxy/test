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
	m_ArrayLen = 100;

	m_x = (double *)malloc(sizeof(double) * m_ArrayLen);
	m_y = (double *)malloc(sizeof(double) * m_ArrayLen);
}

CCOMHTDialog::~CCOMHTDialog()
{
	free(m_x);
	free(m_y);
}

void CCOMHTDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_chart);
}


BEGIN_MESSAGE_MAP(CCOMHTDialog, CDialogEx)
END_MESSAGE_MAP()


// CCOMHTDialog 消息处理程序

void CCOMHTDialog::OnCOMRecvHT(int h, int t) {
	HTSlot::OnCOMRecvHT(h, t);
	double *oldX = NULL;
	double *oldY = NULL;
	int index = m_count;
	int dataLen = m_count + 1;

	long ms = GetTickCount();	//系统启动至今的毫秒数

	if (m_count == 0) {
		m_timeFirst = ms;
	}

	m_count++;
	if (m_count > m_ArrayLen) {
		oldX = m_x;
		oldY = m_y;

		m_x = (double *)malloc(sizeof(double) * m_ArrayLen);
		m_y = (double *)malloc(sizeof(double) * m_ArrayLen);

		memcpy(m_x, oldX + 1, sizeof(double) * (m_ArrayLen - 1));
		memcpy(m_y, oldY + 1, sizeof(double) * (m_ArrayLen - 1));

		index = m_ArrayLen - 1;
		dataLen = m_ArrayLen;
	}

	// 刷新chart
	m_chart.EnableRefresh(false);
	m_chart.RemoveAllSeries();

	double diff = ms - m_timeFirst;
	m_x[index] = diff / 1000;
	m_y[index] = 100 * (double)t / (double)h;

	TRACE("%d: (%g, %g)\n", m_count, m_x[index], m_y[index]);

	CChartLineSerie *pLineSerie = m_chart.CreateLineSerie();
	pLineSerie->SetSeriesOrdering(poXOrdering);
	pLineSerie->AddPoints(m_x, m_y, dataLen);

	m_chart.GetLegend()->SetVisible(true);
	m_chart.EnableRefresh(true);

	if (oldX) free(oldX);
	if (oldY) free(oldY);
}


void CCOMHTDialog::OnCOMRecv() {
	HTSlot::OnCOMRecv();

}


BOOL CCOMHTDialog::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// 设置chart
	CChartStandardAxis *pBottomAxis = m_chart.CreateStandardAxis(CChartCtrl::BottomAxis);
	pBottomAxis->SetAutomatic(true);
	pBottomAxis->SetTickIncrement(false, 1);

	CChartStandardAxis *pLeftAxis = m_chart.CreateStandardAxis(CChartCtrl::LeftAxis);
	pLeftAxis->SetMinMax(0, 100);
	pLeftAxis->SetAutomatic(false);
	//pLeftAxis->SetAutomaticMode(CChartAxis::FullAutomatic);

	//m_chart.GetTitle()->AddString(_T("电压"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
