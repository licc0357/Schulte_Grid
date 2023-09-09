#pragma once
#include "afxdialogex.h"
#include <mmsystem.h> // 加上，不然PlaySound函数无法使用 
#pragma comment(lib, "winmm.lib") // 加上，不然PlaySound函数无法使用

// SPdlg 对话框

class SPdlg : public CDialogEx
{
	DECLARE_DYNAMIC(SPdlg)

public:
	SPdlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SPdlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void TransparentPNG(CImage* png);
	CStatic sp_p;
	CImage img;
	CRect rect;

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CProgressCtrl Progress;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL open = 0;
};
