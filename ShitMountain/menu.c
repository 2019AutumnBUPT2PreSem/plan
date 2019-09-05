#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void modeset(int w,int h);//设置界面大小                  correct
int login();//登录界面                                   correct
int decide(int sort);//决定是哪个种类                     correct              
void userid(int sort);//ID的输入 
void adminid(int sort);//ID的输入 
void judgeid(int sort,char id[10]);//ID的判断             correct             
int innerjudge(char id[10]);//ID多次判断                  correct
void judgepass(int sort,char pass[16],char id[10]);//密码的判断 
int usermenu(int sort);//用户菜单 
int adminmenu(int sort);//管理员菜单 
void markline(int n);//星标行 
void strailine(int n);//直线行
void blankline(int n);//空白行 
 
//用户功能 
void changepersonalinfo();
void checkpackage();
void call();
void checklist();
//用户功能 

//管理员功能 
 
int main()
{
	int log=1;
	modeset(100,50);
	while(log==1)
	{
	    log=login();
    }
	return 0;
}
void modeset(int w,int h)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = {w, h};
	SetConsoleScreenBufferSize(hOut,size);
	SMALL_RECT rc = {1,1, w, h};
	SetConsoleWindowInfo(hOut ,true ,&rc);
	system("cls");
	return;
}

int login()
{
	system("cls");
	int i,sort=1,max=99,mid=47,smid=42,login=0;
	blankline(max);
    markline(max);
    printf("\n");
    blankline(mid);
	printf("LOGIN\n");
    markline(max);
    printf("\n");
	blankline(smid);
	printf("1.adminisitrator");
    blankline(smid);
	printf("2.user\n");
	strailine(max);
	printf("\nPlease choose which identity to log in with:");
	scanf("%d",&sort);
	system("cls");   	
	while(sort!=1&&sort!=2)
	{
		printf("\nError!!!");
		strailine(max);
		printf("\n\nOption does not exist,please choose again!\n");
		strailine(max);
		printf("\n");
		blankline(smid);
	    printf("1.adminisitrator");
        blankline(smid);
    	printf("2.user");
    	strailine(max);
    	printf("\nPlease choose which identity to log in with:");
	    scanf("%d",&sort);
	    system("cls");   
	}
	login=decide(sort);	 
    return login;
}

int decide(int sort)
{
	int login=0;
	if(sort==1)
	{
	    adminid(sort);
	    login=adminmenu(sort);
	}
	else if(sort==2)
	{
		userid(sort);
		login=usermenu(sort);
	}
	return login;
}

void userid(int sort)
{
    int i,cont=0;
	char id[10]={0};
	char pass[16]={0};
    judgeid(sort,id);
	judgepass(sort,pass,id);
}	

void adminid(int sort)
{
	int i,cont=0;
	char id[10]={0};
	char pass[16]={0};
	judgeid(sort,id);
	judgepass(sort,pass,id);
}

void judgeid(int sort,char id[10])
{

    int i,count=0,countc=0,counti=0,prot=0,max=99;
	strailine(max);
	printf("\n");
	printf("Please enter your ID and password\n");
	markline(max);
	printf("\nID:");
	scanf("%s",id);
	int temp=innerjudge(id);
	while(temp==1)
    {
    	temp=innerjudge(id);
    	system("cls");
    	printf("Error!!!\n\nPlease enter the correct ID.");
    	strailine(max);
    	printf("\n");
    	strailine(max);
	    printf("\n");
	    printf("Please enter your ID and password\n");
	    printf("ID:");
	    scanf("%s",id);
	}
}

int innerjudge(char id[10])
{
	int i,count=0,countc=0,counti=0,prot=0,max=99;
    for(i=0;id[i]!='\0';i++)
    {	
	    if(((id[i]>='a')&&(id[i]<='z') )||((id[i]>='A')&&(id[i]<='Z'))||((id[i]>='0')&&(id[i]<='9')))
	    {	
		count++;
		if(((id[i]>='a')&&(id[i]<='z') )||((id[i]>='A')&&(id[i]<='Z')))
		countc++;
		else if((id[i]>='0')&&(id[i]<='9'))
		counti++;	
	    }
	    else 
	    {
		prot=1;
		break;
	    }    
    }
    if(prot==0)
    {
	    if(((countc==0)&&(counti>0))||((countc>0)&&(counti==0)))
	    prot=1;
	    if((count<6)||(count>10))
	    prot=1;
    }
    return prot;
}

void judgepass(int sort,char pass[16],char id[10])
{
	int i,cont=0,max=99;
    printf("\nPassword:");
	scanf("%s",pass);
	while(cont==0)
	{
        for(int i=0;pass[i]!='\0';i++)
	    {
		    cont++;
	    }
	    if(cont>16)
	    {
	    	system("cls");
		    cont=0;
		    markline(max);
            printf("\n\nError!!! \nPassword is incorrect,enter again!\n");
            markline(max);
            printf("\n");
            strailine(max);
            printf("\n");
        	printf("\nPassword:");
        	scanf("%s",pass);
        	system("cls");
        }
        system("cls");
    }
    
}

int usermenu(int sort)
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
	    printf("3.Carrier package inquiry.");
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
	    //changepersonalinfo();
	    //改用户的ID以及显示用户ID 
	        break;
	    case 2:
		//checkpackage();
		//运营商套餐查询 
		    break;
		case 3:
		//call();
		//打电话收费 
		    break;
		case 4:
		//checklist();
		//查询清单
		    break; 
		case 5:
		    login=1;
		    break;
	    } 
	    system("cls");
    }
	return login;	 
}
int adminmenu(int sort)
{
	int i,option,mid=37,smid=34,max=99,login=0;
	while(option!=4&&option!=5)
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
		printf("2.Call charge query statistics management.");
    	blankline(smid);
		printf("3.Package management.");
		blankline(smid);
		printf("4.Back to login.");
		blankline(smid);
		printf("5.Shut down.\n");
		strailine(max);
		printf("\nChoose an option:");
		scanf("%d",&option);
	
		switch(option)
	    {
	    	case 1:
	        	break;
	    	case 2:
		    	break;
			case 3:
			    break;
	    	case 4:
	    		login=1;
	        	break;	
	    	case 5:
	        	break;
	    } 
	    system("cls");
	}
	return login;
}
void markline(int n)
{
	printf("\n");
	for(int i=0;i<=n;i++)
	{ 
	    printf("*");
    }
    
}
void strailine(int n)
{
	printf("\n");
	for(int i=0;i<=n;i++)
	{
		printf("-");
	}
}
void blankline(int n) 
{
	printf("\n");
	for(int i=0;i<=n;i++)
	{
		printf(" ");
	}
}