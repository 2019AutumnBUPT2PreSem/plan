#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include"dbstruct.h"
#include"arraysupport.c"
#include"dboperation.c"
#include"dbio.c"
#include"utilsupport.c"
#include"decoration.c" 
//#include"service.c"


int loginType();//liuge
void InputIDPW(char *ID,char *PW,int type);//shubing
int InputIDPW_iter(char *ID, char *PW, int type);
int Check4User(tbl user,char* ID,char* PW);
int Check4Admin(tbl admin,char* ID,char* PW);
int userMainBody(tbl provider,tbl user,tbl billinfo,tbl telerecord,tbl netrecord,tbl admin,tbl set,tbl moneyrecord);
int adminMainBody(tbl provider,tbl user,tbl billinfo,tbl telerecord,tbl netrecord,tbl admin,tbl set,tbl moneyrecord);


int loginType()
{
	int type = 0;
    printf("Enter your identity: \n 1.Admin;\n 2.User;\n");
    printf("Or press 0 to exit this programme. Your choice:");
    scanf("%d",&type);
    getchar();
    return type;
}

void InputIDPW(char *pID, char *pPW, int type)
{
	while(InputIDPW_iter(pID, pPW, type));
}

int InputIDPW_iter(char *ID, char *PW, int type)
{
	printf("\nPlease input your ID: ");
	int count1=0;
	int count2=0;
	int i=0;
	
	char id[10]={"\0"};
	gets(id);
	
	for(i=0;i<strlen(id);i++)
	{
		  if(id[i]>='0'&&id[i]<='9')
		   count1++;
		  if(id[i]>='a'&&id[i]<='z')
		   count2++;
	}
	 if(count1==0||count2==0||count1+count2<6||count1+count2>10)
	{
		  printf("Error.");
		  return 1;
	}
 
	 printf("\nPlease input your password: ");
	 char password[16]={"\0"};
	 gets(password);
	 strcpy(ID,id);
	 strcpy(PW,password);
	 return 0;
}

int Check4User(tbl user,char* ID,char* PW)
{
	int MAXROW=user.info.rowNum; 
	int counter_trv=0;
	int IDu=-1;
	int pass=0;
	while(counter_trv<MAXROW&&pass==0)
	{
		if(strcmp(user.clm.phnam[counter_trv][1],ID)==0)
		{
			if(strcmp(user.clm.phnam[counter_trv][3],PW)==0)
			{
				pass++;
				IDu=user.clm.phint[counter_trv][0];
			}
		}
		counter_trv++;
	}
	return IDu;
}

int Check4Admin(tbl admin,char* ID,char* PW)
{
	int MAXROW=admin.info.rowNum; 
	int counter_trv=0;
	int IDa=-1;
	int pass=0;
	while(counter_trv<MAXROW&&pass==0)
	{
		if(strcmp(admin.clm.phnam[counter_trv][0],ID)==0)
		{
			if(strcmp(admin.clm.phnam[counter_trv][2],PW)==0)
			{
				pass++;
				IDa=admin.clm.phint[counter_trv][0];
			}
		}
		counter_trv++;
	}
	return IDa;
}

int userMainBody(tbl provider,tbl user,tbl billinfo,tbl telerecord,tbl netrecord,tbl admin,tbl set,tbl moneyrecord)
{
	int i,option=0,mid=37,smid=34,max=99,login=0;
	while(option!=5)
	{
	    strailine(mid);
        printf("What do you want to do?");
        for(i=0;i<=37;i++)
	    { 
	    printf("-");
        } 
        printf("\n");
        blankline(smid);
	    printf("1.Manage your account information.");
	    blankline(smid);
	    printf("2.Check the bill list.");
	    blankline(smid);
	    printf("3.Order a set.");
	    blankline(smid);
	    printf("4.Make a call.");
	    blankline(smid);
	    printf("5.Back to Login.\n");
	    strailine(max);
	    printf("\n");
	    printf("Choose an option:");
	    scanf("%d",&option);
	    switch(option)
	    {
	    case 1:
	        return 0;
	    case 2:
		    return 0;
		case 3: 
		    return 0;
		case 4:
		    return 0;
		case 5:
		    return 1;
	    } 
	    system("cls");
    }
}

int adminMainBody(tbl provider,tbl user,tbl billinfo,tbl telerecord,tbl netrecord,tbl admin,tbl set,tbl moneyrecord)
{
	int i,option,mid=37,smid=34,max=99,login=0;
	    strailine(mid);
        printf("What do you want to do?");
        for(i=0;i<=37;i++)
	    { 
	    	printf("-");
        } 
    	printf("\n");
    	blankline(smid);
		printf("1.Manage account information.");
		blankline(smid);
		printf("2.Call charge query statistics management.");
    	blankline(smid);
		printf("3.Set management.");
		blankline(smid);
		printf("4.Back to login.");
		strailine(max);
		printf("\nChoose an option:");
		scanf("%d",&option);
	
		switch(option)
	    {
	    	case 1:
	    		/*admin manage*/
	        	return 0;
	    	case 2:
	    		/*statistics*/
		    	return 0;
			case 3:
				/*package*/
			    return 0;
	    	case 4:
	    		/*back to login*/
	    		return 1;
	    	
	    } 
	    system("cls");
}


int main()
{
	/*get all table*/
	tbl provider,user,billinfo,telerecord,netrecord,admin,set,moneyrecord;
	setAllTable(&provider, &user, &billinfo, &telerecord, &netrecord, &admin, &set, &moneyrecord);
	if(existFirstTime(provider,user,billinfo,telerecord,netrecord,admin,set,moneyrecord))
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
