// XSCBaseDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "../test.h"
#include "XSCBaseDialog.h"
#include "afxdialogex.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

//typedef int (*PtrFuncToString)(double);

static StaticItemObj g_xscBase[] = {
	StaticItemObj(_T("型号"), DEFAULT_VAL, _T("0x18f40001"), 0, 0, 128, NULL),
	StaticItemObj(_T("系列"), DEFAULT_VAL, _T("0x18f40000"), 0, 0, 2, (PtrFuncToString)(&CXSCBaseDialog::XileiToString)),
	StaticItemObj(_T("车型"), DEFAULT_VAL, _T("0x18f40000"), 0, 2, 6, (PtrFuncToString)(&CXSCBaseDialog::CheXingToString)),
	StaticItemObj(_T("底盘"), DEFAULT_VAL, _T("0x18f40000"), 2, 0, 8, (PtrFuncToString)(&CXSCBaseDialog::DipanToString)),
	StaticItemObj(_T("副发动机"), DEFAULT_VAL, _T("0x18f40000"), 3, 0, 8, (PtrFuncToString)(&CXSCBaseDialog::FujiToString)),
	StaticItemObj(_T("显示屏"), DEFAULT_VAL, _T("0x18f40000"), 4, 0, 4, (PtrFuncToString)(&CXSCBaseDialog::ScreenToString)),
	StaticItemObj(_T("控制器"), DEFAULT_VAL, _T("0x18f40000"), 4, 4, 4, (PtrFuncToString)(&CXSCBaseDialog::ControlToString)),
	StaticItemObj(_T("模块1"), DEFAULT_VAL, _T("0x18f40000"), 5, 0, 4, (PtrFuncToString)(&CXSCBaseDialog::Module1ToString)),
	StaticItemObj(_T("模块2"), DEFAULT_VAL, _T("0x18f40000"), 5, 4, 4, (PtrFuncToString)(&CXSCBaseDialog::Module2ToString)),
	StaticItemObj(_T("语音报警器"), DEFAULT_VAL, _T("0x18f40000"), 6, 0, 4, (PtrFuncToString)(&CXSCBaseDialog::YuyinToString)),
	StaticItemObj(_T("遥控"), DEFAULT_VAL, _T("0x18f40000"), 6, 4, 4, (PtrFuncToString)(&CXSCBaseDialog::YaokongToString)),
	StaticItemObj(_T("电机"), DEFAULT_VAL, _T("0x18f40000"), 7, 0, 8, (PtrFuncToString)(&CXSCBaseDialog::DianjiToString)),
	StaticItemObj(_T("显示屏程序版本号"), DEFAULT_VAL, _T("0x18f40003"), 0, 0, 16, (PtrFuncToString)(&CXSCBaseDialog::ValueToString)),
	StaticItemObj(_T("控制器程序版本号"), DEFAULT_VAL, _T("0x18f40003"), 2, 0, 16, (PtrFuncToString)(&CXSCBaseDialog::ValueToString)),
	StaticItemObj(_T("显示屏与控制器通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 0, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("显示屏与模块1通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 1, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("显示屏与模块2通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 2, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("显示屏与语音通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 3, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("显示屏与遥控通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 4, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("显示屏与副发动机通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 5, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("显示屏与车载终端通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 6, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("显示屏与底盘通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 4, 7, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("控制器与模块1通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 0, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("控制器与模块2通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 1, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("控制器与语音通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 2, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("控制器与遥控通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 3, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("控制器与副发动机通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 4, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("控制器与车载终端通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 5, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("控制器与底盘通讯状态"), DEFAULT_VAL, _T("0x18f40003"), 5, 6, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
};


// CXSCBaseDialog 对话框

IMPLEMENT_DYNAMIC(CXSCBaseDialog, CMyTabDialog)

CXSCBaseDialog::CXSCBaseDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscBase;
	m_objCount = sizeof(g_xscBase) / sizeof(g_xscBase[0]);
	m_leftW = 175;
	m_rightW = 120;
}

CXSCBaseDialog::~CXSCBaseDialog()
{
}

void CXSCBaseDialog::DoDataExchange(CDataExchange* pDX)
{
	CMyTabDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCBaseDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCBaseDialog 消息处理程序


BOOL CXSCBaseDialog::OnInitDialog()
{
	CMyTabDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


CString CXSCBaseDialog::OpenOrClose(double val) {
	if (val == 0) {
		return _T("关闭");
	}
	else if (val == 1) {
		return _T("开启");
	}
	else {
		return _T("数据异常");
	}
}


CString CXSCBaseDialog::XileiToString(double val) {
	CString alls[] = { _T("燃油系列"), _T("纯电动"), _T("天然气系列"), _T("预留") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}


CString CXSCBaseDialog::CheXingToString(double val) {
	//垃圾桶清洗车；4.自装卸式垃圾车；5.吸尘车；6.高压清洗车；7.低压清洗车；8.餐厨车；9.车厢可卸式垃圾车；10.路面养护；11.多功能抑尘车；12.扫路机；
	CString alls[] = {
		_T("无"), _T("扫路车"), _T("洗扫车"), _T("垃圾桶清洗车"),
		_T("吸尘车"), _T("高压清洗车"), _T("低压清洗车") ,_T("餐厨车"),
		_T("车厢可卸式垃圾车"), _T("路面养护"), _T("多功能抑尘车"), _T("扫路机")
	};

	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}


int CXSCBaseDialog::ParseFrame(VCI_CAN_OBJ frame) {
	TRACE("CXSCBaseDialog::ParseFrame\n");
	CMyTabDialog::ParseFrame(frame);
	BOOL isDebug;

#ifdef DEBUG
	isDebug = TRUE;
#else
	isDebug = FALSE;
#endif

	if (frame.ID == 0x18f40001) {
		memcpy(m_szXinghao, frame.Data, 8);
		CString tmp;
		tmp.Format(_T("%s"), m_szXinghao);
		CStaticItem *item = (CStaticItem *)g_xscBase[0].m_pParam;
		item->m_ctrlValue.SetWindowText(tmp);
	}
	else if (frame.ID == 0x18f4002) {
		memcpy(m_szXinghao + 8, frame.Data, 8);
		CString tmp;
		tmp.Format(_T("%s"), m_szXinghao);
		CStaticItem *item = (CStaticItem *)g_xscBase[0].m_pParam;
		item->m_ctrlValue.SetWindowText(tmp);
	}

	return 0;
}

// 0：无；1.东风；2.重汽；3.一汽；5.江淮；
CString CXSCBaseDialog::DipanToString(double val) {
	CString alls[] = {_T("无"), _T("东风"), _T("重汽"), _T("一汽"), _T("江淮")};
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	} else {
		return alls[(int)val];
	}
}

// 0~255；0：无；1：江铃；2：庆铃；3：玉柴；4：康明斯
CString CXSCBaseDialog::FujiToString(double val) {
	CString alls[] = { _T("无"), _T("江铃"), _T("庆铃"), _T("玉柴"), _T("康明斯") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15；0:无；1：嘉诚；2：华兴；3:硕博；4：尤百利；5：森鹏
CString CXSCBaseDialog::ScreenToString(double val) {
	CString alls[] = { _T("无"), _T("嘉诚"), _T("华兴"), _T("硕博"), _T("尤百利"), _T("森鹏") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15；0:无；1：嘉诚；2：华兴；3:硕博；4：尤百利；5：森鹏
CString CXSCBaseDialog::ControlToString(double val) {
	CString alls[] = { _T("无"), _T("嘉诚"), _T("华兴"), _T("硕博"), _T("尤百利"), _T("森鹏") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15；0:无；1：嘉诚；2：华兴；3:硕博；4：尤百利；5：森鹏
CString CXSCBaseDialog::Module1ToString(double val) {
	CString alls[] = { _T("无"), _T("嘉诚"), _T("华兴"), _T("硕博"), _T("尤百利"), _T("森鹏") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15；0:无；1：嘉诚；2：华兴；3:硕博；4：尤百利；5：森鹏
CString CXSCBaseDialog::Module2ToString(double val) {
	CString alls[] = { _T("无"), _T("嘉诚"), _T("华兴"), _T("硕博"), _T("尤百利"), _T("森鹏") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15；0:无；1：嘉诚；2：华兴；3:硕博；4：尤百利；5：森鹏
CString CXSCBaseDialog::YuyinToString(double val) {
	CString alls[] = { _T("无"), _T("嘉诚"), _T("华兴"), _T("硕博"), _T("尤百利"), _T("森鹏") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15；0:无；1：嘉诚；2：华兴；3:硕博；4：尤百利；5：森鹏
CString CXSCBaseDialog::YaokongToString(double val) {
	CString alls[] = { _T("无"), _T("嘉诚"), _T("华兴"), _T("硕博"), _T("尤百利"), _T("森鹏") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15；0:无；1：嘉诚；2：华兴；3:硕博；4：尤百利；5：森鹏
CString CXSCBaseDialog::DianjiToString(double val) {
	CString alls[] = { _T("无"), _T("嘉诚"), _T("华兴"), _T("硕博"), _T("尤百利"), _T("森鹏") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("数据异常");
	}
	else {
		return alls[(int)val];
	}
}
