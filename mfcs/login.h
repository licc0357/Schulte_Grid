#pragma once
#include "afxdialogex.h"
#include"CCaption.h"
#include"DePswDlg.h"

// login 对话框

class login : public CDialogEx
{
	DECLARE_DYNAMIC(login)

public:
	login(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~login();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Name;
	CString Password;
	afx_msg void OnBnClickedLogin();
//	afx_msg void OnBnClickedregister();
	afx_msg void OnBnClickedregister();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	CBrush m_bkBrush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	CCaption m_staticCap;
	BOOL RPsw;
	BOOL Auto;
//	afx_msg void OnBnClickedMfclink1();
	afx_msg void OnBnClickedButtonLost();
	afx_msg void OnBnClickedCheckPsw();
	afx_msg void OnBnClickedCheckAuto();
};
