#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include"dbstruct.h"
#include"arraysupport.c"
#include"dboperation.c"
#include"dbio.c"
#include"utilsupport.c"
#include"decoration.c" 
#include"service.c"

int main()
{
	/*get all table*/
	tbl provider,user,billinfo,telerecord,netrecord,admin,set,moneyrecord;

	setAllTable(&provider, &user, &billinfo, &telerecord, &netrecord, &admin, &set, &moneyrecord);
	if(existFirstTime(provider,user,billinfo,telerecord,netrecord,admin,set,moneyrecord) || 1)
	{
		initAllTable(&provider, &user, &billinfo, &telerecord, &netrecord, &admin, &set, &moneyrecord);
	}
	readAllTable(&provider, &user, &billinfo, &telerecord, &netrecord, &admin, &set, &moneyrecord);
	
	/*we gonna read all table there*/
	int quit_prog=0;
	int quit_menu=0;
	int IDu=-1;
	int IDa=-1;
	int type=0;
	char ID[STRLENLIMIT]={"\0"};
	char PW[STRLENLIMIT]={"\0"};
//	char *ID = IDarray;
//	char *PW = PWarray;
	
//	char **idpw = constructD2_char(2, STRLENLIMIT, '\0');
//	idpw[1]={}
	
	while(quit_prog==0)
	{
		quit_menu=0;
		IDu=-1;
		IDa=-1;
		type=loginType();
		if(type==1||type==2)
		{
			InputIDPW(ID,PW,type);//check whether the ID and PW is legal
		}
		if(type==1)
		{
			IDu=Check4User(user,ID,PW);
			if(IDu!=-1)
			{
				while(quit_menu==0)
				{
					quit_menu=userMainBody(provider,user,billinfo,telerecord,netrecord,admin,set,moneyrecord);
				}
			}
				
		}
		else if(type==2)
		{
			IDa=Check4Admin(admin,ID,PW);
			if(IDa!=-1)
			{
				while(quit_menu==0)
				{
					quit_menu=userMainBody(provider,user,billinfo,telerecord,netrecord,admin,set,moneyrecord);
				}
			}
		}
		else if(type==0)
		{
			quit_prog=1;//quit the program
		}
		else
		{	
			system("cls");
			printf("You have input a wrong num,please retry!\n\n");
		}
	}
	/*write table*/
	writeAllTable(&provider, &user, &billinfo, &telerecord, &netrecord, &admin, &set, &moneyrecord);
	printf("Thank you for using!\n");
	
	return 0;
}
