// TabPositionDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "TabPositionDialog.h"
#include "afxdialogex.h"


// TabPositionDialog 对话框

IMPLEMENT_DYNAMIC(TabPositionDialog, CDialogEx)

TabPositionDialog::TabPositionDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_POSITION_DIALOG, pParent)
	, m_str_status(_T(""))
	, m_str_longitude(_T(""))
	, m_str_latitude(_T(""))
{

}

TabPositionDialog::~TabPositionDialog()
{
}

void TabPositionDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STATUS, m_str_status);
	DDX_Text(pDX, IDC_EDIT_LONGITUDE, m_str_longitude);
	DDX_Text(pDX, IDC_EDIT_LATITUDE, m_str_latitude);
}


BEGIN_MESSAGE_MAP(TabPositionDialog, CDialogEx)
END_MESSAGE_MAP()


int TabPositionDialog::ParseFrame(VCI_CAN_OBJ frame) {
	return 0;
}


// TabPositionDialog 消息处理程序
