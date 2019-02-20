// TabCarDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "TabCarDialog.h"
#include "afxdialogex.h"


// TabCarDialog �Ի���

IMPLEMENT_DYNAMIC(TabCarDialog, CDialogEx)

TabCarDialog::TabCarDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_CAR_DIALOG, pParent)
	, m_str_speed(_T(""))
	, m_str_mil(_T(""))
	, m_str_v(_T(""))
	, m_str_i(_T(""))
	, m_str_journey_speedup(_T(""))
	, m_str_journy_barke(_T(""))
	, m_str_dcdc_status(_T(""))
{
	m_str_run_mode = _T("����");	//�̶�ֵ������
}

TabCarDialog::~TabCarDialog()
{
}

void TabCarDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAR_STATUS, m_str_car_status);
	DDX_Text(pDX, IDC_EDIT_CHARGING_STATUS, m_str_charging_status);
	DDX_Text(pDX, IDC_EDIT_DRIVER_STATUS, m_str_driver_status);
	DDX_Text(pDX, IDC_EDIT_BRAKING_STATUS, m_str_braking_status);
	DDX_Text(pDX, IDC_EDIT_RUN_MODE, m_str_run_mode);
	DDX_Text(pDX, IDC_EDIT_SPEED, m_str_speed);
	DDX_Text(pDX, IDC_EDIT_GEARS, m_str_gears);
	DDX_Text(pDX, IDC_EDIT_SOC, m_str_soc);
	DDX_Text(pDX, IDC_EDIT_RESISTANCE, m_str_r);
	DDX_Text(pDX, IDC_EDIT_MIL, m_str_mil);
	DDX_Text(pDX, IDC_EDIT1_TOTAL_V, m_str_v);
	DDX_Text(pDX, IDC_EDIT1_TOTAL_I, m_str_i);
	DDX_Text(pDX, IDC_EDIT_JOURNEY_SPEEDUP, m_str_journey_speedup);
	DDX_Text(pDX, IDC_EDIT1_JOURNEY_BRAKE, m_str_journy_barke);
	DDX_Text(pDX, IDC_EDIT1_DCDC_STATUS, m_str_dcdc_status);
}


BEGIN_MESSAGE_MAP(TabCarDialog, CDialogEx)
END_MESSAGE_MAP()


int TabCarDialog::ParseFrame(VCI_CAN_OBJ frame) {
	int ID = frame.ID;
	BYTE *data = frame.Data;
	if (ID == 0x18027A70) {
		/*
		����״̬
		��ʼ�ֽ�7 ��ʼλ0 ����2
		0����1Ϩ��2�쳣3��Ч
		*/
		BYTE car_status = data[7] & 0x03;
		CString str_status[] = {_T("����"), _T("Ϩ��"), _T("�쳣"), _T("��Ч")};

		m_str_car_status = str_status[car_status];

		/*
		��λ��Ϣ
		1 0 2 0 0
		0��ǰ����λ��Ϣ��1������Ϣ��2פ���ƶ��źţ�3�ƶ�̤���ź�
		*/
		BYTE val = data[1] & 0x03;
		CString str_val[] = { _T("ǰ������Ϣ"), _T("������Ϣ"), _T("פ���ƶ���Ϣ"), _T("�ƶ�̤����Ϣ") };
		m_str_gears = str_val[val];

		/*
		����̤���г�ֵ
		2 0 8 1% 0
		*/
		val = data[2];
		m_str_journey_speedup.Format("%d", val);

		/*
		�ƶ�̤��״̬
		1 2 2 0 0
		0 off;1 on
		*/
		val = (data[1] >> 2) & 0x0c;
		m_str_journy_barke.Format("%d", val);
	}
	else if (ID == 0x18047A70) {
		/*
		���״̬
		4 0 8 1% 0% (��������ʼ�ֽ� ��ʼλ λ���� ���� ƫ��������ͬ���ٽ���)
		0 ͣ����磬 1��ʻ��� 2δ���״̬ 3������
		*/
		BYTE status = data[4] & 0xff;
		CString str_status[] = { _T("ͣ�����"), _T("��ʻ���"), _T("δ���״̬"), _T("������") };

		if (status <= 3) {
			m_str_braking_status = str_status[status];
		}
		else {
			m_str_braking_status = _T("�����쳣");
		}
	}
	else if (ID == 0x18037A70) {
		/*
		����
		1 0 16 0.00390625 0
		ȡֵ��Χ��0-250.996km/h; 0xff00 error; 0xffff not availbale
		*/
		BYTE l = data[1];
		BYTE h = data[2];

		if (l == 0x00 && h == 0xff) {
			m_str_speed = _T("error");
		}
		else if (l == 0xff && h == 0xffff) {
			m_str_speed = _T("not availbale");
		}
		else {
			double speed = (double)0.00390625 * (l + h << 8) + 0;
			m_str_speed.Format("%.3lf", speed);
		}
	}
	else if (ID == 0x18017A70) {
		/*
			�ۼ������
			0 0 32 100m 0
		*/

		// 0.1: 100m = 0.1km
		int val = (data[0] + data[1] << 8 + data[2] << 16 + data[3] << 24 ) * 0.1 + 0;
		m_str_mil.Format("%d", val);
	}
	else if (ID == 0x18057A70) {
		/*
		�ܵ�ѹ
		2 0 16 0.1V 0
		*/
		int val = (data[2] + data[3] << 8) * 0.1 + 0;
		m_str_v.Format("%d", val);

		/*
		SOC
		1 0 8 1% 0
		*/
		val = data[1];
		m_str_soc.Format("%d", val);
	}
	else if (ID = 0x18067A70) {
		/*
		�ܵ���
		0 0 16 1 -500
		*/
		int val = (data[0] + data[1] << 8) * 1 - 500;
		m_str_i.Format("%d", val);
	}
	else if (ID == 0x18097A70) {
		/*
		DC-DC״̬
		1 2 2 0 0
		0 standby,1 work, 2 failure 3 reserved
		*/
		BYTE val = (data[1] >> 2) & 0x0c;
		CString str_val[] = { _T("����"), _T("����"), _T("ʧ��"), _T("����")};
		m_str_dcdc_status = str_val[val];
	}
	else if (ID == 0x18077A70) {
		/*
		��Ե����
		1 0 16 1 0
		65534 ��ʾ����ֵ>65533
		65535 ����NA ��Ч��ֵ
		*/
		int val = data[1] + data[2] << 8;

		if (val == 65534) {
			m_str_r = _T("����65533");
		}
		else if (val == 65535){
			m_str_r = _T("��Ч��ֵ");
		}
		else {
			m_str_r.Format("%d", val);
		}
	}

	UpdateData(false);

	return 0;
}

// TabCarDialog ��Ϣ�������
