#pragma once
class User
{
public:
	char name[50];//用户名
	char psw[50];//密码
	char email[50];
	double mintime;//最短时间
	double time[20];
	//User();
	//User(CString n, CString p, CString e);
	//~User(void);
	void writeUser(CString n, CString p, CString e);
	void readUser(CString& n, CString& p, CString& e);

};

