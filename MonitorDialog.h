#pragma once
#include "afxcmn.h"


#define MAX_MONITOR_NUM 100

class HaideProtocolDialog;
class FrameRuleObj;

// MonitorDialog 对话框

class MonitorDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MonitorDialog)

public:
	MonitorDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MonitorDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MONITOR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrl_list;
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonSave();

	CListCtrl *m_list;

	void SetCtrlRect();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	virtual void PostNcDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);

	void SetListCtrl();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	FrameRuleObj *m_objs[MAX_MONITOR_NUM];

	BOOL m_allow_update;
	int m_monitor_num;	//被监控对象个数
};
