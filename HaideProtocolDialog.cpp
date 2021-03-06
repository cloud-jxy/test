// HaideProtocolDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "HaideProtocolDialog.h"
#include "afxdialogex.h"
#include "testDlg.h"
#include "MyChartDialog.h"
#include "MonitorDialog.h"


// HaideProtocolDialog 对话框

IMPLEMENT_DYNAMIC(HaideProtocolDialog, CDialogEx)

HaideProtocolDialog::HaideProtocolDialog(CWnd* pParent /*=NULL*/)
	: CParseDialog(IDD_HAIDE_PROTOCOL_DIALOG, pParent)
{
	m_sizing = FALSE;
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
	ON_WM_SIZING()
	ON_BN_CLICKED(IDC_BUTTON_TEST, &HaideProtocolDialog::OnBnClickedButtonTest)
	ON_WM_SIZE()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &HaideProtocolDialog::OnNMDblclkList)
	ON_BN_CLICKED(IDC_BUTTON_CHART, &HaideProtocolDialog::OnBnClickedButtonChart)
	ON_BN_CLICKED(IDC_CHECK_DETAIL, &HaideProtocolDialog::OnBnClickedCheckDetail)
	ON_WM_SYSCOMMAND()
	ON_BN_CLICKED(IDC_BUTTON_ANALYZE, &HaideProtocolDialog::OnBnClickedButtonAnalyze)
	ON_BN_CLICKED(IDC_BUTTON1, &HaideProtocolDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// HaideProtocolDialog 消息处理程序


BOOL HaideProtocolDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	SetCtrlRect();

	// 添加对话框左上角小图标。
	HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, FALSE);

	m_ctrl_list.SetExtendedStyle(LVS_EX_FLATSB	//扁平风格显示滚动
		| LVS_EX_FULLROWSELECT					//允许整行选中
		| LVS_EX_HEADERDRAGDROP					//允许整列拖动
		| LVS_EX_ONECLICKACTIVATE				//单击选中项
		| LVS_EX_GRIDLINES						//画出网格线S
	);

	int i = 0;
	m_ctrl_list.InsertColumn(i++, _T("模块"), 0, 90);
	m_ctrl_list.InsertColumn(i++, _T("数据项名称"), 0, 165);
	m_ctrl_list.InsertColumn(i++, _T("解析结果"), 0, 80);
	m_ctrl_list.InsertColumn(i++, _T("报文解析说明"), 0, 300);

	//InsertDetailHeader();

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
	// ((CButton *)m_p_parent_dlg->GetDlgItem(IDC_CHECK2))->SetCheck(false);
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

	//检测是否被使用中
	POSITION pos = m_ctrl_list.GetFirstSelectedItemPosition();
	int nItem = 0;
	FrameRuleObj *obj;
	BOOL bUsing = FALSE;

	while (pos)
	{
		nItem = m_ctrl_list.GetNextSelectedItem(pos);
		obj = (FrameRuleObj *)m_ctrl_list.GetItemData(nItem);

		if (obj->reserve > 0) {
			bUsing = TRUE;
			break;
		}
	}

	if (bUsing) {
		MessageBox(_T("被删除项正在被统计图窗口使用，请先关闭统计图窗口"), _T("提示"));
		return;
	}

	//执行删除
	while (m_ctrl_list.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED) != -1)
	{
		int index = m_ctrl_list.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

		FrameRuleObj *obj = (FrameRuleObj *)m_ctrl_list.GetItemData(index);
		//TRACE("del: %d, %s \n", index, obj->name.GetBuffer(0));
		
		delete obj;
		m_ctrl_list.DeleteItem(index);
	}
}


void HaideProtocolDialog::OnBnClickedButtonEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	if (GetCurListItem() == -1) {
		MessageBox(_T("请选择修改项"), _T("提示"));
		return;
	}

	FrameRuleDialog dlg(this);

	dlg.m_operate = OperateType::EDIT;
	dlg.m_p_dlg = this;
	dlg.DoModal();
}


void HaideProtocolDialog::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	FrameRuleDialog dlg(this);

	dlg.m_operate = OperateType::LOOK;
	dlg.m_p_dlg = this;
	dlg.DoModal();
}


