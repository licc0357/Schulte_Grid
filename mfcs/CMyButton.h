#pragma once
#include <afxwin.h>
class CMyButton :
    public CButton
{
	DECLARE_DYNAMIC(CMyButton)

public:
	CMyButton();
	virtual ~CMyButton();

protected:
	//正常状态图像路径
	CString m_strNormalImgPath;
	//按下状态图像路径
	CString m_strPressImgPath;
	//悬浮状态图像路径
	CString m_strFloatImgPath;

	//正常状态图像
	CImage m_imgNormal;
	//按下状态图像
	CImage m_imgPress;
	//悬浮状态图像
	CImage m_imgFloat;

	//窗口背景图片
	CImage m_BkImg;

public:

	//设置按钮图片路径
	void SetImagePath(CString strNoramlImgPath, CString strPressImgPath, CString strFloatImgPath);
	//初始化按钮，主要是调整按钮的位置，处理透明色  
	bool InitMyButton(int nX/*左上角X坐标*/, int nY/*左上角Y坐标*/, int nW/*图像宽*/, int nH/*图像高*/, bool bIsPng/*是否是PNG图片*/);
	//自绘制函数  
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	//初始化窗口背景
	void SetBkImg(CString strBkImg);

protected:
	//光标是否在窗口内
	BOOL m_bIsInWnd;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();



};

