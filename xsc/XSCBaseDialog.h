#pragma once
#include "../MyTabDialog.h"

// CXSCBaseDialog �Ի���

class CXSCBaseDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCBaseDialog)

public:
	CXSCBaseDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CXSCBaseDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSC_BASE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