int HaideProtocolDialog::GetCurListItem()
{
	POSITION pos = m_ctrl_list.GetFirstSelectedItemPosition();
	if (pos == NULL) {
		return -1;
	}
	else
	{
		return m_ctrl_list.GetNextSelectedItem(pos);
	}
}


void HaideProtocolDialog::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	int i = 0;
	int len = m_ctrl_list.GetItemCount();
	BOOL bUsing = FALSE;

	//检测使用标记
	for (i = 0; i < len; i++) {
		FrameRuleObj *obj = (FrameRuleObj *)m_ctrl_list.GetItemData(i);
		if (obj->reserve != NULL) {
			bUsing = TRUE;
			break;
		}
	}

	if (bUsing) {
		MessageBox(_T("被删除项正在被统计图窗口使用，请先关闭统计图窗口"), _T("提示"));
		return;
	}

	//执行清除
	for (i = 0; i < len; i++) {
		FrameRuleObj *obj = (FrameRuleObj *)m_ctrl_list.GetItemData(i);
		delete obj;
	}

	m_ctrl_list.DeleteAllItems();
}


int HaideProtocolDialog::ParseFrame(VCI_CAN_OBJ obj)
{
	int status = ((CButton *)GetDlgItem(IDC_CHECK_PARSE))->GetCheck();

	if (status == 0) {
		return 0;
	}

	int i = 0;
	int len = m_ctrl_list.GetItemCount();

	for (i = 0; i < len; i++) {
		FrameRuleObj *rule = (FrameRuleObj *)m_ctrl_list.GetItemData(i);

		if (1 || rule->IsSameId(obj.ID)) {
			CString val = rule->Parse2(obj.Data);

			m_ctrl_list.SetItemText(i, 2, val);
		}
	}

	return 0;
}


void HaideProtocolDialog::OnBnClickedButtonImport()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, _T(".xls"), NULL
		, OFN_FILEMUSTEXIST
		//, _T("Microsoft Excel Files(*.xls)|*.xls|Microsoft Excel Files(*.xlsx)|*.xlsx||"));
	    , _T("Microsoft Excel Files(*.xls)|*.xls||"));

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
		int i;

		if (!app.CreateDispatch(_T("Excel.Application"))) {
			MessageBox(_T("无法创建Excel应用"), _T("提示"));
		}

		books.AttachDispatch(app.get_Workbooks(), TRUE);
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

		//if (1) {
		//	CRange r;
		//	int i = 21;
		//	int val = 0;
		//	Cnterior interior;

		//	for (; i < 26; i++) {
		//		r.AttachDispatch(range.get_Item(COleVariant((long)i),
		//			COleVariant((long)1)).pdispVal, TRUE);

		//		interior.AttachDispatch(r.get_Interior());
		//		VARIANT var = interior.get_Color();

		//		val = var.lVal;


		//		VARIANT var2 = interior.get_ColorIndex();
		//		int val2 = var2.lVal;

		//		interior.ReleaseDispatch();
		//		r.ReleaseDispatch();
		//	}
		//}

		// i = 1: 跳过标头，从第二行开始
		for (i = 1; i < lgUsedRowNum; i++) {
			ReadExcelRow(i, range);
		}

		// 释放资源
		range.ReleaseDispatch();
		books.ReleaseDispatch();
		book.ReleaseDispatch();
		sheet.ReleaseDispatch();
		app.Quit();
		app.ReleaseDispatch();
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
	CString ret;

	oCurCell.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)col)).pdispVal, TRUE);
	ret = oCurCell.get_Text().bstrVal;
	oCurCell.ReleaseDispatch();

	return ret;
}

void HaideProtocolDialog::SetCellWidth(int row, int col, CRange range, int width) {
	CRange oCurCell;

	oCurCell.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)col)).pdispVal, TRUE);
	oCurCell.put_ColumnWidth(variant_t((long)width));
	oCurCell.ReleaseDispatch();
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
	oCurCell.ReleaseDispatch();

	return ret;
}


