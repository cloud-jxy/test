#pragma once
#include "ColorStatic.h"

class StaticItemObj;
class CStaticItem
{
public:
	CStaticItem();
	~CStaticItem();
public:
	CColorStatic m_ctrlKey;
	CColorStatic m_ctrlValue;
	int m_w;
	int m_h;
	int m_leftW;
	int m_rightW;
	CRect m_rtKey;
	CRect m_rtValue;
	StaticItemObj *m_pItem;

	void Create(CWnd *pParent, CString key, CString value, CRect rtKey, CRect rtValue);
	void Create(CWnd *pParent, StaticItemObj *pItem, CRect rtKey, CRect rtValue);

	void Destory();

	void SetItemValue(CString value);
};

