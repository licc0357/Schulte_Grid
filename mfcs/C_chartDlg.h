#pragma once
#include "afxdialogex.h"

// C_chartDlg 对话框

class C_chartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(C_chartDlg)

public:
	C_chartDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~C_chartDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_chart };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
