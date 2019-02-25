// HaideProtocolDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "HaideProtocolDialog.h"
#include "afxdialogex.h"
#include "testDlg.h"



// HaideProtocolDialog �Ի���

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
	ON_BN_CLICKED(IDC_BUTTON_IMPORT, &HaideProtocolDialog::OnBnClickedButtonImport)
	ON_BN_CLICKED(IDC_BUTTON_EXPORT, &HaideProtocolDialog::OnBnClickedButtonExport)
END_MESSAGE_MAP()


// HaideProtocolDialog ��Ϣ�������


BOOL HaideProtocolDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_ctrl_list.InsertColumn(0, _T("����������"), 0, 175);
	m_ctrl_list.InsertColumn(1, _T("�������"), 0, 80);

	m_ctrl_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_groups = new CStringArray();

	/*test code*/
	if (0) {
		int i = 0;
		FrameRuleObj *obj = NULL;
			
		obj = new FrameRuleObj();
		obj->name = _T("����״̬");
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
		obj->name = _T("���״̬");
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
		obj->name = _T("����");
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
		obj->name = _T("�ۼ����");
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
		obj->name = _T("DC-DC״̬");
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
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void HaideProtocolDialog::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	((CButton *)m_p_parent_dlg->GetDlgItem(IDC_CHECK2))->SetCheck(false);
	CDialogEx::OnClose();
}


void HaideProtocolDialog::OnBnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	FrameRuleDialog dlg;

	dlg.m_operate = OperateType::ADD;
	dlg.m_p_dlg = this;
	dlg.DoModal();
}


void HaideProtocolDialog::OnBnClickedButtonDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (GetCurListItem() == -1) {
		MessageBox(_T("��ѡ��ɾ����"));
		return;
	}

	int index = GetCurListItem();
	FrameRuleObj *obj = (FrameRuleObj *)m_ctrl_list.GetItemData(index);
	delete obj;

	m_ctrl_list.DeleteItem(index);
}


void HaideProtocolDialog::OnBnClickedButtonEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (GetCurListItem() == -1) {
		MessageBox(_T("��ѡ���޸���"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(FALSE, _T(".xls"), NULL
		, OFN_FILEMUSTEXIST
		//, _T("Microsoft Excel Files(*.xls)|*.xls|Microsoft Excel Files(*.xlsx)|*.xlsx||"));
	    , _T("Microsoft Excel Files(*.xlsx)|*.xlsx||"));

	int nResponse = dlg.DoModal();

	if (nResponse == IDOK) {
		CString fileName = dlg.GetPathName();

		CApplication app;
		CWorkbooks books;
		CWorkbook book;
		CWorksheets sheets;
		CWorksheet sheet;

		CRange range;

		LPDISPATCH lpDisp = NULL;

		int i, j;

		if (!app.CreateDispatch(_T("Excel.Application"))) {
			MessageBox(_T("�޷�����ExcelӦ��"));
			return;
		}
		else {
			MessageBox(_T("����Excel�ɹ�"));
		}


		books.AttachDispatch(app.get_Workbooks(), TRUE);
		lpDisp = books.Open(fileName
			, _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing)
			, _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing)
			, _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing), _variant_t(vtMissing));

		// ��û��WorkBook����������
		book.AttachDispatch(lpDisp, TRUE);
		// ��û��WorkSheet��������
		sheet.AttachDispatch(book.get_ActiveSheet(), TRUE);
		// ���ʹ�õ�����Range������
		range.AttachDispatch(sheet.get_UsedRange(), TRUE);

		// ������õ�����
		long lgUsedRowNum = 0;
		range.AttachDispatch(range.get_Rows(), TRUE);
		lgUsedRowNum = range.get_Count();

		// ���ʹ�õ�����
		long lgUsedColumnNum = 0;
		range.AttachDispatch(range.get_Columns(), TRUE);
		lgUsedColumnNum = range.get_Count();

		// ��ȡsheet������
		CString strSheetName = sheet.get_Name();

		// �õ�ȫ��Cells����ʱCurRange��cells�ļ���
		range.AttachDispatch(sheet.get_Cells(), TRUE);

		// i = 1: ������ͷ���ӵڶ��п�ʼ
		for (i = 1; i < lgUsedRowNum; i++) {
			ReadExcelRow(i, range);
		}
	}
}

// TRUE���Ǻϲ���Ԫ��
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
	ͨ����ɫֵ�жϣ�ʧ�ܣ�get_ColorIndex���Ƿ���0��get_Color����0xffffff
	���жϷ�������2���Ƿ�Ҳ�Ǻϲ���Ԫ��
	*/
	oNextCell.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)2)).pdispVal, TRUE);

	return IsMergeCell(oNextCell);
}

void HaideProtocolDialog::ReadExcelRow(int row, CRange range) {
	CRange oCurCell;
	CString strItemName;

	oCurCell.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)1)).pdispVal, TRUE);
	strItemName = oCurCell.get_Text().bstrVal;
	
	if (IsGroupHeaderRow(row, range)) {
		// �������ͷ
		m_curGroup = strItemName;
		m_groups->Add(strItemName);
	}
	else if (!strItemName.IsEmpty()) {
		// ��Ϊ�գ����϶��ǽ�����

	}
}

void HaideProtocolDialog::OnBnClickedButtonExport()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// test code
	VCI_CAN_OBJ obj;
	obj.ID = 1;
	obj.Data[0] = 0x01, obj.Data[1] = 0x02, obj.Data[2] = 0x03, obj.Data[3] = 0x04,
		obj.Data[4] = 0x05, obj.Data[5] = 0x06, obj.Data[6] = 0x07, obj.Data[7] = 0x08;

	ParseFrame(obj);
}