void HaideProtocolDialog::AddToListCtrl(FrameRuleObj *obj) {
	int index = m_ctrl_list.GetItemCount();
	int i = 1;

	m_ctrl_list.InsertItem(index, obj->group);
	m_ctrl_list.SetItemText(index, i++, obj->name);

	if (obj->is_const) {
		m_ctrl_list.SetItemText(index, i++, obj->str_const);
	}
	else {
		i++;	//解析结果，暂不设置
	}

	m_ctrl_list.SetItemText(index, i++, obj->description2);

	SetDetailRow(index, obj);

	m_ctrl_list.SetItemData(index, (DWORD_PTR)obj);
}

void HaideProtocolDialog::AddToListCtrl2(FrameRuleObj *obj) {
	int index = 0;
	int i = 1;

	POSITION pos = m_ctrl_list.GetFirstSelectedItemPosition();

	if (pos) {
		// 优先选择在当前item位置插入
		index = m_ctrl_list.GetNextSelectedItem(pos) + 1;
	}
	else {
		index = m_ctrl_list.GetItemCount();
	}

	m_ctrl_list.InsertItem(index, obj->group);
	m_ctrl_list.SetItemText(index, i++, obj->name);
	i++;	//解析结果，暂不设置
	m_ctrl_list.SetItemText(index, i++, obj->description2);

	SetDetailRow(index, obj);

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
	cellGroup.ReleaseDispatch();
	
	if (IsGroupHeaderRow(row, range)) {
		// 处理分组头
		m_curGroup = strGroupName;
		m_groups->Add(strGroupName);

		cellGroup.ReleaseDispatch();
		return;
	}

	cellName.AttachDispatch(range.get_Item(COleVariant((long)(row + 1)),
		COleVariant((long)2)).pdispVal, TRUE);
	strName = cellName.get_Text().bstrVal;
	cellName.ReleaseDispatch();

	if (!strName.IsEmpty()) {
		// 不为空，即认定是规则解析项
		ReadRuleRow(row, range);
	}
}

