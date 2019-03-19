#include "StdAfx.h"
#include "AbovepanData.h"
#include "resource.h"
#include "xsc\XSCScreenDialog.h"
#include "xsc\XSCControlDialog.h"
#include "xsc\XSCYuyinDialog.h"
#include "xsc\XSCFujiDialog.h"
#include "AbovepanDialog.h"


AbovepanTabItemObj g_xscTabItemObjs[] = {
	{ _T("������Ϣ"), new CXSCBaseDialog(), IDD_EMPTY_DIALOG }
	,{ _T("��ʾ��"), new CXSCScreenDialog(), IDD_EMPTY_DIALOG }
	,{ _T("������"), new CXSCControlDialog(), IDD_EMPTY_DIALOG }
	,{ _T("����"), new CXSCYuyinDialog(), IDD_EMPTY_DIALOG }
	,{ _T("����"), new CXSCFujiDialog(), IDD_EMPTY_DIALOG }
};


AbovepanTabItemObj g_xscTabItemObjs2[] = {
	{ _T("������Ϣ2"), new CXSCYuyinDialog(), IDD_EMPTY_DIALOG }
	,{ _T("��ʾ��2"), new CXSCFujiDialog(), IDD_EMPTY_DIALOG }
	,{ _T("������2"), new CXSCBaseDialog(), IDD_EMPTY_DIALOG }
};

AbovepanItemObj g_abovepanItemObjs[] = {
	{ _T("ϴɨ��"), g_xscTabItemObjs, sizeof(g_xscTabItemObjs) / sizeof(g_xscTabItemObjs[0]) }
	,{ _T("ϴɨ��2"), g_xscTabItemObjs2, 3 }
};


int g_abovepanItemCount = sizeof(g_abovepanItemObjs) / sizeof(g_abovepanItemObjs[0]);
