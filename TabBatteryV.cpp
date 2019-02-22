// TabBatteryV.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "TabBatteryV.h"
#include "afxdialogex.h"


static BOOL g_run;

static DWORD WINAPI ThreadProc(LPVOID pParam) {
	TabBatteryV *dlg = (TabBatteryV *)pParam;

	while (g_run) {
		Sleep(1000);
		//dlg->UpdateChart();
		dlg->SendMessage(WM_CHART_V, 0, 0);
	}

	return 0;
}

// TabBatteryV �Ի���

IMPLEMENT_DYNAMIC(TabBatteryV, CDialogEx)

TabBatteryV::TabBatteryV(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_BATTERY_VOLTAGE_DIALOG, pParent)
{

}

TabBatteryV::~TabBatteryV()
{
}

void TabBatteryV::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_chart);
}


BEGIN_MESSAGE_MAP(TabBatteryV, CDialogEx)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_MESSAGE(WM_CHART_V, &TabBatteryV::OnChartV)
END_MESSAGE_MAP()


int TabBatteryV::ParseFrame(VCI_CAN_OBJ frame) {
	BYTE *data = frame.Data;
	UINT l_id = frame.ID & 0x0000ffff;
	UINT h_id = (frame.ID & 0xffff0000) >> 16;
	UINT start_index = 0x180F7A70 >> 16;
	UINT end_index = 0x183B7A70 >> 16;
	int i = 0;

	if (h_id <start_index || h_id > end_index || l_id != 0x7A70) {
		return 0;
	}

	/*
	�����ص�
	ÿ16bite ��ʾһ���¶�ֵ������0.001 ƫ����0
	*/
	for (i = 0; i < 8; i += 2) {
		int x = (h_id - start_index) * 4 + i / 2;
		m_y[x] = (data[i] + data[i + 1] << 8) * 0.001;
	}

	return 0;
}


// TabBatteryV ��Ϣ�������


void TabBatteryV::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


void TabBatteryV::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


BOOL TabBatteryV::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	int i = 0;
	for (i = 0; i < V_ARRAY_LEN; i++) {
		m_x[i] = i;
		m_y[i] = 0;
	}

	// ���ù�����
	SCROLLINFO scrollInfo;
	GetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);
	scrollInfo.nMax = 255;
	SetScrollInfo(SB_HORZ, &scrollInfo, SIF_ALL);

	// ����chart
	CChartStandardAxis *pBottomAxis = m_chart.CreateStandardAxis(CChartCtrl::BottomAxis);
	pBottomAxis->SetMinMax(0, 100);
	pBottomAxis->SetAutomatic(true);
	pBottomAxis->SetTickIncrement(false, 5);

	CChartStandardAxis *pLeftAxis = m_chart.CreateStandardAxis(CChartCtrl::LeftAxis);
	pLeftAxis->SetMinMax(0, 1);
	pLeftAxis->SetAutomatic(true);
	pLeftAxis->GetLabel()->SetText(_T("��ѹ/V"));
	pLeftAxis->SetAutomaticMode(CChartAxis::FullAutomatic);

	//m_chart.GetTitle()->AddString(_T("��ѹͳ��ͼ"));

	m_chart.RemoveAllSeries();
	CChartBarSerie *pLineSerie = m_chart.CreateBarSerie();
	pLineSerie->SetSeriesOrdering(poXOrdering);
	pLineSerie->AddPoints(m_x, m_y, V_ARRAY_LEN);


	// ���̣߳�ˢ��chart
	g_run = TRUE;
	AfxBeginThread((AFX_THREADPROC)ThreadProc, (LPVOID)this);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void TabBatteryV::UpdateChart()
{
	//int i = 0;

	//for (i = 0; i < V_ARRAY_LEN; i++) {
	//	m_y[i] = (rand() % 10);
	//}

	m_chart.EnableRefresh(false);

	m_chart.RemoveAllSeries();
	CChartBarSerie *pLineSerie = m_chart.CreateBarSerie();
	pLineSerie->SetSeriesOrdering(poXOrdering);
	pLineSerie->AddPoints(m_x, m_y, V_ARRAY_LEN);

	m_chart.EnableRefresh(true);
}


LRESULT TabBatteryV::OnChartV(WPARAM wParam, LPARAM lParam) {
	UpdateChart();

	return 0;
}
