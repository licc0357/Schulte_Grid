// DataDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "DataDlg.h"


// DataDlg 对话框

IMPLEMENT_DYNAMIC(DataDlg, CDialogEx)

DataDlg::DataDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DATA, pParent)
{

}

DataDlg::~DataDlg()
{
}

void DataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(DataDlg, CDialogEx)
    ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &DataDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// DataDlg 消息处理程序


BOOL DataDlg::OnInitDialog()
{
    if (theApp.now_user.gametime == 0)
    {
        MessageBox(L"先完成游戏再查看吧");
        CDialogEx::OnCancel();
        return TRUE;
    }
    CDialogEx::OnInitDialog();
    SkinH_Attach();
    SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1), TRUE);

	// TODO:  在此添加额外的初始化
    // TODO: Add extra initialization here   
    CRect tabRect;   // 标签控件客户区的位置和大小   
    m_tab.InsertItem(0, _T("个人统计图"));
    m_tab.InsertItem(1, _T("用户排名"));
    m_tab.InsertItem(2, _T("个人统计表"));
    m_chartDlg.Create(IDD_chart, &m_tab);
    m_rankDlg.Create(IDD_rank, &m_tab);
    m_personDlg.Create(IDD_person, &m_tab);
    m_tab.GetClientRect(&tabRect);
    tabRect.left += 1;
    tabRect.right -= 1;
    tabRect.top += 25;
    tabRect.bottom -= 1;
    m_chartDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
    m_rankDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
    m_personDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void DataDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
    // TODO: 在此添加控件通知处理程序代码
    *pResult = 0;
    CRect tabRect;
    m_tab.GetClientRect(&tabRect);
    tabRect.left += 1;
    tabRect.right -= 1;
    tabRect.top += 25;
    tabRect.bottom -= 1;

    switch (m_tab.GetCurSel())
    {
    case 0:
        m_chartDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
        m_rankDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
        m_personDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
        break;
    case 1:
        m_chartDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
        m_rankDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
        m_personDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
        break;
    case 2:
        m_chartDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
        m_rankDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);
        m_personDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);
        break;
    default:
        break;
    }
}
