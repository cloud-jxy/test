// testDlg.h : header file
//

#if !defined(AFX_TESTDLG_H__0B453A60_AE2F_4119_AF51_CC52D47F30DF__INCLUDED_)
#define AFX_TESTDLG_H__0B453A60_AE2F_4119_AF51_CC52D47F30DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog
#include "TestListBox.h"
#include "afxwin.h"
#include "ControlCAN.h"
#include "HaideProtocolDialog.h"
#include "NavigationDialog.h"
#include "CSerialPort\sigslot.h"
#include "CSerialPort\SerialPort.h"
#include "HTSlot.h"


#define SP_NUM 6
using namespace itas109;
class CInfoDialog;

class CTestDlg : public CDialog, public HTSlot
{
	// Construction
public:
	int m_cannum;
	int m_devtype;
	DWORD m_devind;
	static UINT ReceiveThread(void *param);
	void ShowInfo(CString str,int code);
	int m_connect;
	CTestDlg(CWnd* pParent = NULL);	// standard constructor
	int strtodata(unsigned char *str, unsigned char *data,int len,int flag);
	int chartoint(unsigned char chr, unsigned char *cint);
	// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_TEST_DIALOG };
	CComboBox	m_ComboMode;
	CComboBox	m_ComboFilterType;
	CComboBox	m_ComboCANInd;
	CComboBox	m_ComboIndex;
	CComboBox	m_ComboDevType;
	CTestListBox	m_ListInfo;
	CComboBox	m_ComboSendType;
	CComboBox	m_ComboSendFrmType;
	CComboBox	m_ComboSendFrmFmt;
	CString	m_EditSendData;
	CString	m_EditSendFrmID;
	CString	m_EditCode;
	CString	m_EditMask;
	CString	m_EditTiming0;
	CString	m_EditTiming1;
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	HICON m_hIcon;
	CRITICAL_SECTION m_Section;
	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnButtonConnect();
	afx_msg void OnButtonStartcan();
	afx_msg void OnButtonResetcan();
	afx_msg void OnButtonSend();
	afx_msg void OnMenuRefresh();
	afx_msg void OnSelchangeComboDevType();

	afx_msg LRESULT OnInfoDialogClose(WPARAM w, LPARAM l);
	afx_msg LRESULT OnParseFrame(WPARAM w, LPARAM l);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void test();
	afx_msg void OnBnClickedCheck1();
	CButton m_cbx_parse;
	CInfoDialog *m_info_dialog;
	HaideProtocolDialog *m_haide_protocol_dialog;
	NavigationDialog *m_navi_dialog;


	void ParseFrame(VCI_CAN_OBJ frame);
	afx_msg void OnBnClickedCheck2();
	CComboBox m_cbxBaudrate;
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedCheck3();
	CButton m_btnCOMOpen;
	CString m_strCOMPort;
	afx_msg void OnBnClickedButtonComOpen();

	//CSerialPort m_sp;
	//void OnCOMRecv();
	//void OnCOMRecvHT(int h, int t);
	afx_msg void OnBnClickedButton1();
	CComboBox m_cbxCOM;
	CSerialPort m_arraySp[SP_NUM];
	CDialog *m_arrayCOMDlg[SP_NUM];
	afx_msg void OnCbnSelchangeComboComPort();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__0B453A60_AE2F_4119_AF51_CC52D47F30DF__INCLUDED_)
