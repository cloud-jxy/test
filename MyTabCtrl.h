#pragma once


class CMyTabDialog;
// CMyTabCtrl
#define MAX_ITEM_COUNT 32

// CMyTabCtrl

class CMyTabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTabCtrl)

public:
	CMyTabCtrl();
	virtual ~CMyTabCtrl();

protected:
	DECLARE_MESSAGE_MAP()

public:
	void SetItemData(int, void *);
	void * GetItemData(int);
	void * m_itemData[MAX_ITEM_COUNT];
	void MyInsertItem(CString text, CDialog *dlg, UINT uid);
	void MyDeleteItem(int pos);
	void MyDeleteAllItems();
};


