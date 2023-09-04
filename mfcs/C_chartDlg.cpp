// C_chartDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "C_chartDlg.h"
#include"ChartCtrl_source/ChartCtrl.h"
#include"ChartCtrl_source/ChartAxisLabel.h"
#include"User.h"
#include"ChartCtrl_source/ChartLineSerie.h"
#include"ChartCtrl_source/ChartTitle.h"
// C_chartDlg 对话框

IMPLEMENT_DYNAMIC(C_chartDlg, CDialogEx)

C_chartDlg::C_chartDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_chart, pParent)
{

}

C_chartDlg::~C_chartDlg()
{
}

void C_chartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_chart1, m_chart1);
}


BEGIN_MESSAGE_MAP(C_chartDlg, CDialogEx)
END_MESSAGE_MAP()


// C_chartDlg 消息处理程序


BOOL C_chartDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect, rectChart;
	GetDlgItem(IDC_chart1)->GetWindowRect(&rect);
	ScreenToClient(rect);
	rectChart = rect;
	rectChart.top = rect.bottom + 3;
	rectChart.bottom = rectChart.top + rect.Height();
	CChartAxis* pAxis = NULL;
	pAxis = m_chart1.CreateStandardAxis(CChartCtrl::BottomAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_chart1.CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(true);
	// TODO:  在此添加额外的初始化
	TChartString str;
	str = _T("用户完成时间曲线表");
	m_chart1.GetTitle()->AddString(str);

	CChartAxisLabel* pLabel = NULL;
	TChartString str1 = _T("用户所用时间");

	pAxis = m_chart1.GetLeftAxis();
	if (pAxis)
		pLabel = pAxis->GetLabel();
	if (pLabel)
		pLabel->SetText(str1);
	str1 = _T("序号");
	pAxis = m_chart1.GetBottomAxis();
	if (pAxis)
		pLabel = pAxis->GetLabel();
	if (pLabel)
		pLabel->SetText(str1);
	m_chart1.EnableRefresh(false);
	User U;
	U = theApp.now_user;
	double * x, * y;
	x = new double[U.gametime];
	y = new double[U.gametime];
	for (int i = 0; i < U.gametime; i++)
	{
		x[i] = i+1;
		y[i] = U.G[i].t;
	}
	CChartLineSerie* pLineSerie1;
	m_chart1.SetZoomEnabled(true);
	m_chart1.RemoveAllSeries();//先清空
	pLineSerie1 = m_chart1.CreateLineSerie();
	pLineSerie1->AddPoints(x, y, U.gametime);
	pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第一条线"));
	m_chart1.EnableRefresh(true);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
