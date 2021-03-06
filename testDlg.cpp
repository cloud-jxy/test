// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "uTimeCounter.h"
#include "InfoDialog.h"
#include "api.h"
#include "ParseDialog.h"
#include <set>
#include "CSerialPort\SerialPort.h"
#include "COMHTDialog.h"
#include "CSerialPort\EnumSerial.h"

using namespace itas109;
using namespace std;


//FILE *f = fopen("1.log", "w");
extern set<CParseDialog *> g_listeners;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
	, m_strCOMPort(_T("COM1"))
{
	//{{AFX_DATA_INIT(CTestDlg)
	m_EditSendData = _T("");
	m_EditSendFrmID = _T("");
	m_EditCode = _T("");
	m_EditMask = _T("");
	m_EditTiming0 = _T("");
	m_EditTiming1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_connect=0;
	m_cannum=0;
	m_devtype=VCI_USBCAN2;

	m_info_dialog = new CInfoDialog();
	m_info_dialog->Create(IDD_INFO_DIALOG, this);
	m_info_dialog->m_p_parent_dlg = this;

	m_haide_protocol_dialog = new HaideProtocolDialog();
	m_haide_protocol_dialog->Create(IDD_HAIDE_PROTOCOL_DIALOG, this);
	m_haide_protocol_dialog->m_p_parent_dlg = this;

	m_navi_dialog = new NavigationDialog();
	m_navi_dialog->Create(IDD_NAVIGATION_DIALOG, this);
	m_navi_dialog->m_p_parent_dlg = this;
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
	DDX_Control(pDX, IDC_COMBO_MODE, m_ComboMode);
	DDX_Control(pDX, IDC_COMBO_FILTERTYPE, m_ComboFilterType);
	DDX_Control(pDX, IDC_COMBO_CANIND, m_ComboCANInd);
	DDX_Control(pDX, IDC_COMBO_DEV_TYPE, m_ComboDevType);
	DDX_Control(pDX, IDC_COMBO_INDEX, m_ComboIndex);
	DDX_Control(pDX, IDC_LIST_INFO, m_ListInfo);
	DDX_Control(pDX, IDC_COMBO_SENDTYPE, m_ComboSendType);
	DDX_Control(pDX, IDC_COMBO_SENDFRAMETYPE, m_ComboSendFrmType);
	DDX_Control(pDX, IDC_COMBO_SENDFRAMEFORMAT, m_ComboSendFrmFmt);
	DDX_Text(pDX, IDC_EDIT_SENDDATA, m_EditSendData);
	DDX_Text(pDX, IDC_EDIT_SENDFRAMEID, m_EditSendFrmID);
	DDX_Text(pDX, IDC_EDIT_CODE, m_EditCode);
	DDX_Text(pDX, IDC_EDIT_MASK, m_EditMask);
	DDX_Text(pDX, IDC_EDIT_TIMING0, m_EditTiming0);
	DDX_Text(pDX, IDC_EDIT_TIMING1, m_EditTiming1);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_CHECK1, m_cbx_parse);
	DDX_Control(pDX, IDC_COMBO_BAUDRATE, m_cbxBaudrate);
	DDX_Control(pDX, IDC_BUTTON_COM_OPEN, m_btnCOMOpen);
	DDX_CBString(pDX, IDC_COMBO_COM_PORT, m_strCOMPort);
	DDX_Control(pDX, IDC_COMBO_COM_PORT, m_cbxCOM);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, OnButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_STARTCAN, OnButtonStartcan)
	ON_BN_CLICKED(IDC_BUTTON_RESETCAN, OnButtonResetcan)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_COMMAND(ID_MENU_REFRESH, OnMenuRefresh)
	ON_CBN_SELCHANGE(IDC_COMBO_DEV_TYPE, OnSelchangeComboDevType)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CHECK1, &CTestDlg::OnBnClickedCheck1)

	ON_MESSAGE(WM_INFO_DIALOG_CLOSE, &CTestDlg::OnInfoDialogClose)
	ON_MESSAGE(WM_MY_PARSE_FRAME, &CTestDlg::OnParseFrame)
	ON_BN_CLICKED(IDC_CHECK2, &CTestDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CTestDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_CHECK3, &CTestDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BUTTON_COM_OPEN, &CTestDlg::OnBnClickedButtonComOpen)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO_COM_PORT, &CTestDlg::OnCbnSelchangeComboComPort)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

