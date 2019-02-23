// FrameRuleDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "FrameRuleDialog.h"
#include "afxdialogex.h"


// FrameRuleDialog 对话框

IMPLEMENT_DYNAMIC(FrameRuleDialog, CDialogEx)

FrameRuleDialog::FrameRuleDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FRAME_RULE_DIALOG, pParent)
{

}

FrameRuleDialog::~FrameRuleDialog()
{
}

void FrameRuleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FrameRuleDialog, CDialogEx)
END_MESSAGE_MAP()


// FrameRuleDialog 消息处理程序
