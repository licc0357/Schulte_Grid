#pragma once
#include "afxdialogex.h"
#include <windows.h> 
#include <mmsystem.h> // 加上，不然PlaySound函数无法使用 
#pragma comment(lib, "winmm.lib") // 加上，不然PlaySound函数无法使用

// Dlg3 对话框

class Dlg3 : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg3)

public:
	Dlg3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dlg3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();
	void dis_bn();
	CFont* fn = new CFont; //字体
	CMenu m_Menu;

	void init_bn();
	afx_msg void OnBnClicked3start();

	CTime t0;//开始时间年月日时分秒
	time_t starttime, endtime;
	
	double times= 0;// 总时间
  
	double timez = 0;  //暂停时间


	bool zanTing = 0;//是否暂停
	time_t zstart, zend;//暂停开始 暂停结束
	int ernum = 0;//错误次数
	int num;
	bool start = 0;//游戏是否开始
	void on_num();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

