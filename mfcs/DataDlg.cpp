// DataDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "DataDlg.h"


// DataDlg 对话框

IMPLEMENT_DYNAMIC(DataDlg, CDialogEx)

DataDlg::DataDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DATA, pParent)
{

}

DataDlg::~DataDlg()
{
}

void DataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DataDlg, CDialogEx)
END_MESSAGE_MAP()


// DataDlg 消息处理程序
