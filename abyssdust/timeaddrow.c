#include<stdio.h>
#include<stdlib.h> 
#include"dbstruct.h"
#include"dbio.c"



void dial_user(tbl* teleRecord, tbl* billInfo,  int IDu)
{
	if(billInfo.clmphint[IDu][9] > 0)
	{
		addrow(tbl *table, int *introw, nam *namrow, tim *timrow)
		
		printf("Please enter your startTime:");
		printf("Example:19/09/01 23:40:20");
		scanf("%d",&startTime.yea);
		scanf("%d",&startTime.mon);
		scanf("%d",&startTime.day);
		scanf("%d",&startTime.hou);
		scanf("%d",&startTime.min);
		scanf("%d",&startTime.sec);
		gets();
		
		printf("Enter your teletype: 1.Board    2.Foreign");
		scanf("%d",&teleRecord.clm.phint[IDu][2]);
		
		printf("The number you dial:")
		scanf("%c",&teleRecord.clm.phnam[IDu][1]);

		printf("Please enter your endTime:");
		printf("Example:19/09/01 23:50:30");
		scanf("%d",&endTime.yea);
		scanf("%d",&endTime.mon);
		scanf("%d",&endTime.day);
		scanf("%d",&endTime.hou);
		scanf("%d",&endTime.min);
		scanf("%d",&endTime.sec);
		gets();
	}
	else
	{
		printf("Please charge!");
		//chongzhihanshu
	}

}

void changePersonInfo(tbl* User,int IDu)
{
	printf("Which one do you want to change: 1.Telephone Number    2.User Password    3.User Email    4.Quit");
	int type;
	scanf("%d",&type);
	if(type==1)
	{
		printf("Enter your new number:");
		scanf("%d",&User.clm.phnam[IDu][2]);
		printf("Your telephone number is setted.");
		break;
	}
	if(type==2)
	{
		printf("Enter your new password:");
		scanf("%d",&User.clm.phnam[IDu][3]);
		printf("Your password is setted.");
		break;
	}
	if(type==3)
	{
		printf("Enter your new email:"); 
		scanf(pfile,"%d",&User.clm.phnam[IDu][4]);
		printf("Your email is setted.");
		break;
	}
	if(type==4)
	{
		break;
	}
	else
	{
		printf("Error!");
		changePersonInfo(User, IDu);
	}

}

void checkTeleRecord(tbl teleRecord, int IDu)
{
	printf("IDt:%d\n",teleRecord.clm.phint[IDu][0]);//buzhidaogeduoshaoge
	printf("validt:%d\n",teleRecord.clm.phint[IDu][1]);
	printf("type:%d\n",teleRecord.clm.phint[IDu][2]);
	printf("teleFee:%d\n",teleRecord.clm.phint[IDu][3]);
	printf("user:%s\n",teleRecord.clm.phnam[IDu][0]);
	printf("to:%s\n",teleRecord.clm.phnam[IDu][1]);
	printf("startTime:%d\n",teleRecord.clm.phtim[IDu][0]);
	printf("endTime:%d\n",teleRecord.clm.phtim[IDu][0]);
}

void checkTeleRecordByTime(tbl teleRecord, tim time, int IDu)
{
	int ti;
	printf("Please enter your time: 1.Year    2.Month    3.Day");
	scanf("%d",&ti);
	if(ti == 1)
	{
		//time.yea = teleRecord.clm.phtim[IDu][0]/10000000000;
		

	}

}

void checkNetRecord(tbl netRecord, int IDu)
{
	printf("IDn:%d\n",netRecord.clm.phint[IDu][0]);//buzhidaogeduoshaoge
	printf("validn:%d\n",netRecord.clm.phint[IDu][1]);
	printf("comAmount:%d\n",netRecord.clm.phint[IDu][2]);
	printf("netFee:%d\n",netRecord.clm.phint[IDu][3]);
	printf("user:%s\n",netRecord.clm.phnam[IDu][0]);
	printf("time:%d\n",netRecord.clm.phtim[IDu][0]);
}

void stat(tbl User,int IDp)
{
	int row=User.info.rowNum;
	int row_locater=0;
	int counter_pass=0;
	while(row_locater<=row)
	{
		if(strcmp(User.clm.phnam[IDp][0],User.clm.phint[row_locater][4])==0)
		{
			printf("%s",User.clm.phnam[row_locater][0]);
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
 	printf("price:%d",set.clm.phint[prov][3]);
 	printf("borTime:%d",set.clm.phint[prov][4]);
 	printf("forTime:%d",set.clm.phint[prov][5]);
 	printf("setname:%s",set.clm.phnam[prov][0]);
 	printf("description:%s",set.clm.phnam[prov][1]);
 }

 void changeUserInfo(tbl* User, int IDp)
 {
 	printf("Which one do you want to change: 1.User Password    2.User Email    3.Quit");
	int type;
	scanf("%d",&type);

	if(type==1)
	{
		printf("Enter new password:");
		scanf("%d",&User.clm.phnam[IDp][3]);
		printf("Password is setted.");
		break;
	}
	if(type==2)
	{
		printf("Enter new email:");
		scanf(pfile,"%d",&User.clm.phnam[IDp][4]);
		printf("Email is setted.");
		break;
	}
	if(type==3)
	{
		break;
	}
	else
	{
		printf("Error!");
		changeUserInfo(User, IDu);
	}
 }






