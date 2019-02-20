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
	, m_str_machine_num(_T(""))
	, m_str_machine_id(_T(""))
	, m_str_machine_rev(_T(""))
	, m_str_machine_status(_T(""))
	, m_str_machine_t(_T(""))
	, m_str_machine_torque(_T(""))
	, m_str_controner_t(_T(""))
	, m_str_controner_v(_T(""))
	, m_str_controner_i(_T(""))
{

}

TabDriverDialog::~TabDriverDialog()
{
}

void TabDriverDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MACHINE_NUM, m_str_machine_num);
	DDX_Text(pDX, IDC_EDIT_MACHINE_ID, m_str_machine_id);
	DDX_Text(pDX, IDC_EDIT_MACHINE_REV, m_str_machine_rev);
	DDX_Text(pDX, IDC_EDIT_MACHINE_STATUS, m_str_machine_status);
	DDX_Text(pDX, IDC_EDIT_MACHINE_T, m_str_machine_t);
	DDX_Text(pDX, IDC_EDIT_MACHINE_TORQUE, m_str_machine_torque);
	DDX_Text(pDX, IDC_EDIT_CONTRONER_T, m_str_controner_t);
	DDX_Text(pDX, IDC_EDIT_CONTRONER_V, m_str_controner_v);
	DDX_Text(pDX, IDC_EDIT_CONTRONER_I, m_str_controner_i);
}


BEGIN_MESSAGE_MAP(TabDriverDialog, CDialogEx)
END_MESSAGE_MAP()


int TabDriverDialog::ParseFrame(VCI_CAN_OBJ frame) {
	return 0;
}


// TabDriverDialog 消息处理程序
