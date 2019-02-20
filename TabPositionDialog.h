#pragma once
#include "ControlCAN.h"

// TabPositionDialog 对话框

class TabPositionDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabPositionDialog)

public:
	TabPositionDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabPositionDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_POSITION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	int ParseFrame(VCI_CAN_OBJ frame);
	CString m_str_status;
	CString m_str_longitude;
	CString m_str_latitude;
};
