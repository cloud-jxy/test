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
public:
	CString m_str_machine_num;
	CString m_str_machine_id;
	CString m_str_machine_rev;
	CString m_str_machine_status;
	CString m_str_machine_t;
	CString m_str_machine_torque;
	CString m_str_controner_t;
	CString m_str_controner_v;
	CString m_str_controner_i;
};
