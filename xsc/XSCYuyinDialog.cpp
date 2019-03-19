// ./xsc/XSCYuyinDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "XSCYuyinDialog.h"
#include "afxdialogex.h"
#include "../resource.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

static StaticItemObj g_xscYuyin[] = {
	StaticItemObj(_T("发动机允许参数"), DEFAULT_VAL, _T("0x0C000003"), 0, 0, 2, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("发动机转速（低位）"), DEFAULT_VAL, _T("0x0C000003"), 1, 0, 8, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("发动机转速（高位）"), DEFAULT_VAL, _T("0x0C000003"), 2, 0, 8, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("发动机转速"), DEFAULT_VAL, _T("0x0CF00400"), 4, 0, 16, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("水温"), DEFAULT_VAL, _T("0x18FEEE00"), 0, 0, 8, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("机油温度"), DEFAULT_VAL, _T("0x18FEEE00"), 2, 0, 16, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("机油压力"), DEFAULT_VAL, _T("0x18FEEF00"), 3, 0, 8, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("预热灯状态"), DEFAULT_VAL, _T("0x18FEE400"), 3, 0, 2, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("机油压力信号"), DEFAULT_VAL, _T("0x18FE6800"), 3, 2, 2, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("倒车请注意"), DEFAULT_VAL, _T("0x1911FF14"), 0, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("车辆转弯，请注意安全"), DEFAULT_VAL, _T("0x1911FF14"), 0, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("电池电量不足15%，即将结束清扫作业"), DEFAULT_VAL, _T("0x1911FF14"), 0, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("电池电量不足20%，请注意"), DEFAULT_VAL, _T("0x1911FF14"), 0, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("电池故障，请检修"), DEFAULT_VAL, _T("0x1911FF14"), 0, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("风机故障，请检修"), DEFAULT_VAL, _T("0x1911FF14"), 0, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("行走控制器故障，请检修"), DEFAULT_VAL, _T("0x1911FF14"), 0, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("气压不足"), DEFAULT_VAL, _T("0x1911FF14"), 0, 7, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("安全支架未放下，箱体不能下降"), DEFAULT_VAL, _T("0x1911FF14"), 1, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("后门未开启，请不要举升箱体"), DEFAULT_VAL, _T("0x1911FF14"), 1, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("箱体上升，请注意安全"), DEFAULT_VAL, _T("0x1911FF14"), 1, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("箱体下降，请注意安全"), DEFAULT_VAL, _T("0x1911FF14"), 1, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("后门开启，请注意安全"), DEFAULT_VAL, _T("0x1911FF14"), 1, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("后门关闭，请注意安全"), DEFAULT_VAL, _T("0x1911FF14"), 1, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("副发动机水温过高，请立即停机检查"), DEFAULT_VAL, _T("0x1911FF14"), 2, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("副发动机冷却液位低，请立即停机检查"), DEFAULT_VAL, _T("0x1911FF14"), 2, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("副发动机机油压力故障，请立即停机检查"), DEFAULT_VAL, _T("0x1911FF14"), 2, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("副发动机发电故障，请立即停机检查"), DEFAULT_VAL, _T("0x1911FF14"), 2, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("副发动机超速，请降低转速"), DEFAULT_VAL, _T("0x1911FF14"), 2, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("副发动机启动完成"), DEFAULT_VAL, _T("0x1911FF14"), 2, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("副发动机启动保护中，请等待"), DEFAULT_VAL, _T("0x1911FF14"), 2, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("加水盖已开启，请及时关闭"), DEFAULT_VAL, _T("0x1911FF14"), 3, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("液压油出油闸阀关闭，副机不能启动"), DEFAULT_VAL, _T("0x1911FF14"), 3, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("液压油温过高，请立即停机检查"), DEFAULT_VAL, _T("0x1911FF14"), 3, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("液压系统泄露，请立即停机检查"), DEFAULT_VAL, _T("0x1911FF14"), 3, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("水路闸阀关闭，高压水泵不能启动"), DEFAULT_VAL, _T("0x1911FF14"), 3, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("清水箱水位低，请加水"), DEFAULT_VAL, _T("0x1911FF14"), 3, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("水箱水位过低，不能清洗作业"), DEFAULT_VAL, _T("0x1911FF14"), 3, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("污水箱已满，请停止作业"), DEFAULT_VAL, _T("0x1911FF14"), 3, 7, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("作业中，请您避让"), DEFAULT_VAL, _T("0x1911FF14"), 4, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("垃圾桶上升，请注意"), DEFAULT_VAL, _T("0x1911FF14"), 4, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("垃圾桶下降，请注意"), DEFAULT_VAL, _T("0x1911FF14"), 4, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("垃圾桶倒，请注意"), DEFAULT_VAL, _T("0x1911FF14"), 4, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("垃圾桶回，请注意"), DEFAULT_VAL, _T("0x1911FF14"), 4, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("充电插座指示报警，请检查"), DEFAULT_VAL, _T("0x1911FF14"), 4, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("垃圾箱满，请注意"), DEFAULT_VAL, _T("0x1911FF14"), 4, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("天路"), DEFAULT_VAL, _T("0x1911FF14"), 6, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("北京的金山上"), DEFAULT_VAL, _T("0x1911FF14"), 6, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("我们新疆好地方"), DEFAULT_VAL, _T("0x1911FF14"), 6, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("生日快乐"), DEFAULT_VAL, _T("0x1911FF14"), 6, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("洪湖水浪打浪"), DEFAULT_VAL, _T("0x1911FF14"), 6, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("浏阳河"), DEFAULT_VAL, _T("0x1911FF14"), 6, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("梦里水乡"), DEFAULT_VAL, _T("0x1911FF14"), 6, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("水边的阿狄丽娜"), DEFAULT_VAL, _T("0x1911FF14"), 6, 7, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("太阳最红，毛主席最亲"), DEFAULT_VAL, _T("0x1911FF14"), 7, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("鼓浪屿之歌"), DEFAULT_VAL, _T("0x1911FF14"), 7, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("最美长白山"), DEFAULT_VAL, _T("0x1911FF14"), 7, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("循环播放"), DEFAULT_VAL, _T("0x1911FF14"), 7, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("音量减半"), DEFAULT_VAL, _T("0x1911FF14"), 7, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("播放指定歌曲使能"), DEFAULT_VAL, _T("0x1911FF14"), 7, 7, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose))
};

// CXSCYuyinDialog 对话框

IMPLEMENT_DYNAMIC(CXSCYuyinDialog, CMyTabDialog)

CXSCYuyinDialog::CXSCYuyinDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscYuyin;
	m_objCount = sizeof(g_xscYuyin) / sizeof(g_xscYuyin[0]);
	m_leftW = 250;
	m_rightW = 60;
}

CXSCYuyinDialog::~CXSCYuyinDialog()
{
}

void CXSCYuyinDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCYuyinDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCYuyinDialog 消息处理程序