void HaideProtocolDialog::OnBnClickedButtonExport()
{
	// TODO: 在此添加控件通知处理程序代码
	// test code
	//VCI_CAN_OBJ obj;
	//obj.ID = 1;
	//obj.Data[0] = 0x04, obj.Data[1] = 0x03, obj.Data[2] = 0x02, obj.Data[3] = 0x01,
	//	obj.Data[4] = 0x05, obj.Data[5] = 0x06, obj.Data[6] = 0x07, obj.Data[7] = 0x08;

	//ParseFrame(obj);
	CString saveFilePath = _T("");

	// 设置保存路径
	if (1) {
		//格式：过滤器描述符（显示作用）+ \0 + 文件扩展名称（过滤作用）
		//多个扩展名称之间用（;）分隔，两个过滤字符串之间以\0分隔
		//最后的过滤器需要以两个\0\0结尾
		char szFilters[] = "Microsoft Excel Files(*.xls)\0*.xls\0\0";

		//当过滤器或者默认构造参数赋值较少情况下，
		//使用构造函数修改对话框初始状态可能更好，这过滤器较多
		CFileDialog FileDlg(FALSE, _T("xls"), _T("HaideProtocol"));
		FileDlg.m_ofn.lpstrTitle = "保存";
		FileDlg.m_ofn.lpstrFilter = szFilters;

		//通过以下两个参数修改对话框初始状态，程序奔溃，使用默认构造形式正常
		//环境：VS2008编译器+Wind7系统
		//FileDlg.m_ofn.lpstrDefExt = "txt";
		//FileDlg.m_ofn.lpstrFile = "test";

		if (IDOK == FileDlg.DoModal())
		{
			saveFilePath = FileDlg.GetPathName();
		}
		else {
			return;
		}
	}

	CApplication app;
	CWorkbooks books;
	CWorkbook book;
	CWorksheets sheets;
	CWorksheet sheet;
	CRange range;
	LPDISPATCH lpDisp;
	COleVariant	covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	if (!app.CreateDispatch(_T("Excel.Application"))) {
		MessageBox(_T("无法创建Excel应用"));
	}

	books = app.get_Workbooks();
	book = books.Add(covOptional);
	sheets = book.get_Worksheets();             //得到books
	sheet = sheets.get_Item(COleVariant((short)1));
	//得到全部Cells
	range.AttachDispatch(sheet.get_Cells());

	/*开始解析*/
	int i = 0;		// ClistCtrl下标
	int row = 1;	// excel文档行号，从1开始。
	int index = m_ctrl_list.GetItemCount();
	FrameRuleObj *item = NULL;
	CString group = _T("");

	// 添加表格头
	CFont0 ft;
	lpDisp = GetRange(sheet, 'A', 1, 'L', 1);
	CRange rowRange;	//用于对整行格式操作
	rowRange.AttachDispatch(lpDisp);
	ft.AttachDispatch(rowRange.get_Font());
	ft.put_Bold(_variant_t((long)1));			//粗体
	ft.ReleaseDispatch();

	//水平对齐：默认＝1,居中＝-4108,左＝-4131,右＝-4152   
	//垂直对齐：默认＝2,居中＝-4108,左＝-4160,右＝-4107   
	rowRange.put_HorizontalAlignment(_variant_t((long)-4108));
	rowRange.put_VerticalAlignment(_variant_t((long)-4108));

	rowRange.put_RowHeight(_variant_t((double)42));

	rowRange.ReleaseDispatch();

	//设置标头各段内容
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(1))
		, _variant_t(_T("")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(2))
		, _variant_t(_T("数据项名称")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(3))
		, _variant_t(_T("说明")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(4))
		, _variant_t(_T("CANID")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(5))
		, _variant_t(_T("排列格式(MOTOROLA/INTEL)")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(6))
		, _variant_t(_T("起始字节(从0开始)")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(7))
		, _variant_t(_T("起始位(从0开始)")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(8))
		, _variant_t(_T("位长度")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(9))
		, _variant_t(_T("精度")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(10))
		, _variant_t(_T("偏移量")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(11))
		, _variant_t(_T("数据来源（CAN1/CAN2）")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(12))
		, _variant_t(_T("报文解析说明（说明按CAN解析规则解析得到的值代表的意义）")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(13))
		, _variant_t(_T("固定值")));
	range.put_Item(_variant_t((long)(row)), _variant_t((long)(14))
		, _variant_t(_T("解析结果")));

	//设置标头各段长度
	SetCellWidth(1, 1, range, 15);
	SetCellWidth(1, 2, range, 29);
	SetCellWidth(1, 3, range, 57);
	SetCellWidth(1, 4, range, 10);
	SetCellWidth(1, 5, range, 21);
	SetCellWidth(1, 6, range, 11);
	SetCellWidth(1, 7, range, 11);
	SetCellWidth(1, 8, range, 7);
	SetCellWidth(1, 9, range, 13);
	SetCellWidth(1, 10, range, 7);
	SetCellWidth(1, 11, range, 16);
	SetCellWidth(1, 12, range, 60);
	SetCellWidth(1, 13, range, 7);

	for (row = 2, i = 0; i < index; i++) {
		item = (FrameRuleObj *)m_ctrl_list.GetItemData(i);
		if (group.CompareNoCase(item->group)) {
			// 不相等，新分组的第一个
			
			group = item->group;

			// 合并
			merge(sheet, 'A', row, 'C', row);
			// 插入数据
			range.put_Item(_variant_t((long)(row)), _variant_t((long)(1))
				, _variant_t(group.GetBuffer(0)));
			row++;
		}

		range.put_Item(_variant_t((long)(row)), _variant_t((long)(2))
			, _variant_t(item->name.GetBuffer(0)));
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(3))
			, _variant_t(item->description1.GetBuffer(0)));
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(4))
			, _variant_t(item->id.GetBuffer(0)));
		if (item->is_intel) {
			range.put_Item(_variant_t((long)(row)), _variant_t((long)(5))
				, _variant_t(_T("INTEL")));
		}
		else {
			range.put_Item(_variant_t((long)(row)), _variant_t((long)(5))
				, _variant_t(_T("MOTOROLA")));
		}
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(6))
			, _variant_t(item->start_byte));
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(7))
			, _variant_t(item->start_bite));
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(8))
			, _variant_t(item->bite_len));
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(9))
			, _variant_t((double)item->ratio));
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(10))
			, _variant_t((double)item->offset));
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(11))
			, _variant_t(item->str_from.GetBuffer(0)));
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(12))
			, _variant_t(item->description2.GetBuffer(0)));
		if (item->is_const) {
			range.put_Item(_variant_t((long)(row)), _variant_t((long)(13))
				, _variant_t(item->str_const.GetBuffer(0)));
			// 设置整个row的背景颜色 ColorIndex=50
			CRange r;
			Cnterior it;

			r.AttachDispatch(GetRange(sheet, 'A', row, 'N', row));
			it.AttachDispatch(r.get_Interior());
			it.put_ColorIndex(_variant_t((long)44));

			it.ReleaseDispatch();
			r.ReleaseDispatch();
		}

		//range.put_Item(_variant_t((long)(row)), _variant_t((long)(14))
		//	, _variant_t((double)item->result));

		CString text = m_ctrl_list.GetItemText(i, 2);
		range.put_Item(_variant_t((long)(row)), _variant_t((long)(14))
			, _variant_t(text.GetBuffer(0)));


		row++;
	}

	range.put_WrapText(variant_t((BOOL)TRUE));

	/*保存、释放*/
	//保存
	book.SaveCopyAs(COleVariant(saveFilePath));  //SaveCopyAs在strFile路径下保存为指定格式.xls的文件
	book.put_Saved(true);   //将Workbook的保存状态设置为已保存，即不让系统提示是否人工保存
	app.put_Visible(false);        //设置表可见性

	//释放对象
	range.ReleaseDispatch();
	sheet.ReleaseDispatch();
	sheets.ReleaseDispatch();
	book.ReleaseDispatch();
	books.ReleaseDispatch();
	app.Quit();
	app.ReleaseDispatch();

	MessageBox(_T("保存成功"), _T("提示"));
}


