#pragma once
#include "afxdialogex.h"


// AdcDlg 对话框

class AdcDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AdcDlg)

public:
	AdcDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AdcDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString adcName;
	CString adcPsw;
	CString adcEmail;
	afx_msg void OnBnClickedEditY();
	virtual BOOL OnInitDialog();
	int index = -1;//修改位置
};
