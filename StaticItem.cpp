#include "stdafx.h"
#include "StaticItem.h"
#include "StaticItemObj.h"

CStaticItem::CStaticItem()
{
}


CStaticItem::~CStaticItem()
{
	m_ctrlKey.DestroyWindow();
	m_ctrlValue.DestroyWindow();
}


void CStaticItem::Create(CWnd *pParent, CString key, CString value, CRect rtKey, CRect rtValue) {
	m_ctrlKey.Create(key+':', WS_CHILD | WS_VISIBLE | SS_CENTER, rtKey, pParent);
	m_ctrlValue.Create(value, WS_CHILD | WS_VISIBLE | SS_CENTER, rtValue, pParent);
}


void CStaticItem::Create(CWnd *pParent, StaticItemObj *pItem, CRect rtKey, CRect rtValue) {
	m_pItem = pItem;

	CFont *font = new CFont();
	font->CreatePointFont(100, _T("ËÎÌå"));

	if (m_ctrlKey.m_hWnd == NULL) {
		m_ctrlKey.Create(m_pItem->m_strKey + ':', WS_CHILD | WS_VISIBLE, rtKey, pParent);
	}

	if (m_ctrlValue.m_hWnd == NULL) {
		m_ctrlValue.Create(m_pItem->m_strValue, WS_CHILD | WS_VISIBLE, rtValue, pParent);
	}

	m_ctrlKey.SetFont(font);
	m_ctrlValue.SetFont(font);
}


void CStaticItem::Destory() {

}

void CStaticItem::SetItemValue(CString value) {
	m_ctrlValue.SetWindowText(value);
	//if (value.CompareNoCase("¹Ø±Õ")) {
	//	m_ctrlValue.SetTextColor(RGB(0, 0, 0));
	//}
	//else {
	//	m_ctrlValue.SetTextColor(RGB(0, 255, 0));
	//}
}
