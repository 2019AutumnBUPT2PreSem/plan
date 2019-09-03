#ifndef DBFUNCTION_C
#define DBFUNCTION_C

#include<stdio.h>
#include"dbstruct.h"

#define DBMEMORY_C int
#define MAX_CLIENT 30000
#define IGNR_NUM 30001
#define CompFunType int

void ReadArray(DBMEMORY_C (*database)[2],int row_num,DBMEMORY_C* tempArray)//读取一个2列n行的数组 
{
	int counter=0;
	while(counter<row_num)
	{
		tempArray[counter]=database[counter][1];
		counter++;
	}
}

void genSeqL(int* array,int row)//初始化一个序列数组
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
	int pass_counter=0;//用于确定已经经过了多少数字 
	int trv_counter=0;//用于遍历
	int locater=row-1;//这个函数使用的是反向搜索
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
			if(keyArray[trv_counter]!=IGNR_NUM)//如果读到ignore_num就跳过，不计入counter；
				pass_counter++;
			trv_counter++;
		}
		while(keyArray[trv_counter]==IGNR_NUM)//此处是为了解决如果连续几个IGNR_NUM而出现读取了IGNR_NUM的情况
			{
				trv_counter++;
			}
		rtrnArray[locater]=keyArray[trv_counter];
		keyArray[trv_counter]=IGNR_NUM;
		locater--;//反向进行序数数列的排列
	}
}

void SortFun(DBMEMORY_C (*database)[2],int row_num,int* rtrnArray,int (*CompFun)(CompFunType ch1,CompFunType ch2))//最后的到的输出是按照从小到大的序列
{
	DBMEMORY_C tempArray[row_num]={0};
	DBMEMORY_C compArray[row_num]={0};
	ReadArray(database,row_num,tempArray);//将二元数组的需要比较的数据读入tempArray中
	int row_counter=0;
	int row_locater=0;
	int comp_counter=0;
	
	while(row_counter!=row_num)//获得compArray（由于引入了CompFun函数指针，具体比较方法请自行设定
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
/*
int* filter(tbl t, int nacs, int *acsmap, int *nft, int (*acpt_sth)(tbl table, int rowID, tbl accord, ))
{
	int pass[nacs];
	int count = 0;
	int *p = NULL;
	for(int i = 0; i < nacs; i++)
	{
		pass[i] = acpt_sth(t, acsmap[i]);
		if(pass[i] == 1)
		{
			count++;
		}
	}

}
*/
#endif