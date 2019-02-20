// TabBatteryV.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "TabBatteryV.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(TabBatteryV, CDialogEx)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


int TabBatteryV::ParseFrame(VCI_CAN_OBJ frame) {

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
