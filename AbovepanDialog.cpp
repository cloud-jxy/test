// AbovepanDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "AbovepanDialog.h"
#include "afxdialogex.h"
#include "AbovepanData.h"
#include "ParseDialog.h"
#include "NavigationDialog.h"

// CAbovepanDialog �Ի���

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
	CParseDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_STATIC_TITLE, m_stTitle);
}


BEGIN_MESSAGE_MAP(CAbovepanDialog, CParseDialog)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CAbovepanDialog::OnNMClickList1)
	ON_WM_DESTROY()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CAbovepanDialog::OnTcnSelchangeTab1)
	ON_WM_SIZING()
	ON_WM_SIZE()
	ON_WM_SYSCOMMAND()
	ON_BN_CLICKED(IDC_BUTTON1, &CAbovepanDialog::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CAbovepanDialog ��Ϣ�������


BOOL CAbovepanDialog::OnInitDialog()
{
	CParseDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_list.SetExtendedStyle(LVS_EX_FLATSB	//��ƽ�����ʾ����
		| LVS_EX_FULLROWSELECT					//��������ѡ��
		| LVS_EX_HEADERDRAGDROP					//���������϶�
		| LVS_EX_ONECLICKACTIVATE				//����ѡ����
		| LVS_EX_GRIDLINES						//����������
	);

	m_list.InsertColumn(0, _T("��װ"), 0, m_listW);
	{
		AbovepanItemObj *items = g_abovepanItemObjs;
		int len = g_abovepanItemCount;
		int i = 0;

		for (i = 0; i < len; i++) {
			m_list.InsertItem(i, items[i].m_name);
			//m_list.SetItemData(i, (DWORD_PTR)&items[i]);
		}
	}

	m_list.EnsureVisible(0, FALSE);//Ĭ��ѡ�е�һ��
	m_list.SetItemState(0, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
	m_list.SetFocus();
	InsetToTab(&g_abovepanItemObjs[0]);

#ifdef DEBUG
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
#else
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
#endif // DEBUG


	return FALSE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CAbovepanDialog::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	m_tab.SetCurSel(index);
}


void CAbovepanDialog::OnDestroy()
{
	CParseDialog::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//m_tab.MyDeleteAllItems();
}


void CAbovepanDialog::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// ��ȡdialog rect
	CRect rect, rectTitle, r;
	GetWindowRect(&rect);
	m_stTitle.GetWindowRect(&rectTitle);

	int topDiff = 8;

	ScreenToClient(&rect);
	m_stTitle.ScreenToClient(&rectTitle);

	rectTitle.top += topDiff;
	rectTitle.bottom += topDiff;
	rectTitle.right = rect.right;
	m_stTitle.MoveWindow(rectTitle);


	//���listCtrl
	r.left = rect.left + 10;
	r.right = rect.left + m_listW;
	r.top = rectTitle.bottom + 5;
	r.bottom = rect.bottom - 10;
	m_list.MoveWindow(r);

	// �Ҳ�TabCtrl
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

	// ��������

}

int CAbovepanDialog::ParseFrame(VCI_CAN_OBJ frame) {
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nItem = 0;
	if (pos == NULL) {
		return 0;

	}
	else
	{
		nItem = m_list.GetNextSelectedItem(pos);
	}

	int count = m_tab.GetItemCount();
	int i = 0;

	for (i = 0; i < count; i++) {
		CMyTabDialog *dlg = (CMyTabDialog *)m_tab.GetItemData(i);
		dlg->ParseFrame(frame);
	}

	return 0;
}

void CAbovepanDialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	VCI_CAN_OBJ frame;
	frame.DataLen = 8;
	frame.ID = 0x18f40003;
	frame.Data[0] = 0x30, frame.Data[1] = 0x31, frame.Data[2] = 0x32, frame.Data[3] = 0x33;
	frame.Data[4] = 0x34, frame.Data[5] = 0x35, frame.Data[6] = 0x36, frame.Data[7] = 0x37;

	ParseFrame(frame);
}


void CAbovepanDialog::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_tab.MyDeleteAllItems();

	CParseDialog::OnClose();
	PostNcDestroy();
}


void CAbovepanDialog::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���

	CParseDialog::PostNcDestroy();

	NavigationDialog *dlg = (NavigationDialog *)this->GetParent();
	dlg->m_abovepanDlg = NULL;

	delete this;
}
