#include<stdio.h>
#include<stdlib.h> 
#include"dbstruct.h"
#include"dbio.c"
#include"utilsupport.c"
#define STRLENLIMIT 16
 /*________________________main structure____________________________________________________*/
int loginType();//liuge
void InputIDPW(char *ID,char *PW,int type);//shubing
int InputIDPW_iter(char *ID, char *PW, int type);
int Check4User(tbl user,char* ID,char* PW);
int Check4Admin(tbl admin,char* ID,char* PW);
int userMainBody(tbl provider,tbl user,tbl billinfo,tbl telerecord,tbl netrecord,tbl admin,tbl set,tbl moneyrecord);
int adminMainBody(tbl provider,tbl user,tbl billinfo,tbl telerecord,tbl netrecord,tbl admin,tbl set,tbl moneyrecord);
void enterEmail(tbl* user,int IDu);
 /*________________________user check&buy____________________________________________________*/
void IDp2Provider(int IDp,char* providerNam,tbl provider);
//From IDp(int) to provider_name ;
void displayTitle();
//show the title of the table;
int Provider2IDp(tbl provider,char* provname);
//From provider_name to IDp;
int checkFromSetName(char* setname,tbl setTbl,tbl provider);
//give back result by giving a set name;
int checkFromProvName(char* provname,tbl setTbl,tbl provider);
//give back result by giving provider name;
void sortByPrice(tbl setTbl,tbl provider);
//Sort by the price and display;
void sortByData(tbl setTbl,tbl provider);
//Sort by the amount of data and display;
void sortByBoardLength(tbl setTbl,tbl provider);
//Sort by the amount of Board call time and display;
void sortByForLength(tbl setTbl,tbl provider);
//Sort by the amount of international call time and display;
void BuySet(tbl setTbl,tbl* user,tbl* moneyRecord,tbl* billinfo,int IDu);
//user decide which set to choose. If user doesn't have enough money or have an available set, this function won't work
void CheckAndBuy(tbl setTbl,tbl* user,tbl* moneyRecord,tbl* billinfo,tbl provider,int IDu);
//the main stucture of this programme
 /*________________________user check&buy____________________________________________________*/
 
void ChargeFun(tbl* billInfo,int IDu)
{
	int charge_cnt=0;
	int over=0;
	printf("If you want to charge, please enter 1\n");
	scanf("%d",&charge_cnt);
	getchar();
	if(charge_cnt==1)
	{
		printf("How much would you like to charge?(integer only)\n");
		printf("1. 10 yuan\n");
		printf("2. 50 yuan\n");
		printf("3. 100 yuan\n");
		int charge_num=0;
		scanf("%d",charge_num);
		getchar();
		if(charge_num==1)
		{
			billInfo->clm.phint[IDu][9]= billInfo->clm.phint[IDu][9]+100;
			printf("Your account now has: %d yuan\n",billInfo->clm.phint[IDu][9]/10.0);
		}
		else if(charge_num==2)
		{
			billInfo->clm.phint[IDu][9]= billInfo->clm.phint[IDu][9]+500;
			printf("Your account now has: %d yuan\n",billInfo->clm.phint[IDu][9]/10.0);
		}
		else if(charge_num==3)
		{
			billInfo->clm.phint[IDu][9]= billInfo->clm.phint[IDu][9]+1000;
			printf("Your account now has: %d yuan\n",billInfo->clm.phint[IDu][9]/10.0);
		}
		else
		{
			printf("you input a wrong number.\n");
		}
	}
}

