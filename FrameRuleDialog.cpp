// FrameRuleDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "FrameRuleDialog.h"
#include "afxdialogex.h"


// FrameRuleDialog �Ի���

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


// FrameRuleDialog ��Ϣ�������
