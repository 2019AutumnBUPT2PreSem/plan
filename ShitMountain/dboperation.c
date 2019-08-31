#ifndef DBOPERATION_C
#define DBOPERATION_C

#include"arraysupport.c"
#include"dbstruct.h"

void displayInfo(tblinfo info);
void setInfo(tblinfo *pinfo, const char* name, int intNum, int strNum, int timNum, int floNum, int tblNum, int rowNum);

void displayItem(tblinfo info, nam *pitem);
//void setItem(tblinfo info, nam **ppitem);

tblclmh creatTblclmh(tblinfo info);
void cpyTblclmh(tblinfo info, tblclmh clmh1, tblclmh clmh2);

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
    for(int i = 0; i < (info.intNum +  info.namNum + info.timNum + info.floNum); i++)
    {
        for(int j = 0; j < STRLENLIMIT; j++)
            if(pitem[i].c[j] == '\0')
            {
                printf(" ");
            }
            else
                printf("%c", pitem[i].c[j]);
        printf("|");
    }
}
/*
void setItem(tblinfo info, nam **ppitem)
{

}
*/

tblclmh giveBlankClmh(void)
{
    tblclmh newclmh;
    newclmh.phint = NULL;
    newclmh.phnam = NULL;
    newclmh.phtim = NULL;
    newclmh.phflo = NULL;
}

tblclmh assignTblclmh(tblinfo info)
{
    tblclmh newclmh;
    newclmh.phint = constructD1(intp, info.intNum, NULL);
    if(newclmh.phint == NULL)
    {
        return giveBlankClmh();
    }
    else
    {
        newclmh.phnam = constructD1(namp, info.namNum, NULL);
        if()
        {

        }
        else
        {
            
        }
        
    }
    
    newclmh.phtim = constructD1(timp, info.timNum, NULL);
    newclmh.phflo = constructD1(flop, info.floNum, NULL);
}
void cpyTblclmh(tblinfo info, tblclmh clmh1, tblclmh clmh2)
{
    for(int i = 0; i < info.intNum; i ++)
    {
        clmh2.phint[i] = clmh1.phint[i];
    }
    for(int i = 0; i < info.namNum; i ++)
    {
        clmh2.phnam[i] = clmh1.phnam[i];
    }
    for(int i = 0; i < info.timNum; i ++)
    {
        clmh2.phtim[i] = clmh1.phtim[i];
    }
    for(int i = 0; i < info.floNum; i ++)
    {
        clmh2.phflo[i] = clmh1.phflo[i];
    }
}

nam giveBlankNam(void)
{
    nam blankNam;
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        blankNam.c[i] = '\0';
    }
    return blankNam;
}
time giveBlankTime(void)
{
    time blankTime;
    blankTime.yea = 0;
    blankTime.mon = 0;
    blankTime.day = 0;
    blankTime.hou = 0;
    blankTime.min = 0;
    blankTime.sec = 0;
    return blankTime;
}
    
#endif
