// Register.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "Register.h"
#include"mfcsDlg.h"
#import"jmail.dll"
using namespace std;


// Register 对话框

IMPLEMENT_DYNAMIC(Register, CDialogEx)

Register::Register(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Zhuce, pParent)
	, Name1(_T(""))
	, Password1(_T(""))
	, Password2(_T(""))
	, Email1(_T(""))
	, Ca(_T(""))
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
	DDX_Control(pDX, IDC_BUTTON_RSEND, Rsend);
	//  DDX_Control(pDX, IDC_EDIT_RCAPTCHA, Rcap);
	DDX_Text(pDX, IDC_EDIT_RCAPTCHA, Ca);
}


BEGIN_MESSAGE_MAP(Register, CDialogEx)
	ON_BN_CLICKED(IDC_QRegister, &Register::OnBnClickedQregister)
	ON_BN_CLICKED(IDC_BUTTON_RSEND, &Register::OnBnClickedButtonRsend)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Register 消息处理程序


void Register::OnBnClickedQregister()
{
	CFile file(
		L"data.dat",
		CFile::modeCreate | CFile::modeReadWrite|CFile::modeNoTruncate);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str;
	str = Code;
	if (Ca != str)
	{
		MessageBox(L"验证码错误！");
		return;
	}
	User u1;
	CString n, p, e;
	while (file.Read(&u1, sizeof(u1))== sizeof(u1))
	{
		u1.readUser(n, p, e);
		if (n==Name1)
		{
			MessageBox(L"用户名已存在！");
			return;
		}
	}
	if (Password1 == Password2) {
		
		User user;
		user.writeUser(Name1, Password1, Email1);
		file.SeekToEnd();
		file.Write(&user,sizeof(user));
		file.Close();
		MessageBox(L"注册成功");
		CDialogEx::OnOK();
	}
	else {
		MessageBox(L"两次输入密码不相同请重新输入");
		file.Close();

	}

}


//void Register::OnBnClickedregister()
//{
//	Register Reg;
//	Reg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
//}


void Register::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	OnBnClickedQregister();
	//CDialogEx::OnOK();
}


BOOL Register::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	srand(time(0));
	SkinH_Attach();
	SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1), TRUE);

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Register::OnBnClickedButtonRsend()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	regex pattern("([0-9A-Za-z\\-_\\.]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)");
	// 正则表达式，匹配规则：
	// 第1组（即用户名），匹配规则：0至9、A至Z、a至z、下划线、点、连字符之中
	// 的任意字符，重复一遍或以上
	// 中间，一个“@”符号
	// 第二组（即域名），匹配规则：0至9或a至z之中的任意字符重复一遍或以上，
	// 接着一个点，接着a至z之中的任意字符重复2至3遍（如com或cn等），
	// 第二组内部的一组，一个点，接着a至z之中的任意字符重复2遍（如cn或fr等）
	// 内部一整组重复零次或一次

	//所以CT2A其实就是CW2A就是将Unicode转换为多字符集ASCII，也可写成CW2A
	string em = CT2A(Email1.GetString());
	if (!regex_match(em, pattern))
	{
		MessageBoxW(L"您输入的邮箱地址不合法！");
		return;
	}
	const char* chem = em.data();
	for (int i = 0; i < 6; i++)
	{
		int n = rand() % 10;
		Code[i] = n + '0';
	}
	Code[6] = 0;
	CoInitialize(NULL);
	jmail::IMessagePtr pMessage("JMail.Message");
	pMessage->From = "li2083324705@163.com"; //发送邮箱
	pMessage->FromName = "舒尔特方格"; //not must
	pMessage->AddRecipient(chem, "", ""); //请输入你的接收邮箱
	pMessage->Priority = 3;
	pMessage->Charset = "GB2312";
	pMessage->Subject = "舒尔特方格验证码"; //not must
	pMessage->Body = Code;//not must
	pMessage->MailServerUserName = "li2083324705";
	pMessage->MailServerPassWord = "VBMQAWCFVRCPXZNZ";//发送邮箱密码
	pMessage->Send("smtp.163.com", VARIANT_FALSE);
	pMessage.Release();
	CoUninitialize();
	MessageBox(L"发送成功!");
	t = 60;
	SetTimer(1, 60000, NULL);
	SetTimer(2, 1000, NULL);
	Rsend.EnableWindow(FALSE);
}


void Register::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1:
		Rsend.SetWindowTextW(L"发送验证码");

		Rsend.EnableWindow(TRUE);
		KillTimer(1);
		KillTimer(2);
		break;
	case 2:
		CString str;
		t--;
		str.Format(L"%d秒后重新发送", t);
		Rsend.SetWindowTextW(str);
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
