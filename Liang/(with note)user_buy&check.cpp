#include "dbio.c"
#include "utilsupport.c" 
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
