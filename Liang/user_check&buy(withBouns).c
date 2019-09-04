#include "dbio.c"
#include "utilsupport.c"
#include "arraysupport.c"
 /*________________________login part__________________1______________________________________*/
int AdminOrUser();
int loginFun(int statu);
 /*________________________user part__________________1_______________________________________*/
void showUserMenu();
 /*________________________user check&buy_____________4_______________________________________*/
void UserMenu();
//void weight_recommend(tbl setTbl);
void IDp2Provider(int IDp,char* providerNam,tbl provider);
void displayTitle();
int Provider2IDp(tbl provider,char* provname);
void checkFromSetName(char* setname,tbl setTbl,tbl provider);
void checkFromProvName(char* provname,tbl setTbl,tbl provider);//鑾峰緱id_provider; 
void sortByPrice(tbl setTbl,tbl provider);// joint_new2d(ID;item 2);
void sortByData(tbl setTbl,tbl provider);
void sortByBoardLength(tbl setTbl,tbl provider);
void sortByForLength(tbl setTbl,tbl provider);
void BuySet(tbl setTbl,tbl* user,tbl* moneyRecord,tbl* billinfo,int IDu);

 /*_________________________user dial_____________________2___________________________________*/
void dial_user(tbl* teleRecord,tbl* billinfo,int IDu);
void net_user(tbl* netRecord,tbl* billinfo,int IDu);
 /*_________________________user info______________________2__________________________________*/
void changePersonInfo(tbl* User,int IDu); 
void checkTeleRecord(tbl teleRecord,int IDu);
void checkTeleRecordByTime(tbl teleRecord,tim time);
void checkNetRecord(tbl netRecord);
void checkNetRecordByTime(tbl netRecord,tim time);
 /*_________________________admin part__________________1_____________________________________*/
void showAdminMenu();
 /*_________________________admin check__________________1____________________________________*/
void checkProviderSet(tbl User);
 /*_________________________admin stat______________________3_________________________________*/
void stat(tbl User,int IDu);
void stat_time(tbl teleRecord);
void stat_sort(tbl billinfo);
 /*_________________________admin set________________________3_________________________________*/
 void checkSet(tbl set,int prov);
 void addNewSet(tbl* set,int prov);
 void changeUserInfo(tbl* User);
 /*_________________________FunOver___________________________________________________________*/
 


void displayTitle()
{
	printf("****************************************************************************************************\n");//100
	printf("Name			|");//16
	printf("Provider   		|");//16
	printf("Set_ID  |");//8
	printf("Price   |");//8
	printf("DomesticCall|");//12
	printf("Internation |");//12
	printf("Data   |");//4
	printf("Description\n");
}

void IDp2Provider(int IDp,char* providerNam,tbl provider)
{
	providerNam=provider.clm.phnam[IDp][0];
}

int Provider2IDp(tbl provider,char* provname)
{
	int row=0;
	int pass=0;
	while(pass=0)
	{
		if(strcmp(provname,provider.clm.phnam[row][0])==0)
		{
			pass++;
		}
		else
		{
			row++;
		}
	}
	return row;
}

void checkFromSetName(char* setname,tbl setTbl,tbl provider)
{
	int row=setTbl.info.rowNum;
	int row_locater=0;
	int cnfrm[row];
	int counter_pass=0;
	int counter_out=0;
	int temp=0;
	int IDp=0;
	char temp_prov[12]={"\0"};
	while(row_locater<row)
	{
		if(strcmp(setname,setTbl.clm.phnam[row_locater][0])==0)
		{
			cnfrm[counter_pass]=row_locater;
			counter_pass++;
		}
		row_locater++;
	}
	if (counter_pass==0)
	{
		printf("there's no set named %s \n",setname);
	}
	else 
	{	
		displayTitle();
		while(counter_out<counter_pass)
		{
			temp=cnfrm[counter_out];
			IDp=setTbl.clm.phint[temp][2];
			IDp2Provider(IDp,temp_prov,provider);
			printf("%s",setname);
			printf("%s",temp_prov);
			printf("%-8d",setTbl.clm.phint[temp][3]);
			printf("%-12d",setTbl.clm.phint[temp][4]);
			printf("%-12d",setTbl.clm.phint[temp][5]);
			printf("%-12d",setTbl.clm.phint[temp][5]);
			printf("%-8d",setTbl.clm.phint[temp][6]);
			printf("%s\n",setTbl.clm.phnam[temp][1]);
			counter_out++;
		}
	}
}


