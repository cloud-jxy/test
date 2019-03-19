#pragma once
#include "StdAfx.h"
#include "./xsc/XSCBaseDialog.h"

//class CXSCBaseDialog;
struct AbovepanTabItemObj {
	CString m_name;
	CDialog *m_pDialog;
	UINT m_dlgID;
};

struct AbovepanItemObj {
	CString m_name;
	AbovepanTabItemObj *m_pObjs;
	int m_len;
};

extern AbovepanTabItemObj g_xscTabItemObjs[];


extern AbovepanTabItemObj g_xscTabItemObjs2[];

extern AbovepanItemObj g_abovepanItemObjs[];
extern int g_abovepanItemCount;
