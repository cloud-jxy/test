#pragma once
#include "../MyTabDialog.h"

// CXSCYuyinDialog �Ի���

class CXSCYuyinDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCYuyinDialog)

public:
	CXSCYuyinDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CXSCYuyinDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSC_CONTROL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
