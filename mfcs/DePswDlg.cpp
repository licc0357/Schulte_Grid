// DePswDlg.cpp: 实现文件
//

#include "pch.h"
#include "mfcs.h"
#include "afxdialogex.h"
#include "DePswDlg.h"
#import"jmail.dll"

// DePswDlg 对话框

IMPLEMENT_DYNAMIC(DePswDlg, CDialogEx)

DePswDlg::DePswDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DEPSW, pParent)
	, CAPTCHA(_T(""))
    , DeName(_T(""))
{

}

DePswDlg::~DePswDlg()
{
}

void DePswDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_CAPTCHA, CAPTCHA);
    DDX_Text(pDX, IDC_EDIT_DENAME, DeName);
    DDX_Control(pDX, IDC_BUTTON_SEND, Bn_send);
}


BEGIN_MESSAGE_MAP(DePswDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &DePswDlg::OnBnClickedButtonSend)
    ON_WM_TIMER()
    ON_BN_CLICKED(IDOK, &DePswDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// DePswDlg 消息处理程序


void DePswDlg::OnBnClickedButtonSend()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);
    if (DeName==L"")
    {
        MessageBox(L"请输入用户名！");
        return;
    }
	CFile file(L"data.dat", CFile::modeRead);
    bool isname = 0;
    while (file.Read(&user, sizeof(user)) == sizeof(user))
    {
        CString mName, mPsw, mEmail;
        user.readUser(mName, mPsw, mEmail);
        if (DeName == mName)
        {
            isname = 1;
            break;
        }
        else
        {
            theApp.I_user++;
        }
    }
    if (!isname)
    {
        MessageBox(L"用户名不存在！");
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        int n = rand() % 10;
        Code[i] = n + '0';
    }
    Code[6] = 0;
    CoInitialize(NULL);
    jmail::IMessagePtr pMessage("JMail.Message");
    pMessage->From = "li2083324705@163.com"; //发送邮箱
    pMessage->FromName = "舒尔特方格"; //not must
    pMessage->AddRecipient(user.email, "", ""); //请输入你的接收邮箱
    pMessage->Priority = 3;
    pMessage->Charset = "GB2312";
    pMessage->Subject = "舒尔特方格验证码"; //not must
    pMessage->Body =Code;//not must
    pMessage->MailServerUserName = "li2083324705";
    pMessage->MailServerPassWord = "VBMQAWCFVRCPXZNZ";//发送邮箱密码
    pMessage->Send("smtp.163.com", VARIANT_FALSE);
    pMessage.Release();
    CoUninitialize();
    MessageBox(L"发送成功!");
    t = 60;
    issend = 1;
    SetTimer(1, 60000, NULL);
    SetTimer(2, 1000, NULL);
    Bn_send.EnableWindow(FALSE);
}


BOOL DePswDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // TODO:  在此添加额外的初始化
    srand(time(0));
    return TRUE;  // return TRUE unless you set the focus to a control
    // 异常: OCX 属性页应返回 FALSE
}


void DePswDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    switch (nIDEvent)
    {
    case 1:
        Bn_send.SetWindowTextW(L"发送验证码");

        Bn_send.EnableWindow(TRUE);
        KillTimer(1);
        KillTimer(2);
        issend = 0;
        break;
    case 2:
        CString str;
        t--;
        str.Format(L"%d秒后重新发送", t);
        Bn_send.SetWindowTextW(str);
        break;
    }
  

    
    CDialogEx::OnTimer(nIDEvent);
}


void DePswDlg::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);

    CString str;
    str = Code;
    if (CAPTCHA==str)
    {
        theApp.now_user = user;
        CDialogEx::OnOK();

    }
    else
    {
        MessageBox(L"验证码错误！");
    }
    
}