LRESULT CTestDlg::OnInfoDialogClose(WPARAM w, LPARAM l) {
	m_cbx_parse.SetCheck(false);
	UpdateData(false);
	return 0;
}

LRESULT CTestDlg::OnParseFrame(WPARAM w, LPARAM l) {
	VCI_CAN_OBJ *frame = (VCI_CAN_OBJ *)l;
	ParseFrame(*frame);
	return 0;
}

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	int i = 0;
	for (i = 0; i < SP_NUM; i++) {
		CString tmp;
		tmp.Format(_T("COM%d"), i + 1);
		m_cbxCOM.AddString(tmp);
		m_arraySp[i].init(tmp.GetBuffer(0), 115200);
		m_arrayCOMDlg[i] = NULL;
	}

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_ComboSendType.SetCurSel(2);
	m_ComboSendFrmType.SetCurSel(1);
	m_ComboSendFrmFmt.SetCurSel(0);
	
	m_EditSendFrmID="00000080";
	m_EditSendData="01 02 03 04 05 06 07 08 ";
	
	CString str;
	
	str = "USBCAN-I";
	m_ComboDevType.AddString(str);

	str = "USBCAN-II";
	m_ComboDevType.AddString(str);

	str = "USBalyst-II";
	m_ComboDevType.AddString(str);

	str = "PCICAN-9820";
	m_ComboDevType.AddString(str);
	
	str = "PCICAN-9840";
	m_ComboDevType.AddString(str);

	str = "iCANEC-I";
	m_ComboDevType.AddString(str);

	str = "104plusCAN-II";
	m_ComboDevType.AddString(str);

	// 设置波特率
	m_cbxBaudrate.AddString(_T("5Kbps"));
	m_cbxBaudrate.AddString(_T("10Kbps"));
	m_cbxBaudrate.AddString(_T("20Kbps"));
	m_cbxBaudrate.AddString(_T("40Kbps"));
	m_cbxBaudrate.AddString(_T("50Kbps"));
	m_cbxBaudrate.AddString(_T("80Kbps"));
	m_cbxBaudrate.AddString(_T("100Kbps"));
	m_cbxBaudrate.AddString(_T("125Kbps"));
	m_cbxBaudrate.AddString(_T("200Kbps"));
	m_cbxBaudrate.AddString(_T("250Kbps"));
	m_cbxBaudrate.AddString(_T("400Kbps"));
	m_cbxBaudrate.AddString(_T("500Kbps"));
	m_cbxBaudrate.AddString(_T("666Kbps"));
	m_cbxBaudrate.AddString(_T("800Kbps"));
	m_cbxBaudrate.AddString(_T("1000Kbps"));

	m_cbxBaudrate.SetCurSel(11);

	for( i=0;i<8;i++)
	{
		str.Format("%d",i);
		m_ComboIndex.AddString(str);
	}

	for( i=0;i<2;i++)
	{
		str.Format("%d",i);
		m_ComboCANInd.AddString(str);
	}
	
	m_EditCode="00000000";
	m_EditMask="ffffffff";
	m_EditTiming0="00";
	m_EditTiming1="1C";
	m_ComboDevType.SetCurSel(1);
	m_ComboIndex.SetCurSel(0);
	m_ComboCANInd.SetCurSel(0);
	m_ComboFilterType.SetCurSel(0);
	m_ComboMode.SetCurSel(0);
	
	UpdateData(false);
	InitializeCriticalSection(&m_Section);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	int connect=m_connect;
	m_connect=0;
	if(connect)
	{
		Sleep(500);		
		VCI_CloseDevice(m_devtype,m_devind);
	}
	DeleteCriticalSection(&m_Section);
	CDialog::OnCancel();
}

void CTestDlg::OnOK() 
{
	// TODO: Add extra validation here
	int connect=m_connect;
	m_connect=0;
	Sleep(100);
	if(connect)
		VCI_CloseDevice(m_devtype,m_devind);
	
	DeleteCriticalSection(&m_Section);
	CDialog::OnOK();
}

