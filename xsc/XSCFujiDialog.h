#pragma once
#include "../MyTabDialog.h"

// CXSCFujiDialog 对话框

class CXSCFujiDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCFujiDialog)

public:
	CXSCFujiDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CXSCFujiDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSCFUJIDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
