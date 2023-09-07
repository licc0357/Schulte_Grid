// SPdlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "SPdlg.h"


// SPdlg 对话框

IMPLEMENT_DYNAMIC(SPdlg, CDialogEx)

SPdlg::SPdlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SP, pParent)
{

}

SPdlg::~SPdlg()
{
}

void SPdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_P_SP, sp_p);
	DDX_Control(pDX, IDC_PROGRESS1, Progress);
}


BEGIN_MESSAGE_MAP(SPdlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// SPdlg 消息处理程序


BOOL SPdlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	COLORREF maskColor = RGB(255, 255, 255);   //掩码颜色  
	SetWindowLong(this->GetSafeHwnd(),
		GWL_EXSTYLE,
		GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE) | 0x80000);  //设定窗体使用扩展模式   
	SetLayeredWindowAttributes(maskColor, 128, LWA_COLORKEY);
	SetTimer(1,2000,NULL);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void SPdlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	sp_p.GetClientRect(&rect); //获得pictrue控件所在的矩形区域
	CDC* dc1 = sp_p.GetDC();//获得pictrue控件1的Dc
	int height, width;
	if (!img.IsNull()) img.Destroy();
	CString imgPath1 = _T("logo.png");
	img.Load(imgPath1);
	height = img.GetHeight();
	width = img.GetWidth();
	//TransparentPNG(&img);                    //调用透明化处理函数
	if (!img.IsNull())
		img.Draw(dc1->m_hDC, CRect(0, 0, width, height));//图片控件2展示处理后的图片
	CDialogEx::OnPaint();
	// 获取含有alpha通道的位图
	
}


HBRUSH SPdlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{

		HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

		// TODO:  Change any attributes of the DC here
		if (nCtlColor == CTLCOLOR_DLG)   //此处设置为窗体透明，CTLCOLOR_DLG表示对话框  
		{
			CBrush* brush;
			brush = new CBrush(RGB(255, 255, 255));
			return (HBRUSH)(brush->m_hObject);
		}
		if (nCtlColor == CTLCOLOR_DLG || nCtlColor == CTLCOLOR_BTN || nCtlColor == CTLCOLOR_STATIC) //静态文本背景透明             
		{
			pDC->SetBkMode(TRANSPARENT);
			pDC->SetTextColor(RGB(0, 0, 0));
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		}
		// TODO:  Return a different brush if the default is not desired
		return hbr;
	

}
void SPdlg::TransparentPNG(CImage* png)
{
	for (int i = 0; i < png->GetWidth(); i++)  				//遍历像素处理
	{
		for (int j = 0; j < png->GetHeight(); j++)
		{
			byte* pucColor = (byte*)(png->GetPixelAddress(i, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
	}
}


void SPdlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnOK();
	CDialogEx::OnTimer(nIDEvent);
}
