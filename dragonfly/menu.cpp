 #include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void modeset(int w,int h);//���ý����С                  correct
void login();//��¼����                                   correct
void decide(int sort);//�������ĸ�����                     correct              
void userid(int sort);//ID������ 
void adminid(int sort);//ID������ 
void judgeid(int sort,char id[10]);//ID���ж�             correct             
int innerjudge(char id[10]);//ID����ж�                  correct
void judgepass(int sort,char pass[16],char id[10]);//������ж� 
void usermenu(int sort);//�û��˵� 
void adminmenu(int sort);//����Ա�˵� 
void markline(int n);//�Ǳ��� 
void strailine(int n);//ֱ����
void blankline(int n);//�հ��� 
 
//�û����� 
void changepersonalinfo();
void checkpackage();
void call();
void checklist();
//�û����� 

//����Ա���� 
 
int main()
{
	modeset(100,50);
	login();
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

void login()
{
	system("cls");
	int i,sort,max=99,mid=47,smid=42;
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
	for(;sort!=1&sort!=2;)
	{
		printf("Error!!!");
		strailine(max);
		printf("\n\nOption does not exist,please choose again!\n");
		strailine(max);
		printf("\n");
		blankline(smid);
	    printf("1.adminisitrator");
        blankline(smid);
    	printf("2.user\n");
    	strailine(max);
		printf("\n\nPlease choose which identity to log in with:");
		scanf("%d",&sort);
	}
	system("cls"); 
	strailine(max);
	decide(sort);	 
}

void decide(int sort)
{
	if(sort==1)
	{
	    adminid(sort);
	    adminmenu(sort);
	}
	else if(sort==2)
	{
		userid(sort);
		usermenu(sort);
	}
	system("cls");
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

void usermenu(int sort)
{
	int i,option=0,mid=37,smid=34;
	while(option!=5&&option!=6)
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
	    printf("5.Back to Login.");
	    blankline(smid);
	    printf("6.Quit.\n");
	    printf("Choose an option:");
	    scanf("%d",&option);
	    switch(option)
	    {
	    case 1:
	    //changepersonalinfo();
	    //���û���ID�Լ���ʾ�û�ID 
	        break;
	    case 2:
		//checkpackage();
		//��Ӫ���ײͲ�ѯ 
		    break;
		case 3:
		//call();
		//��绰�շ� 
		    break;
		case 4:
		//checklist();
		//��ѯ�嵥
		    break; 
		case 5:
		    login();
		    break;
		case 6:
		    break;

	    } 
    }
	system("cls");	 
}
void adminmenu(int sort)
{
	int i,option,mid=37,smid=34;
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
		printf("5.Quit.\n");
		printf("Choose an option:");
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
	    		login();
	        	break;	
	    	case 5:
	        	break;
	    } 
	    system("cls");
	}
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

