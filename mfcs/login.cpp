// login.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "login.h"
#include"mfcsDlg.h"
#include"CCaption.h"
#include"CMyButton.h"


// login 对话框

IMPLEMENT_DYNAMIC(login, CDialogEx)

login::login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, Name(_T(""))
	, Password(_T(""))
{

}

login::~login()
{
}

void login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Name, Name);
	DDX_Text(pDX, IDC_Password, Password);
	DDX_Control(pDX, IDC_STATIC_CAPTION, m_staticCap);
	//  DDX_Control(pDX, IDC_BUTTON_CLOSE, m_btnClose);
	//  DDX_Control(pDX, IDC_BUTTON_CLOSE, IDC_BUTTON_CLOSE);
	//  DDX_Control(pDX, IDC_BUTTON_CLOSE, m_btnClose);
}


BEGIN_MESSAGE_MAP(login, CDialogEx)
	ON_BN_CLICKED(IDC_Login, &login::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_register, &login::OnBnClickedregister)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// login 消息处理程序


void login::OnBnClickedLogin()
{
	CFile file(
		L"data.dat",
		CFile::modeRead
	);
		User user;
		file.Read(&user, sizeof(user));
		file.Close();
		UpdateData(TRUE);
		// TODO: 在此添加控件通知处理程序代码7
		CString mName, mPsw, mEmail;
		user.readUser(mName, mPsw, mEmail);
		if (Name == mName && Password ==mPsw)
		{
			CDialogEx::OnOK();
		}
		else {
			MessageBox(L"用户名或密码错误，请重新输入\nPs:若没有注册，请点击注册按钮进行注册");
		}

}


//void login::OnBnClickedregister()
//{
	// TODO: 在此添加控件通知处理程序代码
//}


void login::OnBnClickedregister()
{
	Register Reg;
	Reg.DoModal();


	
	// TODO: 在此添加控件通知处理程序代码
}


void login::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);
	CDialogEx::OnClose();
}


BOOL login::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	MoveWindow(0, 0, 800, 600);
	// TODO:  在此添加额外的初始化
	CString strBmpPath = _T(".\\res\\Tigger.jpg");

	CImage img;

	img.Load(strBmpPath);

	CBitmap bmpTmp;

	bmpTmp.Attach(img.Detach());

	m_bkBrush.CreatePatternBrush(&bmpTmp);
	m_staticCap.Init(400, 300, 105, 30);//调整标题位置
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH login::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔

	if (pWnd == this)
	{
		return m_bkBrush;
	}

	if (pWnd->GetDlgCtrlID() == (IDC_STATIC_CAPTION))
	{
		//MessageBox(_T("static text"));
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 225, 225));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}
	// TODO:  Return a different brush if the default is not desired
	if (pWnd->GetDlgCtrlID() == (IDC_STATIC))
	{
		//MessageBox(_T("static text"));
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 225, 225));
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}


	return hbr;

}