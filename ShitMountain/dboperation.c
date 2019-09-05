#ifndef DBOPERATION_C
#define DBOPERATION_C

#include"arraysupport.c"
#include"dbstruct.h"
#include<string.h>

extern int indent;
extern char diagL[80];

tblclmh giveBlankClmh(void);
tblinfo giveBlankInfo(void);
tbl giveBlankTbl(void);
tim giveBlankTim(void);

char* fillnam(const char *p);  // support the function fill name
char* fillfilenam(const char *p); // don'tuse
void setInfo(tblinfo *pinfo, char* name, int intNum, int strNum, int timNum, int rowNum); //set info
int getClmNum(tblinfo info); // get the number of each column

int xor(int a, int b);

tblclmh assignTblclmh(tblinfo info); // create space for column head
void resignTblclmh(tblclmh tablecolumn); // free space for column head

tblclmh assignTblChart(tblinfo info); //create space for chart
void resignTblChart(tblclmh tablecolumn, tblinfo info); //free space for chart

void cpyTblclmh(tblinfo info, tblclmh clmh1, tblclmh clmh2); //clmh1->clmh2
void extendTblclm(tblinfo info, tblclmh *tablecolumn, int *locRowNum); //this chart will change ptablecolumn to NULL if failed

void addrow(tbl *table, int *introw, char **namrow, tim *timrow); // add a new row to chart

tblclmh giveBlankClmh(void)
{
    tblclmh newclmh;
    newclmh.phint = NULL;
    newclmh.phnam = NULL;
    newclmh.phtim = NULL;
}
//give the form a new blank column head

tblinfo giveBlankInfo(void)
{
    tblinfo info;
    info.name = NULL;
    info.intNum = 0;
    info.namNum = 0;
    info.timNum = 0;
    info.rowNum = 0;
    return info;
}
//give the form new blank info

tbl giveBlankTbl(void)
{
    tbl table;
    table.info = giveBlankInfo();
    table.pitem = NULL;
    table.lrn = 0;
    table.clm = giveBlankClmh(); 
    return table;
}
//give a new blank form

tim giveBlankTim(void)
{
    tim blankTim;
    blankTim.yea = 0;
    blankTim.mon = 0;
    blankTim.day = 0;
    blankTim.hou = 0;
    blankTim.min = 0;
    blankTim.sec = 0;
    return blankTim;
}
// give a new time to the form

char* fillnam(const char *p) //you need to free the pointer // support the function fill name
{
    char* newnam = (char*)malloc(sizeof(char) * STRLENLIMIT);
    if(newnam != NULL)
    {
        strncpy(newnam, p, STRLENLIMIT);
    }
    return newnam;
}
char* fillfilenam(const char *p) // must char * p = fillnam("dfakwfjdshfalkjdf"); char * q = fillfilenam(p); free(p); ... free(q);
{
    char* newnam = (char*)malloc(sizeof(char) * (STRLENLIMIT + 5));
    strncpy(newnam, p, STRLENLIMIT);
    newnam[STRLENLIMIT] = '\0';
    strcat(newnam, ".tbl");
    return newnam;
}
void setInfo(tblinfo *pinfo, char *name, 
              int intNum, int namNum, int timNum, int rowNum) // set infoo
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

int xor(int a, int b)
{
	return (!a && b) || (a && !b);
}

tblclmh assignTblclmh(tblinfo info) // create space for column head
{
    tblclmh newclmh;
    newclmh.phint = constructD1_intp(info.intNum, NULL);
    if(newclmh.phint == NULL && info.intNum > 0)
    {
        newclmh = giveBlankClmh();
    }
    else
    {
        newclmh.phnam = constructD1_charpp(info.namNum, NULL);
        if(newclmh.phnam == NULL && info.namNum > 0)
        {
            destroyD1_intp(newclmh.phint);
            newclmh = giveBlankClmh();
        }
        else
        {
            newclmh.phtim = constructD1_timp(info.timNum, NULL);
            if(newclmh.phtim == NULL && info.timNum > 0)
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
    if(info.rowNum > 0)
    {
        newclmh.phint = constructD2_int(info.intNum, info.rowNum, 0);
        if(newclmh.phint == NULL && info.intNum > 0)
        {
            newclmh = giveBlankClmh();
        }
        else
        {
            newclmh.phnam = constructD3_char(info.namNum, info.rowNum, STRLENLIMIT, '\0');
            if(newclmh.phnam == NULL && info.namNum > 0)
            {
                destroyD2_int(newclmh.phint, info.intNum);
                newclmh = giveBlankClmh();
            }
            else
            {
                newclmh.phtim = constructD2_tim(info.timNum, info.rowNum, giveBlankTim());
                if(newclmh.phtim == NULL && info.namNum > 0)
                {
                    destroyD2_int(newclmh.phint, info.intNum);
                    destroyD3_char(newclmh.phnam, info.namNum, info.rowNum);
                    newclmh = giveBlankClmh();
                }
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
    if(!(xor(ptablecolumn->phint == NULL, info.intNum != 0) ||
        xor(ptablecolumn->phnam == NULL, info.namNum != 0) ||
        xor(ptablecolumn->phtim == NULL, info.timNum != 0)))
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

void addrow(tbl *ptable, int *introw, char **namrow, tim *timrow) // add a new blank row to chart
{
    printf("[trying to add row to table %s]\n", ptable->info.name);
    if(ptable->lrn <= ptable->info.rowNum + 1)
    {
        extendTblclm(ptable->info, &ptable->clm, &ptable->lrn);
        if(ptable->lrn == 0)
        {
            printf("add row failed, stire all.\n");
        }
        else
        {
            addrow(ptable, introw, namrow, timrow);
        }
    }
    else
    {
        for(int i = 0; i < ptable->info.intNum; i++)
        {
            ptable->clm.phint[i][ptable->info.rowNum + 1] = introw[i];
        }
        for(int i = 0; i < ptable->info.namNum; i++)
        {
            strncpy(ptable->clm.phnam[i][ptable->info.rowNum + 1], namrow[i], STRLENLIMIT);
        }
        for(int i = 0; i < ptable->info.intNum; i++)
        {
            ptable->clm.phtim[i][ptable->info.rowNum + 1] = timrow[i];
        }
        ptable->info.rowNum = ptable->info.rowNum + 1;
    }
}

#endif
