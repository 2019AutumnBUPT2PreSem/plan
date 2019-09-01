//相较上一个版本，将最后的输出改为USER_ID的输出形式
#include<stdio.h>
#define DBMEMORY_C int
#define MAX_CLIENT 30000
#define IGNR_NUM 30001
#define CompFunType int
void SortArray2IdArray(DBMEMORY_C (*database)[2],int row_num,int* rtrnArray)//将我们得到的序列排序改成user_id的输出
{
//	int row_locater=0;//遍历行定位器初始化
	int tempArray[row_num]={0};
	int counter_copy=0;
	while(counter_copy<row_num)//复制排序数列到临时数列中 
	{
		tempArray[counter_copy]=rtrnArray[counter_copy];
		counter_copy++; 
	}
	int row_counter=0;//遍历行定位器初始化
	int temp=0;
	while(row_counter<row_num)
	{
		temp=tempArray[row_counter];
		rtrnArray[temp]=database[row_counter][0];
		row_counter++;
	}
	 
}

void ReadArray(DBMEMORY_C (*database)[2],int row_num,DBMEMORY_C* tempArray)//读取一个2列n行的数组 
{
	int counter=0;
	while(counter<row_num)
	{
		tempArray[counter]=database[counter][1];
		counter++;
	}
}

void init(int* array,int row)//初始化一个序列数组； 
{
	int counter=0;
	while(counter<row)
	{
		array[counter]=counter;
		counter++;
	}
}

int CompFun4Int(int comp,int comped)
{
	if(comp>comped)
		return 1;
	else if(comp==comped)
		return 0;
	else
		return -1;
}

void GetRtrnArray(int* compArray,int* rtrnArray,int row)
{
	int pass_counter=0;//用于确定已经经过了多少个数字 
	int trv_counter=0;//用于遍历 
	int locater=row-1;//反向搜索 
	int keyArray[row]; 
	int temp;
	init(keyArray,row);
	while(locater>=0)
	{
		temp=compArray[locater];
		pass_counter=0;
		trv_counter=0;
		while(pass_counter!=temp) 
		{
			if(keyArray[trv_counter]!=IGNR_NUM)//如果读到ignore number就跳过，不计入counter； 
				pass_counter++;
			trv_counter++;
		}
		while(keyArray[trv_counter]==IGNR_NUM)//此处是为了解决如果连续几个IGNR_NUM出现，导致数列错误读取了IGNR_NUM 
			{
				trv_counter++;
			}
		rtrnArray[locater]=keyArray[trv_counter];
		keyArray[trv_counter]=IGNR_NUM;
		locater--;//遍历指针反向前进 
	}
}

void SortFun(DBMEMORY_C (*database)[2],int row_num,int* rtrnArray,int (*CompFun)(CompFunType ch1,CompFunType ch2))//输出为从小到大； 
{
	DBMEMORY_C tempArray[row_num]={0};
	DBMEMORY_C compArray[row_num]={0};
	ReadArray(database,row_num,tempArray);//将要比较的数读取到tempArray中；
	int row_counter=0;
	int row_locater=0;
	int comp_counter=0;
	
	while(row_counter!=row_num)//获得compArray （前面有多少个比后面大/小，由于引入了CompFun函数指针，所以请自行设定comp函数） 
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
	SortArray2IdArray(database,row_num,rtrnArray);
	
}

int main()
{
	int testGroup[5][2]={{20001,2},{20002,4},{20003,4},{20004,3},{20005,1}};
	int row=5;
	int back[row];
	SortFun(testGroup,row,back,CompFun4Int);
	int i=0;
	for(i=0;i<row;i++)
		printf("%d ",back[i]);
	return 0;
}
