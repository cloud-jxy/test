#if !defined(AFX_COLORSTATIC_H__CA9987F9_6A3A_44DB_980C_219928BE86AB__INCLUDED_)
#define AFX_COLORSTATIC_H__CA9987F9_6A3A_44DB_980C_219928BE86AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColorStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorStatic window

class CColorStatic : public CStatic
{
	// Construction
public:
	CColorStatic();

	// Attributes
public:

	// Operations
public:

	void SetTextColor(COLORREF crText);
	void SetFontSize(int nSize);
	void SetBackColor(COLORREF crBackColor);
	void SetTransparent(bool bTran);


	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorStatic)
protected:
	//}}AFX_VIRTUAL

	// Implementation
public:
	virtual ~CColorStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CColorStatic)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	COLORREF m_crText;          // 字体颜色
	COLORREF m_crBackColor;     // 背景颜色
	HBRUSH   m_hBrush;          // 画刷
	LOGFONT  m_lf;              // 字体大小
	CFont    m_font;            // 字体

	bool     m_bTran;            // 是否透明
public:
	afx_msg HBRUSH CtlColor(CDC* /*pDC*/, UINT /*nCtlColor*/);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORSTATIC_H__CA9987F9_6A3A_44DB_980C_219928BE86AB__INCLUDED_)
