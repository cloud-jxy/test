#pragma once


// TabBatteryV 对话框

class TabBatteryV : public CDialogEx
{
	DECLARE_DYNAMIC(TabBatteryV)

public:
	TabBatteryV(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabBatteryV();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_BATTERY_VOLTAGE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
