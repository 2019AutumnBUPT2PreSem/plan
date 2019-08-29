#include<stdio.h>

typedef struct tableinfo  
{  
    int intNum;  
    int strNum;  
    int timNum;  
    int floNum;  
    int tblNum;  
    int rowNum;   
} tblinfo;  

typedef struct table  
{  
    char *name; // max 16 char
    int recordMode; // -1 : abandon; 0 : empty; 1 : column; 2 : row  
    tblinfo info;  
} tbl;

int main()
{
    FILE *data;
    /*
    data = fopen("test.txt","w");
    fprintf(data, "test");
    fclose(data);
    */
    data = fopen("text.txt","r");
    tbl hi;
	char name[16]; 
	hi.name = name;
	/*
    if(!feof(data))
	{
        fscanf(data,"%s%d%d,%d,%d,%d,%d,%d\n",hi.name,&hi.recordMode,&hi.info.floNum,&hi.info.intNum,&hi.info.rowNum,&hi.info.strNum,&hi.info.tblNum,&hi.info.timNum);
        printf("%s%d%d%d%d%d%d%d\n",hi.name,hi.recordMode,hi.info.floNum,hi.info.intNum,hi.info.rowNum,hi.info.strNum,hi.info.tblNum,hi.info.timNum);
    }
    */
    fscanf(data, "%c", name);
    printf("%c", name);
    fclose(data);
    return 0;
}
  

