// AbovepanDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "AbovepanDialog.h"
#include "afxdialogex.h"
#include "AbovepanData.h"

// CAbovepanDialog 对话框

IMPLEMENT_DYNAMIC(CAbovepanDialog, CDialogEx)

CAbovepanDialog::CAbovepanDialog(CWnd* pParent /*=NULL*/)
	: CParseDialog(IDD_ABOVEPAN_DIALOG, pParent)
{
	m_listW = 90;
}

CAbovepanDialog::~CAbovepanDialog()
{
}

void CAbovepanDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CAbovepanDialog, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CAbovepanDialog::OnNMClickList1)
	ON_WM_DESTROY()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CAbovepanDialog::OnTcnSelchangeTab1)
	ON_WM_SIZING()
	ON_WM_SIZE()
	ON_WM_SYSCOMMAND()
END_MESSAGE_MAP()


// CAbovepanDialog 消息处理程序


BOOL CAbovepanDialog::OnInitDialog()
{
	CParseDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list.SetExtendedStyle(LVS_EX_FLATSB	//扁平风格显示滚动
		| LVS_EX_FULLROWSELECT					//允许整行选中
		| LVS_EX_HEADERDRAGDROP					//允许整列拖动
		| LVS_EX_ONECLICKACTIVATE				//单击选中项
		| LVS_EX_GRIDLINES						//画出网格线
	);

	m_list.InsertColumn(0, _T("上装"), 0, m_listW);
	{
		AbovepanItemObj *items = g_abovepanItemObjs;
		int len = g_abovepanItemCount;
		int i = 0;

		for (i = 0; i < len; i++) {
			m_list.InsertItem(i, items[i].m_name);
			//m_list.SetItemData(i, (DWORD_PTR)&items[i]);
		}
	}

	m_list.EnsureVisible(0, FALSE);//默认选中第一行
	m_list.SetItemState(0, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_list.SetFocus();
	InsetToTab(&g_abovepanItemObjs[0]);

	return FALSE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CAbovepanDialog::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nItem = 0;
	if (pos == NULL) {
		return;

	}
	else
	{
		nItem = m_list.GetNextSelectedItem(pos);
	}

	AbovepanItemObj * item = &g_abovepanItemObjs[nItem];
//	TRACE("%s\n", item->m_name);

	m_tab.MyDeleteAllItems();
	InsetToTab(item);
}


void CAbovepanDialog::InsetToTab(AbovepanItemObj * item, int index) {
	AbovepanTabItemObj *tabs = item->m_pObjs;
	int i;
	for (i = 0; i < item->m_len; i++) {
		m_tab.MyInsertItem(tabs[i].m_name, tabs[i].m_pDialog, tabs[i].m_dlgID);
		tabs[i].m_pDialog->ShowWindow(i == index ? SW_SHOW : SW_HIDE);
	}
}


void CAbovepanDialog::OnDestroy()
{
	CParseDialog::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	m_tab.MyDeleteAllItems();
}


void CAbovepanDialog::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	int sel = m_tab.GetCurSel();
	int count = m_tab.GetItemCount();

	int i = 0;
	for (i = 0; i < count; i++) {
		CDialog *dlg = (CDialog *)m_tab.GetItemData(i);
		dlg->ShowWindow(i == sel ? SW_SHOW : SW_HIDE);
	}
}


void CAbovepanDialog::SetCtrlRect() {
	//TRACE("SetCtrlRect\n");
	// 获取dialog rect
	CRect rect;
	GetWindowRect(&rect);
	ScreenToClient(&rect);

	CRect r;

	//左侧listCtrl
	r.left = rect.left + 10;
	r.right = rect.left + m_listW;
	r.top = rect.top + 55;
	r.bottom = rect.bottom - 10;
	m_list.MoveWindow(r);

	// 右侧TabCtrl
	r.left = r.right + 10;
	r.right = rect.right - 10;

	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nItem = 0;
	if (pos == NULL) {
		goto next;
	}
	else
	{
		nItem = m_list.GetNextSelectedItem(pos);
	}

	AbovepanItemObj * item = &g_abovepanItemObjs[nItem];

	AbovepanTabItemObj *tabs = item->m_pObjs;
	int i;
	for (i = 0; i < item->m_len; i++) {
		CMyTabDialog *dlg = (CMyTabDialog *)tabs[i].m_pDialog;
		CRect r2, r3, r4;
		dlg->GetWindowRect(&r2);
		m_tab.GetWindowRect(&r3);
		
		r4.left = 5;
		r4.top = r2.top - r3.top;;
		//r4.top = 20;
		r4.right = r.right - r.left - 10;
		r4.bottom = r.bottom - r.top;

		//dlg->MoveWindow(r4);
		dlg->SetCtrlRect();
		dlg->MoveWindow(r4);

		TRACE("MoveTo L=%d, T=%d\n", r4.left, r4.top);

		if (r2.top - r3.top != 20) {
			TRACE("Error diff \n");
		}
	}
next:
	m_tab.MoveWindow(r);

	// 顶部标题

}
