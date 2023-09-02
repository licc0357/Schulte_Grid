// C_rankDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "C_rankDlg.h"


// C_rankDlg 对话框

IMPLEMENT_DYNAMIC(C_rankDlg, CDialogEx)

C_rankDlg::C_rankDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_rank, pParent)
{

}

C_rankDlg::~C_rankDlg()
{
}

void C_rankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List1);
}


BEGIN_MESSAGE_MAP(C_rankDlg, CDialogEx)
END_MESSAGE_MAP()


// C_rankDlg 消息处理程序


BOOL C_rankDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SkinH_Attach();

	CRect rect;
	// TODO:  在此添加额外的初始化
	m_List1.GetClientRect(&rect);
	m_List1.SetExtendedStyle(m_List1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_List1.InsertColumn(1, _T("名次"), LVCFMT_CENTER, rect.Width() / 4, 1);
	m_List1.InsertColumn(2, _T("用户名"), LVCFMT_CENTER, rect.Width() / 4, 2);
	m_List1.InsertColumn(3, _T("最短用时"), LVCFMT_CENTER, rect.Width() / 4, 3);
	m_List1.InsertColumn(4, _T("完成次数"), LVCFMT_CENTER, rect.Width() / 4, 4);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
