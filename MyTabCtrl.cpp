// MyTabCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "MyTabCtrl.h"
#include "MyTabDialog.h"


// CMyTabCtrl

IMPLEMENT_DYNAMIC(CMyTabCtrl, CTabCtrl)

CMyTabCtrl::CMyTabCtrl()
{

}

CMyTabCtrl::~CMyTabCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
END_MESSAGE_MAP()



// CMyTabCtrl 消息处理程序

void CMyTabCtrl::SetItemData(int pos, void *ptr) {
	if (pos >= MAX_ITEM_COUNT) {
		return;
	}

	m_itemData[pos] = ptr;
}


void * CMyTabCtrl::GetItemData(int pos) {
	if (pos >= MAX_ITEM_COUNT) {
		return NULL;
	}
	else {
		return m_itemData[pos];
	}
}


void CMyTabCtrl::MyInsertItem(CString text, CDialog *dlg, UINT uid) {
	int pos = GetItemCount();
	// CMyTabDialog *dlg = new CMyTabDialog();
	if (dlg->m_hWnd == NULL) {
		dlg->Create(uid, (CWnd *)this);
	}
	//CTabDialog *dlg = CTabDialog::CreateByName(_T("CTab1Dialog"));

	InsertItem(pos, text);
	SetItemData(pos, (void *)dlg);

	CRect rect;
	GetClientRect(&rect);
	rect.top += 20;
	rect.bottom -= 5;
	rect.left += 5;
	rect.right -= 5;

	dlg->MoveWindow(&rect);
	dlg->ShowWindow(SW_SHOW);
}


void CMyTabCtrl::MyDeleteItem(int pos) {
	CMyTabDialog *dlg = (CMyTabDialog *)GetItemData(pos);
	if (dlg) {
		dlg->DestroyWindow();
		//delete dlg;
	}

	DeleteItem(pos);
}

void CMyTabCtrl::MyDeleteAllItems() {
	int count = GetItemCount() - 1;
	int i = 0;
	for (i = count; i >= 0; i--) {
		MyDeleteItem(i);
	}
}
