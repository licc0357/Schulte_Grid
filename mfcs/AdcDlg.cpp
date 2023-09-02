// AdcDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "AdcDlg.h"


// AdcDlg 对话框

IMPLEMENT_DYNAMIC(AdcDlg, CDialogEx)

AdcDlg::AdcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADC, pParent)
{

}

AdcDlg::~AdcDlg()
{
}

void AdcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdcDlg, CDialogEx)
END_MESSAGE_MAP()


// AdcDlg 消息处理程序
