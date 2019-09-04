#include<stdio.h>
#include<stdlib.h> 
#include"dbstruct.h"
#include"dbio.c"



void dial_user(tbl* teleRecord, tbl* billInfo, int IDu)
{
	if(billInfo.clm[IDu]phint[9] > 0)
	{
		
		printf("Please enter your startTime:");
		printf("Example:201909012340");
		scanf("%d",&teleRecord.clm.phtim[IDu][0]);

		printf("Enter your teletype: 1.Board    2.Foreign");
		scanf("%d",&teleRecord.clm.phint[IDu][2]);
		
		printf("The number you dial:")
		scanf("%c",&teleRecord.clm.phnam[IDu][1]);

		printf("Please enter your endTime:");
		printf("Example:201909010145");
		scanf("%d",&teleRecord.clm.phtim[IDu][1]);
	}
	else
	{
		printf("Please charge!");
		//chongzhihanshu
	}

}

void changePersonInfo(tbl User,int IDu)
{
	printf("Which one do you want to change: 1.Telephone Number    2.User Password    3.User Email    4.Quit");
	int type;
	scanf("%d",&type);
	if(type==1)
	{
		printf("Enter your new number:");
		scanf("%d",&User.clm.phnam[IDu][2]);
		printf("Your telephone number is setted.");
		//fanhui
	}
	if(type==2)
	{
		printf("Enter your new password:");
		scanf("%d",&User.clm.phnam[IDu][3]);
		printf("Your password is setted.");
		//fanhui
	}
	if(type==3)
	{
		printf("Enter your new email:");
		scanf(pfile,"%d",&User.clm.phnam[IDu][4]);
		printf("Your email is setted.");
		//fanhui
	}
	if(type==4)
	{
		//fanhui
	}
	else
	{
		printf("Error!");
		//fanhui
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






