#include "pch.h"
#include "CCaption.h"
#include"login.h"


//HBRUSH CCaption::CtlColor(CDC* pDC, UINT nCtlColor)
//{
//	CFont font;
//	LOGFONT lf;
//	if (!pDC)
//		return NULL;
	//����һ���ջ�ˢ�����������ˢ�����þ�̬�ؼ��ı���͸��  
//	HBRUSH hr = (HBRUSH)GetStockObject(NULL_BRUSH);
	//�����ֵı���͸��  	
//	pDC->SetBkMode(TRANSPARENT);
	//�������ֵ���ɫΪ��ɫ  
//	pDC->SetTextColor(RGB(255, 255, 255));
//	::ZeroMemory(&lf, sizeof(lf));
	//�����߼�����ĸ߶�
//	lf.lfHeight = 24;
	//�����߼�����Ϊ������  
//	lf.lfWeight = FW_BOLD;
	//��������Ϊ����  
//	::lstrcpy(lf.lfFaceName, _T("����"));
	//���߼����崴��һ��CFont����  
//	font.CreateFontIndirect(&lf);
	//Ӧ������  
//	pDC->SelectObject(&font);
//	return hr;
//}


void CCaption::Init(int nX, int nY, int nW, int nH)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	MoveWindow(nX, nY, nW, nH);
}
