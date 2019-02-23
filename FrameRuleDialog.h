#pragma once

class HaideProtocolDialog;

class FrameRuleObj {
public:
	CString name;
	CString id;
	int start_byte;
	int start_bite;
	int bite_len;
	double ratio;
	double offset;
};

enum OperateType {
	ADD
	, EDIT
	, LOOK
};

// FrameRuleDialog �Ի���

class FrameRuleDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FrameRuleDialog)

public:
	FrameRuleDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FrameRuleDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FRAME_RULE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	OperateType m_operate;
	HaideProtocolDialog *m_p_dlg;
	afx_msg void OnBnClickedOk();
	CString m_str_name;
	CString m_str_id;
	int m_i_start_byte;
	int m_i_start_bite;
	int m_i_bite_len;
	double m_ratio;
	double m_offset;
	virtual BOOL OnInitDialog();

	int m_list_index;
};
