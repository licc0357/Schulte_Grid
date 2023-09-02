// AdminDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "AdminDlg.h"


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
}


BEGIN_MESSAGE_MAP(AdminDlg, CDialogEx)
END_MESSAGE_MAP()


// AdminDlg 消息处理程序
