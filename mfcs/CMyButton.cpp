#include "pch.h"
#include "CMyButton.h"
#include"login.h"
// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
{
	m_bIsInWnd = FALSE;
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CMyButton 消息处理程序

//设置按钮图片路径
void CMyButton::SetImagePath(CString strNoramlImgPath, CString strPressImgPath, CString strFloatImgPath)
{
	m_strNormalImgPath = strNoramlImgPath;
	m_strPressImgPath = strPressImgPath;
	m_strFloatImgPath = strFloatImgPath;
}

void CMyButton::SetBkImg(CString strBkImg)
{
	if (strBkImg.IsEmpty())
		return;
	m_BkImg.Load(strBkImg);
}

//初始化按钮，主要是调整按钮的位置，处理透明色  
bool CMyButton::InitMyButton(int nX/*左上角X坐标*/, int nY/*左上角Y坐标*/, int nW/*图像宽*/, int nH/*图像高*/, bool bIsPng/*是否是PNG图片*/)
{
	HRESULT hr = 0;

	if (m_strNormalImgPath.IsEmpty())
		return false;
	if (m_strPressImgPath.IsEmpty())
		return false;
	if (m_strFloatImgPath.IsEmpty())
		return false;

	hr = m_imgNormal.Load(m_strNormalImgPath);

	int a = GetLastError();

	if (FAILED(hr))
		return false;

	hr = m_imgPress.Load(m_strPressImgPath);

	if (FAILED(hr))
		return false;

	hr = m_imgFloat.Load(m_strFloatImgPath);

	if (FAILED(hr))
		return false;

	if (bIsPng)
	{
		if (m_imgNormal.GetBPP() == 32)
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < m_imgNormal.GetWidth(); i++)
			{
				for (j = 0; j < m_imgNormal.GetHeight(); j++)
				{
					byte* pbyte = (byte*)m_imgNormal.GetPixelAddress(i, j);
					pbyte[0] = pbyte[0] * pbyte[3] / 255;
					pbyte[1] = pbyte[1] * pbyte[3] / 255;
					pbyte[2] = pbyte[2] * pbyte[3] / 255;
				}
			}
		}

		if (m_imgPress.GetBPP() == 32)
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < m_imgPress.GetWidth(); i++)
			{
				for (j = 0; j < m_imgPress.GetHeight(); j++)
				{
					byte* pbyte = (byte*)m_imgPress.GetPixelAddress(i, j);
					pbyte[0] = pbyte[0] * pbyte[3] / 255;
					pbyte[1] = pbyte[1] * pbyte[3] / 255;
					pbyte[2] = pbyte[2] * pbyte[3] / 255;
				}
			}
		}

		if (m_imgFloat.GetBPP() == 32)
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < m_imgFloat.GetWidth(); i++)
			{
				for (j = 0; j < m_imgFloat.GetHeight(); j++)
				{
					byte* pbyte = (byte*)m_imgFloat.GetPixelAddress(i, j);
					pbyte[0] = pbyte[0] * pbyte[3] / 255;
					pbyte[1] = pbyte[1] * pbyte[3] / 255;
					pbyte[2] = pbyte[2] * pbyte[3] / 255;
				}
			}
		}
	}

	MoveWindow(nX, nY, nW, nH);

	return true;

}
//自绘制函数  
void CMyButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if (!lpDrawItemStruct)
		return;
	HDC hMemDC;
	HBITMAP bmpMem;
	HGDIOBJ hOldObj;
	bmpMem = CreateCompatibleBitmap(lpDrawItemStruct->hDC, lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left, lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top);
	if (!bmpMem)
		return;
	hMemDC = CreateCompatibleDC(lpDrawItemStruct->hDC);
	if (!hMemDC)
	{
		if (bmpMem)
		{
			::DeleteObject(bmpMem);
			bmpMem = NULL;
		}
		return;
	}

	hOldObj = ::SelectObject(hMemDC, bmpMem);

	int nW = lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left;

	int nH = lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top;

	RECT rectTmp = { 0 };

	rectTmp = lpDrawItemStruct->rcItem;

	MapWindowPoints(GetParent(), &rectTmp);

	if (m_BkImg.IsNull() == false)
		m_BkImg.Draw(hMemDC, 0, 0, rectTmp.right - rectTmp.left, rectTmp.bottom - rectTmp.top, rectTmp.left, rectTmp.top, rectTmp.right - rectTmp.left, rectTmp.bottom - rectTmp.top);

	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		//按钮被选择  
		m_imgPress.AlphaBlend(hMemDC, 0, 0, nW, nH, 0, 0, nW, nH);
	}
	else
	{
		//默认状态  
		m_imgNormal.AlphaBlend(hMemDC, 0, 0, nW, nH, 0, 0, nW, nH);

	}

	::BitBlt(lpDrawItemStruct->hDC, 0, 0, nW, nH, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldObj);

	if (bmpMem)
	{
		::DeleteObject(bmpMem);
		bmpMem = NULL;
	}

	if (hMemDC)
	{
		::DeleteDC(hMemDC);
		hMemDC = NULL;
	}
	return;
}

void CMyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CButton::OnMouseMove(nFlags, point);
	if (!m_bIsInWnd)
	{
		TRACKMOUSEEVENT       tme;
		tme.cbSize = sizeof(TRACKMOUSEEVENT);
		tme.dwFlags = TME_HOVER | TME_LEAVE;
		tme.dwHoverTime = 10;
		tme.hwndTrack = m_hWnd;
		_TrackMouseEvent(&tme);
		m_bIsInWnd = TRUE;
	}
}


void CMyButton::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	HDC hMemDC;
	HBITMAP bmpMem;
	HGDIOBJ hOldObj;
	HDC hDC = ::GetDC(GetSafeHwnd());
	CRect rcItem;
	GetClientRect(&rcItem);

	if (hDC)
	{
		bmpMem = CreateCompatibleBitmap(hDC, rcItem.Width(), rcItem.Height());
		if (!bmpMem)
		{
			::ReleaseDC(GetSafeHwnd(), hDC);
			return;
		}
		hMemDC = CreateCompatibleDC(hDC);
		if (!hMemDC)
		{
			if (bmpMem)
			{
				::DeleteObject(bmpMem);
				bmpMem = NULL;
			}
			::ReleaseDC(GetSafeHwnd(), hDC);
			return;
		}

		hOldObj = ::SelectObject(hMemDC, bmpMem);

		RECT rectTmp = { 0 };

		rectTmp = rcItem;

		MapWindowPoints(GetParent(), &rectTmp);

		if (m_BkImg.IsNull() == false)
			m_BkImg.Draw(hMemDC, 0, 0, rectTmp.right - rectTmp.left, rectTmp.bottom - rectTmp.top, rectTmp.left, rectTmp.top, rectTmp.right - rectTmp.left, rectTmp.bottom - rectTmp.top);

		int nW = rcItem.right - rcItem.left;

		int nH = rcItem.bottom - rcItem.top;

		m_imgFloat.AlphaBlend(hMemDC, 0, 0, nW, nH, 0, 0, nW, nH);

		::BitBlt(hDC, 0, 0, nW, nH, hMemDC, 0, 0, SRCCOPY);

		SelectObject(hMemDC, hOldObj);

		if (bmpMem)
		{
			::DeleteObject(bmpMem);
			bmpMem = NULL;
		}

		if (hMemDC)
		{
			::DeleteDC(hMemDC);
			hMemDC = NULL;
		}

		::ReleaseDC(GetSafeHwnd(), hDC);
	}

	CButton::OnMouseHover(nFlags, point);
}


void CMyButton::OnMouseLeave()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CButton::OnMouseLeave();
	InvalidateRect(NULL);
	m_bIsInWnd = FALSE;
}
