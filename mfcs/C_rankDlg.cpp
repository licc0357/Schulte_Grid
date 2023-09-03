// C_rankDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "C_rankDlg.h"
#include"User.h"

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
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &C_rankDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// C_rankDlg 消息处理程序

BOOL C_rankDlg::bFlag = TRUE;
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
	CFile file(L"data.dat", CFile::modeRead);
	User U;
	int i = 0;
	while (file.Read(&U, sizeof(U)) == sizeof(U)) {
		CString mName, mPsw, mEmail,str;
		U.readUser(mName, mPsw, mEmail);
		U.Getmintime();
		if (U.gametime)
		{
			m_List1.InsertItem(i, _T("0"));
			m_List1.SetItemText(i, 1, mName);
			str.Format(L"%.2f", U.mintime);
			m_List1.SetItemText(i, 2, str);
			str.Format(L"%d", U.gametime);
			m_List1.SetItemText(i, 3, str);
			i++;
		}

	}
	sort();
	for (int j = 0; j <= i; j++)
	{
		CString str;
		str.Format(L"%d", j + 1);
		m_List1.SetItemText(j, 0, str);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
int CALLBACK C_rankDlg::CompareByNum(LPARAM lP1, LPARAM lP2, LPARAM lP) {
	C_rankDlg* pThis = (C_rankDlg*)lP;

	//分别获取参与排序的两个行的编号

	int nNum1 = _ttoi(pThis->m_List1.GetItemText(lP1, 0));

	int nNum2 = _ttoi(pThis->m_List1.GetItemText(lP2, 0));

	if (bFlag) return nNum2 > nNum1;

	else      return nNum1 > nNum2;
}

void C_rankDlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
void C_rankDlg::sort() 
{
	bFlag = !bFlag;

	int nCount = m_List1.GetItemCount() - 1;

	while (nCount > -1)//为每一行绑定一个值，将来这个值会传递给排序函数的参数lp1和lp2
	{
		m_List1.SetItemData(nCount, nCount);

		nCount--;
	}

	m_List1.SortItems(CompareByNum, (DWORD_PTR)this);
}
