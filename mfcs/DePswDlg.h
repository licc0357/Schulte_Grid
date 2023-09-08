#pragma once
#include "afxdialogex.h"
#include"User.h"
#include<ctime>
#import"jmail.dll"// 导入jmail.dll, 如jmail.dll不在工程目录下，您需要写上完整路径 
#pragma comment(lib, "comsupp.lib")

// DePswDlg 对话框

class DePswDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DePswDlg)

public:
	DePswDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DePswDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DEPSW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 验证码
	CString CAPTCHA;

	afx_msg void OnBnClickedButtonSend();
	char Code[7];//验证码
	CString DeName;
	User user;
	virtual BOOL OnInitDialog();
	bool issend=0;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CButton Bn_send;
	int t = 60;
	afx_msg void OnBnClickedOk();
};
