﻿// AdminDlg.cpp: 实现文件
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
	ON_BN_CLICKED(IDC_BN_CHANGE, &AdminDlg::OnBnClickedBnChange)
	ON_NOTIFY(NM_CLICK, IDC_LIST_ADMIN, &AdminDlg::OnNMClickListAdmin)
	ON_BN_CLICKED(IDC_BN_DELETE, &AdminDlg::OnBnClickedBnDelete)
END_MESSAGE_MAP()


// AdminDlg 消息处理程序

//添加信息
void AdminDlg::OnBnClickedBnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	AdcDlg adcdlg;
	adcdlg.DoModal();
	adminList.DeleteAllItems();
	CFile file(L"data.dat", CFile::modeRead);
	User U;
	int i = 0;
	while (file.Read(&U, sizeof(U)) == sizeof(U)) {
		CString mName, mPsw, mEmail, str;
		U.readUser(mName, mPsw, mEmail);
		adminList.InsertItem(i, mName);
		adminList.SetItemText(i, 1, mPsw);
		adminList.SetItemText(i, 2, mEmail);
		i++;
	}
	// TODO:  在此添加额外的初始化
	file.Close();

}


BOOL AdminDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SkinH_Attach();
	SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1),TRUE);
	// TODO:  在此添加额外的初始化
	adminList.SetExtendedStyle(adminList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	adminList.InsertColumn(1, _T("用户名"), LVCFMT_CENTER, 100, 1);
	adminList.InsertColumn(2, _T("密码"), LVCFMT_CENTER, 250, 2);
	adminList.InsertColumn(3, _T("email"), LVCFMT_CENTER,250, 3);



	CFile file(L"data.dat", CFile::modeRead);
	User U;
	int i = 0;
	while (file.Read(&U, sizeof(U)) == sizeof(U)) {
		CString mName, mPsw, mEmail, str;
		U.readUser(mName, mPsw, mEmail);
		adminList.InsertItem(i, mName);
		adminList.SetItemText(i, 1, mPsw);
		adminList.SetItemText(i, 2, mEmail);
		i++;
	}
	// TODO:  在此添加额外的初始化
	file.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void AdminDlg::OnBnClickedBnChange()
{
	// TODO: 在此添加控件通知处理程序代码
	if (theApp.sName == L"")
	{
		MessageBox(L"未选择用户！ ");
		return;
	}
	else
	{
		AdcDlg adcdlg;
		adcdlg.DoModal();
		adminList.DeleteAllItems();

		CFile file(L"data.dat", CFile::modeRead);
		User U;
		int i = 0;
		while (file.Read(&U, sizeof(U)) == sizeof(U)) {
			CString mName, mPsw, mEmail, str;
			U.readUser(mName, mPsw, mEmail);
			adminList.InsertItem(i, mName);
			adminList.SetItemText(i, 1, mPsw);
			adminList.SetItemText(i, 2, mEmail);
			i++;
		}
		// TODO:  在此添加额外的初始化
		file.Close();
		
	}

	
}


void AdminDlg::OnNMClickListAdmin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	NMLISTVIEW* pNMListView = (NMLISTVIEW*)pNMHDR;

	if (-1 != pNMListView->iItem)        // 如果iItem不是-1，就说明有列表项被选择   
	{
		// 获取被选择列表项第一个子项的文本   
		theApp.sName= adminList.GetItemText(pNMListView->iItem, 0);
		
	}
	*pResult = 0;
}


void AdminDlg::OnBnClickedBnDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	if (theApp.sName == L"")
	{
		MessageBox(L"未选择用户！ ");
		return;
	}
	else
	{
		
		adminList.DeleteAllItems();
		CFile tfile(L"temp.dat", CFile::modeCreate | CFile::modeWrite);
		CFile dfile(L"data.dat", CFile::modeReadWrite|CFile::shareDenyNone);
		User U;
		int i = 0;
		while (dfile.Read(&U, sizeof(U)) == sizeof(U)) {
			if (U.name != theApp.sName)
			{
				CString mName, mPsw, mEmail, str;
				U.readUser(mName, mPsw, mEmail);
				adminList.InsertItem(i, mName);
				adminList.SetItemText(i, 1, mPsw);
				adminList.SetItemText(i, 2, mEmail);
				i++;
				tfile.Write(&U, sizeof(U));
			}

		}
		dfile.Close();
		dfile.Remove(L"data.dat");
		// TODO:  在此添加额外的初始化
		tfile.Close();
		tfile.Rename(L"temp.dat", L"data.dat");
		tfile.Close();

	}
}
