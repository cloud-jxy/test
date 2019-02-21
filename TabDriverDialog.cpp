// TabDriverDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "TabDriverDialog.h"
#include "afxdialogex.h"


// TabDriverDialog �Ի���

IMPLEMENT_DYNAMIC(TabDriverDialog, CDialogEx)

TabDriverDialog::TabDriverDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_DRIVER_DIALOG, pParent)
	, m_str_machine_num(_T("1"))
	, m_str_machine_id(_T("1"))
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
	UINT ID = frame.ID;
	BYTE *data = frame.Data;

	if (ID == 0x180A7A70) {
		/*
		�������״̬
		0 1 2 0 0
		0��standby��1 �綯״̬ 2 ����״̬ 3 ����ֵ
		*/

		int val = (data[0] >> 1) & 0x03;
		CString str_val[] = { _T("����"), _T("�綯"), _T("����"), _T("����ֵ") };

		m_str_machine_status = str_val[val];

		/*
		�������ת��
		2 0 16 0.5 0
		*/
		val = (data[2] + (data[3] << 8)) * 0.5;
		m_str_machine_rev.Format(_T("%d"), val);

		/*
		�������ת��
		4 0 16 1 -32000
		*/
		val = (data[4] + (data[5] << 8)) - 32000;
		m_str_machine_torque.Format(_T("%d"), val);
	}
	else if (ID == 0x180D7A70) {
		/*
		��������������¶�
		1 0 8 1 -40
		*/
		int val = data[1] - 40;
		m_str_controner_t.Format(_T("%d"), val);

		/*
		��������¶�
		2 0 8 1 -40
		*/
		val = data[2] - 40;
		m_str_machine_t.Format(_T("%d"), val);
	}
	else if (ID == 0x180B7A70) {
		/*
		��������������ѹ
		0 0 16 0.05 0
		*/
		float val = (data[0] + (data[1] << 8)) * 0.05;
		m_str_controner_v.Format(_T("%.2f"), val);

		/*
		���������ֱ��ĸ�ߵ���
		2 0 16 0.05 -1600
		*/
		val = (data[2] + (data[3] << 8)) * 0.05 - 1600;
		m_str_controner_i.Format(_T("%.2f"), val);
	}
	
	UpdateData(false);
	return 0;
}


// TabDriverDialog ��Ϣ�������
