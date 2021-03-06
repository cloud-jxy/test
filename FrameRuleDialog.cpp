// FrameRuleDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "FrameRuleDialog.h"
#include "afxdialogex.h"
#include "HaideProtocolDialog.h"


// FrameRuleDialog 对话框

IMPLEMENT_DYNAMIC(FrameRuleDialog, CDialogEx)

FrameRuleDialog::FrameRuleDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FRAME_RULE_DIALOG, pParent)
	, m_str_name(_T(""))
	, m_str_id(_T(""))
	, m_i_start_byte(0)
	, m_i_start_bite(0)
	, m_i_bite_len(0)
	, m_ratio(1)
	, m_offset(0)
	, m_str_decription1(_T(""))
	, m_str_decription2(_T(""))
	, m_str_group(_T(""))
	, m_str_from(_T(""))
	, m_str_const(_T(""))
{

}

FrameRuleDialog::~FrameRuleDialog()
{
}

void FrameRuleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_str_name);
	DDX_Text(pDX, IDC_EDIT_ID, m_str_id);
	DDX_Text(pDX, IDC_EDIT_START_BYTE, m_i_start_byte);
	DDX_Text(pDX, IDC_EDIT_START_BITE, m_i_start_bite);
	DDX_Text(pDX, IDC_EDIT_BITE_LEN, m_i_bite_len);
	DDX_Text(pDX, IDC_EDIT_RATIO, m_ratio);
	DDX_Text(pDX, IDC_EDIT_OFFSET, m_offset);
	DDX_Text(pDX, IDC_EDIT_DESCRIPTION_1, m_str_decription1);
	DDX_Text(pDX, IDC_EDIT_DESCRIPTION_2, m_str_decription2);
	DDX_Text(pDX, IDC_EDIT_GROUP, m_str_group);
	DDX_Text(pDX, IDC_EDIT_FROM, m_str_from);
	DDX_Text(pDX, IDC_EDIT_CONST, m_str_const);
}


BEGIN_MESSAGE_MAP(FrameRuleDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OK, &FrameRuleDialog::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_CHECK1, &FrameRuleDialog::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &FrameRuleDialog::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK_CONST, &FrameRuleDialog::OnBnClickedCheckConst)
	ON_BN_CLICKED(IDCANCEL, &FrameRuleDialog::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &FrameRuleDialog::OnOK)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &FrameRuleDialog::OnBnClickedButtonEdit)
END_MESSAGE_MAP()


// FrameRuleDialog 消息处理程序


