#pragma once


// FrameRule 对话框

class FrameRule : public CDialogEx
{
	DECLARE_DYNAMIC(FrameRule)

public:
	FrameRule(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~FrameRule();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FRAME_RULE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
