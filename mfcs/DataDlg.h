#pragma once
#include "afxdialogex.h"
#include"C_chartDlg.h"
#include"C_rankDlg.h"
#include"CpersonDlg.h"
#include"ChartCtrl_source/ChartCtrl.h"

// DataDlg 对话框

class DataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DataDlg)

public:
	DataDlg(CWnd* pParent = nullptr);   // 标准构造函数
	C_chartDlg m_chartDlg;
	C_rankDlg m_rankDlg;
	CpersonDlg m_personDlg;
	virtual ~DataDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DATA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	CChartCtrl m_ChartCtrl;
};