//void HaideProtocolDialog::merge(CWorksheet sheet, int a_x, int a_y, int b_x, int b_y) {
//	LPDISPATCH lpDisp = NULL;
//	CRange megerRange;
//	char zimu[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
//	char a[8] = { 0 };
//	char b[8] = { 0 };
//
//	snprintf(a, 8, "%c%d", zimu[a_x], a_y);
//	snprintf(b, 8, "%c%d", zimu[b_x], b_y);
//
//	lpDisp = sheet.get_Range(_variant_t(a), _variant_t(b));
//	megerRange.AttachDispatch(lpDisp);
//	megerRange.put_MergeCells((_variant_t)1);
//
//	megerRange.ReleaseDispatch();
//}


LPDISPATCH HaideProtocolDialog::GetRange(CWorksheet sheet, char a_x, int a_y, char b_x, int b_y) {
	LPDISPATCH lpDisp = NULL;
	CRange megerRange;
	char a[8] = { 0 };
	char b[8] = { 0 };

	snprintf(a, 8, "%c%d", a_x, a_y);
	snprintf(b, 8, "%c%d", b_x, b_y);

	lpDisp = sheet.get_Range(_variant_t(a), _variant_t(b));
	
	return lpDisp;
}

void HaideProtocolDialog::merge(CWorksheet sheet, char a_x, int a_y, char b_x, int b_y) {
	LPDISPATCH lpDisp = NULL;
	CRange megerRange;
	char a[8] = { 0 };
	char b[8] = { 0 };

	snprintf(a, 8, "%c%d", a_x, a_y);
	snprintf(b, 8, "%c%d", b_x, b_y);

	lpDisp = sheet.get_Range(_variant_t(a), _variant_t(b));
	megerRange.AttachDispatch(lpDisp);
	megerRange.put_MergeCells((_variant_t)1);

	/*设置字体*/
	CFont0 ft;
	ft.AttachDispatch(megerRange.get_Font());
	ft.put_Name(_variant_t("宋体"));			//字体 
	//ft.put_ColorIndex(_variant_t((long)11));	//字的颜色 
	ft.put_Size(_variant_t((long)12));			//字号 
	ft.put_Bold(_variant_t((long)1));			//粗体 

	/*设置背景颜色*/
	Cnterior it;
	it.AttachDispatch(megerRange.get_Interior());
	it.put_ColorIndex(_variant_t((long)50));

	/*设置居中对齐*/
	megerRange.put_HorizontalAlignment(_variant_t((long)-4108));
	megerRange.put_VerticalAlignment(_variant_t((long)-4108));

	ft.ReleaseDispatch();
	megerRange.ReleaseDispatch();
}



