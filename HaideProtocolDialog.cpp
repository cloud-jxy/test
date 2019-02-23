// HaideProtocolDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "HaideProtocolDialog.h"
#include "afxdialogex.h"
#include "testDlg.h"


// HaideProtocolDialog 对话框

IMPLEMENT_DYNAMIC(HaideProtocolDialog, CDialogEx)

HaideProtocolDialog::HaideProtocolDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HAIDE_PROTOCOL_DIALOG, pParent)
{

}

HaideProtocolDialog::~HaideProtocolDialog()
{
}

void HaideProtocolDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_ctrl_list);
}


BEGIN_MESSAGE_MAP(HaideProtocolDialog, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &HaideProtocolDialog::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &HaideProtocolDialog::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &HaideProtocolDialog::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &HaideProtocolDialog::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// HaideProtocolDialog 消息处理程序


BOOL HaideProtocolDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ctrl_list.InsertColumn(0, _T("数据项名称"), 0, 175);
	m_ctrl_list.InsertColumn(1, _T("解析结果"), 0, 80);

	m_ctrl_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	/*test code*/
	if (1) {
		FrameRuleObj *obj = new FrameRuleObj();
		obj->name = _T("车辆状态");
		obj->id = _T("0x00000012");
		obj->start_byte = 7;
		obj->start_bite = 0;
		obj->bite_len = 2;
		obj->ratio = 1;
		obj->offset = 0;

		m_ctrl_list.InsertItem(0, obj->name);
		m_ctrl_list.SetItemData(0, (DWORD_PTR)obj);

		obj = new FrameRuleObj();
		obj->name = _T("充电状态");
		obj->id = _T("0x00000080");
		obj->start_byte = 4;
		obj->start_bite = 0;
		obj->bite_len = 8;
		obj->ratio = 1;
		obj->offset = 0;

		m_ctrl_list.InsertItem(1, obj->name);
		m_ctrl_list.SetItemData(1, (DWORD_PTR)obj);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void HaideProtocolDialog::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	((CButton *)m_p_parent_dlg->GetDlgItem(IDC_CHECK2))->SetCheck(false);
	CDialogEx::OnClose();
}


void HaideProtocolDialog::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	FrameRuleDialog dlg;

	dlg.m_operate = OperateType::ADD;
	dlg.m_p_dlg = this;
	dlg.DoModal();
}


void HaideProtocolDialog::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	if (GetCurListItem() == -1) {
		MessageBox(_T("请选择删除项"));
		return;
	}

	int index = GetCurListItem();
	FrameRuleObj *obj = (FrameRuleObj *)m_ctrl_list.GetItemData(index);
	delete obj;

	m_ctrl_list.DeleteItem(index);
}


void HaideProtocolDialog::OnBnClickedButtonEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	if (GetCurListItem() == -1) {
		MessageBox(_T("请选择修改项"));
		return;
	}

	FrameRuleDialog dlg;

	dlg.m_operate = OperateType::EDIT;
	dlg.m_p_dlg = this;
	dlg.DoModal();
}


int HaideProtocolDialog::GetCurListItem()
{
	POSITION pos = m_ctrl_list.GetFirstSelectedItemPosition();
	int ret = -1;
	if (pos == NULL) {
		ret = -1;
	}
	else
	{
		while (pos)
		{
			ret = m_ctrl_list.GetNextSelectedItem(pos);
		}
	}
	return ret;
}


void HaideProtocolDialog::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	int i = 0;
	int len = m_ctrl_list.GetItemCount();

	for (i = 0; i < len; i++) {
		FrameRuleObj *obj = (FrameRuleObj *)m_ctrl_list.GetItemData(i);
		delete obj;
	}

	m_ctrl_list.DeleteAllItems();
}
