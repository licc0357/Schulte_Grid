// login.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "login.h"
#include"mfcsDlg.h"
#include"AdminDlg.h"
#include"CCaption.h"
#include"CMyButton.h"
#include"CPswDlg.h"


// login 对话框

IMPLEMENT_DYNAMIC(login, CDialogEx)

login::login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGIN, pParent)
	, Name(_T(""))
	, Password(_T(""))
	, RPsw(FALSE)
	, Auto(FALSE)
{

}

login::~login()
{
}

void login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Name, Name);
	DDX_Control(pDX, IDC_STATIC_CAPTION, m_staticCap);

	DDX_Text(pDX, IDC_Password, Password);
	DDX_Check(pDX, IDC_CHECK_PSW, RPsw);
	DDX_Check(pDX, IDC_CHECK_AUTO, Auto);
}


BEGIN_MESSAGE_MAP(login, CDialogEx)
	ON_BN_CLICKED(IDC_Login, &login::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_register, &login::OnBnClickedregister)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()

//	ON_BN_CLICKED(IDC_MFCLINK1, &login::OnBnClickedMfclink1)
ON_BN_CLICKED(IDC_BUTTON_LOST, &login::OnBnClickedButtonLost)
END_MESSAGE_MAP()


// login 消息处理程序


void login::OnBnClickedLogin()
{

		UpdateData(TRUE);
		//管理员账户
		if (Name==L"admin"&&Password==L"admin")
		{
			AdminDlg adlg;
			Name.Empty();
			Password.Empty();
			UpdateData(FALSE);

			adlg.DoModal();
			Invalidate();
			return;
		}
		CFile file(L"data.dat",CFile::modeRead);
		User user;
		bool islogin=0;
		while (file.Read(&user, sizeof(user))==sizeof(user))
		{
			CString mName, mPsw, mEmail;
			user.readUser(mName, mPsw, mEmail);
			if (Name == mName && Password == mPsw)
			{
				theApp.now_user = user;
				if (RPsw||Auto)
				{
					WritePrivateProfileString(L"User", L"name", mName, L"User.ini");
					if (Auto)
					{
						WritePrivateProfileString(L"User", L"auto", L"1", L"User.ini");
					}
					else
					{
						WritePrivateProfileString(L"User", L"", L"", L"User.ini");

					}
					
				}
				else
				{
				   WritePrivateProfileString(L"User", L"name", L"", L"User.ini");

				}


				CDialogEx::OnOK();
				islogin = 1;
				break;
			}
			else
			{
				theApp.I_user++;
			}
		}
		file.Close();
		if (!islogin)
		{
			MessageBox(L"用户名或密码错误，请重新输入\nPs:若没有注册，请点击注册按钮进行注册");

		}
		// TODO: 在此添加控件通知处理程序代码7
		//CString mName, mPsw, mEmail;
		//user.readUser(mName, mPsw, mEmail);
		//if (Name == mName && Password ==mPsw)
		//{
		//	theApp.now_user = user;
		//	CDialogEx::OnOK();
		//}
		//else {
		//	MessageBox(L"用户名或密码错误，请重新输入\nPs:若没有注册，请点击注册按钮进行注册");
		//}

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


void login::OnOK()
{
	OnBnClickedLogin();

//	CDialogEx::OnOK();
}


void login::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}
BOOL login::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1), TRUE);
	SkinH_Attach();
	//MoveWindow(0, 0, 800, 600);
	// TODO:  在此添加额外的初始化
	CString str;
	GetPrivateProfileString(L"User", L"name", L"", str.GetBuffer(MAX_PATH), MAX_PATH, L"User.ini");
	Name = str;
	if (str!=L"")
	{
		RPsw = 1;
	}
	CFile file(L"data.dat", CFile::modeRead);
	User user;
	while (file.Read(&user, sizeof(user)) == sizeof(user))
	{
		CString mName, mPsw, mEmail;
		user.readUser(mName, mPsw, mEmail);
		if (str == mName )
		{
			Password = mPsw;
			break;
		}

	}
	file.Close();
	UpdateData(FALSE);
	CString str1;
	GetPrivateProfileString(L"User", L"auto", L"", str1.GetBuffer(MAX_PATH), MAX_PATH, L"User.ini");
	if (str1==L"1")
	{
		OnBnClickedLogin();
	}

	CString strBmpPath = _T(".\\res\\Tigger.jpg");

	CImage img;

	img.Load(strBmpPath);

	CBitmap bmpTmp;

	bmpTmp.Attach(img.Detach());

	m_bkBrush.CreatePatternBrush(&bmpTmp);
	CFont* fc=new CFont;
	fc->CreatePointFont(200, L"隶书");

	m_staticCap.SetFont(fc);
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
		pDC->SetTextColor(RGB(0, 0, 0));
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

//void login::OnBnClickedMfclink1()
//{
	// TODO: 在此添加控件通知处理程序代码
//	DePswDlg dedlg;
//	dedlg.DoModal();
//}


void login::OnBnClickedButtonLost()
{
	// TODO: 在此添加控件通知处理程序代码
	DePswDlg dedlg;
	if (dedlg.DoModal() == IDOK)
	{
		CPswDlg pswdlg;
		pswdlg.DoModal();
	}
}
