// TabBatteryT.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "TabBatteryT.h"
#include "afxdialogex.h"



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
END_MESSAGE_MAP()


int TabBatteryT::ParseFrame(VCI_CAN_OBJ frame) {

	return 0;
}


// TabBatteryT 消息处理程序


BOOL TabBatteryT::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_chart.EnableScrollBar(true);

	CChartStandardAxis *pBottomAxis = m_chart.CreateStandardAxis(CChartCtrl::BottomAxis);
	pBottomAxis->SetMinMax(0, 100);
	pBottomAxis->SetAutomatic(true);
	pBottomAxis->EnableScrollBar(true);
	pBottomAxis->SetTickIncrement(false, 10);
	pBottomAxis->EnableScrollBar(true);
	pBottomAxis->SetAutomaticMode(CChartAxis::FullAutomatic);

	CChartStandardAxis *pLeftAxis = m_chart.CreateStandardAxis(CChartCtrl::LeftAxis);
	pLeftAxis->SetMinMax(0, 10);
	pLeftAxis->SetAutomatic(true);
	pLeftAxis->GetLabel()->SetText(_T("温度"));
	pLeftAxis->SetAutomaticMode(CChartAxis::FullAutomatic);

	m_chart.GetTitle()->AddString(_T("温度统计图"));

	double x[100];
	double y[100];
	int i = 0;
	for (i = 0; i < 100; i++) {
		x[i] = i;
		y[i] = sin((double)x[i] / 0.01);
	}

	m_chart.RemoveAllSeries();
	CChartBarSerie *pLineSerie = m_chart.CreateBarSerie();
	pLineSerie->SetSeriesOrdering(poXOrdering);
	pLineSerie->AddPoints(x, y, 100);

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