void dial_user(tbl* teleRecord, tbl* billInfo,  int IDu)
{
	tim startTime;
	tim endTime;
	int teletype=0;
	int telefee=0;
	char telenum[STRLENLIMIT];
	int counter_pass=0;
	int over;
	int totalTime=0;
	if(billInfo->clm.phint[IDu][9] > 0)
	{
		printf("Please enter your startTime:");
		printf("Example:19/09/01 23:40:20");
		scanf("%d",&startTime.yea);
		scanf("%d",&startTime.mon);
		scanf("%d",&startTime.day);
		scanf("%d",&startTime.hou);
		scanf("%d",&startTime.min);
		scanf("%d",&startTime.sec);
		getchar();
		while(counter_pass==0)
		{
			printf("Enter your teletype: 1.Board    2.Foreign");
			scanf("%d",&teletype);
			getchar();
			if(counter_pass==1||counter_pass==2)
			{
				counter_pass++;
			}
			else
			{
				printf("Invaild input! you can only input between 1 or 2");
			}
		}
		
		
		printf("The number you dial:");
		scanf("%s",telenum);
		getchar();

		printf("Please enter your endTime:");
		printf("Example:19/09/01 23:50:30");
		scanf("%d",&endTime.yea);
		scanf("%d",&endTime.mon);
		scanf("%d",&endTime.day);
		scanf("%d",&endTime.hou);
		scanf("%d",&endTime.min);
		scanf("%d",&endTime.sec);
		getchar();
		
		if(cmp_tim(startTime,endTime)==1||cmp_tim(startTime,endTime)==0)
		{
			printf("your dial startTime should before endTime\n");
		}
		else
		{
			if(startTime.sec<endTime.sec)
			{
				over=1;
			}
			else if(startTime.sec>=endTime.sec)
			{
				over=0;
			}
			
			totalTime = ((endTime.day-startTime.day)*24*60)+((endTime.hou-startTime.hou)*60)+(endTime.min-startTime.min)+over;

			if(teletype==1)
			{
				if(billInfo->clm.phint[IDu][6] >= totalTime)
				{
					billInfo->clm.phint[IDu][6] = billInfo->clm.phint[IDu][6] - totalTime;
				}
				else
				{
					telefee = (totalTime - billInfo->clm.phint[IDu][6])*5;
					billInfo->clm.phint[IDu][6] = 0;
				}
			}
			else if(teletype==2)
			{
				if(billInfo->clm.phint[IDu][7] >= totalTime)
				{
					billInfo->clm.phint[IDu][7] = billInfo->clm.phint[IDu][7] - totalTime;
				}
				else
				{
					telefee = (totalTime - billInfo->clm.phint[IDu][7])*20;
					billInfo->clm.phint[IDu][7] = 0;
				}
			}
			billInfo->clm.phint[IDu][9] = billInfo->clm.phint[IDu][9] - telefee;
			int inte[5]={teleRecord->info.rowNum,1,teletype,telefee,IDu};
			char **nam;
			nam=constructD2_char(1,STRLENLIMIT,'\0');
			strcpy(nam[0],telenum);
			tim time[2];
			time[0]=startTime;
			time[1]=endTime;
			addrow(teleRecord,inte,nam,time);
		}
	}
	else
	{
		printf("Please charge!\n");
		ChargeFun(billInfo,IDu);
	}

}

void net_user(tbl* netRecord, tbl* billInfo, int IDu)
{
	tim Time;
	int comAmount=0;
	int netfee=0;
	int counter_pass=0;
	if(billInfo->clm.phint[IDu][9] > 0)
	{
		printf("Please enter your Time:");
		printf("Example:19/09/01");
		scanf("%d",&Time.yea);
		scanf("%d",&Time.mon);
		scanf("%d",&Time.day);
		getchar();
	
		printf("The data use:");
		scanf("%d",&comAmount);
		getchar();

			if(billInfo->clm.phint[IDu][8] >= comAmount)
				{
					billInfo->clm.phint[IDu][8] = billInfo->clm.phint[IDu][8] - comAmount;
				}
				else
				{
					netfee = (comAmount - billInfo->clm.phint[IDu][8])*1;
					billInfo->clm.phint[IDu][8] = 0;
				}
			int inte[4]={netRecord->info.rowNum,1,netfee,IDu};
			char **nam=NULL;
			tim time[1];
			time[0]=Time;
			addrow(netRecord,inte,nam,time);
	}
	
	else
	{
		printf("Please charge!\n");
		ChargeFun(billInfo,IDu);
	}

}

void changePersonInfo(tbl* User,int IDu)
{
	printf("Which one do you want to change: 1.Telephone Number    2.User Password    3.User Email    4.Quit");
	int type;
	scanf("%d",&type);
	switch(type)
	{
			case 1:
	{
		printf("Enter your new number:");
		scanf("%d",&User->clm.phnam[IDu][2]);
		printf("Your telephone number is setted.");
		break;
	}
	case 2:
	{
		printf("Enter your new password:");
		scanf("%d",&User->clm.phnam[IDu][3]);
		printf("Your password is setted.");
		break;
	}
	case 3:
	{
		printf("Enter your new email:");
		enterEmail(User,IDu);
		printf("Your email is setted.");
		break;
	}
	case 4:
	{
		break;
	}
	default:
	{
		printf("Error!");
		changePersonInfo(User, IDu);
	}
	}
	

}

