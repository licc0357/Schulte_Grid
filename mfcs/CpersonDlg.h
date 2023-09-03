#pragma once
#include "afxdialogex.h"


// CpersonDlg 对话框

class CpersonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CpersonDlg)

public:
	CpersonDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CpersonDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_person };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CListCtrl m_LIST2;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl m_List2;
};
