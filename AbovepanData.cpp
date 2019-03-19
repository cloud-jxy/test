#include "StdAfx.h"
#include "AbovepanData.h"
#include "resource.h"
#include "xsc\XSCScreenDialog.h"
#include "xsc\XSCControlDialog.h"
#include "xsc\XSCYuyinDialog.h"
#include "xsc\XSCFujiDialog.h"
#include "AbovepanDialog.h"


AbovepanTabItemObj g_xscTabItemObjs[] = {
	{ _T("基本信息"), new CXSCBaseDialog(), IDD_EMPTY_DIALOG }
	,{ _T("显示屏"), new CXSCScreenDialog(), IDD_EMPTY_DIALOG }
	,{ _T("控制器"), new CXSCControlDialog(), IDD_EMPTY_DIALOG }
	,{ _T("语音"), new CXSCYuyinDialog(), IDD_EMPTY_DIALOG }
	,{ _T("副机"), new CXSCFujiDialog(), IDD_EMPTY_DIALOG }
};


AbovepanTabItemObj g_xscTabItemObjs2[] = {
	{ _T("基本信息2"), new CXSCYuyinDialog(), IDD_EMPTY_DIALOG }
	,{ _T("显示屏2"), new CXSCFujiDialog(), IDD_EMPTY_DIALOG }
	,{ _T("控制器2"), new CXSCBaseDialog(), IDD_EMPTY_DIALOG }
};

AbovepanItemObj g_abovepanItemObjs[] = {
	{ _T("洗扫车"), g_xscTabItemObjs, sizeof(g_xscTabItemObjs) / sizeof(g_xscTabItemObjs[0]) }
	,{ _T("洗扫车2"), g_xscTabItemObjs2, 3 }
};


int g_abovepanItemCount = sizeof(g_abovepanItemObjs) / sizeof(g_abovepanItemObjs[0]);
