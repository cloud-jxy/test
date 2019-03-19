#pragma once
#include "StaticItem.h"
#include "StaticItemObj.h"

// CMyTabDialog 对话框

class CMyTabDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyTabDialog)

public:
	CMyTabDialog(CWnd* pParent = NULL);   // 标准构造函数

	CMyTabDialog(UINT nIDTemplate, CWnd *pParent = NULL);

	virtual ~CMyTabDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYTABDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	StaticItemObj *m_objs;
	int m_objCount;
	virtual BOOL OnInitDialog();
	int m_leftW;
	int m_rightW;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	void SetCtrlRect();
	int GetcolCount();
	void CreateCtrl();
};
