#pragma once


// TabBatteryT �Ի���

class TabBatteryT : public CDialogEx
{
	DECLARE_DYNAMIC(TabBatteryT)

public:
	TabBatteryT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabBatteryT();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_BATTERY_T_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
