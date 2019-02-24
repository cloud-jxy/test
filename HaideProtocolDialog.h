#pragma once
#include "afxcmn.h"
#include "FrameRuleDialog.h"
#include "ControlCAN.h"


class CTestDlg;

// HaideProtocolDialog �Ի���

class HaideProtocolDialog : public CDialogEx
{
	DECLARE_DYNAMIC(HaideProtocolDialog)

public:
	HaideProtocolDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HaideProtocolDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HAIDE_PROTOCOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CTestDlg *m_p_parent_dlg;
	afx_msg void OnClose();
	CListCtrl m_ctrl_list;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonEdit();
	int GetCurListItem();
	afx_msg void OnBnClickedButtonClear();
	int ParseFrame(VCI_CAN_OBJ obj);
	afx_msg void OnBnClickedButtonImport();
};
