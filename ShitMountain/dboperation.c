#ifndef DBOPERATION_C
#define DBOPERATION_C
#include"dbstruct.h"

void displayInfo(tblinfo info);
void setInfo(tblinfo *pinfo, const char* name, int intNum, int strNum, int timNum, int floNum, int tblNum, int rowNum);

void displayItem(tblinfo info, nam *pitem);
void setItem(tblinfo info, nam **ppitem);

void displayInfo(tblinfo info)
{
    printf("name : ");
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        printf("%c", info.name.c[i]);
    }
    printf("\nintNum : %d\nstrNum : %d\ntimNum : %d\nfloNum : %d\ntblNum : %d\nrowNum : %d\n", 
           info.intNum, info.namNum, info.timNum, info.floNum, info.tblNum, info.rowNum);
}
void setInfo(tblinfo *pinfo, const char* name, 
              int intNum, int namNum, int timNum, int floNum, int tblNum, int rowNum)
{
    int i;
    for(i = 0; i < STRLENLIMIT; i++)
    {
        if(i > 0 && pinfo->name.c[i - 1] == '\0')
        {
            pinfo->name.c[i] = '\0';
        }
        else
        {
            pinfo->name.c[i] = name[i];
        }
    }
    pinfo->intNum = intNum;
    pinfo->namNum = namNum;
    pinfo->timNum = timNum;
    pinfo->floNum = floNum;
    pinfo->tblNum = tblNum;
    pinfo->rowNum = rowNum;
}

void displayItem(tblinfo info, nam *pitem)
{

}
void setItem(tblinfo info, nam **ppitem)
{

}

#endif