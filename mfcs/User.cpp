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
