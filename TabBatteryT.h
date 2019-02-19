#pragma once


// TabBatteryT 对话框

class TabBatteryT : public CDialogEx
{
	DECLARE_DYNAMIC(TabBatteryT)

public:
	TabBatteryT(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabBatteryT();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_BATTERY_T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
