// TabDriverDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "TabDriverDialog.h"
#include "afxdialogex.h"


// TabDriverDialog 对话框

IMPLEMENT_DYNAMIC(TabDriverDialog, CDialogEx)

TabDriverDialog::TabDriverDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_DRIVER_DIALOG, pParent)
{

}

TabDriverDialog::~TabDriverDialog()
{
}

void TabDriverDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabDriverDialog, CDialogEx)
END_MESSAGE_MAP()


// TabDriverDialog 消息处理程序
