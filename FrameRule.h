#pragma once


// FrameRule �Ի���

class FrameRule : public CDialogEx
{
	DECLARE_DYNAMIC(FrameRule)

public:
	FrameRule(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FrameRule();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FRAME_RULE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