void CTestDlg::test() {
	int nDeviceType = 4;
	int nDeviceInd = 0;
	int nCANInd = 1;
	int nReserved = 0;

	VCI_INIT_CONFIG init_config;
	VCI_ERR_INFO err_info;
	DWORD dwRel;

	memset(&init_config, 0, sizeof(VCI_INIT_CONFIG));
	memset(&err_info, 0, sizeof(VCI_ERR_INFO));

	dwRel = VCI_OpenDevice(nDeviceType, nDeviceInd, nReserved);
	if (dwRel != STATUS_OK)
	{
		MessageBox("open fail!", "Warning", MB_OK | MB_ICONQUESTION);
		return;
	}

	init_config.AccCode = 0;     //验收码
	init_config.AccMask = 0xffffffff;     //屏蔽码
	init_config.Filter = 1;    //过滤方式
	init_config.Mode = 0;      //模式
	init_config.Timing0 = 0;    //定时器0
	init_config.Timing1 = 0x1c;    //定时器1

	dwRel = VCI_InitCAN(nDeviceType, nDeviceInd, nCANInd, &init_config);
	if (dwRel == STATUS_ERR)
	{
		dwRel = VCI_ReadErrInfo(nDeviceType, nDeviceInd, nCANInd, &err_info);

		VCI_CloseDevice(nDeviceType, nDeviceInd);
		MessageBox("init fail!", "Warning", MB_OK | MB_ICONQUESTION);
		return;
	}
}

void CTestDlg::OnButtonConnect() 
{
	if (0) {
		test();
		return;
	}

	// TODO: Add your control notification handler code here
	if(m_connect==1)
	{
		m_connect=0;
		Sleep(500);
		GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText("打开");
		VCI_CloseDevice(m_devtype,m_devind);
		return;
	}

	VCI_INIT_CONFIG init_config;
	int index,filtertype,mode,cannum;
	CString strcode,strmask,strtiming0,strtiming1,strtmp;
	char szcode[20],szmask[20],sztiming0[20],sztiming1[20];
	unsigned char sztmp[4];
	DWORD code,mask,timing0,timing1;


	
	UpdateData(true);
	index=m_ComboIndex.GetCurSel();
	filtertype=m_ComboFilterType.GetCurSel();
	mode=m_ComboMode.GetCurSel();
	cannum=m_ComboCANInd.GetCurSel();
	strcode=m_EditCode;
	strmask=m_EditMask;
	strtiming0=m_EditTiming0;
	strtiming1=m_EditTiming1;
	UpdateData(false);
	
	strtmp=strcode;
	strcode.Format("%08s",strtmp);
	strtmp=strmask;
	strmask.Format("%08s",strtmp);
	strtmp=strtiming0;
	strtiming0.Format("%02s",strtmp);
	strtmp=strtiming1;
	strtiming1.Format("%02s",strtmp);
	
	strcpy(szcode,(LPCTSTR)strcode);
	strcpy(szmask,(LPCTSTR)strmask);
	strcpy(sztiming0,(LPCTSTR)strtiming0);
	strcpy(sztiming1,(LPCTSTR)strtiming1);
	
	if(strtodata((unsigned char*)szcode,sztmp,4,0)!=0)
	{
		MessageBox("验收码格式错误!","Warning",MB_OK|MB_ICONQUESTION);
		return;
	}
	code=(((DWORD)sztmp[0])<<24)+(((DWORD)sztmp[1])<<16)+(((DWORD)sztmp[2])<<8)+
		((DWORD)sztmp[3]);
	
	if(strtodata((unsigned char*)szmask,sztmp,4,0)!=0)
	{
		MessageBox("屏蔽码格式错误!","Warning",MB_OK|MB_ICONQUESTION);
		return;
	}
	mask=(((DWORD)sztmp[0])<<24)+(((DWORD)sztmp[1])<<16)+(((DWORD)sztmp[2])<<8)+
		((DWORD)sztmp[3]);
	
	if(strtodata((unsigned char*)sztiming0,sztmp,1,0)!=0)
	{
		MessageBox("BTR0 wrong data format!","Warning",MB_OK|MB_ICONQUESTION);
		return;
	}
	timing0=((DWORD)sztmp[0]);
	
	if(strtodata((unsigned char*)sztiming1,sztmp,1,0)!=0)
	{
		MessageBox("BTR1 wrong data format!","Warning",MB_OK|MB_ICONQUESTION);
		return;
	}
	timing1=((DWORD)sztmp[0]);
	
	init_config.AccCode=code;
	init_config.AccMask=mask;
	init_config.Filter=filtertype;
	init_config.Mode=mode;
	//修改timer
	//init_config.Timing0=timing0;
	//init_config.Timing1=timing1;
	int i = m_cbxBaudrate.GetCurSel();
	UCHAR timer0[] = { 0xbf, 0x31, 0x18, 0x87, 0x09, 0x83, 0x04, 0x03, 0x81, 0x01, 0x80, 0x00, 0x80, 0x00, 0x00};
	UCHAR timer1[] = { 0xff, 0x1c, 0x1c, 0xff, 0x1c, 0xff, 0x1c, 0x1c, 0xfa, 0x1c, 0xfa, 0x1c, 0xb6, 0x16, 0x14};
	init_config.Timing0 = timer0[i];
	init_config.Timing1 = timer1[i];
	
	if(VCI_OpenDevice(m_devtype,index,0)!=STATUS_OK)
	{
		MessageBox("打开设备失败!","Warning",MB_OK|MB_ICONQUESTION);
		return;
	}
	if(VCI_InitCAN(m_devtype,index,cannum,&init_config)!=STATUS_OK)
	{
		MessageBox("CAN初始化失败!","Warning",MB_OK|MB_ICONQUESTION);
		VCI_CloseDevice(m_devtype,index);
		return;
	}
	m_connect=1;
	m_devind=index;
	m_cannum=cannum;
	GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText("关闭");
	AfxBeginThread(ReceiveThread,this, THREAD_PRIORITY_HIGHEST);
}

