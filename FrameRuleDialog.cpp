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
}


BEGIN_MESSAGE_MAP(FrameRuleDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &FrameRuleDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// FrameRuleDialog 消息处理程序


void FrameRuleDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CListCtrl *p_ctrl_list = &(m_p_dlg->m_ctrl_list);

	UpdateData(true);
	
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
	obj->id = m_str_id;
	obj->start_byte = m_i_start_byte;
	obj->start_bite = m_i_start_bite;
	obj->bite_len = m_i_bite_len;
	obj->ratio = m_ratio;
	obj->offset = m_offset;

	if (m_operate == OperateType::ADD) {
		p_ctrl_list->InsertItem(index, obj->name);
		p_ctrl_list->SetItemData(index, (DWORD_PTR)obj);
	}
	else {
		p_ctrl_list->SetItemText(index, 0, obj->name);
	}

	CDialogEx::OnOK();
}


BOOL FrameRuleDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	if (m_operate == OperateType::EDIT) 
	{
		CListCtrl *p_ctrl_list = &(m_p_dlg->m_ctrl_list);
		m_list_index = m_p_dlg->GetCurListItem();
		FrameRuleObj *obj = (FrameRuleObj *)(p_ctrl_list->GetItemData(m_list_index));

		m_str_name = obj->name;
		m_str_id = obj->id;
		m_i_start_byte = obj->start_byte;
		m_i_start_bite = obj->start_bite;
		m_i_bite_len = obj->bite_len;
		m_ratio = obj->ratio;
		m_offset = obj->offset;

		UpdateData(false);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
