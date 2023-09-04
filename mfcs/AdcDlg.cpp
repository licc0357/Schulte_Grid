// AdcDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "AdcDlg.h"
#include"User.h"


// AdcDlg 对话框

IMPLEMENT_DYNAMIC(AdcDlg, CDialogEx)

AdcDlg::AdcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADC, pParent)
	, adcName(_T(""))
	, adcPsw(_T(""))
	, adcEmail(_T(""))
	, adctime(0)
{

}

AdcDlg::~AdcDlg()
{
}

void AdcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, adcName);
	DDX_Text(pDX, IDC_EDIT_PSW, adcPsw);
	DDX_Text(pDX, IDC_EDIT_EMAIL, adcEmail);
	DDX_Control(pDX, IDC_LIST_ADC, adcList);
	DDX_Text(pDX, IDC_EDIT_adcTime, adctime);
}


BEGIN_MESSAGE_MAP(AdcDlg, CDialogEx)
	ON_BN_CLICKED(IDC_EDIT_Y, &AdcDlg::OnBnClickedEditY)
	ON_BN_CLICKED(IDC_adcTime, &AdcDlg::OnBnClickedadctime)
END_MESSAGE_MAP()


// AdcDlg 消息处理程序


void AdcDlg::OnBnClickedEditY()
{
	// TODO: 在此添加控件通知处理程序代码
	CFile file(L"data.dat",CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate);
	// TODO: 在此添加控件通知处理程序代码
	if (index == -1)
	{
		UpdateData(TRUE);
		User u1;
		CString n, p, e;
		while (file.Read(&u1, sizeof(u1)) == sizeof(u1))
		{
			u1.readUser(n, p, e);
			if (n == adcName)
			{
				MessageBox(L"用户名已存在！");
				return;
			}
		}

	
		user.writeUser(adcName, adcPsw, adcEmail);
		file.SeekToEnd();
		file.Write(&user, sizeof(user));
		file.Close();
		MessageBox(L"添加成功");
		adcEmail.Empty();
		adcName.Empty();
		adcPsw.Empty();
	}
	else
	{
		UpdateData(TRUE);
		if (adcName != theApp.sName)
		{
			User u1;
			CString n, p, e;
			while (file.Read(&u1, sizeof(u1)) == sizeof(u1))
			{
				u1.readUser(n, p, e);
				if (n == adcName)
				{
					MessageBox(L"用户名已存在！");
					return;
				}
			}
		}
		
	

		file.Seek(index * sizeof(user), CFile::begin);
		user.writeUser(adcName, adcPsw, adcEmail);
		file.Write(&user, sizeof(user));
		file.Close();
		MessageBox(L"修改成功");
		adcEmail.Empty();
		adcName.Empty();
		adcPsw.Empty();

	}
	
}


BOOL AdcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (theApp.sName!=L"")
	{
		index = 0;
		User u;
		CString n, p, e;
		CFile adf(L"data.dat", CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate);
		while (adf.Read(&u, sizeof(u)) == sizeof(u))
		{
			u.readUser(n, p, e);
			if (n == theApp.sName)
			{
				user = u;
				adcEmail = u.email;
				adcName = u.name;
				adcPsw = u.psw;
				for (int i = 0; i < u.gametime; i++)
				{
					CString str;
					str.Format(L"%.2f", u.G[i].t);
					adcList.AddString(str);
				}
				UpdateData(FALSE);
				break;
			}
			index++;

		}
	}

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void AdcDlg::OnBnClickedadctime()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str;
	str.Format(L"%.2f", adctime);
	adcList.AddString(str);
	user.G[user.gametime].t = adctime;
	user.gametime++;

	
}