void CTestDlg::OnButtonStartcan() 
{
	// TODO: Add your control notification handler code here
	if(m_connect==0)
		return;
	if(VCI_StartCAN(m_devtype,m_devind,m_cannum)==1)
	{
		ShowInfo("启动成功",0);		
	}
	else
	{
		CString str;
		str="启动失败";
		ShowInfo(str,2);
	}

}

void CTestDlg::OnButtonResetcan() 
{
	// TODO: Add your control notification handler code here
	if(m_connect==0)
		return;
	if(VCI_ResetCAN(m_devtype,m_devind,m_cannum)==1)
	{
		//GetDlgItem(IDC_BUTTON_STARTCAN)->EnableWindow(true);
		ShowInfo("重置成功",0);		
	}
	else
	{
		CString str;
		str="重置失败";
		ShowInfo(str,2);
	}
	
}

void CTestDlg::OnButtonSend()
{
	// test code
	//if (0) {
	//	VCI_CAN_OBJ frame;
	//	frame.ID = 0x18027A70;
	//	frame.Data[0] = 0xf4;
	//	frame.Data[1] = 0x01;
	//	ParseFrame(frame);

	//	return;
	//}
	//SendMessage(WM_MY_PARSE_FRAME, 0, (LPARAM)&frame);

	// TODO: Add your control notification handler code here
	if(m_connect==0)
		return;
	VCI_CAN_OBJ frameinfo;
	char szFrameID[9];
	unsigned char FrameID[4]={0,0,0,0};
	memset(szFrameID,'0',9);
	unsigned char Data[8];
	char szData[25];
	BYTE datalen=0;
    int ret = 0;
	
	UpdateData(true);
	if(m_EditSendFrmID.GetLength()==0||
		(m_EditSendData.GetLength()==0&&m_ComboSendFrmType.GetCurSel()==0))
	{
		ShowInfo("请输入帧数据",1);
		return;
	}
	
	if(m_EditSendFrmID.GetLength()>8)
	{
		ShowInfo("ID值越界",1);
		return;
	}
	if(m_EditSendData.GetLength()>24)
	{
		ShowInfo("帧数据过长，不得超过8 bytes",1);
		return;
	}
	if(m_ComboSendFrmType.GetCurSel()==0)
	{
		if(m_EditSendData.GetLength()%3==1)
		{
			ShowInfo("帧数据格式错误",1);
			return;		
		}		
	}
	memcpy(&szFrameID[8-m_EditSendFrmID.GetLength()],(LPCTSTR)m_EditSendFrmID,m_EditSendFrmID.GetLength());
	strtodata((unsigned char*)szFrameID,FrameID,4,0);

	datalen=(m_EditSendData.GetLength()+1)/3;
	strcpy(szData,(LPCTSTR)m_EditSendData);
    
	strtodata((unsigned char*)szData,Data,datalen,1);

	UpdateData(false);
	
	frameinfo.DataLen=datalen;

    memcpy(&frameinfo.Data,Data,datalen);

	frameinfo.RemoteFlag=m_ComboSendFrmFmt.GetCurSel();
	frameinfo.ExternFlag=m_ComboSendFrmType.GetCurSel();
	if(frameinfo.ExternFlag==1)
	{
		frameinfo.ID=((DWORD)FrameID[0]<<24)+((DWORD)FrameID[1]<<16)+((DWORD)FrameID[2]<<8)+
			((DWORD)FrameID[3]);
	}
	else
	{
		frameinfo.ID=((DWORD)FrameID[2]<<8)+((DWORD)FrameID[3]);		
	}
	frameinfo.SendType=m_ComboSendType.GetCurSel();

    ret = VCI_Transmit(m_devtype,m_devind,m_cannum,&frameinfo,1);

	if( ret == 1 )
	{
		ShowInfo("发送成功",0);		
	}
	else
	{
		ShowInfo("发送失败",2);		
	}

    VCI_GetReceiveNum(m_devtype,m_devind,m_cannum);
}

void CTestDlg::ShowInfo(CString str, int code)
{
	m_ListInfo.InsertString(m_ListInfo.GetCount(),str);
	m_ListInfo.SetCurSel(m_ListInfo.GetCount()-1);
}

//-----------------------------------------------------
//Parameters：
//str：The string to be converted
//data：Save converted data string
//len: The length of the data
//function：Converts a string to a data series
//-----------------------------------------------------
int CTestDlg::strtodata(unsigned char *str, unsigned char *data,int len,int flag)
{
	unsigned char cTmp=0;
	int i=0;
	for(int j=0;j<len;j++)
	{
		if(chartoint(str[i++],&cTmp))
			return 1;
		data[j]=cTmp;
		if(chartoint(str[i++],&cTmp))
			return 1;
		data[j]=(data[j]<<4)+cTmp;
		if(flag==1)
			i++;
	}
	return 0;
}

//-----------------------------------------------------
//Parameters：
//chr：Characters that you want to convert
//cint：Save converted data
//function：Convert characters to data
//-----------------------------------------------------
int CTestDlg::chartoint(unsigned char chr, unsigned char *cint)
{
	unsigned char cTmp;
	cTmp=chr-48;
	if(cTmp>=0&&cTmp<=9)
	{
		*cint=cTmp;
		return 0;
	}
	cTmp=chr-65;
	if(cTmp>=0&&cTmp<=5)
	{
		*cint=(cTmp+10);
		return 0;
	}
	cTmp=chr-97;
	if(cTmp>=0&&cTmp<=5)
	{
		*cint=(cTmp+10);
		return 0;
	}
	return 1;
}

UINT CTestDlg::ReceiveThread(void *param)
{
	CTestDlg *dlg=(CTestDlg*)param;
	CListBox *box=(CListBox *)dlg->GetDlgItem(IDC_LIST_INFO);
	VCI_CAN_OBJ frameinfo[50];
	VCI_ERR_INFO errinfo;
	int len=1;
	int i=0;
	CString str,tmpstr;
    uTimeCounter tc;

	while(1)
	{
        tc.Enter();

		//Sleep(1);
		if(dlg->m_connect==0)
			break;
#if 1
		len=VCI_Receive(dlg->m_devtype,dlg->m_devind,dlg->m_cannum,frameinfo,1,10);
        //len = VCI_GetReceiveNum(dlg->m_devtype,dlg->m_devind,dlg->m_cannum);
		if(len<=0)
		{
			VCI_ReadErrInfo(dlg->m_devtype,dlg->m_devind,dlg->m_cannum,&errinfo);
		}
		else
		{
			for(i=0;i<len;i++)
			{
				VCI_CAN_OBJ frame = frameinfo[i];
				//((CTestDlg*)(dlg))->ParseFrame(frame);
				/*
				必须使用SendMessage，因为它是同步的
				之前，如上非Dialog进程UpdateData刷新界面时，Debug Assert Error。
				*/
				dlg->SendMessage(WM_MY_PARSE_FRAME, 0, (LPARAM)&frame);

				char text[255] = { 0 };
				snprintf(text, 255, "0x%x %02x %02x %02x %02x %02x %02x %02x %02x\n", frame.ID
					, frame.Data[0], frame.Data[1], frame.Data[2], frame.Data[3]
					, frame.Data[4], frame.Data[5], frame.Data[6], frame.Data[7]);
				//fwrite(text, strlen(text), 1, f);

				str="收到数据:  ";
				if(frameinfo[i].TimeFlag==0)
					tmpstr="时间戳:null  ";
				else
					tmpstr.Format("时间戳:%08x ",frameinfo[i].TimeStamp);
				str+=tmpstr;
				tmpstr.Format("ID:%08x ",frameinfo[i].ID);
				str+=tmpstr;
				str+="帧类型:";
				if(frameinfo[i].RemoteFlag==0)
					tmpstr="数据帧 ";
				else
					tmpstr="远程帧 ";
				str+=tmpstr;
				str+="帧格式:";
				if(frameinfo[i].ExternFlag==0)
					tmpstr="标准帧 ";
				else
					tmpstr="扩展帧 ";
				str+=tmpstr;
				box->InsertString(box->GetCount(),str);
				if(frameinfo[i].RemoteFlag==0)
				{
					str="内容:";
					if(frameinfo[i].DataLen>8)
						frameinfo[i].DataLen=8;
					for(int j=0;j<frameinfo[i].DataLen;j++)
					{
						tmpstr.Format("%02x ",frameinfo[i].Data[j]);
						str+=tmpstr;
					}
					//EnterCriticalSection(&(dlg->m_Section));
					//LeaveCriticalSection(&(dlg->m_Section));
					box->InsertString(box->GetCount(),str);
				}	

			}
			box->SetCurSel(box->GetCount()-1);
		}
#endif

        tc.Leave( __FILE__, __LINE__ );
	}
	return 0;
}

void CTestDlg::OnMenuRefresh() 
{
	// TODO: Add your command handler code here
}

void CTestDlg::OnSelchangeComboDevType()
{
	int index = m_ComboDevType.GetCurSel();

	switch( index )
	{
	case 0:
		m_devtype = VCI_USBCAN1;
		break;
	case 1:
		m_devtype = VCI_USBCAN2;
		break;
	case 2:
		m_devtype = VCI_USBCAN2;
		break;
	case 3:
		m_devtype = VCI_PCI9820;
		break;
	case 4:
		m_devtype = VCI_PCI9840;
		break;
	case 5:
		m_devtype = VCI_USBCAN1;
		break;
	case 6:
		m_devtype = VCI_PCI9820;
		break;
	}
}


// 控制弹出国标协议解析界面
void CTestDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	// 0,选中；1，未选中，2不确定
	int status = m_cbx_parse.GetCheck();

	if (status == 0) {
		m_info_dialog->ShowWindow(SW_HIDE);
	}
	else {
		m_info_dialog->ShowWindow(SW_SHOW);
	}
}

