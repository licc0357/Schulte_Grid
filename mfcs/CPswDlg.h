#pragma once
#include "afxdialogex.h"


// CPswDlg 对话框

class CPswDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPswDlg)

public:
	CPswDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CPswDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CPSW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString Cpsw;
	CString Cpsw2;
};