void checkFromProvName(char* provname,tbl setTbl,tbl provider)
{
	int IDp=0;
	int row=0;
	int counter_pass=0;
	IDp=Provider2IDp(provider,provname);
	while(row<setTbl.info.rowNum)
	{
		if(setTbl.clm.phint[row][0]==IDp&&setTbl.clm.phint[row][1]==1)
		{
			if(counter_pass==0)
			{
				displayTitle();
			}
			counter_pass++;
			printf("%s",setTbl.clm.phnam[row][0]);
			printf("%s",provname);
			printf("%-8d",setTbl.clm.phint[row][3]);
			printf("%-12d",setTbl.clm.phint[row][4]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-8d",setTbl.clm.phint[row][6]);
			printf("%s\n",setTbl.clm.phnam[row][1]);
		}
		row++;
	}
}

void sortByPrice(tbl setTbl,tbl provider)
{
	int rowNum=setTbl.info.rowNum;
	int tempArray[rowNum][2];
	int rtrnArray[rowNum];
	int counter_row=0;
	int row=0;
	char provname[16]={"\0"};
	while(counter_row<rowNum)
	{
		tempArray[counter_row][0]=setTbl.clm.phint[counter_row][0];
		tempArray[counter_row][1]=setTbl.clm.phint[counter_row][3];
		counter_row++;
	}
	SortFun(tempArray,rowNum,rtrnArray,CompFun4Int);
	counter_row=0;
	while(counter_row<rowNum)
	{
		row=rtrnArray[counter_row];
		if(setTbl.clm.phint[row][1]==1)//check whether the set is vaild
		{
			if(counter_row==0)
			{
				displayTitle();
			}
			printf("%s",setTbl.clm.phnam[row][0]);
			IDp2Provider(setTbl.clm.phint[row][2],provname,provider);
			printf("%s",provname);
			printf("%-8d",setTbl.clm.phint[row][3]);
			printf("%-12d",setTbl.clm.phint[row][4]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-8d",setTbl.clm.phint[row][6]);
			printf("%s\n",setTbl.clm.phnam[row][1]);
		}
		counter_row++;
	}
}

void sortByData(tbl setTbl,tbl provider)
{
	int rowNum=setTbl.info.rowNum;
	int tempArray[rowNum][2];
	int rtrnArray[rowNum];
	int counter_row=0;
	int row=0;
	char provname[16]={"\0"};
	while(counter_row<rowNum)
	{
		tempArray[counter_row][0]=setTbl.clm.phint[counter_row][0];
		tempArray[counter_row][1]=setTbl.clm.phint[counter_row][6];
		counter_row++;
	}
	SortFun(tempArray,rowNum,rtrnArray,CompFun4Int);
	counter_row=0;
	while(counter_row<rowNum)
	{
		row=rtrnArray[counter_row];
		if(setTbl.clm.phint[row][1]==1)//check whether the set is vaild
		{
			if(counter_row==0)
			{
				displayTitle();
			}
			printf("%s",setTbl.clm.phnam[row][0]);
			IDp2Provider(setTbl.clm.phint[row][2],provname,provider);
			printf("%s",provname);
			printf("%-8d",setTbl.clm.phint[row][3]);
			printf("%-12d",setTbl.clm.phint[row][4]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-8d",setTbl.clm.phint[row][6]);
			printf("%s\n",setTbl.clm.phnam[row][1]);
		}
		counter_row++;
	}
}

void sortByBoardLength(tbl setTbl,tbl provider)
{
	int rowNum=setTbl.info.rowNum;
	int tempArray[rowNum][2];
	int rtrnArray[rowNum];
	int counter_row=0;
	int row=0;
	char provname[16]={"\0"};
	while(counter_row<rowNum)
	{
		tempArray[counter_row][0]=setTbl.clm.phint[counter_row][0];
		tempArray[counter_row][1]=setTbl.clm.phint[counter_row][4];
		counter_row++;
	}
	SortFun(tempArray,rowNum,rtrnArray,CompFun4Int);
	counter_row=0;
	while(counter_row<rowNum)
	{
		row=rtrnArray[counter_row];
		if(setTbl.clm.phint[row][1]==1)//check whether the set is vaild
		{
			if(counter_row==0)
			{
				displayTitle();
			}
			printf("%s",setTbl.clm.phnam[row][0]);
			IDp2Provider(setTbl.clm.phint[row][2],provname,provider);
			printf("%s",provname);
			printf("%-8d",setTbl.clm.phint[row][3]);
			printf("%-12d",setTbl.clm.phint[row][4]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-8d",setTbl.clm.phint[row][6]);
			printf("%s\n",setTbl.clm.phnam[row][1]);
		}
		counter_row++;
	}
}

void sortByForLength(tbl setTbl,tbl provider)
{
	int rowNum=setTbl.info.rowNum;
	int tempArray[rowNum][2];
	int rtrnArray[rowNum];
	int counter_row=0;
	int row=0;
	char provname[16]={"\0"};
	while(counter_row<rowNum)
	{
		tempArray[counter_row][0]=setTbl.clm.phint[counter_row][0];
		tempArray[counter_row][1]=setTbl.clm.phint[counter_row][5];
		counter_row++;
	}
	SortFun(tempArray,rowNum,rtrnArray,CompFun4Int);
	counter_row=0;
	while(counter_row<rowNum)
	{
		row=rtrnArray[counter_row];
		if(setTbl.clm.phint[row][1]==1)//check whether the set is vaild
		{
			if(counter_row==0)
			{
				displayTitle();
			}
			printf("%s",setTbl.clm.phnam[row][0]);
			IDp2Provider(setTbl.clm.phint[row][2],provname,provider);
			printf("%s",provname);
			printf("%-8d",setTbl.clm.phint[row][3]);
			printf("%-12d",setTbl.clm.phint[row][4]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-12d",setTbl.clm.phint[row][5]);
			printf("%-8d",setTbl.clm.phint[row][6]);
			printf("%s\n",setTbl.clm.phnam[row][1]);
		}
		counter_row++;
	}
}

void BuySet(tbl setTbl,tbl* user,tbl* moneyRecord,tbl* billinfo,int IDu)
{
	int choice=-1;
	int haveSetOrNot=0;//0 means no set;1 means have
	if(billinfo->clm.phint[IDu][1]!=0)
		{
			printf("Sorry, you still have a vaild set so you cannot order a new one.\n");
		}
	else if(billinfo->clm.phint[IDu][1]==0&&setTbl.clm.phint[choice][1]==0)
	{
		printf("This set is not available.\n");
	}
	else
	{
		printf("please input the ID of the set to buy a new set,or enter -1 to leave:\n");
		scanf("%d",&choice);
		
		if(choice!=-1&&setTbl.clm.phint[choice][1]==1)
		{
			//first,to get the info of the set
			int prov=setTbl.clm.phint[choice][2];
			int price=setTbl.clm.phint[choice][3];
			int borTime=setTbl.clm.phint[choice][4];
			int forTime=setTbl.clm.phint[choice][5];
			int data=setTbl.clm.phint[choice][6];
			if(user->clm.phint[IDu][3]==0)
			{
				printf("Dear teacher, you will have  discount.\n");
				price=price*0.9;
			}
			else if(user->clm.phint[IDu][3]==1)
			{
				printf("Dear student,you will have 20%% discount.\n");
				price=price*0.8;
			}
			if(billinfo->clm.phint[IDu][10]<price)
			{
				printf("Warning! The account has not enough money!\n");
			}
			else
			{
				user->clm.phint[IDu][4]=prov;//change provider;
				//printf("%d,%d,%d,%d\n",billinfo->clm.phint[IDu][6],billinfo->clm.phint[IDu][7],billinfo->clm.phint[IDu][8],billinfo->clm.phint[IDu][10]);//for test
				billinfo->clm.phint[IDu][6]=borTime;//change billinfo;
				billinfo->clm.phint[IDu][7]=forTime;
				billinfo->clm.phint[IDu][8]=data;
				billinfo->clm.phint[IDu][10]=billinfo->clm.phint[IDu][10]-price;
				printf("Success!\n");
				//printf("%d,%d,%d,%d\n",billinfo->clm.phint[IDu][6],billinfo->clm.phint[IDu][7],billinfo->clm.phint[IDu][8],billinfo->clm.phint[IDu][10]);	//for test			
			}
		}
		/*else
		{
			if(setTbl.clm.phint[choice][1]==0)
			{
				printf("This set is not available now!\n");
			}
		}*/	
	}
}
