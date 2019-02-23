#pragma once


class CTestDlg;

// HaideProtocolDialog 对话框

class HaideProtocolDialog : public CDialogEx
{
	DECLARE_DYNAMIC(HaideProtocolDialog)

public:
	HaideProtocolDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HaideProtocolDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HAIDE_PROTOCOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CTestDlg *m_p_parent_dlg;
	afx_msg void OnClose();
};
