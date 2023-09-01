
// mfcsDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "mfcs.h"
#include "mfcsDlg.h"
#include "afxdialogex.h"
#include"Dlg3.h"
#include"DataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcsDlg 对话框



CmfcsDlg::CmfcsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CmfcsDlg::OnBnClickedStart)
	//数字按钮
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON4, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON5, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON6, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON7, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON8, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON9, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON10, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON11, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON12, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON13, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON14, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON15, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON16, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON17, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON18, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON19, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON20, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON21, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON22, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON23, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON24, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_MFCBUTTON25, &CmfcsDlg::on_num)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ZanTing, &CmfcsDlg::OnZanting)
	ON_UPDATE_COMMAND_UI(ID_ZanTing, &CmfcsDlg::OnUpdateZanting)
	ON_COMMAND(ID_Kaishi, &CmfcsDlg::OnKaishi)
	ON_WM_TIMER()
	ON_COMMAND(ID_S_FONT, &CmfcsDlg::OnSFont)
	ON_COMMAND(ID_DE_FONT, &CmfcsDlg::OnDeFont)
	ON_COMMAND(ID_3dlg, &CmfcsDlg::On3dlg)
	ON_COMMAND(ID_Hard, &CmfcsDlg::OnHard)
	ON_COMMAND(ID_Normal, &CmfcsDlg::OnNormal)
	ON_COMMAND(ID_Hardhard, &CmfcsDlg::OnHardhard)
	ON_COMMAND(ID_ShowData, &CmfcsDlg::OnShowdata)
END_MESSAGE_MAP()


// CmfcsDlg 消息处理程序

BOOL CmfcsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//菜单栏
	srand(time(0));
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	GetMenu()->GetSubMenu(0)->CheckMenuRadioItem(0,2, 0,  MF_BYPOSITION);
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);


	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	fn->CreatePointFont(400, TEXT("微软雅黑"), NULL);
	// TODO: 在此添加额外的初始化代码
	//初始按钮不可用
	dis_bn();


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmfcsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmfcsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcsDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}





// 按钮不可用
void CmfcsDlg::dis_bn()
{
	// TODO: 在此处添加实现代码.
	
	/*CMFCButton* bn = (CMFCButton*)GetDlgItem(IDC_MFCBUTTON2);
	bn->SetFaceColor(RGB(0, 255, 0));
	bn->m_bTransparent = FALSE;
	bn->m_bDontUseWinXPTheme = TRUE;*/
	for (int i = 1029; i <= 1053; i++)
	{
		//id =1029~1053
		GetDlgItem(i)->EnableWindow(FALSE);
		GetDlgItem(i)->SetFont(fn);
	}


}


// 按钮随机初始化
void CmfcsDlg::init_bn()
{
	// TODO: 在此处添加实现代码.
	for (int i = 1029; i <= 1053; i++)
	{
		//id =1029~1053
		GetDlgItem(i)->EnableWindow(TRUE);
	}


	int shunxu[25], luanxu[25], i, j;
	CString s;
	for (i = 0; i < 25; i++)
	{
		shunxu[i] = i + 1;
	}
	for (i = 25; i > 0; i--)
	{
		j = rand() % i;
		luanxu[i - 1] = shunxu[j];
		while (j < i - 1)
		{
			shunxu[j] = shunxu[j + 1];
			j++;
		}
	}
	i = 0;
	for (int n = 1029; n <= 1053; n++)
	{
		//id =1029~1053
		SetDlgItemText(n, (s.Format(L"%d", luanxu[i++]), s));
		
	}

	
}


void CmfcsDlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE_BGM), NULL, SND_RESOURCE | SND_ASYNC|SND_LOOP);
	if (!start)
	{
		//播放bgm
		//CWinThread* pThread = AfxBeginThread(ThreadBgm,(LPVOID)NULL);
		mciSendString(L"open ./bgm.mp3 alias bgm", NULL, 0, NULL);
		mciSendString(L"play bgm repeat", NULL, 0, NULL);
		SetTimer(1, 1, NULL);
		CFont* font=new CFont;
		font->CreatePointFont(150, TEXT("微软雅黑"), NULL);

		GetDlgItem(IDC_START)->SetFont(font);
		init_bn();
		start = 1;
		num = 1;
		t0 = CTime::GetCurrentTime();
		starttime = clock();
	}

	
}


// 按下数字
void CmfcsDlg::on_num()
{
	// TODO: 在此处添加实现代码.
	CString m_numT;
	CMFCButton* bn = (CMFCButton*)GetDlgItem(GetFocus()->GetDlgCtrlID());
	//GetDlgItemText(GetFocus()->GetDlgCtrlID(), m_numT);
	GetDlgItemText(bn->GetDlgCtrlID(), m_numT);

	 
	int m_num = _ttoi(m_numT);
	if (m_num != num)//错误变色
	{
		if (difficulty == 0)//普通难度
		{
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_ER), NULL, SND_RESOURCE | SND_ASYNC);

			//CMFCButton* bn = (CMFCButton*)GetDlgItem(GetFocus()->GetDlgCtrlID());
			//GetDlgItem(GetFocus()->GetDlgCtrlID())->EnableWindow(FALSE);
			//Beep(300,300);
			bn->SetFaceColor(RGB(255, 0, 0));
			bn->m_bTransparent = FALSE;
			bn->m_bDontUseWinXPTheme = TRUE;
			ernum++;
			Invalidate();
		}
		else
		{
			Beep(500, 300);
			stop();
			MessageBox(L"游戏失败！");
			
		}


	}
	else
	{
		Beep(800, 100);
		//PlaySound(MAKEINTRESOURCE(IDR_WAVE_BN), NULL, SND_RESOURCE | SND_ASYNC);

		//CMFCButton* bn = (CMFCButton*)GetDlgItem(GetFocus()->GetDlgCtrlID());
		if (difficulty != 2)
		{
			bn->EnableWindow(FALSE);
			for (int n = 1029; n <= 1053; n++)
			{
				//id =1029~1053
				CMFCButton* bnall = (CMFCButton*)GetDlgItem(n);
				bnall->m_bTransparent = TRUE;
				bnall->m_bDontUseWinXPTheme = FALSE;

			}
		}
		else
		{
			init_bn();
		}

		
		Invalidate();
		num++;
	}

		
	
	if (num == 26)
	{
		endtime = clock();
		times = (double)(endtime - starttime)/CLOCKS_PER_SEC;
		times -= timez;
		CString str;
		str.Format(TEXT("共用时%.2f秒\n失误%d次"), times,ernum);
		MessageBox(str);
	}
}


void CmfcsDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	//右键菜单
	// TODO: 在此处添加消息处理程序代码
	if (start)
	{
		CMenu menuR;
		menuR.LoadMenuW(IDR_MENUR);
		if (zanTing)
		{
			CMenu* pmenu = menuR.GetSubMenu(1);
			pmenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);


		}
		else
		{

			CMenu* pmenu = menuR.GetSubMenu(0);
			pmenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);

		}



	}
	

	
}


void CmfcsDlg::OnZanting()
{
	//右键暂停
	// TODO: 在此添加命令处理程序代码
	zanTing = 1;
	zstart = clock();
	dis_bn();
	//MessageBeep(MB_ICONERROR);
	Beep(800, 200);
	//PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
	MessageBox(TEXT("暂停成功！"));
}


void CmfcsDlg::OnUpdateZanting(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	//pCmdUI->Enable(FALSE);
}


void CmfcsDlg::OnKaishi()
{
	// TODO: 在此添加命令处理程序代码
	
	
	for (int i = 1029; i <= 1053; i++)
	{
		//id =1029~1053
		CString numT;
		GetDlgItemTextW(i, numT);
		int m_num = _ttoi(numT);
		if (m_num < num)
		{
			GetDlgItem(i)->EnableWindow(FALSE);
		}
		else
		{
			GetDlgItem(i)->EnableWindow(TRUE);

		}
	}
	Beep(800, 200);
	MessageBox(TEXT("开始成功！"));
	zanTing = 0;
	zend = clock();
	timez += (double)(zend - zstart) / CLOCKS_PER_SEC;
}


void CmfcsDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!zanTing)
	{
		CMFCButton* bns = (CMFCButton*)GetDlgItem(IDC_START);
		endtime = clock();
		times = (double)(endtime - starttime) / CLOCKS_PER_SEC;
		times -= timez;
		CString str;
		str.Format(TEXT("当前用时%.2f秒\n失误%d次"), times, ernum);
		bns->SetWindowTextW(str);
		CDialogEx::OnTimer(nIDEvent);
	}

	
}


void CmfcsDlg::OnSFont()
{
	// TODO: 在此添加命令处理程序代码
	//选择字体
	CFontDialog fdlg;
	if (IDOK==fdlg.DoModal())
	{
		LOGFONT lfont;
		fdlg.GetCurrentFont(&lfont);
		delete fn;
		fn = new CFont;
		fn->CreateFontIndirectW(&lfont);
		for (int i = 1029; i <= 1053; i++)
		{
			//id =1029~1053
			GetDlgItem(i)->SetFont(fn);
		}
	}
}


void CmfcsDlg::OnDeFont()
{
	// TODO: 在此添加命令处理程序代码
	delete fn;
	fn = new CFont;
	fn->CreatePointFont(400, TEXT("宋体"), NULL);
	for (int i = 1029; i <= 1053; i++)
	{
		//id =1029~1053
		GetDlgItem(i)->SetFont(fn);
	}
}


// bgm播放
//UINT CmfcsDlg::ThreadBgm(LPVOID p)
//{
//	 TODO: 在此处添加实现代码.
//
//		PlaySound(MAKEINTRESOURCE(IDR_WAVE_BGM), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
//		
//	
//
//	return 0;
//}


void CmfcsDlg::On3dlg()
{
	// TODO: 在此添加命令处理程序代码
	GetMenu()->GetSubMenu(2)->CheckMenuItem(1, MF_BYPOSITION|MF_CHECKED);
	Dlg3 dlg3;
	CmfcsDlg::OnCancel();
	dlg3.DoModal();
	

}

//不能失误
void CmfcsDlg::OnHard()
{
	// TODO: 在此添加命令处理程序代码
	difficulty = 1;
	GetMenu()->GetSubMenu(0)->CheckMenuRadioItem(0, 2, 1, MF_BYPOSITION);

}


// 中止游戏
void CmfcsDlg::stop()
{
	// TODO: 在此处添加实现代码.
	KillTimer(1);
	dis_bn();
	times = timez = 0;
	start = 0;
	GetDlgItem(IDC_START)->SetWindowTextW(L"开始");
}


void CmfcsDlg::OnNormal()
{
	// TODO: 在此添加命令处理程序代码
	difficulty = 0;
	GetMenu()->GetSubMenu(0)->CheckMenuRadioItem(0, 2, 0, MF_BYPOSITION);

}


void CmfcsDlg::OnHardhard()
{
	// TODO: 在此添加命令处理程序代码
	difficulty = 2;
	GetMenu()->GetSubMenu(0)->CheckMenuRadioItem(0, 2, 2, MF_BYPOSITION);

}




void CmfcsDlg::OnShowdata()
{
	// TODO: 在此添加命令处理程序代码
	DataDlg ddlg;
	ddlg.DoModal();
}
