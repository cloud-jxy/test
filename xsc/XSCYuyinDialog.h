#pragma once
#include "../MyTabDialog.h"

// CXSCYuyinDialog 对话框

class CXSCYuyinDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCYuyinDialog)

public:
	CXSCYuyinDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CXSCYuyinDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSC_CONTROL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
