// XSCBaseDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "../test.h"
#include "XSCBaseDialog.h"
#include "afxdialogex.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

static StaticItemObj g_xscBase[] = {
	StaticItemObj(_T("系列"), DEFAULT_VAL, _T("0x18f40000"), 0, 0, 2),
	StaticItemObj(_T("车型"), DEFAULT_VAL, _T("0x18f40000"), 0, 2, 6),
	StaticItemObj(_T("底盘"), DEFAULT_VAL, _T("0x18f40000"), 2, 0, 8),
	StaticItemObj(_T("副发动机"), DEFAULT_VAL, _T("0x18f40000"), 3, 0, 8),
	StaticItemObj(_T("显示屏"), DEFAULT_VAL, _T("0x18f40000"), 4, 0, 4),
	StaticItemObj(_T("控制器"), DEFAULT_VAL, _T("0x18f40000"), 4, 4, 4),
	StaticItemObj(_T("模块1"), DEFAULT_VAL, _T("0x18f40000"), 5, 0, 4),
	StaticItemObj(_T("模块2"), DEFAULT_VAL, _T("0x18f40000"), 5, 4, 4),
	StaticItemObj(_T("语音报警器"), DEFAULT_VAL, _T("0x18f40000"), 6, 0, 4),
	StaticItemObj(_T("遥控"), DEFAULT_VAL, _T("0x18f40000"), 6, 4, 4),
	StaticItemObj(_T("电机"), DEFAULT_VAL, _T("0x18f40000"), 7, 0, 8),
	StaticItemObj(_T("显示屏程序版本号"), DEFAULT_VAL, _T("0x18f40003"), 0, 0, 16),
	StaticItemObj(_T("控制器程序版本号"), DEFAULT_VAL, _T("0x18f40003"), 2, 0, 16),
	StaticItemObj(_T("显示屏与控制器通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 0, 1),
	StaticItemObj(_T("显示屏与模块1通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 1, 1),
	StaticItemObj(_T("显示屏与模块2通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 2, 1),
	StaticItemObj(_T("显示屏与语音通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 3, 1),
	StaticItemObj(_T("显示屏与遥控通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 4, 1),
	StaticItemObj(_T("显示屏与副发动机通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 5, 1),
	StaticItemObj(_T("显示屏与车载终端通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 6, 1),
	StaticItemObj(_T("显示屏与底盘通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 7, 1),
	StaticItemObj(_T("控制器与模块1通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 0, 1),
	StaticItemObj(_T("控制器与模块2通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 1, 1),
	StaticItemObj(_T("控制器与语音通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 2, 1),
	StaticItemObj(_T("控制器与遥控通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 3, 1),
	StaticItemObj(_T("控制器与副发动机通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 4, 1),
	StaticItemObj(_T("控制器与车载终端通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 5, 1),
	StaticItemObj(_T("控制器与底盘通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 6, 1)
};


// CXSCBaseDialog 对话框

IMPLEMENT_DYNAMIC(CXSCBaseDialog, CMyTabDialog)

CXSCBaseDialog::CXSCBaseDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscBase;
	m_objCount = sizeof(g_xscBase) / sizeof(g_xscBase[0]);
	m_leftW = 175;
	m_rightW = 100;
}

CXSCBaseDialog::~CXSCBaseDialog()
{
}

void CXSCBaseDialog::DoDataExchange(CDataExchange* pDX)
{
	CMyTabDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCBaseDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCBaseDialog 消息处理程序


BOOL CXSCBaseDialog::OnInitDialog()
{
	CMyTabDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
