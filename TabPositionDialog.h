#pragma once


// TabPositionDialog �Ի���

class TabPositionDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabPositionDialog)

public:
	TabPositionDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabPositionDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_POSITION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
