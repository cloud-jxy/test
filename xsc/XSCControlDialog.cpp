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

	StaticItemObj(_T("后操作盒箱内冲水"), DEFAULT_VAL, _T("0x18F40200"), 0, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后操作盒洗车泵"), DEFAULT_VAL, _T("0x18F40200"), 0, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后操作盒箱体升"), DEFAULT_VAL, _T("0x18F40200"), 0, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后操作盒箱体降"), DEFAULT_VAL, _T("0x18F40200"), 0, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后操作盒后门开"), DEFAULT_VAL, _T("0x18F40200"), 0, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后操作盒后门关"), DEFAULT_VAL, _T("0x18F40200"), 0, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("左边安全支架限位"), DEFAULT_VAL, _T("0x18F40200"), 0, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("右安全支架限位"), DEFAULT_VAL, _T("0x18F40200"), 0, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("水路开关"), DEFAULT_VAL, _T("0x18F40200"), 1, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("液压油开关"), DEFAULT_VAL, _T("0x18F40200"), 1, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("清水缺水报警"), DEFAULT_VAL, _T("0x18F40200"), 1, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("水泵停机浮子"), DEFAULT_VAL, _T("0x18F40200"), 1, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("污水箱满"), DEFAULT_VAL, _T("0x18F40200"), 1, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("液压油位"), DEFAULT_VAL, _T("0x18F40200"), 1, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("油温过高"), DEFAULT_VAL, _T("0x18F40200"), 1, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("气压检测"), DEFAULT_VAL, _T("0x18F40200"), 1, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("箱体升限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("箱体降限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("吸口收限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("吸口降限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后门开限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后门关限位"), DEFAULT_VAL, _T("0x18F40200"), 2, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("卸荷"), DEFAULT_VAL, _T("0x18F40201"), 0, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("箱体升阀"), DEFAULT_VAL, _T("0x18F40201"), 0, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("箱体降阀"), DEFAULT_VAL, _T("0x18F40201"), 0, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后门开阀"), DEFAULT_VAL, _T("0x18F40201"), 0, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后门关阀"), DEFAULT_VAL, _T("0x18F40201"), 0, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("前左扫盘升阀"), DEFAULT_VAL, _T("0x18F40201"), 0, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("前左扫盘降阀"), DEFAULT_VAL, _T("0x18F40201"), 0, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("前右扫盘升阀"), DEFAULT_VAL, _T("0x18F40201"), 0, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("前右扫盘降阀"), DEFAULT_VAL, _T("0x18F40201"), 1, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后刷升阀"), DEFAULT_VAL, _T("0x18F40201"), 1, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后刷降阀"), DEFAULT_VAL, _T("0x18F40201"), 1, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("吸口升阀"), DEFAULT_VAL, _T("0x18F40201"), 1, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("吸口降阀"), DEFAULT_VAL, _T("0x18F40201"), 1, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("前左扫盘转阀"), DEFAULT_VAL, _T("0x18F40201"), 1, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("前右扫盘转阀"), DEFAULT_VAL, _T("0x18F40201"), 1, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后刷转阀"), DEFAULT_VAL, _T("0x18F40201"), 1, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("左喷水架伸"), DEFAULT_VAL, _T("0x18F40201"), 2, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("左喷水架缩"), DEFAULT_VAL, _T("0x18F40201"), 2, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("右喷水架伸"), DEFAULT_VAL, _T("0x18F40201"), 2, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("右喷水架缩"), DEFAULT_VAL, _T("0x18F40201"), 2, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("左冲水阀"), DEFAULT_VAL, _T("0x18F40201"), 2, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("右冲水阀"), DEFAULT_VAL, _T("0x18F40201"), 2, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("吸口冲水"), DEFAULT_VAL, _T("0x18F40201"), 2, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("箱内冲水"), DEFAULT_VAL, _T("0x18F40201"), 2, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("后喷雾"), DEFAULT_VAL, _T("0x18F40201"), 3, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("上盖开阀"), DEFAULT_VAL, _T("0x18F40201"), 3, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("高压水泵"), DEFAULT_VAL, _T("0x18F40201"), 3, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("底盘取力器"), DEFAULT_VAL, _T("0x18F40201"), 3, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("气路卸荷阀"), DEFAULT_VAL, _T("0x18F40201"), 3, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("左低压冲水阀"), DEFAULT_VAL, _T("0x18F40201"), 3, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("右低压冲水阀"), DEFAULT_VAL, _T("0x18F40201"), 3, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("低压洒水阀"), DEFAULT_VAL, _T("0x18F40201"), 3, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("总气阀"), DEFAULT_VAL, _T("0x18F40201"), 4, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("油水转换"), DEFAULT_VAL, _T("0x18F40201"), 4, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("挡链"), DEFAULT_VAL, _T("0x18F40201"), 4, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("低压水泵"), DEFAULT_VAL, _T("0x18F40201"), 4, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("风机离合"), DEFAULT_VAL, _T("0x18F40201"), 4, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("启动继电器"), DEFAULT_VAL, _T("0x18F40201"), 4, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("电动水泵"), DEFAULT_VAL, _T("0x18F40201"), 4, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("调速线圈"), DEFAULT_VAL, _T("0x18F40201"), 4, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("挡板"), DEFAULT_VAL, _T("0x18F40201"), 5, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("箭头灯"), DEFAULT_VAL, _T("0x18F40201"), 5, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("警灯"), DEFAULT_VAL, _T("0x18F40201"), 5, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("熄火电磁阀"), DEFAULT_VAL, _T("0x18F40201"), 5, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose))
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

