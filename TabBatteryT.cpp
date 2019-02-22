// TabBatteryT.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "TabBatteryT.h"
#include "afxdialogex.h"
#include "InfoDialog.h"


static BOOL g_run;

DWORD WINAPI ThreadProc(LPVOID pParam);

// TabBatteryT 对话框

IMPLEMENT_DYNAMIC(TabBatteryT, CDialogEx)

TabBatteryT::TabBatteryT(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_BATTERY_T_DIALOG, pParent)
{

}

TabBatteryT::~TabBatteryT()
{
}

void TabBatteryT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM_T, m_chart);
}


BEGIN_MESSAGE_MAP(TabBatteryT, CDialogEx)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_MESSAGE(WM_CHART_T, &TabBatteryT::OnChartT)
END_MESSAGE_MAP()


int TabBatteryT::ParseFrame(VCI_CAN_OBJ frame) {
	BYTE *data = frame.Data;
	//frame.ID = 0x18407A70;
	UINT l_id = frame.ID & 0x0000ffff;
	UINT h_id = (frame.ID & 0xffff0000) >> 16;
	UINT start_index = 0x18407A70 >> 16;
	UINT end_index = 0x18487A70 >> 16;
	int index = 0;
	int i = 0;
	TabExtremumDialog *p_dlg = &((CInfoDialog *)m_p_parent_dlg)->m_dlg_extremum;


	if (h_id <start_index || h_id > end_index || l_id != 0x7A70) {
		return 0;
	}

	index = h_id - start_index;

	/*
	温度报文特点
	每8bite 表示一个温度值，精度1 偏移量-40
	*/
	for (i = 0; i < 8; i++) {
		int x = index * 8 + i;
		int y = data[i] - 40;
		m_y[x] = y;

		if (m_max == -1 || m_max < y) {
			m_max = x;
			CString str;
			str.Format("%d", m_max);

			((CEdit *)p_dlg->GetDlgItem(IDC_EDIT_H_T_BATTERY_ID))->SetWindowText(str);
		}

		if (m_min == -1 || m_min > y) {
			m_min = x;

			CString str;
			str.Format("%d", m_min);

			((CEdit *)p_dlg->GetDlgItem(IDC_EDIT_L_T_BATTERY_ID))->SetWindowText(str);
		}
	}

	return 0;
}


// TabBatteryT 消息处理程序


