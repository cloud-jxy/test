#pragma once
#include "afxcmn.h"

class CAbovepanDialog;
class CTestDlg;
// NavigationDialog 对话框

class NavigationDialog : public CDialogEx
{
	DECLARE_DYNAMIC(NavigationDialog)

public:
	NavigationDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~NavigationDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NAVIGATION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CTestDlg *m_p_parent_dlg;
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonCostom();
	afx_msg void OnBnClickedButtonCar();
	afx_msg void OnBnClickedButtonAbovePan();

	CAbovepanDialog *m_abovepanDlg = NULL;
};
