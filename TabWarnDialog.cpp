// TabWarnDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "TabWarnDialog.h"
#include "afxdialogex.h"


WarnInfo warns[] = {
	{ _T("温度差异报警"), 0, 0, 0 }
	,{ _T("电池高温报警"), 0, 2, 0 }
	,{ _T("车载储能装置类型过压报警"), 0, 4, 0 }
	,{ _T("车载储能装置类型欠压报警"), 0, 6, 0 }

	,{ _T("SOC低报警"), 1, 0, 0 }
	,{ _T("单体电池过压报警"), 1, 2, 0 }
	,{ _T("单体电池欠压报警"), 1, 4, 0 }
	,{ _T("SOC过高报警"), 1, 6, 0 }

	,{ _T("SOC跳变报警"), 2, 0, 0 }
	,{ _T("可充电储能设别不匹配报警"), 2, 2, 0 }
	,{ _T("电池单体一致性报警"), 2, 4, 0 }
	,{ _T("绝缘报警"), 2, 6, 0 }

	,{ _T("DC-DC温度报警"), 3, 0, 0 }
	,{ _T("制动系统报警"), 3, 2, 0 }
	,{ _T("驱动电机控制器温度报警"), 3, 4, 0 }
	,{ _T("高压互锁状态报警"), 7, 6, 0 }

	,{ _T("驱动电机温度报警"), 3, 6, 0 }
	,{ _T("驱动电机温度报警"), 5, 6, 0 }
	,{ _T("车载储能装置装置类型过充"), 4, 0, 0 }
};


// TabWarnDialog 对话框

IMPLEMENT_DYNAMIC(TabWarnDialog, CDialogEx)

TabWarnDialog::TabWarnDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_WARN_DIALOG, pParent)
{

}

TabWarnDialog::~TabWarnDialog()
{
}

void TabWarnDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabWarnDialog, CDialogEx)
END_MESSAGE_MAP()


// TabWarnDialog 消息处理程序


BOOL TabWarnDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

int TabWarnDialog::ParseFrame(VCI_CAN_OBJ frame) {
	BYTE *data = frame.Data;
	int i = 0;
	int len = sizeof(warns) / sizeof(warns[0]);

	if (frame.ID != 0x182C7A70) {
		return 0;
	}

	for (i = 0; i < len; i++) {
		warns[i].level = (data[warns[i].byte_pos] >> warns[i].bite_pos) & 0x03;
	}

	return 0;
}
