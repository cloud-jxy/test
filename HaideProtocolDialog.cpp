// HaideProtocolDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "HaideProtocolDialog.h"
#include "afxdialogex.h"
#include "testDlg.h"


// HaideProtocolDialog �Ի���

IMPLEMENT_DYNAMIC(HaideProtocolDialog, CDialogEx)

HaideProtocolDialog::HaideProtocolDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HAIDE_PROTOCOL_DIALOG, pParent)
{

}

HaideProtocolDialog::~HaideProtocolDialog()
{
}

void HaideProtocolDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HaideProtocolDialog, CDialogEx)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// HaideProtocolDialog ��Ϣ�������


BOOL HaideProtocolDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void HaideProtocolDialog::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	((CButton *)m_p_parent_dlg->GetDlgItem(IDC_CHECK2))->SetCheck(false);
	CDialogEx::OnClose();
}
