#pragma once
#include "ControlCAN.h"


struct WarnInfo {
	CString name;
	int byte_pos;
	int bite_pos;
	//int bite_len; //全是2bite，暂去掉
	int level;		// 0 无故障， 1-3：1-3级故障；初始默认值0
};

// TabWarnDialog 对话框

class TabWarnDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TabWarnDialog)

public:
	TabWarnDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TabWarnDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_WARN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int ParseFrame(VCI_CAN_OBJ frame);
};
