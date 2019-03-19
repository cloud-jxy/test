// MyTabDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "MyTabDialog.h"
#include "afxdialogex.h"


// CMyTabDialog 对话框

IMPLEMENT_DYNAMIC(CMyTabDialog, CDialogEx)

CMyTabDialog::CMyTabDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYTABDIALOG, pParent)
{

}

CMyTabDialog::CMyTabDialog(UINT nIDTemplate, CWnd *pParent) : CDialogEx(nIDTemplate, pParent) {

}

CMyTabDialog::~CMyTabDialog()
{
}

void CMyTabDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyTabDialog, CDialogEx)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CMyTabDialog 消息处理程序


BOOL CMyTabDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CreateCtrl();
	SetCtrlRect();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CMyTabDialog::CreateCtrl() {
	//StaticItemObj *pObjs = m_objs;
	//StaticItemObj* pObj = &pObjs[0];
	//int i = 0;

	//for (i = 0; i < m_objCount; i++) {
	//	CStaticItem *item = new CStaticItem();
	//	pObj->m_pParam = item;
	//}
}

void CMyTabDialog::SetCtrlRect() {
	CRect rect, rtKey, rtValue;
	GetWindowRect(&rect);
	ScreenToClient(&rect);

	//去除margin
	int marginT = 10, marginB = 10, marginL = 5, marginR = 5;
	rect.top += marginT;
	rect.bottom -= marginB;
	rect.left += marginL;
	rect.right -= marginR;

	int leftW = m_leftW;
	int rightW = m_rightW;
	int h = 20;

	int i = 0;
	StaticItemObj *pObjs = m_objs;

	int col = 0;
	int row = 0;
	int colCount = GetcolCount();
	if (colCount == 0) colCount = 1;
	i = 0;

	StaticItemObj* pObj = &pObjs[0];
	for (i = 0; i < m_objCount; i++) {
		pObj = &pObjs[i];

		if (col >= colCount) {
			col = col % colCount;
			row++;
		}

		rtKey.top = rect.top + row * h;
		rtKey.bottom = rtKey.top + h;
		rtKey.left = rect.left + col * (leftW + rightW);
		rtKey.right = rtKey.left + leftW;

		rtValue.top = rtKey.top;
		rtValue.bottom = rtKey.bottom;
		rtValue.left = rtKey.right;
		rtValue.right = rtValue.left + rightW;

		CStaticItem *item = (CStaticItem *)pObj->m_pParam;
		if (item == NULL) {
			item = new CStaticItem();
			pObj->m_pParam = item;
			item->Create(this, pObj, rtKey, rtValue);
		}
		else {
			if (item->m_ctrlKey.m_hWnd == NULL || item->m_ctrlValue.m_hWnd == NULL) item->Create(this, pObj, rtKey, rtValue);

			item->m_ctrlKey.MoveWindow(rtKey);
			item->m_ctrlValue.MoveWindow(rtValue);
		}

		col++;
	}

	 // 重新计算dialog rect
	rect.bottom = rect.top + (row + 1) * h;
	rect.right = rect.left + 2 * (leftW + rightW) - 40;

	rect.top -= marginT;
	rect.bottom += marginB;
	rect.left -= marginL;
	rect.right += marginR;

	ClientToScreen(&rect);
	MoveWindow(&rect);
}


int CMyTabDialog::GetcolCount() {
	CRect r;
	GetParent()->GetWindowRect(&r);

	return (r.right - r.left - 30) / (m_leftW + m_rightW);
}


void CMyTabDialog::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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


void CMyTabDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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