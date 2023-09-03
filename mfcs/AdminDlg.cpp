// AdminDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "AdminDlg.h"
#include"AdcDlg.h"

// AdminDlg 对话框

IMPLEMENT_DYNAMIC(AdminDlg, CDialogEx)

AdminDlg::AdminDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADMIN, pParent)
{

}

AdminDlg::~AdminDlg()
{
}

void AdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ADMIN, adminList);
}


BEGIN_MESSAGE_MAP(AdminDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BN_ADD, &AdminDlg::OnBnClickedBnAdd)
END_MESSAGE_MAP()


// AdminDlg 消息处理程序

//添加信息
void AdminDlg::OnBnClickedBnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	AdcDlg adcdlg;
	adcdlg.DoModal();

}
