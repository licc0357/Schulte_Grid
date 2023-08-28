
// mfcsDlg.h: 头文件
//

#pragma once

#include<time.h>
// CmfcsDlg 对话框
class CmfcsDlg : public CDialogEx
{
// 构造
public:
	CmfcsDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	CMenu m_Menu;
	// 按钮不可用
	void dis_bn();
	// 按钮随机初始化
	void init_bn();
	afx_msg void OnBnClickedStart();
	// 按下数字
	void on_num();
	int num;
	CTime t0;//开始时间年月日时分秒
	time_t start, end;
	// 总时间
	double times;
};
