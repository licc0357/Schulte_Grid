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
	//����״̬ͼ��·��
	CString m_strNormalImgPath;
	//����״̬ͼ��·��
	CString m_strPressImgPath;
	//����״̬ͼ��·��
	CString m_strFloatImgPath;

	//����״̬ͼ��
	CImage m_imgNormal;
	//����״̬ͼ��
	CImage m_imgPress;
	//����״̬ͼ��
	CImage m_imgFloat;

	//���ڱ���ͼƬ
	CImage m_BkImg;

public:

	//���ð�ťͼƬ·��
	void SetImagePath(CString strNoramlImgPath, CString strPressImgPath, CString strFloatImgPath);
	//��ʼ����ť����Ҫ�ǵ�����ť��λ�ã�����͸��ɫ  
	bool InitMyButton(int nX/*���Ͻ�X����*/, int nY/*���Ͻ�Y����*/, int nW/*ͼ���*/, int nH/*ͼ���*/, bool bIsPng/*�Ƿ���PNGͼƬ*/);
	//�Ի��ƺ���  
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	//��ʼ�����ڱ���
	void SetBkImg(CString strBkImg);

protected:
	//����Ƿ��ڴ�����
	BOOL m_bIsInWnd;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();



};

