#pragma once
#include "afxdialogex.h"
#include "ControlCAN.h"

class CParseDialog :
	public CDialogEx
{
public:
	CParseDialog();
	~CParseDialog();

	CParseDialog(UINT nIDTemplate, CWnd *pParent = NULL);

public:
	virtual int ParseFrame(VCI_CAN_OBJ obj) = 0;
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	virtual void SetCtrlRect();
	BOOL m_sizing = FALSE;
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	virtual BOOL OnInitDialog();
};

