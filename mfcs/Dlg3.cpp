// Dlg3.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "Dlg3.h"


// Dlg3 对话框

IMPLEMENT_DYNAMIC(Dlg3, CDialogEx)

Dlg3::Dlg3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_3, pParent)
{

}

Dlg3::~Dlg3()
{
}

void Dlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlg3, CDialogEx)
	ON_BN_CLICKED(IDC_3MFCBUTTON1, &Dlg3::on_num)
	ON_BN_CLICKED(IDC_3MFCBUTTON2, &Dlg3::on_num)
	ON_BN_CLICKED(IDC_3MFCBUTTON3, &Dlg3::on_num)
	ON_BN_CLICKED(IDC_3MFCBUTTON4, &Dlg3::on_num)
	ON_BN_CLICKED(IDC_3MFCBUTTON5, &Dlg3::on_num)
	ON_BN_CLICKED(IDC_3MFCBUTTON6, &Dlg3::on_num)
	ON_BN_CLICKED(IDC_3MFCBUTTON7, &Dlg3::on_num)
	ON_BN_CLICKED(IDC_3MFCBUTTON8, &Dlg3::on_num)
	ON_BN_CLICKED(IDC_3MFCBUTTON9, &Dlg3::on_num)


	ON_BN_CLICKED(IDC_3START, &Dlg3::OnBnClicked3start)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Dlg3 消息处理程序


void Dlg3::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


BOOL Dlg3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	srand(time(0));
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);
	fn->CreatePointFont(400, TEXT("微软雅黑"), NULL);
	// TODO: 在此添加额外的初始化代码
	//初始按钮不可用
	dis_bn();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Dlg3::dis_bn()
{
	// TODO: 在此处添加实现代码.
	for (int i = 1061; i <= 1069; i++)
	{
		//id =1061~1069
		GetDlgItem(i)->EnableWindow(FALSE);
		GetDlgItem(i)->SetFont(fn);
	}

}


void Dlg3::init_bn()
{
	// TODO: 在此处添加实现代码.
	for (int i = 1061; i <= 1069; i++)
	{
		//id =1061~1069
		GetDlgItem(i)->EnableWindow(TRUE);
	}


	int shunxu[9], luanxu[9], i, j;
	CString s;
	for (i = 0; i < 9; i++)
	{
		shunxu[i] = i + 1;
	}
	for (i = 9; i > 0; i--)
	{
		j = rand() % i;
		luanxu[i - 1] = shunxu[j];
		while (j < i - 1)
		{
			shunxu[j] = shunxu[j + 1];
			j++;
		}
	}
	i = 0;
	for (int n = 1061; n <= 1069; n++)
	{
		//id =1061~1069
		SetDlgItemText(n, (s.Format(L"%d", luanxu[i++]), s));

	}

}


void Dlg3::OnBnClicked3start()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!start)
	{
		init_bn();
		//播放bgm
		//CWinThread* pThread = AfxBeginThread(ThreadBgm,(LPVOID)NULL);
		mciSendString(L"open ./bgm.mp3 alias bgm", NULL, 0, NULL);
		mciSendString(L"play bgm repeat", NULL, 0, NULL);
		SetTimer(1, 1, NULL);
		CFont* font = new CFont;
		font->CreatePointFont(100, TEXT("微软雅黑"), NULL);

		GetDlgItem(IDC_3START)->SetFont(font);
		
		start = 1;
		num = 1;
		t0 = CTime::GetCurrentTime();
		starttime = clock();
	}
}


void Dlg3::on_num()
{
	// TODO: 在此处添加实现代码.
	CString m_numT;
	CMFCButton* bn = (CMFCButton*)GetDlgItem(GetFocus()->GetDlgCtrlID());
	//GetDlgItemText(GetFocus()->GetDlgCtrlID(), m_numT);
	GetDlgItemText(bn->GetDlgCtrlID(), m_numT);


	int m_num = _ttoi(m_numT);
	if (m_num != num)//错误变色
	{
		PlaySound(MAKEINTRESOURCE(IDR_WAVE_ER), NULL, SND_RESOURCE | SND_ASYNC);

		//CMFCButton* bn = (CMFCButton*)GetDlgItem(GetFocus()->GetDlgCtrlID());
		//GetDlgItem(GetFocus()->GetDlgCtrlID())->EnableWindow(FALSE);
		//Beep(300,300);
		bn->SetFaceColor(RGB(255, 0, 0));
		bn->m_bTransparent = FALSE;
		bn->m_bDontUseWinXPTheme = TRUE;
		ernum++;
		Invalidate();

	}
	else
	{
		Beep(800, 100);
		//PlaySound(MAKEINTRESOURCE(IDR_WAVE_BN), NULL, SND_RESOURCE | SND_ASYNC);

		//CMFCButton* bn = (CMFCButton*)GetDlgItem(GetFocus()->GetDlgCtrlID());
		bn->EnableWindow(FALSE);
		for (int n = 1061; n <= 1069; n++)
		{
			//id =1061~1069
			CMFCButton* bnall = (CMFCButton*)GetDlgItem(n);
			bnall->m_bTransparent = TRUE;
			bnall->m_bDontUseWinXPTheme = FALSE;

		}

		Invalidate();
		num++;
		if (num == 10)
		{
			endtime = clock();
			times = (double)(endtime - starttime) / CLOCKS_PER_SEC;
			times -= timez;
			CString str;
			str.Format(TEXT("共用时%.2f秒\n失误%d次"), times, ernum);
			MessageBox(str);
		}
	}
}


void Dlg3::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!zanTing)
	{
		CMFCButton* bns = (CMFCButton*)GetDlgItem(IDC_3START);
		endtime = clock();
		times = (double)(endtime - starttime) / CLOCKS_PER_SEC;
		times -= timez;
		CString str;
		str.Format(TEXT("当前用时%.2f秒\n失误%d次"), times, ernum);
		bns->SetWindowTextW(str);
		CDialogEx::OnTimer(nIDEvent);
	}
	CDialogEx::OnTimer(nIDEvent);
}
