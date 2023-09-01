// C_chartDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "C_chartDlg.h"


// C_chartDlg 对话框

IMPLEMENT_DYNAMIC(C_chartDlg, CDialogEx)

C_chartDlg::C_chartDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_chart, pParent)
{

}

C_chartDlg::~C_chartDlg()
{
}

void C_chartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(C_chartDlg, CDialogEx)
END_MESSAGE_MAP()


// C_chartDlg 消息处理程序
