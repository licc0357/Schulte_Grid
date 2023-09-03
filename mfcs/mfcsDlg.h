
// mfcsDlg.h: 头文件
//

#pragma once

#include<time.h>
#include <windows.h> 
#include <mmsystem.h> // 加上，不然PlaySound函数无法使用 
#pragma comment(lib, "winmm.lib") // 加上，不然PlaySound函数无法使用


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
	time_t starttime, endtime;
	// 总时间
	double times,timez=0;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnZanting();
	afx_msg void OnUpdateZanting(CCmdUI* pCmdUI);

	bool zanTing = 0;//是否暂停
	time_t zstart, zend;//暂停开始 暂停结束
	int ernum = 0;//错误次数
	afx_msg void OnKaishi();
	bool start = 0;//游戏是否开始
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CFont* fn = new CFont; //字体
	afx_msg void OnSFont();
	afx_msg void OnDeFont();
	// bgm播放
	static UINT  ThreadBgm(LPVOID p);
	afx_msg void On3dlg();
	afx_msg void OnHard();
	int  difficulty = 0;//难度
	// 中止游戏
	void stop();
	afx_msg void OnNormal();
	afx_msg void OnHardhard();

	afx_msg void OnShowdata();
	void writeData();
	afx_msg void OnStop();
	CWinThread* pThread=NULL;//bgm线程
	afx_msg void OnClose();
	afx_msg void Onqby();
	 int bgm=0;
	 int* p = &bgm;
	afx_msg void Ontkzc();
	afx_msg void OnNbgm();
};
