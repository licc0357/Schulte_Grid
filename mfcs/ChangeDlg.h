#pragma once
#include "afxdialogex.h"


// ChangeDlg 对话框

class ChangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChangeDlg)

public:
	ChangeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChangeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHANGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString ChName;
//	CEdit ChEmail;
	CString ChEmail;
	CString ChPsw;
	CString ChPsw2;
	afx_msg void OnBnClickedChOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedChCl();
	virtual void OnOK();
};
