// CPswDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "CPswDlg.h"


// CPswDlg 对话框

IMPLEMENT_DYNAMIC(CPswDlg, CDialogEx)

CPswDlg::CPswDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CPSW, pParent)
	, Cpsw(_T(""))
	, Cpsw2(_T(""))
{

}

CPswDlg::~CPswDlg()
{
}

void CPswDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_C_PSW, Cpsw);
	DDX_Text(pDX, IDC_C_PSW2, Cpsw2);
}


BEGIN_MESSAGE_MAP(CPswDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPswDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CPswDlg 消息处理程序


void CPswDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CFile file(L"data.dat", CFile::modeReadWrite);
	if (Cpsw != Cpsw2)
	{
		MessageBox(L"两次输入密码不同");
		return;
	}
	file.Seek(theApp.I_user * sizeof(theApp.now_user), CFile::begin);
	CString n, p, e;
	theApp.now_user.readUser(n, p, e);
	p = Cpsw;
	theApp.now_user.writeUser(n, p, e);
	file.Write(&theApp.now_user, sizeof(theApp.now_user));
	file.Close();
	MessageBox(L"修改成功");
	CDialogEx::OnOK();
}


BOOL CPswDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SkinH_Attach();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
