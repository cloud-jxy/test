#pragma once
#include "ControlCAN.h"


struct WarnInfo {
	CString name;
	int byte_pos;
	int bite_pos;
	//int bite_len; //ȫ��2bite����ȥ��
	int level;		// 0 �޹��ϣ� 1-3��1-3�����ϣ���ʼĬ��ֵ0
};

// TabWarnDialog �Ի���

class TabWarnDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabWarnDialog)

public:
	TabWarnDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TabWarnDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_WARN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int ParseFrame(VCI_CAN_OBJ frame);
};
