#pragma once


// TabCarDialog �Ի���

class TabCarDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabCarDialog)

public:
	TabCarDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabCarDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_CAR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
