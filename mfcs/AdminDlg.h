#pragma once
#include "afxdialogex.h"


// AdminDlg 对话框

class AdminDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AdminDlg)

public:
	AdminDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AdminDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADMIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBnAdd();
	CListCtrl adminList;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBnChange();
	afx_msg void OnNMClickListAdmin(NMHDR* pNMHDR, LRESULT* pResult);

	afx_msg void OnBnClickedBnDelete();
};