void checkTeleRecord(tbl teleRecord, int IDu)
{
	int row=teleRecord.info.rowNum;
	int row_locater=0;
	int counter_pass=0;
	while(row_locater<=row)
	{
		if(teleRecord.clm.phint[row_locater][4]==IDu)
		{
			printf("IDt:%d\n",teleRecord.clm.phint[row_locater][0]);
			printf("validt:%d\n",teleRecord.clm.phint[row_locater][1]);
			printf("type:%d\n",teleRecord.clm.phint[row_locater][2]);
			printf("teleFee:%d\n",teleRecord.clm.phint[row_locater][3]);
			printf("user:%d\n",teleRecord.clm.phint[row_locater][4]);
			printf("to:%s\n",teleRecord.clm.phnam[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
		}
		row_locater++;
	}	
}

void checkTeleRecordByTime(tbl teleRecord, int IDu)
{
	tim temp_time;
	printf("Please enter your time like this 19/09/01 21:50:10\n");
	printf("time:");
	scanf("%2d/%2d/%2d %2d:%2d:%2d",&temp_time.yea,&temp_time.mon,&temp_time.day,&temp_time.hou,&temp_time.min,&temp_time.sec);
	int row_locater=0;
	int counter_pass=0;
	while(row_locater<teleRecord.info.rowNum)
	{
		if(cmp_tim(temp_time,teleRecord.clm.phtim[row_locater][0])==1&&teleRecord.clm.phint[row_locater][4]==IDu)
		{
			printf("IDt:%d\n",teleRecord.clm.phint[row_locater][0]);
			printf("validt:%d\n",teleRecord.clm.phint[row_locater][1]);
			printf("type:%d\n",teleRecord.clm.phint[row_locater][2]);
			printf("teleFee:%d\n",teleRecord.clm.phint[row_locater][3]);
			printf("user:%d\n",teleRecord.clm.phint[row_locater][4]);
			printf("to:%s\n",teleRecord.clm.phnam[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("startTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d",teleRecord.clm.phtim[row_locater][0]);
			printf("endTime:%02d\n",teleRecord.clm.phtim[row_locater][0]);
			counter_pass++;
		}
		row_locater++;
	}
	if(counter_pass==0)
	{
		printf("Sorry,there's no matching record.");
	}
}

void checkNetRecord(tbl netRecord, int IDu)
{
	int row=netRecord.info.rowNum;
	int row_locater=0;
	int counter_pass=0;
	while(row_locater<=row)
	{
		if(netRecord.clm.phint[row_locater][4]==IDu)
		{
			printf("IDn:%d\n",netRecord.clm.phint[row_locater][0]);//buzhidaogeduoshaoge
			printf("validn:%d\n",netRecord.clm.phint[row_locater][1]);
			printf("comAmount:%d\n",netRecord.clm.phint[row_locater][2]);
			printf("netFee:%d\n",netRecord.clm.phint[row_locater][3]);
			printf("user:%d\n",netRecord.clm.phint[row_locater][4]);
			printf("time:%02d",netRecord.clm.phtim[row_locater][0]);
			printf("time:%02d",netRecord.clm.phtim[row_locater][0]);
			printf("time:%02d\n",netRecord.clm.phtim[row_locater][0]);
		}
		row_locater++;
	}	
}

void checkNetRecordByTime(tbl netRecord, int IDu)
{
	tim temp_time;
	printf("Please enter your time like this 19/09/01\n");
	printf("time:");
	scanf("%2d/%2d/%2d",&temp_time.yea,&temp_time.mon,&temp_time.day);
	int row_locater=0;
	int counter_pass=0;
	while(row_locater<netRecord.info.rowNum)
	{
		if(cmp_tim(temp_time,netRecord.clm.phtim[row_locater][0])==1&&netRecord.clm.phint[row_locater][4]==IDu)
		{
			printf("IDn:%d\n",netRecord.clm.phint[row_locater][0]);//buzhidaogeduoshaoge
			printf("validn:%d\n",netRecord.clm.phint[row_locater][1]);
			printf("comAmount:%d\n",netRecord.clm.phint[row_locater][2]);
			printf("netFee:%d\n",netRecord.clm.phint[row_locater][3]);
			printf("user:%d\n",netRecord.clm.phint[row_locater][4]);
			printf("time:%02d",netRecord.clm.phtim[row_locater][0]);
			printf("time:%02d",netRecord.clm.phtim[row_locater][0]);
			printf("time:%02d\n",netRecord.clm.phtim[row_locater][0]);
			counter_pass++;
		}
		row_locater++;
	}
	if(counter_pass==0)
	{
		printf("Sorry,there's no matching record.");
	}
}

void stat(tbl User, tbl moneyRecord, int IDp)
{
	int row=User.info.rowNum;
	int rowMoney=moneyRecord.info.rowNum;
	int row_locater=0;
	int rowMoney_locater=0;
	int counter_pass=0;
	while(row_locater<=row)
	{
		if(User.clm.phint[row_locater][4] == IDp)
		{
			printf("Name: %s ",User.clm.phnam[row_locater][0]);
			while(rowMoney_locater<=rowMoney)
			{
				if(User.clm.phint[row_locater][0] == moneyRecord.clm.phint[rowMoney_locater][2])
				{
					printf("Time:%02d",moneyRecord.clm.phtim[rowMoney_locater][0]);
					printf("Time:%02d",moneyRecord.clm.phtim[rowMoney_locater][0]);
					printf("Time:%02d\n",moneyRecord.clm.phtim[rowMoney_locater][0]);
				}
				rowMoney_locater++;
			}
			counter_pass++;
		}
		row_locater++;
	}
	if (counter_pass==0)
	{
		printf("there's no user.");
	}
} 

void checkSet(tbl set,int prov)
{ 
	int row=set.info.rowNum;
	int row_locater=0;
	int counter_pass=0;
	while(row_locater<=row)
	{
		if(set.clm.phint[row_locater][2]==prov)
		{
			printf("price:%d\n",set.clm.phint[prov][3]);
			printf("netAmount:%d\n",set.clm.phint[prov][4]);
 			printf("borTime:%d\n",set.clm.phtim[prov][0]);
 			printf("forTime:%d\n",set.clm.phtim[prov][1]);
 			printf("setname:%s\n",set.clm.phnam[prov][0]);
 			printf("description:%s\n",set.clm.phnam[prov][1]);
 			counter_pass++;
		}
		row_locater++;
	}	
	if (counter_pass==0)
	{
		printf("there's no.");
	}
}

void addNewSet(tbl* set,int prov)
{
	int bortime, fortime, data, price;
	char name[STRLENLIMIT];
	printf("Price  Bortime  Fortime  Date  Name");
	scanf("%d%d%d%d%s",&price,&bortime,&fortime,&data,name);
	int inte[7]={set->info.rowNum,1,prov,price,bortime,fortime,data};
	//char nam[STRLENLIMIT]=name;
	char **nam=constructD2_char(1,STRLENLIMIT,'\0');
	strcpy(nam[0],name);
	tim *time=NULL;
	addrow(set,inte,nam,time);
}


 void changeUserInfo(tbl* User, int IDp,int IDu)
 {
 	printf("Which one do you want to change: 1.User Password    2.User Email    3.Quit");
	int type;
	scanf("%d",&type);
	switch(type)
	{
		case 1:
	{
		printf("Enter new password:");
		scanf("%d",&User->clm.phnam[IDp][3]);
		printf("Password is setted.");
		break;
	}
	case 2:
	{
		printf("Enter new email:");
		enterEmail(User,IDu);
		printf("Email is setted.");
		break;
	}
	case 3:
	{
		break;
	}
	default:
	{
		printf("Error!");
		changeUserInfo(User,IDp,IDu);
	}
	}
	
 }

void stattele(tbl teleRecord, int IDp)
{
	int row=teleRecord.info.rowNum;
	int row_locater=0;
	int bortotalTime=0;
	int fortotalTime=0;
	while(row_locater<=row)
	{
		if(teleRecord.clm.phint[row_locater][4] == IDp)
		{

			bortotalTime = bortotalTime + teleRecord.clm.phint[row_locater][5];
			fortotalTime = fortotalTime + teleRecord.clm.phint[row_locater][6];
		}
		row_locater++;
	}
	printf("Dial in borad is %d minutes",bortotalTime);
	printf("Dial in foreign is %d minutes",fortotalTime);
}

int timSgmetSupport(tim startTime,tim endTime,int startHour)
{
		if(endTime.day==startTime.day)//not allow to over a day;
		{
			if(startTime.hou>=startHour)// possibility 1:starthour before the startTime
			{
				if(endTime.hou<=startHour+2)//possibility 1.1 endTime before the endHour
				{
					if(endTime.sec-startTime.sec>0)
					{
						return (endTime.hou-startTime.hou)*60+endTime.min-startTime.min+1;
					}
					else
					{
						return (endTime.hou-startTime.hou)*60+endTime.min-startTime.min;
					}
				}
				else if(endTime.hou>startHour+2)//possibility 1.2 endTime After the endHour
				{
					if(endTime.sec>0)
					{
						return (endTime.hou-startHour)*60+endTime.min+1;
					}
					else
					{
						return (endTime.hou-startHour)*60+endTime.min;
					}
				}
			}
			else if(startTime.hou<startHour&&endTime.hou>=startHour)// possibility 2:starthour after the startTime,and before the endTime
			{
				int temp_min=0;
				int over=0;
				if(endTime.sec!=0)
				{
					over=1;
				}
				temp_min=(endTime.hou-startHour)*60+(endTime.min-startTime.min)+over;
				return temp_min;
			}
		}
//		else//we temporarily don't support the over day due to the design of the table hasn't finished; 
//		{
//			int temp_sec=86400;
//			temp_sec=temp_sec+(endTime.hou-startTime.hou)*60*60+(endTime.min-startTime.min)*60+(endTime.sec-startTime.sec);
//			int temp_min=0;
//			temp_min=temp_sec/60;
//			if(temp_sec%60!=0)
//			{
//				temp_min++;
//				if(temp_min>=120)
//				{
//					return 120;
//				}
//				else
//				{
//					return temp_min;
//				}
//			}
//			else
//			{
//				if(temp_min>=120)
//				{
//					return 120;
//				}
//				else
//				{
//					return temp_min;
//				}
//			}
//		}
}

void sortCallingByTimeSgmt(tbl teleRecord,int type)
{
	int temp[12][2];
	int counter_init=0;
	while(counter_init<12)//init a TimeSgmt Array
	{
		temp[counter_init][0]=(counter_init*2);
		temp[counter_init][1]=0;
		counter_init++;
	}
	int counter_trv=0;
	int counter_sgmt=0;
	int sum=0;
	while(counter_sgmt<12)
	{
		counter_trv=0;
		sum=0;
		if(type==1)
		{
			while(counter_trv<teleRecord.info.rowNum)
			{
				if(teleRecord.clm.phint[counter_trv][2]==1)//manual filiter
				{
					sum=sum+timSgmetSupport(teleRecord.clm.phtim[counter_trv][0],teleRecord.clm.phtim[counter_trv][1],temp[counter_sgmt][0]);//get the sum time
				}
				counter_trv++;
			}
			temp[counter_sgmt][1]=sum;
			counter_sgmt++;
		}
		else if(type==2)
		{
			while(counter_trv<teleRecord.info.rowNum)
			{
				if(teleRecord.clm.phint[counter_trv][2]==2)
				{
					sum=sum+timSgmetSupport(teleRecord.clm.phtim[counter_trv][0],teleRecord.clm.phtim[counter_trv][1],temp[counter_sgmt][0]);
				}
				counter_trv++;
			}
			temp[counter_sgmt][1]=sum;
			counter_sgmt++;
		}
		
	}
	int rtrnArray[12];
	SortFun(temp,12,rtrnArray,CompFun4Int);//return after_sorting id_tele Array;
	int counter_show=0;
	while(counter_show<12)
	{
		if(counter_show==0)//print the type of the telerecord
		{
			if(type==1)
			{
				printf("Type:Board Tele\n");
			}
			else if(type==2)
			{
				printf("Type:International Tele\n");
			}
		}
		printf("%2d:00-%2d:00 sum:%d\n",temp[rtrnArray[counter_show]][0],temp[rtrnArray[counter_show]][0]+2,temp[rtrnArray[counter_show]][1]);
		counter_show++;
	}
}

void sortFee(tbl User, tbl teleRecord, tbl netRecord, int IDp)
{
	int row=User.info.rowNum;
	int rowtele_locater=0;
	int rownet_locater=0;
	int telenumber=0;
	int tele[telenumber];
	int IDtele[telenumber];
	int netnumber=0;
	int net[netnumber];
	int IDnet[netnumber];

	while(rowtele_locater<=row)
	{
		if(User.clm.phint[rowtele_locater][4] == IDp)
		{		
			tele[telenumber] = teleRecord.clm.phint[rowtele_locater][3];
			IDtele[telenumber] = teleRecord.clm.phint[rowtele_locater][4];
			telenumber++;
		}
		rowtele_locater++;
	}
	int i=0;
	int j=0;
	int temp1=0;
	int temp=0;
	for(j=0; j<telenumber; j++)
	{
		 for(i=0; i<telenumber-1-j; i++)
		{
		 	if(tele[i]<tele[i+1])
			{
	 		temp=tele[i];
			tele[i]=tele[i+1];
			tele[i+1]=temp;

			temp1=IDtele[i];
			IDtele[i]=IDtele[i+1];
			IDtele[i+1]=temp1;
			}
		 }
	}

	printf("Sorted telephone charges：");
    for(int i=0; i<telenumber; i++)
    {
        printf("%d\n",IDtele[i]);
    }

	while(rownet_locater<=row)
	{
		if(User.clm.phint[rownet_locater][4] == IDp)
		{
			net[netnumber] = netRecord.clm.phint[rownet_locater][3];
			IDnet[netnumber] = netRecord.clm.phint[rownet_locater][4];
			netnumber++;
		}
		rowtele_locater++;
	}

	i=0;
	j=0;
	temp1=temp=0;
	 for(j=0; j<netnumber; j++)
	{
		 for(i=0; i<netnumber-1-j; i++)
		 {
		 	if(net[i]<net[i+1])
		 	 	 {
		 	 	 	 temp=net[i];
		 	 	 	 net[i]=net[i+1];
		 	 	 	 net[i+1]=temp;

		 	 	 	 temp1=IDnet[i];
		 	 	 	 IDnet[i]=IDnet[i+1];
		 	 	 	 IDnet[i+1]=temp1;
		 	 	 }
		 }
	}

	printf("Sorted telephone charges：");
    for(int i=0; i<netnumber; i++)
    {
        printf("%d\n",IDnet[i]);
    }
}

void enterEmail(tbl* user,int IDu)
{
    char mailName[STRLENLIMIT];
    printf("Please enter your mailname XXX@XXX.com:\n");
    printf("for example ILOVEBUPT@bupt.com (mail name must less than 15)\n");
    while(scanf ("%s",mailName)!= EOF)
    {
        strcpy(user->clm.phnam[IDu][4],mailName);
    }
}


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
	providerNam=provider.clm.phnam[IDp][0];//IDp is the primaty key in provider table
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

int checkFromSetName(char* setname,tbl setTbl,tbl provider)
{
	int row=setTbl.info.rowNum;
	int row_locater=0;
	int cnfrm[row];
	int counter_pass=0;
	int counter_out=0;
	int temp=0;
	int IDp=0;
	char temp_prov[STRLENLIMIT]={"\0"};
	
	while(row_locater<row)//judge whether there exist a set/sets in the setTbl
	{
		if(strcmp(setname,setTbl.clm.phnam[row_locater][0])==0)
		{
			cnfrm[counter_pass]=row_locater;//if the set has the input name, it's ID_SET will be record in this array;
			counter_pass++;
		}
		row_locater++;
	}

	if (counter_pass==0)
	{
		printf("there's no set named %s \n",setname);
		return 0;
	}
	else // There has at least 1 set have the name user type;
	{	
		displayTitle();
		while(counter_out<counter_pass)//print the data 
		{
			temp=cnfrm[counter_out];//get the ID_SET storage in the confirmArray;
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
		return 1;
	}
}


int checkFromProvName(char* provname,tbl setTbl,tbl provider)
{
	int IDp=0;
	int row=0;
	int counter_pass=0; 
	IDp=Provider2IDp(provider,provname);
	while(row<setTbl.info.rowNum)
	{
		if(setTbl.clm.phint[row][0]==IDp&&setTbl.clm.phint[row][1]==1)
		{
			if(counter_pass==0)//if we find one target pass, this part will print the title of this table
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
	if(counter_pass==0)//If there's no matching provider
	{
		printf("Sorry, there's no matching Provider");
		return 0;
	}
	else
	{
		return 1;
	}
	
}

void sortByPrice(tbl setTbl,tbl provider)
{
	int rowNum=setTbl.info.rowNum;
	int tempArray[rowNum][2];
	int rtrnArray[rowNum];
	int counter_row=0;
	int row=0;
	char provname[STRLENLIMIT]={"\0"};

	while(counter_row<rowNum)//To get an array[rowNum][2] which's first clm is the ID_SET
	{
		tempArray[counter_row][0]=setTbl.clm.phint[counter_row][0];
		tempArray[counter_row][1]=setTbl.clm.phint[counter_row][3];
		counter_row++;
	}
	SortFun(tempArray,rowNum,rtrnArray,CompFun4Int);//send the tempArray and return an array of ID_set that has already sorted
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
	char provname[]={"\0"};
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
	char provname[STRLENLIMIT]={"\0"};
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
	char provname[STRLENLIMIT]={"\0"};
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
			if(billinfo->clm.phint[IDu][10]<price)
			{
				printf("Waring! The account has no enough money!\n");
			}
			else
			{
				user->clm.phint[IDu][4]=prov;//change provider;
				//printf("%d,%d,%d,%d\n",billinfo->clm.phint[IDu][6],billinfo->clm.phint[IDu][7],billinfo->clm.phint[IDu][8],billinfo->clm.phint[IDu][10]);//for test
				billinfo->clm.phint[IDu][6]=borTime;//change billinfo;
				billinfo->clm.phint[IDu][7]=forTime;
				billinfo->clm.phint[IDu][8]=data;
				billinfo->clm.phint[IDu][10]=billinfo->clm.phint[IDu][10]-price;
				int inte[5]={setTbl.info.rowNum,1,IDu,choice};
				char **name;
				tim time;
				printf("Please enter your Time:");
				printf("Example:19/09/01 23:40:20");
				scanf("%d",&time.yea);
				scanf("%d",&time.mon);
				scanf("%d",&time.day);
				scanf("%d",&time.hou);
				scanf("%d",&time.min);
				scanf("%d",&time.sec);
				getchar();
				addrow(moneyRecord,inte,name,&time);
				printf("Success!\n");
				//printf("%d,%d,%d,%d\n",billinfo->clm.phint[IDu][6],billinfo->clm.phint[IDu][7],billinfo->clm.phint[IDu][8],billinfo->clm.phint[IDu][10]);	//for test			
			}
		}

	}
}

void CheckAndBuy(tbl setTbl,tbl* user,tbl* moneyRecord,tbl* billinfo,tbl provider,int IDu)
{
	int choice=-1;
	printf("****************************************************************************************************\n");
	printf("welcome,please choose a service\n");
	printf("1.Check sets by name\n");
	printf("2.Check sets by provider\n");
	printf("3.Check sets by price sequence\n");
	printf("4.Check sets by data sequence\n");
	printf("5.Check sets by board call sequence\n");
	printf("6.Check sets by international call sequence\n");
	printf("Press other button to Exit\n");
	printf("Your choice:");
	scanf("%d",&choice);
	getchar();
	int Check_counter=0;
	if(choice==1)
	{
		char setname[STRLENLIMIT]={"\0"};
		scanf("%s",setname);
		getchar();
		Check_counter=checkFromSetName(setname,setTbl,provider);
	}
	else if(choice==2)
	{
		char provname[STRLENLIMIT]={"\0"};
		scanf("%s",provname);
		getchar();
		Check_counter=checkFromProvName(provname,setTbl,provider);
	}
	else if(choice==3)
	{	
		sortByPrice(setTbl,provider);
		Check_counter++;
	}
	else if(choice==4)
	{
		sortByData(setTbl,provider);
		Check_counter++;
	}
	else if(choice==5)
	{
		sortByBoardLength(setTbl,provider);
		Check_counter++;
	}
	else if(choice==6)
	{
		sortByForLength(setTbl,provider);
		Check_counter++;
	}
	if (Check_counter!=0)
	{
		BuySet(setTbl,user,moneyRecord,billinfo,IDu);
	}
	
}

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
