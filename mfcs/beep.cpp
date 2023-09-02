
#include "pch.h"
#include "framework.h"
#include "mfcs.h"
#include "mfcsDlg.h"
#include "afxdialogex.h"
#define qdo 262 
#define qre 294
#define qmi 330     //q前缀为低音，1后缀为高音，s前缀为半音阶 
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do 523
#define re 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define si1 1976
#define sqdo 277
#define sqre 311
#define sqfa 370
#define sqso 415
#define sqla 466
#define sdo 554
#define sre 622
#define sfa 740
#define sso 831
#define sla 932
#define sdo1 1046
#define sre1 1245
#define sfa1 1480
#define sso1 1661
#define sla1 1865

//bgm播放
UINT CmfcsDlg::ThreadBgm(LPVOID bgm)
{
	//TODO: 在此处添加实现代码.
	
	if (bgm==0)
	{
		int pai = 400, ban = 200, four = 100, ei = 50;

		int ting = 70;
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, four);
		Beep(do, four);
		Beep(re, four);
		Beep(do, four + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, four);
		Beep(do, four);
		Beep(re, four);
		Beep(do, four + ting);
		//一节
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, four);
		Beep(do, four);
		Beep(re, four);
		Beep(do, four + ting);
		Beep(fa, ban);
		Beep(mi, ban + ting);
		//2
		Beep(so, ban);
		Beep(la, ban);
		Beep(re, four);
		Beep(do, four);
		Beep(re, four);
		Beep(do, four + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, four);
		Beep(do, four);
		Beep(re, four);
		Beep(do, four + ting);
		//3
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(do1, ban);
		Beep(fa1, ban);
		Beep(mi1, four);
		Beep(fa1, four);
		Beep(mi1, four);
		Beep(re1, four + ting);
		Beep(do1, ban);
		Beep(la, ban);
		//4
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		//5
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		Beep(fa, ban);
		Beep(mi, ban + ting);
		Beep(fa, pai / 8);
		Beep(mi, pai / 8);
		Beep(re, pai / 4);
		Beep(do, ban + ting);
		//6
		Beep(re, ban);
		Beep(do, pai / 4);
		Beep(re, pai / 4 + ting);
		Beep(fa, ban);
		Beep(re, pai / 4);
		Beep(fa, pai / 4 + ting);
		Beep(la, ban);
		Beep(so, pai / 4);
		Beep(la, pai / 4 + ting);
		Beep(do1, ban);
		Beep(la, pai / 4);
		Beep(do1, pai / 4 + ting);
		//7
		Beep(fa1, ban);
		Beep(mi1, pai / 4);
		Beep(fa1, pai / 8);
		Beep(mi1, pai / 8 + ting);
		Beep(re1, ban);
		Beep(do1, ban + ting);
		Beep(re1, pai + ting);
		Beep(re, ban);
		Beep(fa, ban);
		//8
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		//9
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		Beep(fa, ban);
		Beep(mi, ban + ting);
		Beep(fa, pai / 8);
		Beep(mi, pai / 8);
		Beep(re, pai / 4);
		Beep(do, ban + ting);
		//10
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		//11
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(do1, ban);
		Beep(fa1, ban + ting);
		Beep(mi1, pai / 4);
		Beep(fa1, pai / 4);
		Beep(mi1, pai / 4);
		Beep(re1, pai / 4 + ting);
		Beep(do1, ban);
		Beep(la, ban);
		//12
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		//13
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(re, ban / 2);
		Beep(do, ban / 2);
		Beep(re, ban / 2);
		Beep(do, ban / 2 + ting);
		Beep(fa, ban);
		Beep(mi, ban + ting);
		Beep(fa, pai / 8);
		Beep(mi, pai / 8);
		Beep(re, pai / 4);
		Beep(do, ban + ting);
		//14            
		Beep(so, pai / 4);
		Beep(fa, pai / 4);
		Beep(la, pai / 4);
		Beep(do1, pai / 4 + ting);
		Beep(re1, ban / 2);
		Beep(do1, ban / 2);
		Beep(la, ban / 2);
		Beep(so, ban / 2 + ting);
		Beep(re, pai * 3 / 4);
		Beep(fa, ban / 2 + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		//15
		Beep(re, ban);
		Beep(re, ban / 2);
		Beep(re, ban * 1.5 + ting);
		Beep(do, ban + ting);
		Beep(re, pai * 2 + ting);
		//16
		//   
		Beep(re, pai * 3 / 4);
		Beep(re, pai / 4 + ting);
		Beep(re, ban);
		Beep(do, ban + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		Beep(fa, ban);
		Beep(so, ban + ting);
		//17
		Beep(re, pai * 3 / 4);
		Beep(re, pai / 4 + ting);
		Beep(re, ban);
		Beep(do, ban + ting);
		Beep(re, ban);
		Beep(do, ban + ting);
		Beep(qla, ban);
		Beep(do, ban);
		//18          
		Beep(re, (pai + ban) / 2);
		Beep(re, pai / 4 + ting);
		Beep(re, ban);
		Beep(do, ban + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		Beep(fa, ban);
		Beep(so, ban);
		//19
		Beep(la, pai + ting);
		Beep(so, ban);
		Beep(la, pai / 4);
		Beep(so, pai / 4 + ting);
		Beep(fa, pai);
		Beep(re, pai + ting);
		//20
		Beep(re, pai * 3 / 4);
		Beep(re, pai / 4 + ting);
		Beep(re, ban);
		Beep(do, ban + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		Beep(fa, ban);
		Beep(so, ban + ting);
		//21
		Beep(re, pai * 3 / 4);
		Beep(re, pai / 4 + ting);
		Beep(re, ban);
		Beep(do, ban + ting);
		Beep(re, ban);
		Beep(do, ban + ting);
		Beep(do, ban);
		Beep(qla, ban);
		//22          
		Beep(re, (pai + ban) / 2);
		Beep(re, pai / 4 + ting);
		Beep(re, ban);
		Beep(do, ban + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		Beep(fa, ban);
		Beep(so, ban);
		//23
		Beep(la, pai + ting);
		Beep(so, ban);
		Beep(la, pai / 4);
		Beep(so, pai / 4 + ting);
		Beep(fa, pai);
		Beep(re, pai + ting);
		//24
		Beep(fa, pai + ting);
		Beep(mi, pai + ting);
		Beep(re, pai + ting);
		Beep(do, pai + ting);
		//25
		Beep(do, ban);
		Beep(do, pai / 4);
		Beep(re, pai / 4 + ting);
		Beep(qla, ban);
		Beep(qso, ban + ting);
		Beep(qla, pai * 2);
		//26
		Beep(qla, ban + ting);
		Beep(do, pai + ting);
		Beep(re, ban + ting);
		Beep(so, pai + ting);
		Beep(mi, pai + ting);
		//27
		Beep(fa, (3 / 4) * pai);
		Beep(fa, four + ting);
		Beep(mi, ban);
		Beep(do, ban + ting);
		Beep(re, pai * 2);
		//28
		Beep(fa, pai + ting);
		Beep(mi, pai + ting);
		Beep(re, pai + ting);
		Beep(do, pai + ting);
		//29
		Beep(do, ban);
		Beep(do, pai / 4);
		Beep(re, pai / 4 + ting);
		Beep(qla, ban);
		Beep(qso, ban + ting);
		Beep(qla, pai + ting);
		Beep(qla, ban);
		Beep(do, pai + ting);
		//30
		Beep(re, ban + ting);
		Beep(re, pai + ting);
		Beep(re, ban + ting);
		Beep(fa, pai + ting);
		Beep(so, pai + ting);
		//31
		Beep(mi, pai * 3);
		Beep(re, ban);
		Beep(fa, ban + ting);
		//32
		Beep(so, ban);
		Beep(so, four);
		Beep(so, four + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(la, 1.5 * pai + ting);
		Beep(la, ban + ting);
		//33
		Beep(do1, ban);
		Beep(re1, ban + ting);
		Beep(so, ban);
		Beep(fa, ban + ting);
		Beep(la, pai + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		//34
		Beep(so, ban);
		Beep(so, four);
		Beep(so, four + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(la, 1.5 * pai + ting);
		Beep(la, ban + ting);
		//35
		Beep(sla, ban);
		Beep(la, ban + ting);
		Beep(so, ban);
		Beep(fa, pai + ting);
		Beep(fa, pai + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		//36
		Beep(so, ban);
		Beep(so, four);
		Beep(so, four + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(la, 1.5 * pai + ting);
		Beep(la, ban + ting);
		//37
		Beep(do1, ban);
		Beep(re1, ban + ting);
		Beep(so, ban);
		Beep(fa, ban + ting);
		Beep(la, pai + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		//38
		Beep(sla, pai + ting);
		Beep(la, pai + ting);
		Beep(so, pai + ting);
		Beep(fa, pai + ting);
		//39
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(fa, ban);
		Beep(do, ban + ting);
		Beep(re, pai + ting);
		Beep(re, ban);
		Beep(fa, ban);
		//40
		Beep(so, ban);
		Beep(fa, ban + ting);
		Beep(la, ban);
		Beep(do1, ban + ting);
		Beep(re1, pai + ting * 7);
		//,,,,,,,//
		//41
		Beep(fa, pai + ting);
		Beep(mi, pai + ting);
		Beep(re, pai + ting);
		Beep(do, pai + ting);
		//42
		Beep(do, ban);
		Beep(do, pai / 4);
		Beep(re, pai / 4 + ting);
		Beep(qla, ban);
		Beep(qso, ban + ting);
		Beep(qla, pai * 2);
		//43
		Beep(qla, ban + ting);
		Beep(do, pai + ting);
		Beep(re, ban + ting);
		Beep(so, pai + ting);
		Beep(mi, pai + ting);
		//44
		Beep(fa, (3 / 4) * pai);
		Beep(fa, four + ting);
		Beep(mi, ban);
		Beep(do, ban + ting);
		Beep(re, pai * 2);
		//45
		Beep(fa, pai + ting);
		Beep(mi, pai + ting);
		Beep(re, pai + ting);
		Beep(do, pai + ting);
		//46
		Beep(do, ban);
		Beep(do, pai / 4);
		Beep(re, pai / 4 + ting);
		Beep(qla, ban);
		Beep(qso, ban + ting);
		Beep(qla, pai + ting);
		Beep(qla, ban);
		Beep(do, pai + ting);
		//47
		Beep(re, ban + ting);
		Beep(re, pai + ting);
		Beep(re, ban + ting);
		Beep(fa, pai + ting);
		Beep(so, pai + ting);
		//48
		Beep(mi, pai * 3);
		Beep(re, ban);
		Beep(fa, ban + ting);
		//49
		Beep(so, ban);
		Beep(so, four);
		Beep(so, four + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(la, 1.5 * pai + ting);
		Beep(la, ban + ting);
		//50
		Beep(do1, ban);
		Beep(re1, ban + ting);
		Beep(so, ban);
		Beep(fa, ban + ting);
		Beep(la, pai + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		//51
		Beep(so, ban);
		Beep(so, four);
		Beep(so, four + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(la, 1.5 * pai + ting);
		Beep(la, ban + ting);
		//52
		Beep(sla, ban);
		Beep(la, ban + ting);
		Beep(so, ban);
		Beep(fa, pai + ting);
		Beep(fa, pai + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		//53
		Beep(so, ban);
		Beep(so, four);
		Beep(so, four + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(la, 1.5 * pai + ting);
		Beep(la, ban + ting);
		//54
		Beep(do1, ban);
		Beep(re1, ban + ting);
		Beep(so, ban);
		Beep(fa, ban + ting);
		Beep(la, pai + ting);
		Beep(re, ban);
		Beep(fa, ban + ting);
		//55
		Beep(sla, pai + ting);
		Beep(la, pai + ting);
		Beep(so, pai + ting);
		Beep(fa, pai + ting);
		//56
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(so, ban);
		Beep(la, ban + ting);
		Beep(la, pai + ting);
		Beep(mi, ban);
		Beep(so, ban + ting);
		//57
		Beep(la, ban);
		Beep(la, four);
		Beep(la, four + ting);
		Beep(la, ban);
		Beep(si, ban + ting);
		Beep(si, 1.5 * pai + ting);
		Beep(si, ban);
		//58
		Beep(re1, ban);
		Beep(mi1, ban + ting);
		Beep(la, ban);
		Beep(so, ban + ting);
		Beep(si, pai + ting);
		Beep(mi, ban);
		Beep(so, ban + ting);
		//59
		Beep(la, ban);
		Beep(la, four);
		Beep(la, four + ting);
		Beep(la, ban);
		Beep(si, ban + ting);
		Beep(si, 1.5 * pai + ting);
		Beep(si, ban);
		//60
		Beep(do1, ban);
		Beep(si, ban + ting);
		Beep(la, ban);
		Beep(so, ban + ting);
		Beep(so, pai + ting);
		Beep(mi, ban);
		Beep(so, ban + ting);
		//61
		Beep(la, ban);
		Beep(la, four);
		Beep(la, four + ting);
		Beep(la, ban);
		Beep(si, ban + ting);
		Beep(si, 1.5 * pai + ting);
		Beep(si, ban);
		//62
		Beep(re1, ban);
		Beep(mi1, ban + ting);
		Beep(la, ban);
		Beep(so, ban + ting);
		Beep(si, pai + ting);
		Beep(mi, ban);
		Beep(so, ban);
		//63
		Beep(do1, pai + ting);
		Beep(si, pai + ting);
		Beep(la, pai + ting);
		Beep(so, pai + ting);
		//64
		Beep(la, ban);
		Beep(so, ban + ting);
		Beep(si, ban);
		Beep(re1, ban + ting);
		Beep(mi1, pai * 2);
	}
	else
	{
		int pai = 400, ban = 200;
		int ting = 128;
		Beep(la, ban);
		Beep(si, ban);
		Sleep(ting);
		Beep(do1, pai + ban);
		Beep(si, ban);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(mi1, pai);
		Sleep(ting);
		Beep(si, 3 * pai);
		Sleep(ting);
		Beep(mi, ban);
		Beep(mi, ban);
		Beep(la, ban + pai);
		Beep(so, ban);
		Sleep(ting);
		Beep(la, pai);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(so, 2 * pai);
		Sleep(ting);
		Sleep(pai);
		Beep(mi, ban);
		Sleep(ting / 2);
		Beep(mi, ban);
		Sleep(ting / 2);
		Beep(fa, pai + ban);
		Beep(mi, ban);
		Sleep(ting);
		Beep(fa, ban);
		Beep(do1, ban + pai);
		Sleep(ting);
		Beep(mi, 2 * pai);
		Sleep(ting);
		Sleep(ban);
		Beep(do1, ban);
		Sleep(ting / 2);
		Beep(do1, ban);
		Sleep(ting / 2);
		Beep(do1, ban);
		Sleep(ting / 2);
		Beep(si, ban + pai);
		Beep(sfa, ban);
		Sleep(ting);
		Beep(sfa, pai);
		Beep(si, pai);
		Sleep(ting);
		Beep(si, 2 * pai);
		Sleep(ting);
		Sleep(pai);
		Beep(la, ban);
		Beep(si, ban);
		Sleep(ting);
		Beep(do1, pai + ban);
		Beep(si, ban);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(mi1, pai);
		Sleep(ting);
		Beep(si, 2 * pai);
		Sleep(ting);
		Sleep(pai);
		Beep(mi, ban);
		Sleep(20);
		Beep(mi, ban);
		Sleep(ting);
		Beep(la, pai + ban);
		Beep(so, ban);
		Sleep(ting);
		Beep(la, pai);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(so, 3 * pai);
		Sleep(ting + ban);
		Beep(mi, ban);
		Sleep(ting / 2);
		Beep(fa, pai);
		Sleep(ting);
		Beep(do1, ban);
		Beep(si, ban);
		Sleep(20);
		Beep(si, pai);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(re1, ban);
		Sleep(20);
		Beep(re1, ban);
		Sleep(20);
		Beep(mi1, ban);
		Sleep(ting / 2);
		Beep(do1, pai);
		Sleep(ting + pai);
		Beep(do1, pai);
		Beep(si, ban);
		Sleep(ting);
		Beep(la, ban);
		Sleep(20);
		Beep(la, ban);
		Sleep(ting);
		Beep(si, pai);
		Sleep(ting);
		Beep(sso, pai);
		Sleep(ting);
		Beep(sso, 2 * pai);
		Sleep(ting + pai);
		Beep(do1, ban);
		Beep(re1, ban);
		Sleep(ting);
		Beep(mi1, pai + ban);
		Beep(re1, ban);
		Sleep(ting);
		Beep(mi1, pai);
		Sleep(ting);
		Beep(fa1, pai);
		Sleep(ting);
		Beep(re1, 2 * pai);
		Sleep(pai + ting);
		Beep(so, ban);
		Sleep(20);
		Beep(so, ban);
		Sleep(ting);
		Beep(do1, ban);
		Beep(si, ban);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(mi1, pai);
		Sleep(ting);
		Beep(mi1, 2 * pai);
		Sleep(ting + 2 * pai);
		Beep(la, ban);
		Beep(si, ban);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(si, pai);
		Sleep(ting);
		Beep(re1, ban);
		Sleep(20);
		Beep(re1, ban);
		Sleep(ting);
		Beep(do1, pai + ban);
		Beep(so, ban);
		Sleep(20);
		Beep(so, pai);
		Sleep(pai + ting);
		Beep(fa1, pai);
		Sleep(ting);
		Beep(mi1, pai);
		Sleep(ting);
		Beep(re1, pai);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(mi1, 4 * pai);
		Beep(mi1, pai * 2);
		Sleep(pai + ting);
		Beep(mi1, pai);
		Sleep(ting);
		Beep(la1, 2 * pai);
		Sleep(ting);
		Beep(so1, pai);
		Sleep(ting);
		Beep(so1, pai);
		Sleep(ting);
		Beep(mi1, ban);
		Sleep(ting / 2);
		Beep(re1, ban);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting + ban);
		Beep(do1, ban);
		Sleep(ting);
		Beep(re1, pai);
		Sleep(ting);
		Beep(do1, ban);
		Beep(re1, ban);
		Sleep(20);
		Beep(re1, ban);
		Sleep(ting);
		Beep(so1, pai);
		Sleep(ting);
		Beep(mi1, 2 * pai);
		Sleep(ting + pai);
		Beep(mi, pai);
		Sleep(ting);
		Beep(la1, 2 * pai);
		Sleep(ting);
		Beep(so1, 2 * pai);
		Sleep(ting);
		Beep(mi1, ban);
		Beep(re1, ban);
		Sleep(ting);
		Beep(do1, 2 * pai);
		Sleep(ting + ban);
		Beep(do1, ban);
		Sleep(ting);
		Beep(re1, pai);
		Sleep(ting);
		Beep(do1, ban);
		Beep(re1, ban);
		Sleep(20);
		Beep(re1, ban);
		Sleep(ting);
		Beep(si, pai);
		Sleep(ting);
		Beep(la, 2 * pai);
		Sleep(ting);
		Beep(la, ban);
		Beep(si, ban);
		Beep(do1, pai + ban);
		Beep(si, ban);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(mi1, pai);
		Sleep(ting);
		Beep(si, 3 * pai);
		Sleep(ting);
		Beep(mi, ban);
		Beep(mi, ban);
		Beep(la, ban + pai);
		Beep(so, ban);
		Sleep(ting);
		Beep(la, pai);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(so, 2 * pai);
		Sleep(ting);
		Sleep(pai);
		Beep(mi, ban);
		Sleep(ting / 2);
		Beep(mi, ban);
		Sleep(ting / 2);
		Beep(fa, pai + ban);
		Beep(mi, ban);
		Sleep(ting);
		Beep(fa, ban);
		Beep(do1, ban + pai);
		Sleep(ting);
		Beep(mi, 2 * pai);
		Sleep(ting);
		Sleep(ban);
		Beep(do1, ban);
		Sleep(ting / 2);
		Beep(do1, ban);
		Sleep(ting / 2);
		Beep(do1, ban);
		Sleep(ting / 2);
		Beep(si, ban + pai);
		Beep(sfa, ban);
		Sleep(ting);
		Beep(sfa, pai);
		Beep(si, pai);
		Sleep(ting);
		Beep(si, 2 * pai);
		Sleep(ting);
		Sleep(pai);
		Beep(la, ban);
		Beep(si, ban);
		Sleep(ting);
		Beep(do1, pai + ban);
		Beep(si, ban);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(mi1, pai);
		Sleep(ting);
		Beep(si, 2 * pai);
		Sleep(ting);
		Sleep(pai);
		Beep(mi, ban);
		Sleep(20);
		Beep(mi, ban);
		Sleep(ting);
		Beep(la, pai + ban);
		Beep(so, ban);
		Sleep(ting);
		Beep(la, pai);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(so, 3 * pai);
		Sleep(ting + ban);
		Beep(mi, ban);
		Sleep(ting / 2);
		Beep(fa, pai);
		Sleep(ting);
		Beep(do1, ban);
		Beep(si, ban);
		Sleep(20);
		Beep(si, pai);
		Sleep(ting);
		Beep(do1, pai);
		Sleep(ting);
		Beep(re1, ban);
		Sleep(20);
		Beep(re1, ban);
		Sleep(20);
		Beep(mi1, ban);
		Sleep(ting / 2);
		Beep(do1, pai);
		Sleep(ting + pai);
		Beep(la, 4 * pai);
	}
	//int pai = 400, ban = 200, four = 100, ei = 50;
	




	return 0;
}