void FrameRuleDialog::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CListCtrl *p_ctrl_list = &(m_p_dlg->m_ctrl_list);

	UpdateData(true);

	m_str_name.TrimRight();
	m_str_name.TrimLeft();
	m_str_const.TrimRight();
	m_str_const.TrimLeft();
	m_str_group.TrimRight();
	m_str_group.TrimLeft();
	

	if (m_str_name.IsEmpty()) {
		MessageBox(_T("数据项不能为空"), _T("提示"));
		return;
	}

	if (((CButton *)GetDlgItem(IDC_CHECK_CONST))->GetCheck() && m_str_const.IsEmpty()) {
		MessageBox(_T("固定值不能为空"), _T("提示"));
		return;
	}

	if (m_str_id.Find(_T("0x")) != 0) {
		MessageBox(_T("CANID格式错误"), _T("提示"));
		return;
	}
	
	int index = 0;

	FrameRuleObj *obj = NULL;

	if (m_operate == OperateType::ADD) {
		index = p_ctrl_list->GetItemCount();
		obj = new FrameRuleObj();
	}
	else {
		index = m_p_dlg->GetCurListItem();
		obj = ((FrameRuleObj *)p_ctrl_list->GetItemData(index));
	}
	
	obj->name = m_str_name;
	obj->description1 = m_str_decription1;
	obj->id = m_str_id;
	obj->is_intel = ((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck();
	obj->start_byte = m_i_start_byte;
	obj->start_bite = m_i_start_bite;
	obj->bite_len = m_i_bite_len;
	obj->ratio = m_ratio;
	obj->offset = m_offset;
	obj->description2 = m_str_decription2;
	obj->group = m_str_group;
	obj->str_from = m_str_from;
	obj->is_const = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
	if (obj->is_const) {
		obj->str_const = m_str_const;
	}
	else {
		obj->str_const = _T("");
	}

	if (m_operate == OperateType::ADD) {
		m_p_dlg->AddToListCtrl2(obj);
		//p_ctrl_list->InsertItem(index, obj->name);
		//p_ctrl_list->SetItemData(index, (DWORD_PTR)obj);
	}
	else {
		p_ctrl_list->SetItemText(index, 0, obj->group);
		p_ctrl_list->SetItemText(index, 1, obj->name);
		p_ctrl_list->SetItemText(index, 3, obj->description1);
		m_p_dlg->SetDetailRow(index, obj);
	}

	CDialogEx::OnCancel();
}


BOOL FrameRuleDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	if (m_operate == OperateType::EDIT || m_operate == OperateType::LOOK)
	{
		CListCtrl *p_ctrl_list = &(m_p_dlg->m_ctrl_list);
		m_list_index = m_p_dlg->GetCurListItem();
		FrameRuleObj *obj = (FrameRuleObj *)(p_ctrl_list->GetItemData(m_list_index));

		m_str_name = obj->name;
		m_str_decription1 = obj->description1;
		m_str_id = obj->id;
		m_is_intel = obj->is_intel;
		m_i_start_byte = obj->start_byte;
		m_i_start_bite = obj->start_bite;
		m_i_bite_len = obj->bite_len;
		m_ratio = obj->ratio;
		m_offset = obj->offset;
		m_str_from = obj->str_from;
		m_str_decription2 = obj->description2;
		m_str_group = obj->group;
		m_is_const = obj->is_const;
		m_str_const = obj->str_const;

		((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(!m_is_intel);
		((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(m_is_intel);

		UpdateForConstCtrl(m_is_const);

		UpdateData(false);
	}
	else {
		// 新建
		m_is_const = false;
		m_is_intel = true;
		((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(!m_is_intel);
		((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(m_is_intel);
		UpdateForConstCtrl(false);
	}

	if (m_operate == OperateType::LOOK) {
		GetDlgItem(IDC_EDIT_GROUP)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_NAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_DESCRIPTION_1)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_DESCRIPTION_2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_ID)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_START_BYTE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_START_BITE)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_BITE_LEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_RATIO)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_OFFSET)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_CONST)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_CONST)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_FROM)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK2)->EnableWindow(FALSE);

		GetDlgItem(IDC_BUTTON_OK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_EDIT)->ShowWindow(SW_SHOW);
	}
	else {
		GetDlgItem(IDC_BUTTON_OK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDCANCEL)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_EDIT)->ShowWindow(SW_HIDE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void FrameRuleDialog::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_is_intel = FALSE;
	((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(!m_is_intel);
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(m_is_intel);
}


// intel cbx-box
void FrameRuleDialog::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_is_intel = TRUE;
	((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(!m_is_intel);
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(m_is_intel);
}


void FrameRuleDialog::UpdateForConstCtrl(BOOL status) {
	((CButton *)GetDlgItem(IDC_CHECK_CONST))->SetCheck(status);
	((CButton *)GetDlgItem(IDC_EDIT_CONST))->EnableWindow(status);
}

void FrameRuleDialog::OnBnClickedCheckConst()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL status = ((CButton *)GetDlgItem(IDC_CHECK_CONST))->GetCheck();
	m_is_const = status;
	UpdateForConstCtrl(status);
}


void FrameRuleDialog::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL FrameRuleDialog::PreTranslateMessage(MSG* pMsg)
{
	//屏蔽ESC关闭窗体/
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE) {
		return TRUE;
	}

	//屏蔽回车关闭窗体,但会导致回车在窗体上失效.
	//if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN && pMsg->wParam) return TRUE;
	else {
		return CDialog::PreTranslateMessage(pMsg);
	}
}


void FrameRuleDialog::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void FrameRuleDialog::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}


void FrameRuleDialog::OnBnClickedButtonEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	m_operate = OperateType::EDIT;

	GetDlgItem(IDC_EDIT_GROUP)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_NAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_DESCRIPTION_1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_DESCRIPTION_2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_ID)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_START_BYTE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_START_BITE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_BITE_LEN)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_RATIO)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_OFFSET)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_CONST)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK_CONST)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT_FROM)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK1)->EnableWindow(TRUE);
	GetDlgItem(IDC_CHECK2)->EnableWindow(TRUE);

	GetDlgItem(IDC_BUTTON_OK)->ShowWindow(SW_SHOW);
	GetDlgItem(IDCANCEL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON_EDIT)->ShowWindow(SW_HIDE);
}
