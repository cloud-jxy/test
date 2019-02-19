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
}


BEGIN_MESSAGE_MAP(TabBatteryT, CDialogEx)
END_MESSAGE_MAP()


// TabBatteryT 消息处理程序
