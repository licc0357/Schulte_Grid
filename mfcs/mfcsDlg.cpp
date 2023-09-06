
// mfcsDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "mfcs.h"
#include "mfcsDlg.h"
#include "afxdialogex.h"
#include"Dlg3.h"
#include"DataDlg.h"
#include"User.h"

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
public:
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
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
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
	ON_COMMAND(ID_STOP, &CmfcsDlg::OnStop)
	ON_COMMAND(ID_STOP2, &CmfcsDlg::OnStop)

	ON_WM_CLOSE()
	ON_COMMAND(ID_qby, &CmfcsDlg::Onqby)
	ON_COMMAND(ID_tkzc, &CmfcsDlg::Ontkzc)
	ON_COMMAND(ID_NBGM, &CmfcsDlg::OnNbgm)
	ON_COMMAND(ID_DEUSER, &CmfcsDlg::OnDeuser)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_WUJIN, &CmfcsDlg::OnWujin)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CmfcsDlg 消息处理程序

BOOL CmfcsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SkinH_Attach();
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
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		CDC dcMem;                                                 //用于缓冲作图的内存DC
		CBitmap bmp;                                                //内存中承载临时图象的位图
		dcMem.CreateCompatibleDC(&dc);              //依附窗口DC创建兼容内存DC
		bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());//创建兼容位图
		dcMem.SelectObject(&bmp);                         //将位图选择进内存DC
		dcMem.FillSolidRect(rect, dc.GetBkColor());//按原来背景填充客户区，不然会是黑色
		//Draw()//你得重绘内容，使用dcMem      
		dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);//将内存DC上的图象拷贝到前台
		dcMem.DeleteDC();                                      //删除DC
		bmp.DeleteObject();                                       //删除位图
		CDialog::OnPaint();
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
		if (bgm)
		{
			pThread = AfxBeginThread(ThreadBgm, (LPVOID)1);

		}else
		{
			pThread = AfxBeginThread(ThreadBgm, (LPVOID)NULL);

		}
		ernum = 0;
		//mciSendString(L"open ./bgm.mp3 alias bgm", NULL, 0, NULL);
		//mciSendString(L"play bgm repeat", NULL, 0, NULL);
		SetTimer(1, 1, NULL);
		CFont* font=new CFont;
		font->CreatePointFont(150, TEXT("微软雅黑"), NULL);
		for (int n = 1029; n <= 1053; n++)
		{
			//id =1029~1053
			CMFCButton* bnall = (CMFCButton*)GetDlgItem(n);
			bnall->m_bTransparent = TRUE;
			bnall->m_bDontUseWinXPTheme = FALSE;

		}
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
		switch (difficulty)
		{case 0:
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_ER), NULL, SND_RESOURCE | SND_ASYNC);

			//CMFCButton* bn = (CMFCButton*)GetDlgItem(GetFocus()->GetDlgCtrlID());
			//GetDlgItem(GetFocus()->GetDlgCtrlID())->EnableWindow(FALSE);
			//Beep(300,300);
			bn->SetFaceColor(RGB(255, 0, 0));
			bn->m_bTransparent = FALSE;
			bn->m_bDontUseWinXPTheme = TRUE;
			ernum++;
			Invalidate();
			break;
		case 1: case 2: //
			Beep(500, 300);
			stop();
			MessageBox(L"游戏失败！");
			break;
		case 3:
			Beep(500, 300);
			stop();
			CString str;
			str.Format(L"游戏结束！\n您的成绩是%d", num-1);
			MessageBox(str);
			break;
		}



	}
	else
	{
		//Beep(800, 100);
		PlaySound(MAKEINTRESOURCE(IDR_WAVE_BN), NULL, SND_RESOURCE | SND_ASYNC);

		//CMFCButton* bn = (CMFCButton*)GetDlgItem(GetFocus()->GetDlgCtrlID());
		switch (difficulty)
		{
		case 0:case 1:
			bn->EnableWindow(FALSE);
			for (int n = 1029; n <= 1053; n++)
			{
				//id =1029~1053
				CMFCButton* bnall = (CMFCButton*)GetDlgItem(n);
				if (bnall->m_bTransparent == FALSE)
				{
					bnall->m_bTransparent = TRUE;
					bnall->m_bDontUseWinXPTheme = FALSE;
					Invalidate();
					//InvalidateRect(&rec, TRUE);
				}


			}
			break;
		case 2:
			init_bn();
			break;
		case 3:
			
			WuJin();
			break;
		}

		
		
		num++;
	}

		
	
	if (num == 26)
	{
		if (difficulty!=3)
		{
			endtime = clock();
			times = (double)(endtime - starttime) / CLOCKS_PER_SEC;
			times -= timez;
			CString str;
			str.Format(TEXT("共用时%.2f秒\n失误%d次"), times, ernum);
			writeData();
			stop();
			MessageBox(str);
		}

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
	pThread->SuspendThread();
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
	pThread->ResumeThread();
	zanTing = 0;
	zend = clock();
	timez += (double)(zend - zstart) / CLOCKS_PER_SEC;
}


void CmfcsDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!zanTing)
	{
		if (difficulty!=3)
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
		else
		{
			CMFCButton* bns = (CMFCButton*)GetDlgItem(IDC_START);
			CString str;
			str.Format(TEXT("当前分数%d"), num-1);
			bns->SetWindowTextW(str);
			CDialogEx::OnTimer(nIDEvent);
		}

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
	fn->CreatePointFont(400, TEXT("微软雅黑"), NULL);
	for (int i = 1029; i <= 1053; i++)
	{
		//id =1029~1053
		GetDlgItem(i)->SetFont(fn);
	}
}





void CmfcsDlg::On3dlg()
{
	// TODO: 在此添加命令处理程序代码
	GetMenu()->GetSubMenu(2)->CheckMenuItem(1, MF_BYPOSITION|MF_CHECKED);
	Dlg3 dlg3;
	dlg3.DoModal();
	

}

//不能失误
void CmfcsDlg::OnHard()
{
	// TODO: 在此添加命令处理程序代码
	difficulty = 1;
	GetMenu()->GetSubMenu(0)->CheckMenuRadioItem(0, 3, 1, MF_BYPOSITION);

}


// 中止游戏
void CmfcsDlg::stop()
{
	// TODO: 在此处添加实现代码.
	KillTimer(1);
	pThread->SuspendThread();
	times = timez = 0;
	start = 0;
	GetDlgItem(IDC_START)->SetWindowTextW(L"开始");
}


void CmfcsDlg::OnNormal()
{
	// TODO: 在此添加命令处理程序代码
	difficulty = 0;
	GetMenu()->GetSubMenu(0)->CheckMenuRadioItem(0, 3, 0, MF_BYPOSITION);

}


void CmfcsDlg::OnHardhard()
{
	// TODO: 在此添加命令处理程序代码
	difficulty = 2;
	GetMenu()->GetSubMenu(0)->CheckMenuRadioItem(0, 3, 2, MF_BYPOSITION);

}




void CmfcsDlg::OnShowdata()
{
	// TODO: 在此添加命令处理程序代码
	DataDlg ddlg;
	ddlg.DoModal();
}




void CmfcsDlg::writeData()
{
	// TODO: 在此处添加实现代码.
	if (difficulty == 0)
	{
		theApp.now_user.G[theApp.now_user.gametime].clock = t0;
		theApp.now_user.G[theApp.now_user.gametime].ernum = ernum;
		theApp.now_user.G[theApp.now_user.gametime].t = times;
		theApp.now_user.gametime++;
		CFile file(L"data.dat", CFile::modeWrite);
		long loff = sizeof(theApp.now_user);
		file.Seek(theApp.I_user * loff, CFile::begin);
		file.Write(&theApp.now_user, sizeof(theApp.now_user));
		file.Close();

	}


}


void CmfcsDlg::OnStop()
{
	// TODO: 在此添加命令处理程序代码
	if (MessageBox(L"确定要停止游戏吗？", L"停止游戏", MB_OKCANCEL) == IDOK)
	{
		stop();

		MessageBox(L"游戏停止！\n请按开始键重新开始游戏");


	}
}


void CmfcsDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (MessageBox(L"确定要关闭游戏吗？", L"关闭游戏", MB_OKCANCEL) == IDOK)
	{
		CDialogEx::OnClose();

		MessageBox(L"再见");


	}
	
}


void CmfcsDlg::Onqby()
{
	// TODO: 在此添加命令处理程序代码
	bgm = 0;
	if (pThread)
	{
		pThread->SuspendThread();

		pThread = AfxBeginThread(ThreadBgm, (LPVOID)NULL);
	}


}


void CmfcsDlg::Ontkzc()
{
	// TODO: 在此添加命令处理程序代码
	bgm = 1;
	if (pThread)
	{
		pThread->SuspendThread();

		pThread = AfxBeginThread(ThreadBgm, (LPVOID)1);
	}


}


void CmfcsDlg::OnNbgm()
{
	// TODO: 在此添加命令处理程序代码
	if (pThread)
	{
		pThread->SuspendThread();


	}
	


}


void CmfcsDlg::OnDeuser()
{
	// TODO: 在此添加命令处理程序代码
	if (MessageBox(L"确定要退出登录吗？", L"退出登录", MB_OKCANCEL) == IDOK)
	{

		MessageBox(L"退出成功");


	}
	CDialogEx::OnOK();
}


BOOL CmfcsDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return CDialogEx::OnEraseBkgnd(pDC);
	//return TRUE;
}


void CmfcsDlg::OnWujin()
{
	// TODO: 在此添加命令处理程序代码
	difficulty = 3;
	GetMenu()->GetSubMenu(0)->CheckMenuRadioItem(0, 3, 3, MF_BYPOSITION);
}


void CmfcsDlg::WuJin()
{
	// TODO: 在此处添加实现代码.
	/*CMFCButton* bn = (CMFCButton*)GetDlgItem(GetFocus()->GetDlgCtrlID());*/
	int shunxu[25], luanxu[25], i, j;
	CString s;
	for (i = 0; i < 25; i++)
	{
		shunxu[i] = i + 1+num;
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
	/*CString str;
	str.Format(L"%d", num + 25);
	bn->SetWindowTextW(str);*/
}


int CmfcsDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	//CSplashWnd::ShowSplashScreen(this);
	return 0;
}
