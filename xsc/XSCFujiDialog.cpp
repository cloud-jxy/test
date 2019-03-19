// ./xsc/XSCFujiDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "XSCFujiDialog.h"
#include "afxdialogex.h"
#include "../resource.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

static StaticItemObj g_xscFuji[] = {
	StaticItemObj(_T("发动机允许参数"), DEFAULT_VAL, _T("0x0C000003"), 0, 0, 2, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("发动机转速（低位）"), DEFAULT_VAL, _T("0x0C000003"), 1, 0, 8, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("发动机转速（高位）"), DEFAULT_VAL, _T("0x0C000003"), 2, 0, 8, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("发动机转速"), DEFAULT_VAL, _T("0x0CF00400"), 4, 0, 16, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("水温"), DEFAULT_VAL, _T("0x18FEEE00"), 0, 0, 8, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("机油温度"), DEFAULT_VAL, _T("0x18FEEE00"), 2, 0, 16, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("机油压力"), DEFAULT_VAL, _T("0x18FEEF00"), 3, 0, 8, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("预热灯状态"), DEFAULT_VAL, _T("0x18FEE400"), 3, 0, 2, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
	StaticItemObj(_T("机油压力信号"), DEFAULT_VAL, _T("0x18FE6800"), 3, 2, 2, (PtrFuncToString)(&CXSCFujiDialog::ValueToString)),
};


// CXSCFujiDialog 对话框

IMPLEMENT_DYNAMIC(CXSCFujiDialog, CMyTabDialog)

CXSCFujiDialog::CXSCFujiDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscFuji;
	m_objCount = sizeof(g_xscFuji) / sizeof(g_xscFuji[0]);
	m_leftW = 175;
	m_rightW = 100;
}

CXSCFujiDialog::~CXSCFujiDialog()
{
}

void CXSCFujiDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCFujiDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCFujiDialog 消息处理程序
