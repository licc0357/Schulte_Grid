#pragma once
#include "afxdialogex.h"


// C_rankDlg 对话框

class C_rankDlg : public CDialogEx
{
	DECLARE_DYNAMIC(C_rankDlg)

public:
	C_rankDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~C_rankDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_rank };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List1;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
};
