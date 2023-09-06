#pragma once


// CSplashWnd

class CSplashWnd : public CWnd
{
	DECLARE_DYNAMIC(CSplashWnd)

public:
	CSplashWnd();
	virtual ~CSplashWnd();

protected:
	virtual void PostNcDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	BOOL Create(CWnd* pParentWnd = NULL);
	void HideSplashScreen(void);
	DECLARE_MESSAGE_MAP()

protected:
	CBitmap m_bitmap;
	static CSplashWnd* c_pSplashWnd;
	static BOOL c_bShowSplashWnd;

public:
	static void EnableSplashScreen(BOOL bEnable = TRUE);
	static void ShowSplashScreen(CWnd* pParentWnd = NULL);
	static BOOL PreTranslateAppMessage(MSG* pMsg);
};