void HaideProtocolDialog::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);

	// TODO: 在此处添加消息处理程序代码
	m_sizing = TRUE;
	SetCtrlRect();
}


void HaideProtocolDialog::SetCtrlRect() {
	// 获取dialog rect
	CRect rect;   
	GetWindowRect(&rect);
	ScreenToClient(&rect);

	CRect r;

	//设置CListCtrl rect
	r.left = rect.left + 10;
	r.right = rect.right - 10;
	r.top = rect.top + 80;
	r.bottom = rect.bottom - 10;

	m_ctrl_list.MoveWindow(r);

	// 设置Button rect
	// 添加、修改
	int buttonWidth = 40, buttonHeight = 25, spaceWidth = 1;
	r.left = rect.left + 15;
	r.top = rect.top + 45;
	r.bottom = r.top + buttonHeight;
	r.right = r.left + buttonWidth;

	GetDlgItem(IDC_BUTTON_ADD)->MoveWindow(r);

	r.left = r.right + spaceWidth;
	r.right = r.left + buttonWidth;

	GetDlgItem(IDC_BUTTON_EDIT)->MoveWindow(r);

	//删除、清空
	r.left = r.right + 10;
	r.right = r.left + buttonWidth;

	GetDlgItem(IDC_BUTTON_DEL)->MoveWindow(r);

	r.left = r.right + spaceWidth;
	r.right = r.left + buttonWidth;

	GetDlgItem(IDC_BUTTON_CLEAR)->MoveWindow(r);

	// Chart、分析
	r.left = r.right + 10;
	r.right = r.left + buttonWidth + 5;
	GetDlgItem(IDC_BUTTON_CHART)->MoveWindow(r);

	r.left = r.right + spaceWidth;
	r.right = r.left + buttonWidth;
	GetDlgItem(IDC_BUTTON_ANALYZE)->MoveWindow(r);

	r.left = r.right + spaceWidth;
	r.right = r.left + buttonWidth;
	GetDlgItem(IDC_BUTTON1)->MoveWindow(r);


	//导入、导出
	r.right = rect.right - 15;
	r.left = r.right - buttonWidth;

	GetDlgItem(IDC_BUTTON_EXPORT)->MoveWindow(r);

	r.right = r.left - spaceWidth;
	r.left = r.right - buttonWidth;

	GetDlgItem(IDC_BUTTON_IMPORT)->MoveWindow(r);

	// 设置CheckBox rect
	r.right = r.left - 10;
	r.left = r.right - 90;
	GetDlgItem(IDC_CHECK_DETAIL)->MoveWindow(r);
	
	r.right = r.left - 10;
	r.left = r.right - 90;
	GetDlgItem(IDC_CHECK_PARSE)->MoveWindow(r);
}


void HaideProtocolDialog::OnBnClickedButtonTest()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDetailColumn();
}


void HaideProtocolDialog::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (m_sizing) {
		SetCtrlRect();
		m_sizing = FALSE;
	}
}



void HaideProtocolDialog::OnBnClickedButtonChart()
{
	// TODO: 在此添加控件通知处理程序代码
	if (0) {
		// 模态
		MyChartDialog dlg(this);
		dlg.m_list = &m_ctrl_list;
		dlg.DoModal();
	}
	else {
		// 非模态
		MyChartDialog *dlg = new MyChartDialog();
		dlg->m_list = &m_ctrl_list;
		dlg->Create(IDD_CHART_DIALOG, this);
		dlg->ShowWindow(SW_SHOW);
	}
}


