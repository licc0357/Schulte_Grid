#pragma once
struct game
{
	double t;//��ʱ
	CTime clock;//��ʼʱ��
	int ernum = 0;//ʧ�����

};
class User
{
public:
	char name[50];//�û���
	char psw[50];//����
	char email[50];
	double mintime;//���ʱ��
	game G[50];
	int gametime=0;//��ɴ���
	//User();
	//User(CString n, CString p, CString e);
	//~User(void);
	void writeUser(CString n, CString p, CString e);
	void readUser(CString& n, CString& p, CString& e);

};

