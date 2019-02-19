// TabExtremumDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "TabExtremumDialog.h"
#include "afxdialogex.h"


// TabExtremumDialog 对话框

IMPLEMENT_DYNAMIC(TabExtremumDialog, CDialogEx)

TabExtremumDialog::TabExtremumDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_EXTREMUM_DIALOG, pParent)
{

}

TabExtremumDialog::~TabExtremumDialog()
{
}

void TabExtremumDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabExtremumDialog, CDialogEx)
END_MESSAGE_MAP()


// TabExtremumDialog 消息处理程序
