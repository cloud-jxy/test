#pragma once


// TabDriverDialog 对话框

class TabDriverDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabDriverDialog)

public:
	TabDriverDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabDriverDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DRIVER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
