#pragma once


// TabCarDialog 对话框

class TabCarDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabCarDialog)

public:
	TabCarDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabCarDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_CAR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
