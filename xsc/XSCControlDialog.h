#pragma once
#include "../MyTabDialog.h"

// CXSCControlDialog �Ի���

class CXSCControlDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCControlDialog)

public:
	CXSCControlDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CXSCControlDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSC_SCREEN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
