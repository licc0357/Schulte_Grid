#pragma once
class User
{
public:
	char name[50];//�û���
	char psw[50];//����
	char email[50];
	double mintime;//���ʱ��
	double time[20];
	//User();
	//User(CString n, CString p, CString e);
	//~User(void);
	void writeUser(CString n, CString p, CString e);
	void readUser(CString& n, CString& p, CString& e);

};

