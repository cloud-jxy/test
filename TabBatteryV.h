#pragma once


// TabBatteryV �Ի���

class TabBatteryV : public CDialogEx
{
	DECLARE_DYNAMIC(TabBatteryV)

public:
	TabBatteryV(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabBatteryV();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_BATTERY_VOLTAGE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
