#include<stdio.h>
#include<stdlib.h> 
#include"dbstruct.h"
#include"dbio.c"

void dial_user(tbl* teleRecord, tbl* billInfo, int IDu);


int main()
{
	tbl* teleRecord;
	tbl* billInfo;
	tblinfo info;
	dial_user(teleRecord, billInfo,1);
	tblclmh assignTblclmh(info);
	
    return 0;
}

void dial_user(tbl* teleRecord, tbl* billInfo, int IDu)
{
	if(billInfo[IDu].moneyRem > 0)
	{
		FILE *pfile;
		pfile=fopen("Tele.txt","ab");
		printf("Please enter your startTime:");
		printf("Example:201909012340");
		fprintf(pfile,"%d",&teleRecord.clm.phtim[IDu][0]);
		

		printf("Enter your teletype: 1.Board    2.Foreign");
		fprintf(pfile,"%d",&teleRecord.clm.phint[IDu][2]);
		
		printf("The number you dial:")
		fprintf(pfile,"%c",&teleRecord.clm.phnam[IDu][1]);

		printf("Please enter your endTime:");
		printf("Example:201909010145");
		fprintf(pfile,"%d",&teleRecord.clm.phtim[IDu][1]);
		fclose(pfile);

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
	FILE *pfile;
	scanf("%d",&type);
	if(type==1)
	{
		pfile=fopen("Tele.txt","ab");
		printf("Enter your new number:");
		fprintf(pfile,"%d",&User.clm.phnam[IDu][2]);
		printf("Your telephone number is setted.");
		fclose(pfile);
		//fanhui
	}
	if(type==2)
	{
		pfile=fopen("Tele.txt","ab");
		printf("Enter your new password:");
		fprintf(pfile,"%d",&User.clm.phnam[IDu][3]);
		printf("Your password is setted.");
		fclose(pfile);
		//fanhui
	}
	if(type==3)
	{
		pfile=fopen("Tele.txt","ab");
		printf("Enter your new email:");
		fprintf(pfile,"%d",&User.clm.phnam[IDu][4]);
		printf("Your email is setted.");
		fclose(pfile);
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

void checkTeleRecord(tbl teleRecord, int IDu);
{
	FILE *pfile;
	pfile=fopen("Tele.txt","rb");
	fscanf(pfile, "%s",teleRecord.clm.phint[IDu][0]);//buzhidaogeduoshaoge
	fscanf(pfile, "%s",teleRecord.clm.phint[IDu][1]);
	fscanf(pfile, "%s",teleRecord.clm.phint[IDu][2]);
	fscanf(pfile, "%s",teleRecord.clm.phint[IDu][3]);
	fscanf(pfile, "%s",teleRecord.clm.phnam[IDu][0]);
	fscanf(pfile, "%s",teleRecord.clm.phnam[IDu][1]);
	fscanf(pfile, "%s",teleRecord.clm.phtim[IDu][0]);
	fscanf(pfile, "%s",teleRecord.clm.phtim[IDu][0]);

	printf("IDt:%s",teleRecord.clm.phint[IDu][0]);//buzhidaogeduoshaoge
	printf("validt:%s",teleRecord.clm.phint[IDu][1]);
	printf("type:%s",teleRecord.clm.phint[IDu][2]);
	printf("teleFee:%s",teleRecord.clm.phint[IDu][3]);
	printf("user:%s",teleRecord.clm.phnam[IDu][0]);
	printf("to:%s",teleRecord.clm.phnam[IDu][1]);
	printf("startTime:%s",teleRecord.clm.phtim[IDu][0]);
	printf("endTime:%s",teleRecord.clm.phtim[IDu][0]);
	fclose(pfile);
}

void checkTeleRecordByTime(tbl teleRecord,tim time)
{

}

void checkNetRecord(tbl netRecord, int IDu);
{
	FILE *pfile;
	pfile=fopen("Net.txt","rb");
	fscanf(pfile, "IDn:%s",netRecord.clm.phint[IDu][0]);//buzhidaogeduoshaoge
	fscanf(pfile, "validn:%s",netRecord.clm.phint[IDu][1]);
	fscanf(pfile, "comAmount:%s",netRecord.clm.phint[IDu][2]);
	fscanf(pfile, "netFee:%s",netRecord.clm.phint[IDu][3]);
	fscanf(pfile, "user:%s",netRecord.clm.phnam[IDu][0]);
	fscanf(pfile, "time:%s",netRecord.clm.phtim[IDu][0]);

	printf("IDn:%s",netRecord.clm.phint[IDu][0]);//buzhidaogeduoshaoge
	printf("validn:%s",netRecord.clm.phint[IDu][1]);
	printf("comAmount:%s",netRecord.clm.phint[IDu][2]);
	printf("netFee:%s",netRecord.clm.phint[IDu][3]);
	printf("user:%s",netRecord.clm.phnam[IDu][0]);
	printf("time:%s",netRecord.clm.phtim[IDu][0]);
	fclose(pfile);
}

void stat(tbl User,int IDp)
{
	FILE *file;
	file=fopen("Adm.txt","ab");
	char p = fprintf(file,"%s",User.clm.phnam[IDp][0]);
	FILE *pfile;
	pfile=fopen("Tele.txt","ab");
	int row=User.info.rowNum;
	int row_locater=0;
	int cnfrm[row]={0};
	int counter_pass=0;
	int counter_out=0;
	int temp=0;
	int IDp=0;
	char temp_prov[12]={"\0"};
	while(row_locater<row)
	{
		if(strcmp(p,User.clm.phint[row_locater][4])==0)
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
