#pragma once


// TabExtremumDialog �Ի���

class TabExtremumDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabExtremumDialog)

public:
	TabExtremumDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabExtremumDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_EXTREMUM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
