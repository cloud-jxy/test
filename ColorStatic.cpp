// ColorStatic.cpp : implementation file
//

#include "stdafx.h"
#include "ColorStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColorStatic

CColorStatic::CColorStatic()
{
	//m_crBg = RGB(255, 255, 255);
}

CColorStatic::~CColorStatic()
{
}


BEGIN_MESSAGE_MAP(CColorStatic, CStatic)
	//{{AFX_MSG_MAP(CColorStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorStatic message handlers

void CColorStatic::SetTextColor(COLORREF crText)
{
	m_crText = crText;
	RedrawWindow();
}

void CColorStatic::SetFontSize(int nSize)
{
	nSize *= -1;
	m_lf.lfHeight = nSize;
	m_font.DeleteObject();
	m_font.CreateFontIndirect(&m_lf);
	RedrawWindow();
}


void CColorStatic::SetBackColor(COLORREF crBackColor)
{
	m_crBackColor = crBackColor;
	RedrawWindow();
}

void CColorStatic::SetTransparent(bool bTran)
{
	m_bTran = bTran;
	RedrawWindow();
}


HBRUSH CColorStatic::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果不应调用父级的处理程序，则返回非 null 画笔
	if (CTLCOLOR_STATIC == nCtlColor)
	{
		pDC->SelectObject(&m_font);
		pDC->SetTextColor(m_crText);
		pDC->SetBkColor(m_crBackColor);
		if (m_bTran == true)
			pDC->SetBkMode(TRANSPARENT);
	}

	return m_hBrush;
}
