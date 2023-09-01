// Register.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "Register.h"


// Register 对话框

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Zhuce, pParent)
	, Name1(_T(""))
	, Password1(_T(""))
	, Password2(_T(""))
	, Email1(_T(""))
{

}

Register::~Register()
{
}

void Register::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Name1, Name1);
	DDX_Text(pDX, IDC_Password1, Password1);
	DDX_Text(pDX, IDC_Password2, Password2);
	DDX_Text(pDX, IDC_Email1, Email1);
}


BEGIN_MESSAGE_MAP(Register, CDialogEx)
	ON_BN_CLICKED(IDC_QRegister, &Register::OnBnClickedQregister)
END_MESSAGE_MAP()


// Register 消息处理程序


void Register::OnBnClickedQregister()
{
	CFile file(
		L"data.dat",
		CFile::modeCreate | CFile::modeWrite);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	User user;
	user.writeUser(Name1, Password1,Email1);
	file.Write(
		&user,
		sizeof(user));
	file.Close();

}


//void Register::OnBnClickedregister()
//{
//	Register Reg;
//	Reg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
//}
