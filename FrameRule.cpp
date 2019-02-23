// FrameRule.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "FrameRule.h"
#include "afxdialogex.h"


// FrameRule 对话框

IMPLEMENT_DYNAMIC(FrameRule, CDialogEx)

FrameRule::FrameRule(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FRAME_RULE_DIALOG, pParent)
{

}

FrameRule::~FrameRule()
{
}

void FrameRule::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FrameRule, CDialogEx)
END_MESSAGE_MAP()


// FrameRule 消息处理程序
