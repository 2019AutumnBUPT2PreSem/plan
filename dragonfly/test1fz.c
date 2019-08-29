#include <stdio.h> 

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

void read_head(FILE *pfile, tbl table);

int main()
{
	FILE *p;
    p = fopen("open.txt", "r");
    tbl k;
    char name[16];
    k.name=name;
    if(!feof(p))
    {
        fscanf(p,"%s%d%d%d%d%d%d%d",k.name,&k.recordMode,&k.info.floNum,&k.info.intNum,&k.info.rowNum,&k.info.strNum,&k.info.tblNum,&k.info.timNum);
        printf("%s\n%d\n%d %d %d %d %d %d",k.name,k.recordMode,k.info.floNum,k.info.intNum,k.info.rowNum,k.info.strNum,k.info.tblNum,k.info.timNum);
    }
    fclose(p);
    return 0;

}
