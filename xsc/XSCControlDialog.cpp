// ./xsc/XSCControlDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XSCControlDialog.h"
#include "afxdialogex.h"
#include "../resource.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

StaticItemObj g_xscControl[] = {

	StaticItemObj(_T("����������ڳ�ˮ"), DEFAULT_VAL, _T("0x18F40200"), 0, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("�������ϴ����"), DEFAULT_VAL, _T("0x18F40200"), 0, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("�������������"), DEFAULT_VAL, _T("0x18F40200"), 0, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("����������彵"), DEFAULT_VAL, _T("0x18F40200"), 0, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("������к��ſ�"), DEFAULT_VAL, _T("0x18F40200"), 0, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("������к��Ź�"), DEFAULT_VAL, _T("0x18F40200"), 0, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��߰�ȫ֧����λ"), DEFAULT_VAL, _T("0x18F40200"), 0, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("�Ұ�ȫ֧����λ"), DEFAULT_VAL, _T("0x18F40200"), 0, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("ˮ·����"), DEFAULT_VAL, _T("0x18F40200"), 1, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("Һѹ�Ϳ���"), DEFAULT_VAL, _T("0x18F40200"), 1, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ˮȱˮ����"), DEFAULT_VAL, _T("0x18F40200"), 1, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("ˮ��ͣ������"), DEFAULT_VAL, _T("0x18F40200"), 1, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ˮ����"), DEFAULT_VAL, _T("0x18F40200"), 1, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("Һѹ��λ"), DEFAULT_VAL, _T("0x18F40200"), 1, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���¹���"), DEFAULT_VAL, _T("0x18F40200"), 1, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ѹ���"), DEFAULT_VAL, _T("0x18F40200"), 1, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��������λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���彵��λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��������λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���ڽ���λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���ſ���λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���Ź���λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("ж��"), DEFAULT_VAL, _T("0x18F40201"), 0, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��������"), DEFAULT_VAL, _T("0x18F40201"), 0, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���彵��"), DEFAULT_VAL, _T("0x18F40201"), 0, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���ſ���"), DEFAULT_VAL, _T("0x18F40201"), 0, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���Źط�"), DEFAULT_VAL, _T("0x18F40201"), 0, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("ǰ��ɨ������"), DEFAULT_VAL, _T("0x18F40201"), 0, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("ǰ��ɨ�̽���"), DEFAULT_VAL, _T("0x18F40201"), 0, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("ǰ��ɨ������"), DEFAULT_VAL, _T("0x18F40201"), 0, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("ǰ��ɨ�̽���"), DEFAULT_VAL, _T("0x18F40201"), 1, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ˢ����"), DEFAULT_VAL, _T("0x18F40201"), 1, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ˢ����"), DEFAULT_VAL, _T("0x18F40201"), 1, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��������"), DEFAULT_VAL, _T("0x18F40201"), 1, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���ڽ���"), DEFAULT_VAL, _T("0x18F40201"), 1, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("ǰ��ɨ��ת��"), DEFAULT_VAL, _T("0x18F40201"), 1, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("ǰ��ɨ��ת��"), DEFAULT_VAL, _T("0x18F40201"), 1, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ˢת��"), DEFAULT_VAL, _T("0x18F40201"), 1, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("����ˮ����"), DEFAULT_VAL, _T("0x18F40201"), 2, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("����ˮ����"), DEFAULT_VAL, _T("0x18F40201"), 2, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("����ˮ����"), DEFAULT_VAL, _T("0x18F40201"), 2, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("����ˮ����"), DEFAULT_VAL, _T("0x18F40201"), 2, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���ˮ��"), DEFAULT_VAL, _T("0x18F40201"), 2, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("�ҳ�ˮ��"), DEFAULT_VAL, _T("0x18F40201"), 2, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���ڳ�ˮ"), DEFAULT_VAL, _T("0x18F40201"), 2, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���ڳ�ˮ"), DEFAULT_VAL, _T("0x18F40201"), 2, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18F40201"), 3, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("�ϸǿ���"), DEFAULT_VAL, _T("0x18F40201"), 3, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ѹˮ��"), DEFAULT_VAL, _T("0x18F40201"), 3, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("����ȡ����"), DEFAULT_VAL, _T("0x18F40201"), 3, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��·ж�ɷ�"), DEFAULT_VAL, _T("0x18F40201"), 3, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("���ѹ��ˮ��"), DEFAULT_VAL, _T("0x18F40201"), 3, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("�ҵ�ѹ��ˮ��"), DEFAULT_VAL, _T("0x18F40201"), 3, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ѹ��ˮ��"), DEFAULT_VAL, _T("0x18F40201"), 3, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18F40201"), 4, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ˮת��"), DEFAULT_VAL, _T("0x18F40201"), 4, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18F40201"), 4, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ѹˮ��"), DEFAULT_VAL, _T("0x18F40201"), 4, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18F40201"), 4, 4, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("�����̵���"), DEFAULT_VAL, _T("0x18F40201"), 4, 5, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("�綯ˮ��"), DEFAULT_VAL, _T("0x18F40201"), 4, 6, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("������Ȧ"), DEFAULT_VAL, _T("0x18F40201"), 4, 7, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18F40201"), 5, 0, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("��ͷ��"), DEFAULT_VAL, _T("0x18F40201"), 5, 1, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18F40201"), 5, 2, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose)),
	StaticItemObj(_T("Ϩ���ŷ�"), DEFAULT_VAL, _T("0x18F40201"), 5, 3, 1,(PtrFuncToString)(&CXSCControlDialog::OpenOrClose))
};

// CXSCControlDialog �Ի���

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


// CXSCControlDialog ��Ϣ�������

void CXSCControlDialog::SetCtrlRect() {
	// 0-21�����룬֮�������

	CRect rect, rtKey, rtValue;
	GetWindowRect(&rect);
	ScreenToClient(&rect);

	//ȥ��margin
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

	// ���¼���dialog rect
	rect.bottom = rect.top + (row + 1) * h;
	rect.right = rect.left + 2 * (leftW + rightW) - 40;

	rect.top -= marginT;
	rect.bottom += marginB;
	rect.left -= marginL;
	rect.right += marginR;

	ClientToScreen(&rect);
	MoveWindow(&rect);
}
