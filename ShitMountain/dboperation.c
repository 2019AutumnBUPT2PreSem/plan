#ifndef DBOPERATION_C
#define DBOPERATION_C

#include"arraysupport.c"
#include"dbstruct.h"
#include<string.h>


char* fillnam(const char *p);
char* fillfilenam(const char *p); // don'tuse
void setInfo(tblinfo *pinfo, char* name, int intNum, int strNum, int timNum, int rowNum);
int getClmNum(tblinfo info);

tblclmh assignTblclmh(tblinfo info); // create space for column head
void resignTblclmh(tblclmh tablecolumn); // free space for column head

tblclmh assignTblChart(tblinfo info); //create space for chart
void resignTblChart(tblclmh tablecolumn, tblinfo info); //free space for chart

void cpyTblclmh(tblinfo info, tblclmh clmh1, tblclmh clmh2); //clmh1->clmh2
void extendTblclm(tblinfo info, tblclmh *tablecolumn, int *locRowNum); //this chart will change ptablecolumn to NULL if failed

void addrow(tbl *table, int *introw, char **namrow, tim *timrow); // add a new row to chart

char* fillnam(const char *p) //you need to free the pointer
{
    char* newnam = (char*)malloc(sizeof(char) * STRLENLIMIT);
    if(newnam != NULL)
    {
        strncpy(newnam, p, STRLENLIMIT);
    }
    return newnam;
}
char* fillfilenam(const char *p)// must char * p = fillnam("dfakwfjdshfalkjdf"); char * q = fillfilenam(p); free(p); ... free(q);
{
    char* newnam = (char*)malloc(sizeof(char) * (STRLENLIMIT + 5));
    strncpy(newnam, p, STRLENLIMIT);
    newnam[STRLENLIMIT] = '\0';
    strcat(newnam, ".tbl");
    return newnam;
}
void setInfo(tblinfo *pinfo, char *name, 
              int intNum, int namNum, int timNum, int rowNum)
{
    
    pinfo->name = name;
    pinfo->intNum = intNum;
    pinfo->namNum = namNum;
    pinfo->timNum = timNum;
    pinfo->rowNum = rowNum;
}

int getClmNum(tblinfo info) // get the number of each column
{
    return info.intNum + info.namNum + info.timNum;
}

tblclmh assignTblclmh(tblinfo info) // create space for column head
{
    tblclmh newclmh;
    newclmh.phint = constructD1_intp(info.intNum, NULL);
    if(newclmh.phint == NULL)
    {
        newclmh = giveBlankClmh();
    }
    else
    {
        newclmh.phnam = constructD1_charpp(info.namNum, NULL);
        if(newclmh.phnam == NULL)
        {
            destroyD1_intp(newclmh.phint);
            newclmh = giveBlankClmh();
        }
        else
        {
            newclmh.phtim = constructD1_timp(info.timNum, NULL);
            if(newclmh.phtim == NULL)
            {
                destroyD1_intp(newclmh.phint);
                destroyD1_charpp(newclmh.phnam);
                newclmh = giveBlankClmh();
            }
        }
    }
    return newclmh;
}
void resignTblclmh(tblclmh tablecolumn) // free space for column head
{
	destroyD1_intp(tablecolumn.phint);
    destroyD1_charpp(tablecolumn.phnam);
    destroyD1_timp(tablecolumn.phtim);
}

void cpyTblclmh(tblinfo info, tblclmh clmh1, tblclmh clmh2) // clmh1 -> clmh2
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
}

tblclmh assignTblChart(tblinfo info) //create space for chart
{
    tblclmh newclmh;
    
    newclmh.phint = constructD2_int(info.intNum, info.rowNum, 0);
    if(newclmh.phint == NULL)
    {
        newclmh = giveBlankClmh();
    }
    else
    {
        newclmh.phnam = constructD3_char(info.namNum, info.rowNum, STRLENLIMIT, '\0');
        if(newclmh.phnam == NULL)
        {
            destroyD2_int(newclmh.phint, info.intNum);
            newclmh = giveBlankClmh();
        }
        else
        {
            newclmh.phtim = constructD2_tim(info.timNum, info.rowNum, giveBlankTim());
            if(newclmh.phtim == NULL)
            {
                destroyD2_int(newclmh.phint, info.intNum);
                destroyD3_char(newclmh.phnam, info.namNum, info.rowNum);
                newclmh = giveBlankClmh();
            }
        }
    }
    return newclmh;
}
void resignTblChart(tblclmh tablecolumn, tblinfo info) //free space for chart
{
	destroyD2_int(tablecolumn.phint, info.intNum);
    destroyD3_char(tablecolumn.phnam, info.namNum, info.rowNum);
    destroyD2_tim(tablecolumn.phtim, info.timNum);
}

void extendTblclm(tblinfo info, tblclmh *ptablecolumn, int *plocRowNum) // this chart will change ptablecolumn to NULL if failed
{
   
    ptablecolumn->phint = extendD2M_int(ptablecolumn->phint, info.intNum, *plocRowNum, EXPPT, 0);
    ptablecolumn->phnam = extendD3M_char(ptablecolumn->phnam, info.namNum, *plocRowNum, STRLENLIMIT, EXPPT, '\0');
    ptablecolumn->phtim = extendD2M_tim(ptablecolumn->phtim, info.timNum, *plocRowNum, EXPPT, giveBlankTim());
    if((ptablecolumn->phint == NULL && info.intNum != 0) ||
        (ptablecolumn->phnam == NULL && info.namNum != 0) ||
        (ptablecolumn->phtim == NULL && info.timNum != 0))
    {
        destroyD2_int(ptablecolumn->phint, info.intNum);
        destroyD3_char(ptablecolumn->phnam, info.namNum, info.rowNum);
        destroyD2_tim(ptablecolumn->phtim, info.timNum);
        *ptablecolumn = giveBlankClmh();
        *plocRowNum = 0;
    }
    else
	{
		*plocRowNum += EXPPT;
	}
}

void addrow(tbl *table, int *introw, char **namrow, tim *timrow) // add a new blank row to chart
{
    if(table->lrn <= table->info.rowNum + 1)
    {
        extendTblclm(table->info, &table->clm, &table->lrn);
        if(table->lrn == 0)
        {
            printf("add row failed, stire all.\n");
        }
        else
        {
            addrow(table, introw, namrow, timrow);
        }
    }
    else
    {
        for(int i = 0; i < table->info.intNum; i++)
        {
            table->clm.phint[i][table->info.rowNum + 1] = introw[i];
        }
        for(int i = 0; i < table->info.namNum; i++)
        {
            strncpy(table->clm.phnam[i][table->info.rowNum + 1], namrow[i], STRLENLIMIT);
        }
        for(int i = 0; i < table->info.intNum; i++)
        {
            table->clm.phtim[i][table->info.rowNum + 1] = timrow[i];
        }
        table->info.rowNum = table->info.rowNum + 1;
    }
}

#endif
