#pragma once
struct game
{
	double t;//用时
	CTime clock;//开始时刻
	int ernum = 0;//失误次数

};
class User
{
public:
	char name[50];//用户名
	char psw[50];//密码
	char email[50];
	double mintime;//最短时间
	game G[50];
	int gametime=0;//完成次数
	//User();
	//User(CString n, CString p, CString e);
	//~User(void);
	void writeUser(CString n, CString p, CString e);
	void readUser(CString& n, CString& p, CString& e);

};