BOOL TabBatteryT::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	int i = 0;

	for (i = 0; i < T_ARRAY_LEN; i++) {
		m_x[i] = i;
		m_y[i] = 0;
	}

	m_max = -1;
	m_min = -1;

	CChartStandardAxis *pBottomAxis = m_chart.CreateStandardAxis(CChartCtrl::BottomAxis);
	pBottomAxis->SetMinMax(0, 100);
	pBottomAxis->SetAutomatic(true);
	pBottomAxis->SetTickIncrement(false, 5);

	CChartStandardAxis *pLeftAxis = m_chart.CreateStandardAxis(CChartCtrl::LeftAxis);
	pLeftAxis->SetMinMax(0, 1);
	pLeftAxis->SetAutomatic(true);
	pLeftAxis->GetLabel()->SetText(_T("温度"));
	pLeftAxis->SetAutomaticMode(CChartAxis::FullAutomatic);

	//m_chart.GetTitle()->AddString(_T("温度统计图"));

	m_chart.RemoveAllSeries();
	CChartBarSerie *pLineSerie = m_chart.CreateBarSerie();
	pLineSerie->SetSeriesOrdering(poXOrdering);
	pLineSerie->AddPoints(m_x, m_y, T_ARRAY_LEN);


	// 起线程，刷新chart
	g_run = TRUE;
	AfxBeginThread((AFX_THREADPROC)ThreadProc, (LPVOID)this);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void TabBatteryT::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SCROLLINFO scrollInfo;
	GetScrollInfo(SB_VERT, &scrollInfo, SIF_ALL);
	switch (nSBCode)
	{
	case   SB_LINEUP:
		scrollInfo.nPos -= 1;
		if (scrollInfo.nPos < scrollInfo.nMin)
		{
			scrollInfo.nPos = scrollInfo.nMin;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollInfo, SIF_ALL);
		ScrollWindow(0, 1);
		break;
	case   SB_LINEDOWN:
		scrollInfo.nPos += 1;
		if (scrollInfo.nPos > scrollInfo.nMax)
		{
			scrollInfo.nPos = scrollInfo.nMax;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollInfo, SIF_ALL);
		ScrollWindow(0, -1);
		break;
	case   SB_TOP:
		ScrollWindow(0, (scrollInfo.nPos - scrollInfo.nMin) * 1);
		scrollInfo.nPos = scrollInfo.nMin;
		SetScrollInfo(SB_VERT, &scrollInfo, SIF_ALL);
		break;
	case   SB_BOTTOM:
		ScrollWindow(0, -(scrollInfo.nMax - scrollInfo.nPos) * 1);
		scrollInfo.nPos = scrollInfo.nMax;
		SetScrollInfo(SB_VERT, &scrollInfo, SIF_ALL);
		break;
	case   SB_PAGEUP:
		scrollInfo.nPos -= 1;
		if (scrollInfo.nPos < scrollInfo.nMin)
		{
			scrollInfo.nPos = scrollInfo.nMin;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollInfo, SIF_ALL);
		ScrollWindow(0, 1 * 1);
		break;
	case   SB_PAGEDOWN:
		scrollInfo.nPos += 1;
		if (scrollInfo.nPos > scrollInfo.nMax)
		{
			scrollInfo.nPos = scrollInfo.nMax;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollInfo, SIF_ALL);
		ScrollWindow(0, -1 * 1);
		break;
	case   SB_ENDSCROLL:
		break;
	case   SB_THUMBPOSITION:
		break;
	case   SB_THUMBTRACK:

		char mstr[64] = { 0 };
		sprintf(mstr, "nPos1:%d nPos1:%d/n", scrollInfo.nPos, nPos);
		OutputDebugString(mstr);

		ScrollWindow(0, (scrollInfo.nPos - nPos));
		scrollInfo.nPos = nPos;
		SetScrollInfo(SB_VERT, &scrollInfo, SIF_ALL);
		break;
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void TabBatteryT::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SCROLLINFO scrollInfo;
	GetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);
	switch (nSBCode)
	{
	case   SB_LINEUP:
		scrollInfo.nPos -= 1;
		if (scrollInfo.nPos < scrollInfo.nMin)
		{
			scrollInfo.nPos = scrollInfo.nMin;
			break;
		}
		SetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);
		ScrollWindow(10, 0);
		break;
	case   SB_LINEDOWN:
		scrollInfo.nPos += 1;
		if (scrollInfo.nPos > scrollInfo.nMax)
		{
			scrollInfo.nPos = scrollInfo.nMax;
			break;
		}
		SetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);
		ScrollWindow(-10, 0);
		break;
	case   SB_TOP:
		ScrollWindow((scrollInfo.nPos - scrollInfo.nMin) * 10, 0);
		scrollInfo.nPos = scrollInfo.nMin;
		SetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);
		break;
	case   SB_BOTTOM:
		ScrollWindow(-(scrollInfo.nMax - scrollInfo.nPos) * 10, 0);
		scrollInfo.nPos = scrollInfo.nMax;
		SetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);
		break;
	case   SB_PAGEUP:
		scrollInfo.nPos -= 5;
		if (scrollInfo.nPos < scrollInfo.nMin)
		{
			scrollInfo.nPos = scrollInfo.nMin;
			break;
		}
		SetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);
		ScrollWindow(10 * 5, 0);
		break;
	case   SB_PAGEDOWN:
		scrollInfo.nPos += 5;
		if (scrollInfo.nPos > scrollInfo.nMax)
		{
			scrollInfo.nPos = scrollInfo.nMax;
			break;
		}
		SetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);
		ScrollWindow(-10 * 5, 0);
		break;
	case   SB_ENDSCROLL:
		break;
	case   SB_THUMBPOSITION:
		break;
	case   SB_THUMBTRACK:
		ScrollWindow((scrollInfo.nPos - nPos) * 10, 0);
		scrollInfo.nPos = nPos;
		SetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);
		break;
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

static DWORD WINAPI ThreadProc(LPVOID pParam) {
	TabBatteryT *dlg = (TabBatteryT *)pParam;

	while (g_run) {
		Sleep(1000);
		//dlg->UpdateChart();
		dlg->SendMessage(WM_CHART_T, 0, 0);
	}

	return 0;
}


void TabBatteryT::UpdateChart()
{
	//int i = 0;

	//for (i = 0; i < T_ARRAY_LEN; i++) {
	//	m_y[i] = (rand() % 10);
	//}

	m_chart.EnableRefresh(false);

	m_chart.RemoveAllSeries();
	CChartBarSerie *pLineSerie = m_chart.CreateBarSerie();
	pLineSerie->SetSeriesOrdering(poXOrdering);
	pLineSerie->AddPoints(m_x, m_y, T_ARRAY_LEN);

	m_chart.EnableRefresh(true);
}


LRESULT TabBatteryT::OnChartT(WPARAM wParam, LPARAM lParam) {
	UpdateChart();

	return 0;
}
