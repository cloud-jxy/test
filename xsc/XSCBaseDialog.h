#pragma once
#include "../MyTabDialog.h"

// CXSCBaseDialog 对话框

class CXSCBaseDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCBaseDialog)

public:
	CXSCBaseDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CXSCBaseDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSC_BASE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual int ParseFrame(VCI_CAN_OBJ);

	CString OpenOrClose(double val);
	CString XileiToString(double val);
	CString CheXingToString(double val);
};
