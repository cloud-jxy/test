#pragma once


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
};
