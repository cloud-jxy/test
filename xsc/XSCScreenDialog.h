#pragma once
#include "../MyTabDialog.h"

// CXSCScreenDialog �Ի���

class CXSCScreenDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCScreenDialog)

public:
	CXSCScreenDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CXSCScreenDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSCSCREENDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
