#pragma once
#include "afxcmn.h"
#include "FrameRuleDialog.h"
#include "ControlCAN.h"
#include "CApplication.h"
#include "CWorkbooks.h"
#include "CWorkbook.h"
#include "CWorksheets.h"
#include "CWorksheet.h"
#include "CRange.h"
#include "Cnterior.h"


class CTestDlg;

// HaideProtocolDialog �Ի���

class HaideProtocolDialog : public CDialogEx
{
	DECLARE_DYNAMIC(HaideProtocolDialog)

public:
	HaideProtocolDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HaideProtocolDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HAIDE_PROTOCOL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CTestDlg *m_p_parent_dlg;
	afx_msg void OnClose();
	CListCtrl m_ctrl_list;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonEdit();
	int GetCurListItem();
	afx_msg void OnBnClickedButtonClear();
	int ParseFrame(VCI_CAN_OBJ obj);
	afx_msg void OnBnClickedButtonImport();
	afx_msg void OnBnClickedButtonExport();

	void ReadExcelRow(int i, CRange range);

	CStringArray *m_groups;	//��¼���еĴ����������
	CString m_curGroup;		//��¼��ǰ�Ĵ����������

	BOOL IsGroupHeaderRow(int row, CRange range);
	BOOL IsMergeCell(CRange cell);
	void ReadRuleRow(int row, CRange range);
	CString GetExcelText(int row, int col, CRange range); // col��1��
	CString GetExcelText(CRange cell);
	double GetExcelVal(int row, int col, CRange range);
	void AddToListCtrl(FrameRuleObj *obj);

	CApplication m_app;
	virtual BOOL DestroyWindow();
};
