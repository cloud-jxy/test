#pragma once
#include "../MyTabDialog.h"

// CXSCScreenDialog 对话框

class CXSCScreenDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCScreenDialog)

public:
	CXSCScreenDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CXSCScreenDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSCSCREENDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
