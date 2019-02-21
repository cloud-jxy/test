// TabWarnDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "TabWarnDialog.h"
#include "afxdialogex.h"


WarnInfo warns[] = {
	{ _T("�¶Ȳ��챨��"), 0, 0, 0 }
	,{ _T("��ظ��±���"), 0, 2, 0 }
	,{ _T("���ش���װ�����͹�ѹ����"), 0, 4, 0 }
	,{ _T("���ش���װ������Ƿѹ����"), 0, 6, 0 }

	,{ _T("SOC�ͱ���"), 1, 0, 0 }
	,{ _T("�����ع�ѹ����"), 1, 2, 0 }
	,{ _T("������Ƿѹ����"), 1, 4, 0 }
	,{ _T("SOC���߱���"), 1, 6, 0 }

	,{ _T("SOC���䱨��"), 2, 0, 0 }
	,{ _T("�ɳ�索�����ƥ�䱨��"), 2, 2, 0 }
	,{ _T("��ص���һ���Ա���"), 2, 4, 0 }
	,{ _T("��Ե����"), 2, 6, 0 }

	,{ _T("DC-DC�¶ȱ���"), 3, 0, 0 }
	,{ _T("�ƶ�ϵͳ����"), 3, 2, 0 }
	,{ _T("��������������¶ȱ���"), 3, 4, 0 }
	,{ _T("��ѹ����״̬����"), 7, 6, 0 }

	,{ _T("��������¶ȱ���"), 3, 6, 0 }
	,{ _T("��������¶ȱ���"), 5, 6, 0 }
	,{ _T("���ش���װ��װ�����͹���"), 4, 0, 0 }
};


// TabWarnDialog �Ի���

IMPLEMENT_DYNAMIC(TabWarnDialog, CDialogEx)

TabWarnDialog::TabWarnDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_WARN_DIALOG, pParent)
{

}

TabWarnDialog::~TabWarnDialog()
{
}

void TabWarnDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabWarnDialog, CDialogEx)
END_MESSAGE_MAP()


// TabWarnDialog ��Ϣ�������


BOOL TabWarnDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

int TabWarnDialog::ParseFrame(VCI_CAN_OBJ frame) {
	BYTE *data = frame.Data;
	int i = 0;
	int len = sizeof(warns) / sizeof(warns[0]);

	if (frame.ID != 0x182C7A70) {
		return 0;
	}

	for (i = 0; i < len; i++) {
		warns[i].level = (data[warns[i].byte_pos] >> warns[i].bite_pos) & 0x03;
	}

	return 0;
}
