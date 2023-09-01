﻿#pragma once
#include "afxdialogex.h"


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
};
