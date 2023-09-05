﻿#pragma once
#include "afxdialogex.h"


// Register 对话框

class Register : public CDialogEx
{
	DECLARE_DYNAMIC(Register)

public:
   Register(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Register();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Zhuce };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Name1;
	CString Password1;
	CString Password2;
	afx_msg void OnBnClickedQregister();
	CString Email1;
//	afx_msg void OnBnClickedregister();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
};
