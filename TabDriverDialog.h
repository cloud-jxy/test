#pragma once


// TabDriverDialog �Ի���

class TabDriverDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabDriverDialog)

public:
	TabDriverDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabDriverDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DRIVER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
