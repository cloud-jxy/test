// ./xsc/XSCYuyinDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XSCYuyinDialog.h"
#include "afxdialogex.h"
#include "../resource.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

static StaticItemObj g_xscYuyin[] = {
	StaticItemObj(_T("�������������"), DEFAULT_VAL, _T("0x0C000003"), 0, 0, 2, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������ת�٣���λ��"), DEFAULT_VAL, _T("0x0C000003"), 1, 0, 8, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������ת�٣���λ��"), DEFAULT_VAL, _T("0x0C000003"), 2, 0, 8, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������ת��"), DEFAULT_VAL, _T("0x0CF00400"), 4, 0, 16, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("ˮ��"), DEFAULT_VAL, _T("0x18FEEE00"), 0, 0, 8, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("�����¶�"), DEFAULT_VAL, _T("0x18FEEE00"), 2, 0, 16, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����ѹ��"), DEFAULT_VAL, _T("0x18FEEF00"), 3, 0, 8, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("Ԥ�ȵ�״̬"), DEFAULT_VAL, _T("0x18FEE400"), 3, 0, 2, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����ѹ���ź�"), DEFAULT_VAL, _T("0x18FE6800"), 3, 2, 2, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������ע��"), DEFAULT_VAL, _T("0x1911FF14"), 0, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����ת�䣬��ע�ⰲȫ"), DEFAULT_VAL, _T("0x1911FF14"), 0, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��ص�������15%������������ɨ��ҵ"), DEFAULT_VAL, _T("0x1911FF14"), 0, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��ص�������20%����ע��"), DEFAULT_VAL, _T("0x1911FF14"), 0, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��ع��ϣ������"), DEFAULT_VAL, _T("0x1911FF14"), 0, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������ϣ������"), DEFAULT_VAL, _T("0x1911FF14"), 0, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("���߿��������ϣ������"), DEFAULT_VAL, _T("0x1911FF14"), 0, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��ѹ����"), DEFAULT_VAL, _T("0x1911FF14"), 0, 7, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��ȫ֧��δ���£����岻���½�"), DEFAULT_VAL, _T("0x1911FF14"), 1, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����δ�������벻Ҫ��������"), DEFAULT_VAL, _T("0x1911FF14"), 1, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������������ע�ⰲȫ"), DEFAULT_VAL, _T("0x1911FF14"), 1, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("�����½�����ע�ⰲȫ"), DEFAULT_VAL, _T("0x1911FF14"), 1, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("���ſ�������ע�ⰲȫ"), DEFAULT_VAL, _T("0x1911FF14"), 1, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("���Źرգ���ע�ⰲȫ"), DEFAULT_VAL, _T("0x1911FF14"), 1, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��������ˮ�¹��ߣ�������ͣ�����"), DEFAULT_VAL, _T("0x1911FF14"), 2, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����������ȴҺλ�ͣ�������ͣ�����"), DEFAULT_VAL, _T("0x1911FF14"), 2, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������������ѹ�����ϣ�������ͣ�����"), DEFAULT_VAL, _T("0x1911FF14"), 2, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��������������ϣ�������ͣ�����"), DEFAULT_VAL, _T("0x1911FF14"), 2, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("�����������٣��뽵��ת��"), DEFAULT_VAL, _T("0x1911FF14"), 2, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("���������������"), DEFAULT_VAL, _T("0x1911FF14"), 2, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("�����������������У���ȴ�"), DEFAULT_VAL, _T("0x1911FF14"), 2, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��ˮ���ѿ������뼰ʱ�ر�"), DEFAULT_VAL, _T("0x1911FF14"), 3, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("Һѹ�ͳ���բ���رգ�������������"), DEFAULT_VAL, _T("0x1911FF14"), 3, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("Һѹ���¹��ߣ�������ͣ�����"), DEFAULT_VAL, _T("0x1911FF14"), 3, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("Һѹϵͳй¶��������ͣ�����"), DEFAULT_VAL, _T("0x1911FF14"), 3, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("ˮ·բ���رգ���ѹˮ�ò�������"), DEFAULT_VAL, _T("0x1911FF14"), 3, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��ˮ��ˮλ�ͣ����ˮ"), DEFAULT_VAL, _T("0x1911FF14"), 3, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("ˮ��ˮλ���ͣ�������ϴ��ҵ"), DEFAULT_VAL, _T("0x1911FF14"), 3, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��ˮ����������ֹͣ��ҵ"), DEFAULT_VAL, _T("0x1911FF14"), 3, 7, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��ҵ�У���������"), DEFAULT_VAL, _T("0x1911FF14"), 4, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����Ͱ��������ע��"), DEFAULT_VAL, _T("0x1911FF14"), 4, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����Ͱ�½�����ע��"), DEFAULT_VAL, _T("0x1911FF14"), 4, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����Ͱ������ע��"), DEFAULT_VAL, _T("0x1911FF14"), 4, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����Ͱ�أ���ע��"), DEFAULT_VAL, _T("0x1911FF14"), 4, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������ָʾ����������"), DEFAULT_VAL, _T("0x1911FF14"), 4, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������������ע��"), DEFAULT_VAL, _T("0x1911FF14"), 4, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��·"), DEFAULT_VAL, _T("0x1911FF14"), 6, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("�����Ľ�ɽ��"), DEFAULT_VAL, _T("0x1911FF14"), 6, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("�����½��õط�"), DEFAULT_VAL, _T("0x1911FF14"), 6, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("���տ���"), DEFAULT_VAL, _T("0x1911FF14"), 6, 3, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("���ˮ�˴���"), DEFAULT_VAL, _T("0x1911FF14"), 6, 4, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("�����"), DEFAULT_VAL, _T("0x1911FF14"), 6, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����ˮ��"), DEFAULT_VAL, _T("0x1911FF14"), 6, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("ˮ�ߵİ�������"), DEFAULT_VAL, _T("0x1911FF14"), 6, 7, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("̫����죬ë��ϯ����"), DEFAULT_VAL, _T("0x1911FF14"), 7, 0, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("������֮��"), DEFAULT_VAL, _T("0x1911FF14"), 7, 1, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��������ɽ"), DEFAULT_VAL, _T("0x1911FF14"), 7, 2, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("ѭ������"), DEFAULT_VAL, _T("0x1911FF14"), 7, 5, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("��������"), DEFAULT_VAL, _T("0x1911FF14"), 7, 6, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose)),
	StaticItemObj(_T("����ָ������ʹ��"), DEFAULT_VAL, _T("0x1911FF14"), 7, 7, 1, (PtrFuncToString)(&CXSCYuyinDialog::OpenOrClose))
};

// CXSCYuyinDialog �Ի���

IMPLEMENT_DYNAMIC(CXSCYuyinDialog, CMyTabDialog)

CXSCYuyinDialog::CXSCYuyinDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscYuyin;
	m_objCount = sizeof(g_xscYuyin) / sizeof(g_xscYuyin[0]);
	m_leftW = 250;
	m_rightW = 60;
}

CXSCYuyinDialog::~CXSCYuyinDialog()
{
}

void CXSCYuyinDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCYuyinDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCYuyinDialog ��Ϣ�������
