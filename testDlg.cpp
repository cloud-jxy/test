// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "ControlCAN.h"
#include "uTimeCounter.h"
#include "InfoDialog.h"

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
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

LRESULT CTestDlg::OnInfoDialogClose(WPARAM w, LPARAM l) {
	m_cbx_parse.SetCheck(false);
	UpdateData(false);
	return 0;
}

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

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
	int i = 0;
	
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
		MessageBox("Acceptance code wrong data format!","Warning",MB_OK|MB_ICONQUESTION);
		return;
	}
	code=(((DWORD)sztmp[0])<<24)+(((DWORD)sztmp[1])<<16)+(((DWORD)sztmp[2])<<8)+
		((DWORD)sztmp[3]);
	
	if(strtodata((unsigned char*)szmask,sztmp,4,0)!=0)
	{
		MessageBox("Mask data format does not!","Warning",MB_OK|MB_ICONQUESTION);
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
	init_config.Timing0=timing0;
	init_config.Timing1=timing1;
	
	if(VCI_OpenDevice(m_devtype,index,0)!=STATUS_OK)
	{
		MessageBox("Failed to open device!","Warning",MB_OK|MB_ICONQUESTION);
		return;
	}
	if(VCI_InitCAN(m_devtype,index,cannum,&init_config)!=STATUS_OK)
	{
		MessageBox("Failed to initialize the CAN!","Warning",MB_OK|MB_ICONQUESTION);
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
		ShowInfo("Started successfully",0);		
	}
	else
	{
		CString str;
		str="Failed to start";
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
		ShowInfo("Reset successful",0);		
	}
	else
	{
		CString str;
		str="Reset failed";
		ShowInfo(str,2);
	}
	
}

void CTestDlg::OnButtonSend() 
{
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
		ShowInfo("Please enter the data",1);
		return;
	}
	
	if(m_EditSendFrmID.GetLength()>8)
	{
		ShowInfo("ID-value out of range",1);
		return;
	}
	if(m_EditSendData.GetLength()>24)
	{
		ShowInfo("Data longer than the range maximum is 8 bytes",1);
		return;
	}
	if(m_ComboSendFrmType.GetCurSel()==0)
	{
		if(m_EditSendData.GetLength()%3==1)
		{
			ShowInfo("Data format is wrong, please re-enter",1);
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
		ShowInfo("Writing successed",0);		
	}
	else
	{
		ShowInfo("Writing failed",2);		
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
				str="Receiving data frame:  ";
				if(frameinfo[i].TimeFlag==0)
					tmpstr="Time stamps:null  ";
				else
					tmpstr.Format("Time stamps:%08x ",frameinfo[i].TimeStamp);
				str+=tmpstr;
				tmpstr.Format("ID:%08x ",frameinfo[i].ID);
				str+=tmpstr;
				str+="Type:";
				if(frameinfo[i].RemoteFlag==0)
					tmpstr="Data frame ";
				else
					tmpstr="Remote frame ";
				str+=tmpstr;
				str+="Format:";
				if(frameinfo[i].ExternFlag==0)
					tmpstr="Standard frame ";
				else
					tmpstr="Extended frame ";
				str+=tmpstr;
				box->InsertString(box->GetCount(),str);
				if(frameinfo[i].RemoteFlag==0)
				{
					str="Data:";
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
