// TabBatteryV.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "TabBatteryV.h"
#include "afxdialogex.h"


// TabBatteryV �Ի���

IMPLEMENT_DYNAMIC(TabBatteryV, CDialogEx)

TabBatteryV::TabBatteryV(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB_BATTERY_VOLTAGE_DIALOG, pParent)
{

}

TabBatteryV::~TabBatteryV()
{
}

void TabBatteryV::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TabBatteryV, CDialogEx)
END_MESSAGE_MAP()


// TabBatteryV ��Ϣ�������
