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
	if (!m_app.CreateDispatch(_T("Excel.Application"))) {
		MessageBox(_T("无法创建Excel应用"));
	}
}

HaideProtocolDialog::~HaideProtocolDialog()
{
	m_app.Quit();
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
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, &HaideProtocolDialog::OnBnClickedButtonImport)
	ON_BN_CLICKED(IDC_BUTTON_EXPORT, &HaideProtocolDialog::OnBnClickedButtonExport)
END_MESSAGE_MAP()


// HaideProtocolDialog 消息处理程序


BOOL HaideProtocolDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_ctrl_list.InsertColumn(0, _T("数据项名称"), 0, 175);
	m_ctrl_list.InsertColumn(1, _T("解析结果"), 0, 80);
	m_ctrl_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_groups = new CStringArray();

	/*test code*/
	if (0) {
		int i = 0;
		FrameRuleObj *obj = NULL;
			
		obj = new FrameRuleObj();
		obj->name = _T("车辆状态");
		obj->id = _T("0x00000012");
		obj->start_byte = 7;
		obj->start_bite = 0;
		obj->bite_len = 2;
		obj->ratio = 1;
		obj->offset = 0;

		m_ctrl_list.InsertItem(i, obj->name);
		m_ctrl_list.SetItemData(i, (DWORD_PTR)obj);
		i++;

		obj = new FrameRuleObj();
		obj->name = _T("充电状态");
		obj->id = _T("0x00000080");
		obj->start_byte = 4;
		obj->start_bite = 0;
		obj->bite_len = 8;
		obj->ratio = 1;
		obj->offset = 0;

		m_ctrl_list.InsertItem(i, obj->name);
		m_ctrl_list.SetItemData(i, (DWORD_PTR)obj);
		i++;

		obj = new FrameRuleObj();
		obj->name = _T("车速");
		obj->id = _T("0x18037a7a");
		obj->start_byte = 1;
		obj->start_bite = 0;
		obj->bite_len = 16;
		obj->ratio = 0.00390625;
		obj->offset = 0;

		m_ctrl_list.InsertItem(i, obj->name);
		m_ctrl_list.SetItemData(i, (DWORD_PTR)obj);
		i++;

		obj = new FrameRuleObj();
		obj->name = _T("累计里程");
		obj->id = _T("0x18017a70");
		obj->start_byte = 0;
		obj->start_bite = 0;
		obj->bite_len = 32;
		obj->ratio = 0.1;
		obj->offset = 0;

		m_ctrl_list.InsertItem(i, obj->name);
		m_ctrl_list.SetItemData(i, (DWORD_PTR)obj);
		i++;

		obj = new FrameRuleObj();
		obj->name = _T("DC-DC状态");
		obj->id = _T("0x18097A70");
		obj->start_byte = 1;
		obj->start_bite = 2;
		obj->bite_len = 2;
		obj->ratio = 1;
		obj->offset = 0;

		m_ctrl_list.InsertItem(i, obj->name);
		m_ctrl_list.SetItemData(i, (DWORD_PTR)obj);
		i++;
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
	FrameRuleDialog dlg(this);

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

	FrameRuleDialog dlg(this);

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


int HaideProtocolDialog::ParseFrame(VCI_CAN_OBJ obj)
{
	int i = 0;
	int len = m_ctrl_list.GetItemCount();

	for (i = 0; i < len; i++) {
		FrameRuleObj *rule = (FrameRuleObj *)m_ctrl_list.GetItemData(i);

		if (rule->IsSameId(obj.ID) || 1) {
			CString val = rule->Parse2(obj.Data);

			m_ctrl_list.SetItemText(i, 1, val);
		}
	}

	return 0;
}


void HaideProtocolDialog::OnBnClickedButtonImport()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(FALSE, _T(".xls"), NULL
		, OFN_FILEMUSTEXIST
		//, _T("Microsoft Excel Files(*.xls)|*.xls|Microsoft Excel Files(*.xlsx)|*.xlsx||"));
	    , _T("Microsoft Excel Files(*.xlsx)|*.xlsx||"));

	int nResponse = dlg.DoModal();

	if (nResponse == IDOK) {
		CString fileName = dlg.GetPathName();

		CWorkbooks books;
		CWorkbook book;
		CWorksheets sheets;
		CWorksheet sheet;

		CRange range;

		LPDISPATCH lpDisp = NULL;

		int i;

		books.AttachDispatch(m_app.get_Workbooks(), TRUE);
		lpDisp = books.Open(fileName
			, _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing)
			, _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing)
			, _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing));

		// 获得活动的WorkBook（工作簿）
		book.AttachDispatch(lpDisp, TRUE);
		// 获得活动的WorkSheet（工作表）
		sheet.AttachDispatch(book.get_ActiveSheet(), TRUE);
		// 获得使用的区域Range（区域）
		range.AttachDispatch(sheet.get_UsedRange(), TRUE);

		// 获得试用的行数
		long lgUsedRowNum = 0;
		range.AttachDispatch(range.get_Rows(), TRUE);
		lgUsedRowNum = range.get_Count();

		// 获得使用的列数
		long lgUsedColumnNum = 0;
		range.AttachDispatch(range.get_Columns(), TRUE);
		lgUsedColumnNum = range.get_Count();

		// 读取sheet的名称
		CString strSheetName = sheet.get_Name();

		// 得到全部Cells，此时CurRange是cells的集合
		range.AttachDispatch(sheet.get_Cells(), TRUE);

		// i = 1: 跳过标头，从第二行开始
		for (i = 1; i < lgUsedRowNum; i++) {
			ReadExcelRow(i, range);
		}

		// 释放资源
		range.ReleaseDispatch();

	}
}

