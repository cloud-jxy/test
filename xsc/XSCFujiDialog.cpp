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
	StaticItemObj(_T("发动机允许参数"), DEFAULT_VAL, _T("0x0C000003"), 0, 0, 2,(PtrFuncToString)(&CXSCFujiDialog::OpenOrClose)),
	StaticItemObj(_T("上装控制器-发动机转速"), DEFAULT_VAL, _T("0x0C000003"), 1, 0, 16,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 0.125, 0),
	StaticItemObj(_T("庆铃国三-发动机转速"), DEFAULT_VAL, _T("0x0CF00400"), 4, 0, 16,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 0.125, 0),
	StaticItemObj(_T("水温"), DEFAULT_VAL, _T("0x18FEEE00"), 0, 0, 8,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 1, -40),
	StaticItemObj(_T("机油温度"), DEFAULT_VAL, _T("0x18FEEE00"), 2, 0, 16,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 0.03125, -40),
	StaticItemObj(_T("机油压力"), DEFAULT_VAL, _T("0x18FEEF00"), 3, 0, 8,(PtrFuncToString)(&CXSCFujiDialog::ValueToString), 4, 0),
	StaticItemObj(_T("预热灯状态"), DEFAULT_VAL, _T("0x18FEE400"), 3, 0, 2,(PtrFuncToString)(&CXSCFujiDialog::YuredengToString)),
	StaticItemObj(_T("机油压力信号"), DEFAULT_VAL, _T("0x18FE6800"), 3, 2, 2,(PtrFuncToString)(&CXSCFujiDialog::JiyouyaliToString)),
};

// 00：OFF-熄灭；01：ON-点亮；10：Error-错误；11：不能获取
CString CXSCFujiDialog::YuredengToString(double val)
{
	CString alls[] = { _T("熄灭"), _T("点亮"), _T("错误"), _T("不能获取") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}

/*00：NOT OK-机油压力低
01：OK - 机油压力大于最小值
10：Error - 信号不能确定
11：不能获取*/
CString CXSCFujiDialog::JiyouyaliToString(double val)
{
	CString alls[] = { _T("机油压力低"), _T("机油压力大于最小值"), _T("信号不能确定"), _T("不能获取") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}


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
