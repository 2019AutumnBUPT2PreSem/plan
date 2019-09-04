#ifndef DBFUNCTION_C
#define DBFUNCTION_C

#include<stdio.h>
#include"dbstruct.h"

#define DBMEMORY_C int
#define MAX_CLIENT 30000
#define IGNR_NUM 30001
#define CompFunType int

void ReadArray(DBMEMORY_C (*database)[2],int row_num,DBMEMORY_C* tempArray)//Read an array of two columns and N rows
{
	int counter=0;
	while(counter<row_num)
	{
		tempArray[counter]=database[counter][1];
		counter++;
	}
}

void genSeqL(int* array,int row)//Initialize a sequence array
{
	int counter=0;
	while(counter<row)
	{
		array[counter]=counter;
		counter++;
	}
}



void GetRtrnArray(int* compArray,int* rtrnArray,int row)
{
	int pass_counter=0;//Used to determine how many words have passed
	int trv_counter=0;//Used to loop through
	int locater=row-1;//This function uses reverse search
	int keyArray[row]; 
	int temp;
	genSeqL(keyArray,row);
	while(locater>=0)
	{
		temp=compArray[locater];
		pass_counter=0;
		trv_counter=0;
		while(pass_counter!=temp) 
		{
			if(keyArray[trv_counter]!=IGNR_NUM)//skip ignore_num,won't count in counter；
				pass_counter++;
			trv_counter++;
		}
		while(keyArray[trv_counter]==IGNR_NUM)//This is to solve the problem of reading IGNR_NUM if there are several successive IGNR_NUM.
			{
				trv_counter++;
			}
		rtrnArray[locater]=keyArray[trv_counter];
		keyArray[trv_counter]=IGNR_NUM;
		locater--;//Reverse Arrangement of Ordinal Sequences
	}
}

void SortFun(DBMEMORY_C (*database)[2],int row_num,int* rtrnArray,int (*CompFun)(CompFunType ch1,CompFunType ch2))//The final output is in a sequence from small to large.
{
	DBMEMORY_C tempArray[row_num]={0};
	DBMEMORY_C compArray[row_num]={0};
	ReadArray(database,row_num,tempArray);//Read the data needed to compare binary arrays into tempArray
	int row_counter=0;
	int row_locater=0;
	int comp_counter=0;
	
	while(row_counter!=row_num)//Get compArray (since the introduction of the CompFun function pointer, specific comparison method should be set by yourself
	{
		row_locater=0;
		comp_counter=0;
		while(row_locater<row_counter)
		{
			if(CompFun(tempArray[row_counter],tempArray[row_locater])==1)
				comp_counter++;
			row_locater++;
		}
		compArray[row_counter]=comp_counter;
		row_counter++;
	}
	GetRtrnArray(compArray,rtrnArray,row_num);
}

int accum(int *p, int n,  int *acsmap)
{
    int acmres = 0;
    for(int i = 0; i < n; i++)
    {
        acmres = p[acsmap[i]];
    }
	return acmres;
}
#endif