// 控制弹出海德协议解析界面
void CTestDlg::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	int status = ((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck();

	if (status == 0) {
		m_navi_dialog->ShowWindow(SW_HIDE);
	}
	else {
		m_navi_dialog->ShowWindow(SW_SHOW);
	}
}

//弹出设备导航页面
void CTestDlg::OnBnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
	int status = ((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck();

	if (status == 0) {
		m_navi_dialog->ShowWindow(SW_HIDE);
	}
	else {
		m_navi_dialog->ShowWindow(SW_SHOW);
	}
}


void CTestDlg::ParseFrame(VCI_CAN_OBJ frame)
{
	//int status = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();

	//if (status) {
	//	m_info_dialog->ParseFrame(frame);
	//}

	//status = ((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck();
	//if (status) {
	//	m_haide_protocol_dialog->ParseFrame(frame);
	//}
	
	set<CParseDialog *>::iterator iter = g_listeners.begin();

	while (iter != g_listeners.end())
	{
		CParseDialog *dlg = (CParseDialog *)(*iter);

		dlg->ParseFrame(frame);
		iter++;
	}

}



void CTestDlg::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	int count = m_ListInfo.GetCount();

	for (int i = count; i >= 0; i--)
	{
		m_ListInfo.DeleteString(i);
	}
}


//CArray<SSerInfo, SSerInfo&> m_asi;
//
//// Populate the list of serial ports.
//EnumSerialPorts(m_asi, FALSE/*include all*/);
//for (int ii = 0; ii<m_asi.GetSize(); ii++) {
//	TRACE("%s: %s %s %s\n", m_asi[ii].strFriendlyName, m_asi[ii].strPortName, m_asi[ii].strPortDesc, m_asi[ii].strDevPath);
//	m_cbxCOM.AddString(m_asi[ii].strFriendlyName);
//}

void CTestDlg::OnBnClickedButtonComOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(TRUE);
	BOOL result;
	CString status;
	int sel = m_cbxCOM.GetCurSel();
	CSerialPort *sp = &m_arraySp[sel];

	GetDlgItem(IDC_BUTTON_COM_OPEN)->GetWindowText(status);
	if (status == _T("打开")) {
		result = sp->open();
		std::string name = sp->getPortName();
		int64 len = sp->getReadBufferSize();

		if (!result) {
			MessageBox(_T("端口打开失败"));
			return;
		}

		GetDlgItem(IDC_BUTTON_COM_OPEN)->SetWindowText(_T("关闭"));
	}
	else {
		sp->close();

		GetDlgItem(IDC_BUTTON_COM_OPEN)->SetWindowText(_T("打开"));
	}
}

//void CTestDlg::OnCOMRecvHT(int h, int t) {
//	HTSlot::OnCOMRecvHT(h, t);
//	TRACE("child: h= %d, t=%d\n", h, t);
//}
//
//void CTestDlg::OnCOMRecv() {
//	HTSlot::OnCOMRecv();
//	TRACE("child: OnCOMRecv\n");
//}


void CTestDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int sel = m_cbxCOM.GetCurSel();
	CSerialPort *sp = &m_arraySp[sel];
	CCOMHTDialog *dlg = (CCOMHTDialog *)m_arrayCOMDlg[sel];

	if (dlg == NULL) {
		dlg = new CCOMHTDialog();
		dlg->Create(IDD_COM_HT_DIALOG, this);
		dlg->SetSerialPort(sp);
		sp->readReady.connect(dlg, &CCOMHTDialog::OnCOMRecv);
		dlg->SetWindowText(m_strCOMPort);


		m_arrayCOMDlg[sel] = dlg;
	}

	dlg->ShowWindow(SW_SHOW);
}


void CTestDlg::OnCbnSelchangeComboComPort()
{
	// TODO: 在此添加控件通知处理程序代码
	int sel = m_cbxCOM.GetCurSel();
	CSerialPort *sp = &m_arraySp[sel];

	if (sp->isOpened()) {
		GetDlgItem(IDC_BUTTON_COM_OPEN)->SetWindowText(_T("关闭"));
	}
	else {
		GetDlgItem(IDC_BUTTON_COM_OPEN)->SetWindowText(_T("打开"));
	}
}


BOOL CTestDlg::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	int i = 0;
	for (i = 0; i < SP_NUM; i++) {
		CDialog *dlg = m_arrayCOMDlg[i];
		if (dlg) {
			dlg->DestroyWindow();
			delete dlg;
		}
	}

	if (m_info_dialog) {
		m_info_dialog->DestroyWindow();
		delete m_info_dialog;
	}

	if (m_haide_protocol_dialog) {
		m_haide_protocol_dialog->DestroyWindow();
		delete m_haide_protocol_dialog;
	}

	if (m_navi_dialog) {
		m_navi_dialog->DestroyWindow();
		delete m_navi_dialog;
	}
	return __super::DestroyWindow();
}
