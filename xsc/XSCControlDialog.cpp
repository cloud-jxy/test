// ./xsc/XSCControlDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "XSCControlDialog.h"
#include "afxdialogex.h"
#include "../resource.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

StaticItemObj g_xscControl[] = {
	StaticItemObj(_T("后操作盒箱内冲水"), DEFAULT_VAL, _T("0x18F40200"), 0, 0, 1),
	StaticItemObj(_T("后操作盒洗车泵"), DEFAULT_VAL, _T("0x18F40200"), 0, 1, 1),
	StaticItemObj(_T("后操作盒箱体升"), DEFAULT_VAL, _T("0x18F40200"), 0, 2, 1),
	StaticItemObj(_T("后操作盒箱体降"), DEFAULT_VAL, _T("0x18F40200"), 0, 3, 1),
	StaticItemObj(_T("后操作盒后门开"), DEFAULT_VAL, _T("0x18F40200"), 0, 4, 1),
	StaticItemObj(_T("后操作盒后门关"), DEFAULT_VAL, _T("0x18F40200"), 0, 5, 1),
	StaticItemObj(_T("左边安全支架限位"), DEFAULT_VAL, _T("0x18F40200"), 0, 6, 1),
	StaticItemObj(_T("右安全支架限位"), DEFAULT_VAL, _T("0x18F40200"), 0, 7, 1),
	StaticItemObj(_T("水路开关"), DEFAULT_VAL, _T("0x18F40200"), 1, 0, 1),
	StaticItemObj(_T("液压油开关"), DEFAULT_VAL, _T("0x18F40200"), 1, 1, 1),
	StaticItemObj(_T("清水缺水报警"), DEFAULT_VAL, _T("0x18F40200"), 1, 2, 1),
	StaticItemObj(_T("水泵停机浮子"), DEFAULT_VAL, _T("0x18F40200"), 1, 3, 1),
	StaticItemObj(_T("污水箱满"), DEFAULT_VAL, _T("0x18F40200"), 1, 4, 1),
	StaticItemObj(_T("液压油位"), DEFAULT_VAL, _T("0x18F40200"), 1, 5, 1),
	StaticItemObj(_T("油温过高"), DEFAULT_VAL, _T("0x18F40200"), 1, 6, 1),
	StaticItemObj(_T("气压检测"), DEFAULT_VAL, _T("0x18F40200"), 1, 7, 1),
	StaticItemObj(_T("箱体升限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 0, 1),
	StaticItemObj(_T("箱体降限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 1, 1),
	StaticItemObj(_T("吸口收限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 2, 1),
	StaticItemObj(_T("吸口降限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 3, 1),
	StaticItemObj(_T("后门开限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 4, 1),
	StaticItemObj(_T("后门关限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 5, 1),
	StaticItemObj(_T("卸荷"), DEFAULT_VAL, _T("0x18F40201"), 0, 0, 1),
	StaticItemObj(_T("箱体升阀"), DEFAULT_VAL, _T("0x18F40202"), 0, 1, 1),
	StaticItemObj(_T("箱体降阀"), DEFAULT_VAL, _T("0x18F40203"), 0, 2, 1),
	StaticItemObj(_T("后门开阀"), DEFAULT_VAL, _T("0x18F40204"), 0, 3, 1),
	StaticItemObj(_T("后门关阀"), DEFAULT_VAL, _T("0x18F40205"), 0, 4, 1),
	StaticItemObj(_T("前左扫盘升阀"), DEFAULT_VAL, _T("0x18F40206"), 0, 5, 1),
	StaticItemObj(_T("前左扫盘降阀"), DEFAULT_VAL, _T("0x18F40207"), 0, 6, 1),
	StaticItemObj(_T("前右扫盘升阀"), DEFAULT_VAL, _T("0x18F40208"), 0, 7, 1),
	StaticItemObj(_T("前右扫盘降阀"), DEFAULT_VAL, _T("0x18F40209"), 1, 0, 1),
	StaticItemObj(_T("后刷升阀"), DEFAULT_VAL, _T("0x18F40210"), 1, 1, 1),
	StaticItemObj(_T("后刷降阀"), DEFAULT_VAL, _T("0x18F40211"), 1, 2, 1),
	StaticItemObj(_T("吸口升阀"), DEFAULT_VAL, _T("0x18F40212"), 1, 3, 1),
	StaticItemObj(_T("吸口降阀"), DEFAULT_VAL, _T("0x18F40213"), 1, 4, 1),
	StaticItemObj(_T("前左扫盘转阀"), DEFAULT_VAL, _T("0x18F40214"), 1, 5, 1),
	StaticItemObj(_T("前右扫盘转阀"), DEFAULT_VAL, _T("0x18F40215"), 1, 6, 1),
	StaticItemObj(_T("后刷转阀"), DEFAULT_VAL, _T("0x18F40216"), 1, 7, 1),
	StaticItemObj(_T("左喷水架伸"), DEFAULT_VAL, _T("0x18F40217"), 2, 0, 1),
	StaticItemObj(_T("左喷水架缩"), DEFAULT_VAL, _T("0x18F40218"), 2, 1, 1),
	StaticItemObj(_T("右喷水架伸"), DEFAULT_VAL, _T("0x18F40219"), 2, 2, 1),
	StaticItemObj(_T("右喷水架缩"), DEFAULT_VAL, _T("0x18F40220"), 2, 3, 1),
	StaticItemObj(_T("左冲水阀"), DEFAULT_VAL, _T("0x18F40221"), 2, 4, 1),
	StaticItemObj(_T("右冲水阀"), DEFAULT_VAL, _T("0x18F40222"), 2, 5, 1),
	StaticItemObj(_T("吸口冲水"), DEFAULT_VAL, _T("0x18F40223"), 2, 6, 1),
	StaticItemObj(_T("箱内冲水"), DEFAULT_VAL, _T("0x18F40224"), 2, 7, 1),
	StaticItemObj(_T("后喷雾"), DEFAULT_VAL, _T("0x18F40225"), 3, 0, 1),
	StaticItemObj(_T("上盖开阀"), DEFAULT_VAL, _T("0x18F40226"), 3, 1, 1),
	StaticItemObj(_T("高压水泵"), DEFAULT_VAL, _T("0x18F40227"), 3, 2, 1),
	StaticItemObj(_T("底盘取力器"), DEFAULT_VAL, _T("0x18F40228"), 3, 3, 1),
	StaticItemObj(_T("气路卸荷阀"), DEFAULT_VAL, _T("0x18F40229"), 3, 4, 1),
	StaticItemObj(_T("左低压冲水阀"), DEFAULT_VAL, _T("0x18F40230"), 3, 5, 1),
	StaticItemObj(_T("右低压冲水阀"), DEFAULT_VAL, _T("0x18F40231"), 3, 6, 1),
	StaticItemObj(_T("低压洒水阀"), DEFAULT_VAL, _T("0x18F40232"), 3, 7, 1),
	StaticItemObj(_T("总气阀"), DEFAULT_VAL, _T("0x18F40233"), 4, 0, 1),
	StaticItemObj(_T("油水转换"), DEFAULT_VAL, _T("0x18F40234"), 4, 1, 1),
	StaticItemObj(_T("挡链"), DEFAULT_VAL, _T("0x18F40235"), 4, 2, 1),
	StaticItemObj(_T("低压水泵"), DEFAULT_VAL, _T("0x18F40236"), 4, 3, 1),
	StaticItemObj(_T("风机离合"), DEFAULT_VAL, _T("0x18F40237"), 4, 4, 1),
	StaticItemObj(_T("启动继电器"), DEFAULT_VAL, _T("0x18F40238"), 4, 5, 1),
	StaticItemObj(_T("电动水泵"), DEFAULT_VAL, _T("0x18F40239"), 4, 6, 1),
	StaticItemObj(_T("调速线圈"), DEFAULT_VAL, _T("0x18F40240"), 4, 7, 1),
	StaticItemObj(_T("挡板"), DEFAULT_VAL, _T("0x18F40241"), 5, 0, 1),
	StaticItemObj(_T("箭头灯"), DEFAULT_VAL, _T("0x18F40242"), 5, 1, 1),
	StaticItemObj(_T("警灯"), DEFAULT_VAL, _T("0x18F40243"), 5, 2, 1),
	StaticItemObj(_T("熄火电磁阀"), DEFAULT_VAL, _T("0x18F40244"), 5, 3, 1)
};

// CXSCControlDialog 对话框

IMPLEMENT_DYNAMIC(CXSCControlDialog, CMyTabDialog)

CXSCControlDialog::CXSCControlDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscControl;
	m_objCount = sizeof(g_xscControl) / sizeof(g_xscControl[0]);
	m_leftW = 175;
	m_rightW = 100;
}

CXSCControlDialog::~CXSCControlDialog()
{
}

void CXSCControlDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCControlDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCControlDialog 消息处理程序
