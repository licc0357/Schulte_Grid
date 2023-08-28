
// mfcsDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "mfcs.h"
#include "mfcsDlg.h"
#include "afxdialogex.h"

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
	ON_BN_CLICKED(IDC_BUTTON1, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON2, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON3, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON4, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON5, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON6, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON7, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON8, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON9, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON10, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON11, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON12, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON13, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON14, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON15, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON16, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON17, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON18, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON19, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON20, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON21, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON22, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON23, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON24, &CmfcsDlg::on_num)
	ON_BN_CLICKED(IDC_BUTTON25, &CmfcsDlg::on_num)
END_MESSAGE_MAP()


// CmfcsDlg 消息处理程序

BOOL CmfcsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//菜单栏
	srand(time(0));
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
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
	CFont *fn = new CFont;
	fn->CreatePointFont(500, TEXT("宋体"), NULL);

	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON1)->SetFont(fn);

	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON17)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON18)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON20)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON21)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON22)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON23)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON24)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON25)->EnableWindow(FALSE);
}


// 按钮随机初始化
void CmfcsDlg::init_bn()
{
	// TODO: 在此处添加实现代码.
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON12)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON17)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON18)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON19)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON20)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON21)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON22)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON23)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON24)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON25)->EnableWindow(TRUE);

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
	SetDlgItemText(IDC_BUTTON1, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON2, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON3, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON4, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON5, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON6, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON7, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON8, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON9, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON10, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON11, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON12, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON13, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON14, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON15, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON16, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON17, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON18, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON19, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON20, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON21, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON22, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON23, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON24, (s.Format(L"%d", luanxu[i++]), s));
	SetDlgItemText(IDC_BUTTON25, (s.Format(L"%d", luanxu[i++]), s));
}


void CmfcsDlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	init_bn();
	num = 1;
	t0 = CTime::GetCurrentTime();
	start = clock();
	
}


// 按下数字
void CmfcsDlg::on_num()
{
	// TODO: 在此处添加实现代码.
	CString m_numT;
	GetDlgItemText(GetFocus()->GetDlgCtrlID(), m_numT);

	
	int m_num = _ttoi(m_numT);
	if (m_num == num)
	{
		GetDlgItem(GetFocus()->GetDlgCtrlID())->EnableWindow(FALSE);
		num++;
	}
	if (num == 26)
	{
		end = clock();
		times = (double)(end - start)/CLOCKS_PER_SEC;
		CString str;
		str.Format(TEXT("共用时%.2f秒"), times);
		MessageBox(str);
	}
}
