// XSCBaseDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "../test.h"
#include "XSCBaseDialog.h"
#include "afxdialogex.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

//typedef int (*PtrFuncToString)(double);

static StaticItemObj g_xscBase[] = {
	StaticItemObj(_T("�ͺ�"), DEFAULT_VAL, _T("0x18f40001"), 0, 0, 128, NULL),
	StaticItemObj(_T("ϵ��"), DEFAULT_VAL, _T("0x18f40000"), 0, 0, 2, (PtrFuncToString)(&CXSCBaseDialog::XileiToString)),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18f40000"), 0, 2, 6, (PtrFuncToString)(&CXSCBaseDialog::CheXingToString)),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18f40000"), 2, 0, 8, (PtrFuncToString)(&CXSCBaseDialog::DipanToString)),
	StaticItemObj(_T("��������"), DEFAULT_VAL, _T("0x18f40000"), 3, 0, 8, (PtrFuncToString)(&CXSCBaseDialog::FujiToString)),
	StaticItemObj(_T("��ʾ��"), DEFAULT_VAL, _T("0x18f40000"), 4, 0, 4, (PtrFuncToString)(&CXSCBaseDialog::ScreenToString)),
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18f40000"), 4, 4, 4, (PtrFuncToString)(&CXSCBaseDialog::ControlToString)),
	StaticItemObj(_T("ģ��1"), DEFAULT_VAL, _T("0x18f40000"), 5, 0, 4, (PtrFuncToString)(&CXSCBaseDialog::Module1ToString)),
	StaticItemObj(_T("ģ��2"), DEFAULT_VAL, _T("0x18f40000"), 5, 4, 4, (PtrFuncToString)(&CXSCBaseDialog::Module2ToString)),
	StaticItemObj(_T("����������"), DEFAULT_VAL, _T("0x18f40000"), 6, 0, 4, (PtrFuncToString)(&CXSCBaseDialog::YuyinToString)),
	StaticItemObj(_T("ң��"), DEFAULT_VAL, _T("0x18f40000"), 6, 4, 4, (PtrFuncToString)(&CXSCBaseDialog::YaokongToString)),
	StaticItemObj(_T("���"), DEFAULT_VAL, _T("0x18f40000"), 7, 0, 8, (PtrFuncToString)(&CXSCBaseDialog::DianjiToString)),
	StaticItemObj(_T("��ʾ������汾��"), DEFAULT_VAL, _T("0x18f40003"), 0, 0, 16, (PtrFuncToString)(&CXSCBaseDialog::ValueToString)),
	StaticItemObj(_T("����������汾��"), DEFAULT_VAL, _T("0x18f40003"), 2, 0, 16, (PtrFuncToString)(&CXSCBaseDialog::ValueToString)),
	StaticItemObj(_T("��ʾ���������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 0, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��ʾ����ģ��1ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 1, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��ʾ����ģ��2ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 2, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��ʾ��������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 3, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��ʾ����ң��ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 4, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��ʾ���븱������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 5, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��ʾ���복���ն�ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 6, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��ʾ�������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 4, 7, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��������ģ��1ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 0, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��������ģ��2ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 1, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("������������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 2, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("��������ң��ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 3, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("�������븱������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 4, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("�������복���ն�ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 5, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
	StaticItemObj(_T("�����������ͨѶ״̬"), DEFAULT_VAL, _T("0x18f40003"), 5, 6, 1, (PtrFuncToString)(&CXSCBaseDialog::OpenOrClose)),
};


// CXSCBaseDialog �Ի���

IMPLEMENT_DYNAMIC(CXSCBaseDialog, CMyTabDialog)

CXSCBaseDialog::CXSCBaseDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscBase;
	m_objCount = sizeof(g_xscBase) / sizeof(g_xscBase[0]);
	m_leftW = 175;
	m_rightW = 120;
}

CXSCBaseDialog::~CXSCBaseDialog()
{
}

void CXSCBaseDialog::DoDataExchange(CDataExchange* pDX)
{
	CMyTabDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCBaseDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCBaseDialog ��Ϣ�������


BOOL CXSCBaseDialog::OnInitDialog()
{
	CMyTabDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


CString CXSCBaseDialog::OpenOrClose(double val) {
	if (val == 0) {
		return _T("�ر�");
	}
	else if (val == 1) {
		return _T("����");
	}
	else {
		return _T("�����쳣");
	}
}


CString CXSCBaseDialog::XileiToString(double val) {
	CString alls[] = { _T("ȼ��ϵ��"), _T("���綯"), _T("��Ȼ��ϵ��"), _T("Ԥ��") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}


CString CXSCBaseDialog::CheXingToString(double val) {
	//����Ͱ��ϴ����4.��װжʽ��������5.��������6.��ѹ��ϴ����7.��ѹ��ϴ����8.�ͳ�����9.�����жʽ��������10.·��������11.�๦���ֳ�����12.ɨ·����
	CString alls[] = {
		_T("��"), _T("ɨ·��"), _T("ϴɨ��"), _T("����Ͱ��ϴ��"),
		_T("������"), _T("��ѹ��ϴ��"), _T("��ѹ��ϴ��") ,_T("�ͳ���"),
		_T("�����жʽ������"), _T("·������"), _T("�๦���ֳ���"), _T("ɨ·��")
	};

	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}


int CXSCBaseDialog::ParseFrame(VCI_CAN_OBJ frame) {
	TRACE("CXSCBaseDialog::ParseFrame\n");
	CMyTabDialog::ParseFrame(frame);
	BOOL isDebug;

#ifdef DEBUG
	isDebug = TRUE;
#else
	isDebug = FALSE;
#endif

	if (frame.ID == 0x18f40001) {
		memcpy(m_szXinghao, frame.Data, 8);
		CString tmp;
		tmp.Format(_T("%s"), m_szXinghao);
		CStaticItem *item = (CStaticItem *)g_xscBase[0].m_pParam;
		item->m_ctrlValue.SetWindowText(tmp);
	}
	else if (frame.ID == 0x18f4002) {
		memcpy(m_szXinghao + 8, frame.Data, 8);
		CString tmp;
		tmp.Format(_T("%s"), m_szXinghao);
		CStaticItem *item = (CStaticItem *)g_xscBase[0].m_pParam;
		item->m_ctrlValue.SetWindowText(tmp);
	}

	return 0;
}

// 0���ޣ�1.���磻2.������3.һ����5.������
CString CXSCBaseDialog::DipanToString(double val) {
	CString alls[] = {_T("��"), _T("����"), _T("����"), _T("һ��"), _T("����")};
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	} else {
		return alls[(int)val];
	}
}

// 0~255��0���ޣ�1�����壻2�����壻3�����4������˹
CString CXSCBaseDialog::FujiToString(double val) {
	CString alls[] = { _T("��"), _T("����"), _T("����"), _T("���"), _T("����˹") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15��0:�ޣ�1���γϣ�2�����ˣ�3:˶����4���Ȱ�����5��ɭ��
CString CXSCBaseDialog::ScreenToString(double val) {
	CString alls[] = { _T("��"), _T("�γ�"), _T("����"), _T("˶��"), _T("�Ȱ���"), _T("ɭ��") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15��0:�ޣ�1���γϣ�2�����ˣ�3:˶����4���Ȱ�����5��ɭ��
CString CXSCBaseDialog::ControlToString(double val) {
	CString alls[] = { _T("��"), _T("�γ�"), _T("����"), _T("˶��"), _T("�Ȱ���"), _T("ɭ��") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15��0:�ޣ�1���γϣ�2�����ˣ�3:˶����4���Ȱ�����5��ɭ��
CString CXSCBaseDialog::Module1ToString(double val) {
	CString alls[] = { _T("��"), _T("�γ�"), _T("����"), _T("˶��"), _T("�Ȱ���"), _T("ɭ��") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15��0:�ޣ�1���γϣ�2�����ˣ�3:˶����4���Ȱ�����5��ɭ��
CString CXSCBaseDialog::Module2ToString(double val) {
	CString alls[] = { _T("��"), _T("�γ�"), _T("����"), _T("˶��"), _T("�Ȱ���"), _T("ɭ��") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15��0:�ޣ�1���γϣ�2�����ˣ�3:˶����4���Ȱ�����5��ɭ��
CString CXSCBaseDialog::YuyinToString(double val) {
	CString alls[] = { _T("��"), _T("�γ�"), _T("����"), _T("˶��"), _T("�Ȱ���"), _T("ɭ��") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15��0:�ޣ�1���γϣ�2�����ˣ�3:˶����4���Ȱ�����5��ɭ��
CString CXSCBaseDialog::YaokongToString(double val) {
	CString alls[] = { _T("��"), _T("�γ�"), _T("����"), _T("˶��"), _T("�Ȱ���"), _T("ɭ��") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}

// 0~15��0:�ޣ�1���γϣ�2�����ˣ�3:˶����4���Ȱ�����5��ɭ��
CString CXSCBaseDialog::DianjiToString(double val) {
	CString alls[] = { _T("��"), _T("�γ�"), _T("����"), _T("˶��"), _T("�Ȱ���"), _T("ɭ��") };
	int len = sizeof(alls) / sizeof(alls[0]);

	if (val < 0 || val >= len) {
		return _T("�����쳣");
	}
	else {
		return alls[(int)val];
	}
}
