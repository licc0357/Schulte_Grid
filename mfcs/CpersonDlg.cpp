// CpersonDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "CpersonDlg.h"
#include"User.h"

// CpersonDlg 对话框

IMPLEMENT_DYNAMIC(CpersonDlg, CDialogEx)

CpersonDlg::CpersonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_person, pParent)
{

}

CpersonDlg::~CpersonDlg()
{
}

void CpersonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST2, m_LIST2);
	DDX_Control(pDX, IDC_LIST2, m_List2);
}


BEGIN_MESSAGE_MAP(CpersonDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CpersonDlg::OnLvnItemchangedList2)
END_MESSAGE_MAP()


// CpersonDlg 消息处理程序


BOOL CpersonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	// TODO:  在此添加额外的初始化
	m_List2.GetClientRect(&rect);
	m_List2.SetExtendedStyle(m_List2.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_List2.InsertColumn(1, _T("序号"), LVCFMT_CENTER, rect.Width() / 6, 1);
	m_List2.InsertColumn(2, _T("开始时间"), LVCFMT_CENTER, rect.Width() / 2, 2);
	m_List2.InsertColumn(3, _T("用时"), LVCFMT_CENTER, rect.Width() / 6, 3);
	m_List2.InsertColumn(4, _T("失误次数"), LVCFMT_CENTER, rect.Width() / 6, 4);
	User U;
	U = theApp.now_user;

	for (int i = 0; i <U.gametime; i++) {
		CString str;
		str.Format(L"%d", i + 1);
		m_List2.InsertItem(i, str);
		str = U.G[i].clock.Format(L"%c");
		if (U.G[i].clock == 0)
			str = L"手动添加";
		m_List2.SetItemText(i, 1, str);
		str.Format(L"%.2f", U.G[i].t);
		m_List2.SetItemText(i, 2, str);
		str.Format(L"%d", U.G[i].ernum);
		m_List2.SetItemText(i, 3, str);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CpersonDlg::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
