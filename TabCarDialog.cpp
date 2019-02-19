// TabCarDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "TabCarDialog.h"
#include "afxdialogex.h"


// TabCarDialog 对话框

IMPLEMENT_DYNAMIC(TabCarDialog, CDialogEx)

TabCarDialog::TabCarDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_CAR_DIALOG, pParent)
{

}

TabCarDialog::~TabCarDialog()
{
}

void TabCarDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabCarDialog, CDialogEx)
END_MESSAGE_MAP()


// TabCarDialog 消息处理程序
