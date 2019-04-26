// ./xsc/XSCScreenDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "../test.h"
#include "XSCScreenDialog.h"
#include "afxdialogex.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"
#include "../MyTabDialog.h"

#define DEFAULT_VAL _T("")


StaticItemObj g_xscScreen[] = {

	StaticItemObj(_T("箱体升"), DEFAULT_VAL, _T("0x18F40100"), 0, 0, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("箱体降"), DEFAULT_VAL, _T("0x18F40100"), 0, 1, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("后门开"), DEFAULT_VAL, _T("0x18F40100"), 0, 2, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("后门关"), DEFAULT_VAL, _T("0x18F40100"), 0, 3, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("箱内冲水"), DEFAULT_VAL, _T("0x18F40100"), 0, 4, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("冲水"), DEFAULT_VAL, _T("0x18F40100"), 0, 5, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("洗扫"), DEFAULT_VAL, _T("0x18F40100"), 0, 6, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("清扫"), DEFAULT_VAL, _T("0x18F40100"), 0, 7, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("后门喷雾"), DEFAULT_VAL, _T("0x18F40100"), 1, 0, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("左作业"), DEFAULT_VAL, _T("0x18F40100"), 1, 1, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("全作业"), DEFAULT_VAL, _T("0x18F40100"), 1, 2, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("右作业"), DEFAULT_VAL, _T("0x18F40100"), 1, 3, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("喷雾降尘"), DEFAULT_VAL, _T("0x18F40100"), 1, 4, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("油泵"), DEFAULT_VAL, _T("0x18F40100"), 1, 5, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("水泵"), DEFAULT_VAL, _T("0x18F40100"), 1, 6, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("吸口工作"), DEFAULT_VAL, _T("0x18F40100"), 1, 7, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("挡板开"), DEFAULT_VAL, _T("0x18F40100"), 2, 0, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("上盖开"), DEFAULT_VAL, _T("0x18F40100"), 2, 1, 1, (PtrFuncToString)(&CXSCScreenDialog::OpenOrClose)),
	StaticItemObj(_T("发动机转速"), DEFAULT_VAL, _T("0x18F40102"), 0, 0, 16, (PtrFuncToString)(&CXSCScreenDialog::ValueToString), 0.125, 0),
	StaticItemObj(_T("扫刷转速"), DEFAULT_VAL, _T("0x18F40102"), 2, 0, 8, (PtrFuncToString)(&CXSCScreenDialog::ValueToString), 1, 0)
};

// CXSCScreenDialog 对话框

IMPLEMENT_DYNAMIC(CXSCScreenDialog, CMyTabDialog)

CXSCScreenDialog::CXSCScreenDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_XSCSCREENDIALOG, pParent)
{
	m_objs = g_xscScreen;
	m_objCount = sizeof(g_xscScreen) / sizeof(g_xscScreen[0]);
	m_leftW = 90;
	m_rightW = 140;
}

CXSCScreenDialog::~CXSCScreenDialog()
{
}

void CXSCScreenDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCScreenDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCScreenDialog 消息处理程序
