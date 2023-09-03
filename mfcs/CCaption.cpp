#include "pch.h"
#include "CCaption.h"
#include"login.h"


//HBRUSH CCaption::CtlColor(CDC* pDC, UINT nCtlColor)
//{
//	CFont font;
//	LOGFONT lf;
//	if (!pDC)
//		return NULL;
	//创建一个空画刷，返回这个画刷可以让静态控件的背景透明  
//	HBRUSH hr = (HBRUSH)GetStockObject(NULL_BRUSH);
	//让文字的背景透明  	
//	pDC->SetBkMode(TRANSPARENT);
	//设置文字的颜色为白色  
//	pDC->SetTextColor(RGB(255, 255, 255));
//	::ZeroMemory(&lf, sizeof(lf));
	//设置逻辑字体的高度
//	lf.lfHeight = 24;
	//设置逻辑字体为粗体字  
//	lf.lfWeight = FW_BOLD;
	//设置字体为黑体  
//	::lstrcpy(lf.lfFaceName, _T("宋体"));
	//用逻辑字体创建一个CFont对象  
//	font.CreateFontIndirect(&lf);
	//应用字体  
//	pDC->SelectObject(&font);
//	return hr;
//}


void CCaption::Init(int nX, int nY, int nW, int nH)
{
	// TODO: 在此处添加实现代码.
	MoveWindow(nX, nY, nW, nH);
}
