#pragma once


// TabExtremumDialog 对话框

class TabExtremumDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabExtremumDialog)

public:
	TabExtremumDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabExtremumDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_EXTREMUM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
