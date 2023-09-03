// login.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "login.h"
#include"mfcsDlg.h"
#include"AdminDlg.h"


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
}


BEGIN_MESSAGE_MAP(login, CDialogEx)
	ON_BN_CLICKED(IDC_Login, &login::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_register, &login::OnBnClickedregister)
	ON_WM_CLOSE()
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
	// TODO: 在此添加专用代码和/或调用基类

//	CDialogEx::OnOK();
}


void login::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnCancel();
}
