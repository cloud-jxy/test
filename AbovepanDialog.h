#pragma once
#include "ParseDialog.h"
#include "ControlCAN.h"
#include "afxcmn.h"
#include "MyTabCtrl.h"
#include "afxwin.h"

struct AbovepanItemObj;

// CAbovepanDialog �Ի���

class CAbovepanDialog : public CParseDialog
{
	DECLARE_DYNAMIC(CAbovepanDialog)

public:
	CAbovepanDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAbovepanDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOVEPAN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_list;
	int m_listW;
	CMyTabCtrl m_tab;
	virtual BOOL OnInitDialog();
	virtual int ParseFrame(VCI_CAN_OBJ obj);
	virtual void SetCtrlRect();

	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);

	void InsetToTab(AbovepanItemObj* item, int index = 0);
	CStatic m_stTitle;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
};
