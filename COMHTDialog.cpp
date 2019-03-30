// COMHTDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "COMHTDialog.h"
#include "afxdialogex.h" 


using namespace itas109;
using namespace std;

// CCOMHTDialog �Ի���

IMPLEMENT_DYNAMIC(CCOMHTDialog, CDialogEx)

CCOMHTDialog::CCOMHTDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COM_HT_DIALOG, pParent)
{
	m_count = 0;
	m_ArrayLen = CHAER_X_LEN;
	m_f = NULL;
}

CCOMHTDialog::~CCOMHTDialog()
{
	//free(m_x);
	//free(m_y);
	KillTimer(1);
	if (m_f) {
		fclose(m_f);
	}
}

void CCOMHTDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_chart);
}


BEGIN_MESSAGE_MAP(CCOMHTDialog, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CCOMHTDialog ��Ϣ�������

void CCOMHTDialog::OnCOMRecvHT(int h, int t) {
	HTSlot::OnCOMRecvHT(h, t);
	int index = m_count;
	int dataLen = m_count + 1;

	long ms = GetTickCount();	//ϵͳ��������ĺ�����

	if (m_count == 0) {
		m_timeFirst = ms;
	}

	m_count++;
	if (m_count > m_ArrayLen) {
		memcpy(m_oldX, m_x, sizeof(double) * m_ArrayLen);
		memcpy(m_oldY, m_y, sizeof(double) * m_ArrayLen);

		memcpy(m_x, m_oldX + 1, sizeof(double) * (m_ArrayLen - 1));
		memcpy(m_y, m_oldY + 1, sizeof(double) * (m_ArrayLen - 1));

		index = m_ArrayLen - 1;
		dataLen = m_ArrayLen;
	}

	double diff = ms - m_timeFirst;
	m_x[index] = diff / 1000;
	m_y[index] = 100 * (double)h / (double)t;

	writeToFile(h, t);
}


void CCOMHTDialog::OnCOMRecv() {
	HTSlot::OnCOMRecv();

}


BOOL CCOMHTDialog::OnInitDialog()
{
	__super::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, FALSE);

	// ����chart
	CChartMyTimeAxis *pBottomAxis = m_chart.CreateMyTimeAxis(CChartCtrl::BottomAxis);
	pBottomAxis->SetAutomatic(true);
	pBottomAxis->SetTickIncrement(false, 1);
	pBottomAxis->GetLabel()->SetText(_T("ʱ�䣨�룩"));

	CChartStandardAxis *pLeftAxis = m_chart.CreateStandardAxis(CChartCtrl::LeftAxis);
	pLeftAxis->SetMinMax(0, 100);
	pLeftAxis->SetAutomatic(false);
	pLeftAxis->GetLabel()->SetText(_T("��ѹ�ٷֱ�"));
	//pLeftAxis->SetAutomaticMode(CChartAxis::FullAutomatic);

	//m_chart.GetTitle()->AddString(_T("��ѹ"));

	SetTimer(1, 100, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CCOMHTDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == 1) {

		//WriteToFile();

		if (m_count == 0) {
			return;
		}

		// ˢ��chart
		m_chart.EnableRefresh(false);
		m_chart.RemoveAllSeries();

		CChartLineSerie *pLineSerie = m_chart.CreateLineSerie();
		pLineSerie->SetSeriesOrdering(poXOrdering);
		pLineSerie->AddPoints(m_x, m_y, (m_count > CHAER_X_LEN) ? CHAER_X_LEN : m_count);

		m_chart.GetLegend()->SetVisible(true);
		m_chart.EnableRefresh(true);
	}

	__super::OnTimer(nIDEvent);
}