void CXSCControlDialog::SetCtrlRect() {
	// 0-21是输入，之后是输出

	CRect rect, rtKey, rtValue;
	GetWindowRect(&rect);
	ScreenToClient(&rect);

	//去除margin
	int marginT = 10, marginB = 10, marginL = 5, marginR = 5;
	rect.top += marginT;
	rect.bottom -= marginB;
	rect.left += marginL;
	rect.right -= marginR;

	int leftW = m_leftW;
	int rightW = m_rightW;
	int h = 20;

	int i = 0;
	StaticItemObj *pObjs = m_objs;

	int col = 0;
	int row = 0;
	int colCount = GetcolCount();
	if (colCount == 0) colCount = 1;
	i = 0;

	StaticItemObj* pObj = &pObjs[0];
	for (i = 0; i < m_objCount; i++) {
		pObj = &pObjs[i];

		if (col >= colCount) {
			col = col % colCount;
			row++;
		}

		if (i == 22) {
			if (col != 0) {
				col = 0; row += 2;
			}
			else {
				row += 1;
			}
		}

		rtKey.top = rect.top + row * h;
		rtKey.bottom = rtKey.top + h;
		rtKey.left = rect.left + col * (leftW + rightW);
		rtKey.right = rtKey.left + leftW;

		rtValue.top = rtKey.top;
		rtValue.bottom = rtKey.bottom;
		rtValue.left = rtKey.right;
		rtValue.right = rtValue.left + rightW;

		CStaticItem *item = (CStaticItem *)pObj->m_pParam;
		if (item == NULL) {
			item = new CStaticItem();
			pObj->m_pParam = item;
			item->Create(this, pObj, rtKey, rtValue);
		}
		else {
			if (item->m_ctrlKey.m_hWnd == NULL || item->m_ctrlValue.m_hWnd == NULL) item->Create(this, pObj, rtKey, rtValue);

			item->m_ctrlKey.MoveWindow(rtKey);
			item->m_ctrlValue.MoveWindow(rtValue);
		}

		col++;
	}

	// 重新计算dialog rect
	rect.bottom = rect.top + (row + 1) * h;
	rect.right = rect.left + 2 * (leftW + rightW) - 40;

	rect.top -= marginT;
	rect.bottom += marginB;
	rect.left -= marginL;
	rect.right += marginR;

	ClientToScreen(&rect);
	MoveWindow(&rect);
}
