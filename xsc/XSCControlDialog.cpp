// ./xsc/XSCControlDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "XSCControlDialog.h"
#include "afxdialogex.h"
#include "../resource.h"
#include "../StaticItem.h"
#include "../StaticItemObj.h"

#define DEFAULT_VAL _T("")

StaticItemObj g_xscControl[] = {
	StaticItemObj(_T("����������ڳ�ˮ"), DEFAULT_VAL, _T("0x18F40200"), 0, 0, 1),
	StaticItemObj(_T("�������ϴ����"), DEFAULT_VAL, _T("0x18F40200"), 0, 1, 1),
	StaticItemObj(_T("�������������"), DEFAULT_VAL, _T("0x18F40200"), 0, 2, 1),
	StaticItemObj(_T("����������彵"), DEFAULT_VAL, _T("0x18F40200"), 0, 3, 1),
	StaticItemObj(_T("������к��ſ�"), DEFAULT_VAL, _T("0x18F40200"), 0, 4, 1),
	StaticItemObj(_T("������к��Ź�"), DEFAULT_VAL, _T("0x18F40200"), 0, 5, 1),
	StaticItemObj(_T("��߰�ȫ֧����λ"), DEFAULT_VAL, _T("0x18F40200"), 0, 6, 1),
	StaticItemObj(_T("�Ұ�ȫ֧����λ"), DEFAULT_VAL, _T("0x18F40200"), 0, 7, 1),
	StaticItemObj(_T("ˮ·����"), DEFAULT_VAL, _T("0x18F40200"), 1, 0, 1),
	StaticItemObj(_T("Һѹ�Ϳ���"), DEFAULT_VAL, _T("0x18F40200"), 1, 1, 1),
	StaticItemObj(_T("��ˮȱˮ����"), DEFAULT_VAL, _T("0x18F40200"), 1, 2, 1),
	StaticItemObj(_T("ˮ��ͣ������"), DEFAULT_VAL, _T("0x18F40200"), 1, 3, 1),
	StaticItemObj(_T("��ˮ����"), DEFAULT_VAL, _T("0x18F40200"), 1, 4, 1),
	StaticItemObj(_T("Һѹ��λ"), DEFAULT_VAL, _T("0x18F40200"), 1, 5, 1),
	StaticItemObj(_T("���¹���"), DEFAULT_VAL, _T("0x18F40200"), 1, 6, 1),
	StaticItemObj(_T("��ѹ���"), DEFAULT_VAL, _T("0x18F40200"), 1, 7, 1),
	StaticItemObj(_T("��������λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 0, 1),
	StaticItemObj(_T("���彵��λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 1, 1),
	StaticItemObj(_T("��������λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 2, 1),
	StaticItemObj(_T("���ڽ���λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 3, 1),
	StaticItemObj(_T("���ſ���λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 4, 1),
	StaticItemObj(_T("���Ź���λ"), DEFAULT_VAL, _T("0x18F40200"), 2, 5, 1),
	StaticItemObj(_T("ж��"), DEFAULT_VAL, _T("0x18F40201"), 0, 0, 1),
	StaticItemObj(_T("��������"), DEFAULT_VAL, _T("0x18F40202"), 0, 1, 1),
	StaticItemObj(_T("���彵��"), DEFAULT_VAL, _T("0x18F40203"), 0, 2, 1),
	StaticItemObj(_T("���ſ���"), DEFAULT_VAL, _T("0x18F40204"), 0, 3, 1),
	StaticItemObj(_T("���Źط�"), DEFAULT_VAL, _T("0x18F40205"), 0, 4, 1),
	StaticItemObj(_T("ǰ��ɨ������"), DEFAULT_VAL, _T("0x18F40206"), 0, 5, 1),
	StaticItemObj(_T("ǰ��ɨ�̽���"), DEFAULT_VAL, _T("0x18F40207"), 0, 6, 1),
	StaticItemObj(_T("ǰ��ɨ������"), DEFAULT_VAL, _T("0x18F40208"), 0, 7, 1),
	StaticItemObj(_T("ǰ��ɨ�̽���"), DEFAULT_VAL, _T("0x18F40209"), 1, 0, 1),
	StaticItemObj(_T("��ˢ����"), DEFAULT_VAL, _T("0x18F40210"), 1, 1, 1),
	StaticItemObj(_T("��ˢ����"), DEFAULT_VAL, _T("0x18F40211"), 1, 2, 1),
	StaticItemObj(_T("��������"), DEFAULT_VAL, _T("0x18F40212"), 1, 3, 1),
	StaticItemObj(_T("���ڽ���"), DEFAULT_VAL, _T("0x18F40213"), 1, 4, 1),
	StaticItemObj(_T("ǰ��ɨ��ת��"), DEFAULT_VAL, _T("0x18F40214"), 1, 5, 1),
	StaticItemObj(_T("ǰ��ɨ��ת��"), DEFAULT_VAL, _T("0x18F40215"), 1, 6, 1),
	StaticItemObj(_T("��ˢת��"), DEFAULT_VAL, _T("0x18F40216"), 1, 7, 1),
	StaticItemObj(_T("����ˮ����"), DEFAULT_VAL, _T("0x18F40217"), 2, 0, 1),
	StaticItemObj(_T("����ˮ����"), DEFAULT_VAL, _T("0x18F40218"), 2, 1, 1),
	StaticItemObj(_T("����ˮ����"), DEFAULT_VAL, _T("0x18F40219"), 2, 2, 1),
	StaticItemObj(_T("����ˮ����"), DEFAULT_VAL, _T("0x18F40220"), 2, 3, 1),
	StaticItemObj(_T("���ˮ��"), DEFAULT_VAL, _T("0x18F40221"), 2, 4, 1),
	StaticItemObj(_T("�ҳ�ˮ��"), DEFAULT_VAL, _T("0x18F40222"), 2, 5, 1),
	StaticItemObj(_T("���ڳ�ˮ"), DEFAULT_VAL, _T("0x18F40223"), 2, 6, 1),
	StaticItemObj(_T("���ڳ�ˮ"), DEFAULT_VAL, _T("0x18F40224"), 2, 7, 1),
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18F40225"), 3, 0, 1),
	StaticItemObj(_T("�ϸǿ���"), DEFAULT_VAL, _T("0x18F40226"), 3, 1, 1),
	StaticItemObj(_T("��ѹˮ��"), DEFAULT_VAL, _T("0x18F40227"), 3, 2, 1),
	StaticItemObj(_T("����ȡ����"), DEFAULT_VAL, _T("0x18F40228"), 3, 3, 1),
	StaticItemObj(_T("��·ж�ɷ�"), DEFAULT_VAL, _T("0x18F40229"), 3, 4, 1),
	StaticItemObj(_T("���ѹ��ˮ��"), DEFAULT_VAL, _T("0x18F40230"), 3, 5, 1),
	StaticItemObj(_T("�ҵ�ѹ��ˮ��"), DEFAULT_VAL, _T("0x18F40231"), 3, 6, 1),
	StaticItemObj(_T("��ѹ��ˮ��"), DEFAULT_VAL, _T("0x18F40232"), 3, 7, 1),
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18F40233"), 4, 0, 1),
	StaticItemObj(_T("��ˮת��"), DEFAULT_VAL, _T("0x18F40234"), 4, 1, 1),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18F40235"), 4, 2, 1),
	StaticItemObj(_T("��ѹˮ��"), DEFAULT_VAL, _T("0x18F40236"), 4, 3, 1),
	StaticItemObj(_T("������"), DEFAULT_VAL, _T("0x18F40237"), 4, 4, 1),
	StaticItemObj(_T("�����̵���"), DEFAULT_VAL, _T("0x18F40238"), 4, 5, 1),
	StaticItemObj(_T("�綯ˮ��"), DEFAULT_VAL, _T("0x18F40239"), 4, 6, 1),
	StaticItemObj(_T("������Ȧ"), DEFAULT_VAL, _T("0x18F40240"), 4, 7, 1),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18F40241"), 5, 0, 1),
	StaticItemObj(_T("��ͷ��"), DEFAULT_VAL, _T("0x18F40242"), 5, 1, 1),
	StaticItemObj(_T("����"), DEFAULT_VAL, _T("0x18F40243"), 5, 2, 1),
	StaticItemObj(_T("Ϩ���ŷ�"), DEFAULT_VAL, _T("0x18F40244"), 5, 3, 1)
};

// CXSCControlDialog �Ի���

IMPLEMENT_DYNAMIC(CXSCControlDialog, CMyTabDialog)

CXSCControlDialog::CXSCControlDialog(CWnd* pParent /*=NULL*/)
	: CMyTabDialog(IDD_EMPTY_DIALOG, pParent)
{
	m_objs = g_xscControl;
	m_objCount = sizeof(g_xscControl) / sizeof(g_xscControl[0]);
	m_leftW = 175;
	m_rightW = 100;
}

CXSCControlDialog::~CXSCControlDialog()
{
}

void CXSCControlDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CXSCControlDialog, CMyTabDialog)
END_MESSAGE_MAP()


// CXSCControlDialog ��Ϣ�������
