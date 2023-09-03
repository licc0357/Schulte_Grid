#include "pch.h"
#include "User.h"
void User::writeUser(CString n, CString p, CString e)
{
	CStringA na, pa, ea;
	na = n;
	pa = p;
	ea = e;
	char* strn = na.GetBuffer();
	char* strp = pa.GetBuffer();
	char* stre = ea.GetBuffer();
	strcpy_s(name, strn);
	strcpy_s(psw, strp);
	strcpy_s(email, stre);


}



void User::readUser(CString& n, CString& p, CString& e)
{
	n = name;
	p = psw;
	e = email;
}


double User::Getmintime()
{
	// TODO: 在此处添加实现代码.
	mintime = G[0].t;
	for (int i = 0; i < gametime;i++)
	{
		if (G[i].t < mintime)
		{
			mintime = G[i].t;
		}
	}
	return mintime;
}
