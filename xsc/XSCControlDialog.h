#pragma once
#include "../MyTabDialog.h"

// CXSCControlDialog 对话框

class CXSCControlDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCControlDialog)

public:
	CXSCControlDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CXSCControlDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSC_SCREEN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