void HaideProtocolDialog::OnBnClickedCheckDetail()
{
	// TODO: 在此添加控件通知处理程序代码
	int status = ((CButton *)GetDlgItem(IDC_CHECK_DETAIL))->GetCheck();

	if (status) {
		// 显示详情
		InsertDetailHeader();
		
		int i = 0;
		int len = m_ctrl_list.GetItemCount();
		FrameRuleObj *obj = NULL;

		for (; i < len; i++) {
			obj = (FrameRuleObj *)(m_ctrl_list.GetItemData(i));
			SetDetailRow(i, obj);
		}
	}
	else {
		// 不显示详情
		DeleteDetailColumn();
	}
}


void HaideProtocolDialog::InsertDetailHeader() {
	int i = 5;

	m_ctrl_list.InsertColumn(i++, _T("CANID"), 0, 60);
	m_ctrl_list.InsertColumn(i++, _T("排列格式"), 0, 50);
	m_ctrl_list.InsertColumn(i++, _T("起始字节"), 0, 55);
	m_ctrl_list.InsertColumn(i++, _T("起始位"), 0, 50);
	m_ctrl_list.InsertColumn(i++, _T("位长度"), 0, 50);
	m_ctrl_list.InsertColumn(i++, _T("精度"), 0, 45);
	m_ctrl_list.InsertColumn(i++, _T("偏移量"), 0, 50);
	m_ctrl_list.InsertColumn(i++, _T("数据来源"), 0, 60);
	m_ctrl_list.InsertColumn(i++, _T("固定值"), 0, 50);
	m_ctrl_list.InsertColumn(i++, _T("说明"), 0, 300);
}


void HaideProtocolDialog::SetDetailRow(int index, FrameRuleObj *obj) {
	CString tmp;
	int i = 4;

	m_ctrl_list.SetItemText(index, i++, obj->id);
	m_ctrl_list.SetItemText(index, i++, obj->is_intel ? _T("INTEL") : _T("MOTOROLA"));
	tmp.Format(_T("%d"), obj->start_byte);
	m_ctrl_list.SetItemText(index, i++, tmp);
	tmp.Format(_T("%d"), obj->start_bite);
	m_ctrl_list.SetItemText(index, i++, tmp);
	tmp.Format(_T("%d"), obj->bite_len);
	m_ctrl_list.SetItemText(index, i++, tmp);
	tmp.Format(_T("%lg"), obj->ratio);
	m_ctrl_list.SetItemText(index, i++, tmp);
	tmp.Format(_T("%lg"), obj->offset);
	m_ctrl_list.SetItemText(index, i++, tmp);
	m_ctrl_list.SetItemText(index, i++, obj->str_from);
	if (obj->is_const) {
		m_ctrl_list.SetItemText(index, i++, obj->str_const);
	}
	else {
		m_ctrl_list.SetItemText(index, i++, _T(""));
	}
	m_ctrl_list.SetItemText(index, i++, obj->description1);
}


void HaideProtocolDialog::DeleteDetailColumn() {
	int i = 14;

	for (; i > 3; i--) {
		m_ctrl_list.DeleteColumn(i);
	}
}



void HaideProtocolDialog::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnSysCommand(nID, lParam);

 	if (nID == SC_MAXIMIZE || nID == SC_RESTORE) {
		SetCtrlRect();
	}
}


void HaideProtocolDialog::OnBnClickedButtonAnalyze()
{
	// TODO: 在此添加控件通知处理程序代码
	if (GetCurListItem() == -1) {
		MessageBox(_T("请选择分析项"), _T("提示"));
		return;
	}

	AnalyzeDialog *dlg = new AnalyzeDialog();
	dlg->m_list = &m_ctrl_list;
	dlg->Create(IDD_ANALYZE_DIALOG, this);
	dlg->ShowWindow(SW_SHOW);
}


//监控、记录数据
void HaideProtocolDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//if (GetCurListItem() == -1) {
	//	MessageBox(_T("请选择操作项"), _T("提示"));
	//	return;
	//}

	MonitorDialog *dlg = new MonitorDialog();
	dlg->m_list = &m_ctrl_list;
	dlg->Create(IDD_MONITOR_DIALOG, this);
	dlg->ShowWindow(SW_SHOW);
}
