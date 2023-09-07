// ChangeDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "ChangeDlg.h"


// ChangeDlg 对话框

IMPLEMENT_DYNAMIC(ChangeDlg, CDialogEx)

ChangeDlg::ChangeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CHANGE, pParent)
	, ChName(_T(""))
	, ChEmail(_T(""))
	, ChPsw(_T(""))
	, ChPsw2(_T(""))
{

}

ChangeDlg::~ChangeDlg()
{
}

void ChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CH_NAME, ChName);
	//  DDX_Control(pDX, IDC_CH_EM, ChEmail);
	DDX_Text(pDX, IDC_CH_EM, ChEmail);
	DDX_Text(pDX, IDC_CH_PSW, ChPsw);
	DDX_Text(pDX, IDC_CH_PSW2, ChPsw2);
}


BEGIN_MESSAGE_MAP(ChangeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CH_OK, &ChangeDlg::OnBnClickedChOk)
	ON_BN_CLICKED(IDC_CH_CL, &ChangeDlg::OnBnClickedChCl)
END_MESSAGE_MAP()


// ChangeDlg 消息处理程序


void ChangeDlg::OnBnClickedChOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CFile file(L"data.dat", CFile::modeReadWrite);
		UpdateData(TRUE);
		if (ChPsw != ChPsw2)
		{
			MessageBox(L"两次输入密码不同");
			return;
		}
		if (ChName != theApp.now_user.name)
		{
			User u1;
			CString n, p, e;
			while (file.Read(&u1, sizeof(u1)) == sizeof(u1))
			{
				u1.readUser(n, p, e);
				if (n == ChName)
				{
					MessageBox(L"用户名已存在！");
					return;
				}
			}
		}
		User user;
		file.Seek(theApp.I_user * sizeof(user), CFile::begin);
		theApp.now_user.writeUser(ChName, ChPsw, ChEmail);
		file.Write(&theApp.now_user, sizeof(user));
		file.Close();
		MessageBox(L"修改成功");
		CDialogEx::OnOK();

}


BOOL ChangeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CFile file(L"data.dat", CFile::modeRead);
	// TODO: 在此添加控件通知处理程序代码
	ChEmail = theApp.now_user.email;
	ChName = theApp.now_user.name;
	ChPsw2 = theApp.now_user.psw;
	UpdateData(FALSE);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void ChangeDlg::OnBnClickedChCl()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void ChangeDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	OnBnClickedChOk();
}