// TRUE：是合并单元格
BOOL HaideProtocolDialog::IsMergeCell(CRange cell) {
	return cell.get_MergeCells().boolVal != 0;
}


BOOL HaideProtocolDialog::IsGroupHeaderRow(int row, CRange range) {
	CRange oCurCell;
	CRange oNextCell;

	oCurCell.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)1)).pdispVal, TRUE);

	if (IsMergeCell(oCurCell) == FALSE) {
		return FALSE;
	}

	/*
	通过颜色值判断，失败：get_ColorIndex总是返回0，get_Color返回0xffffff
	新判断方法：第2个是否也是合并单元格
	*/
	oNextCell.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)2)).pdispVal, TRUE);

	return IsMergeCell(oNextCell);
}

// col从1起
CString HaideProtocolDialog::GetExcelText(int row, int col, CRange range) {
	CRange oCurCell;
	
	oCurCell.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)col)).pdispVal, TRUE);

	return oCurCell.get_Text().bstrVal;
}


CString HaideProtocolDialog::GetExcelText(CRange cell) {
	return cell.get_Text().bstrVal;
}

double HaideProtocolDialog::GetExcelVal(int row, int col, CRange range) {
	double ret = 0;
	CString str;
	CRange oCurCell;

	oCurCell.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)col)).pdispVal, TRUE);
	str = oCurCell.get_Text().bstrVal;

	ret = atof(str.GetBuffer(0));
	return ret;
}


void HaideProtocolDialog::AddToListCtrl(FrameRuleObj *obj) {
	int index = m_ctrl_list.GetItemCount();

	m_ctrl_list.InsertItem(index, obj->name);
	m_ctrl_list.SetItemData(index, (DWORD_PTR)obj);
}



void HaideProtocolDialog::ReadRuleRow(int row, CRange range) {
	CRange oCurCell;
	CString strText;
	FrameRuleObj *rule = NULL;
		
	rule = new FrameRuleObj();

	// 解析row
	rule->group = m_curGroup;
	rule->name = GetExcelText(row, 2, range);
	rule->description1 = GetExcelText(row, 3, range);
	rule->id = GetExcelText(row, 4, range);
	rule->is_intel = GetExcelText(row, 5, range).CompareNoCase(_T("INTEL")) ? FALSE : TRUE;
	rule->start_byte = (int)GetExcelVal(row, 6, range);
	rule->start_bite = (int)GetExcelVal(row, 7, range);
	rule->bite_len = (int)GetExcelVal(row, 8, range);
	rule->ratio = GetExcelVal(row, 9, range);
	rule->offset = GetExcelVal(row, 10, range);
	rule->str_from = GetExcelText(row, 11, range);
	rule->description2 = GetExcelText(row, 12, range);
	rule->str_const = GetExcelText(row, 13, range);
	rule->is_const = !rule->str_const.IsEmpty();

	// 插入CListCtrl
	AddToListCtrl(rule);
}

void HaideProtocolDialog::ReadExcelRow(int row, CRange range) {
	CRange cellGroup;
	CString strGroupName;
	CRange cellName;
	CString strName;

	cellGroup.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)1)).pdispVal, TRUE);
	strGroupName = cellGroup.get_Text().bstrVal;
	
	if (IsGroupHeaderRow(row, range)) {
		// 处理分组头
		m_curGroup = strGroupName;
		m_groups->Add(strGroupName);

		return;
	}

	cellName.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)2)).pdispVal, TRUE);
	strName = cellName.get_Text().bstrVal;

	if (!strName.IsEmpty()) {
		// 不为空，即认定是规则解析项
		ReadRuleRow(row, range);
	}
}

void HaideProtocolDialog::OnBnClickedButtonExport()
{
	// TODO: 在此添加控件通知处理程序代码
	// test code
	VCI_CAN_OBJ obj;
	obj.ID = 1;
	obj.Data[0] = 0x04, obj.Data[1] = 0x03, obj.Data[2] = 0x02, obj.Data[3] = 0x01,
		obj.Data[4] = 0x05, obj.Data[5] = 0x06, obj.Data[6] = 0x07, obj.Data[7] = 0x08;

	ParseFrame(obj);
}



BOOL HaideProtocolDialog::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialogEx::DestroyWindow();
}
