#pragma once
#include "../MyTabDialog.h"

// CXSCFujiDialog �Ի���

class CXSCFujiDialog : public CMyTabDialog
{
	DECLARE_DYNAMIC(CXSCFujiDialog)

public:
	CXSCFujiDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CXSCFujiDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XSCFUJIDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
