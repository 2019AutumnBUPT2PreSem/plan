#ifndef DBOPERATION_C
#define DBOPERATION_C

#include"arraysupport.c"
#include"dbstruct.h"
#include<string.h>


nam fillnam(const char *p);
void setInfo(tblinfo *pinfo, nam name, int intNum, int strNum, int timNum, int floNum, int rowNum);
int getClmNum(tblinfo info);

//void setItem(tblinfo info, nam **ppitem);

tblclmh assignTblclmh(tblinfo info);
void resignTblclmh(tblclmh tablecolumn); //need to be done

tblclmh assignTblChart(tblinfo info);
void resignTblChart(tblclmh tablecolumn, tblinfo info); //need to be done

void cpyTblclmh(tblinfo info, tblclmh clmh1, tblclmh clmh2);
void extendTblclm(tblinfo info, tblclmh *tablecolumn, int *locRowNum);


nam fillnam(const char *p)
{
    nam newnam;

    if((int)strlen(p)<STRLENLIMIT)
    {
    	strncpy(newnam, p, strlen(p));
    	for(int i = strlen(p); i < STRLENLIMIT; i++)
    	{
    		newnam[i] = '\n';
		}
	}
	else
	{
		strncpy(newnam, p, STRLENLIMIT);
	}
}
void setInfo(tblinfo *pinfo, nam name, 
              int intNum, int namNum, int timNum, int floNum, int rowNum)
{
    
    pinfo->name = name;
    pinfo->intNum = intNum;
    pinfo->namNum = namNum;
    pinfo->timNum = timNum;
    pinfo->floNum = floNum;
    pinfo->rowNum = rowNum;
}

int getClmNum(tblinfo info)
{
    return info.intNum + info.namNum + info.timNum + info.floNum;
}

tblclmh assignTblclmh(tblinfo info) // creat space foe column head
{
    tblclmh newclmh;
    newclmh.phint = constructD1_intp(info.intNum, NULL);
    if(newclmh.phint == NULL)
    {
        return giveBlankClmh();
    }
    else
    {
        newclmh.phnam = constructD1_namp(info.namNum, NULL);
        if(newclmh.phnam == NULL)
        {
            destroyD1_intp(newclmh.phint);
            return giveBlankClmh();
        }
        else
        {
            newclmh.phtim = constructD1_timp(info.timNum, NULL);
            if(newclmh.phtim == NULL)
            {
                destroyD1_intp(newclmh.phint);
                destroyD1_namp(newclmh.phnam);
                return giveBlankClmh();
            }
            else
            {
                newclmh.phflo = constructD1_flop(info.floNum, NULL);
                if(newclmh.phflo = NULL)
                {
                    destroyD1_intp(newclmh.phint);
                    destroyD1_namp(newclmh.phnam);
                    destroyD1_timp(newclmh.phtim);
                    return giveBlankClmh();
                }
            }
        }
    }
    return newclmh;
}

void resignTblclmh(tblclmh tablecolumn)
{
	destroyD1_intp(tablecolumn.phint);
    destroyD1_namp(tablecolumn.phnam);
    destroyD1_timp(tablecolumn.phtim);
    destroyD1_flop(tablecolumn.phflo);
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

tblclmh assignTblChart(tblinfo info)
{
    tblclmh newclmh;
    
    newclmh.phint = constructD3_int(info.intNum, info.rowNum,STRLENLIMIT, 0);
    if(newclmh.phint == NULL)
    {
        return giveBlankClmh();
    }
    else
    {
        newclmh.phnam = constructD3_nam(info.namNum, info.rowNum, STRLENLIMIT, giveBlankNam());
        if(newclmh.phnam == NULL)
        {
            destroyD3_int(newclmh.phint, info.intNum, info.rowNum);
            return giveBlankClmh();
        }
        else
        {
            newclmh.phtim = constructD3_tim(info.timNum, info.rowNum, STRLENLIMIT, giveBlankTim());
            if(newclmh.phtim == NULL)
            {
                destroyD3_int(newclmh.phint, info.intNum, info.rowNum);
                destroyD3_nam(newclmh.phnam, info.namNum, info.rowNum);
                return giveBlankClmh();
            }
            else
            {
                newclmh.phflo = constructD3_float(info.floNum, info.rowNum,STRLENLIMIT, 0.0);
                if(newclmh.phflo = NULL)
                {
                    destroyD3_int(newclmh.phint, info.intNum, info.rowNum);
                    destroyD3_nam(newclmh.phnam, info.namNum, info.rowNum);
                    destroyD3_tim(newclmh.phtim, info.timNum, info.rowNum);
                    return giveBlankClmh();
                }
            }
        }
    }
    return newclmh;
}

void resignTblChart(tblclmh tablecolumn, tblinfo info)
{
	destroyD3_int(tablecolumn.phint, info.intNum, info.rowNum);
    destroyD3_nam(tablecolumn.phnam, info.namNum, info.rowNum);
    destroyD3_tim(tablecolumn.phtim, info.timNum, info.rowNum);
    destroyD3_float(tablecolumn.phflo, info.floNum, info.rowNum);
}
void extendTblclm(tblinfo info, tblclmh *ptablecolumn, int *locRowNum)
{
   
    ptablecolumn->phint = extendD2M_int(ptablecolumn->phint, info.intNum, *locRowNum, STRLENLIMIT, EXPPT );
    ptablecolumn->phnam = extendD3M_nam(ptablecolumn->phnam, info.namNum, *locRowNum, STRLENLIMIT, EXPPT, *locRowNum);
    ptablecolumn->phtim = extendD2M_tim(ptablecolumn->phtim, info.timNum, *locRowNum, STRLENLIMIT, EXPPT, *locRowNum);
    ptablecolumn->phflo = extendD2M_float(ptablecolumn->phflo, info.floNum, *locRowNum, STRLENLIMIT, EXPPT, *locRowNum);
    if((ptablecolumn->phint == NULL && info.intNum != 0) ||
        (ptablecolumn->phnam == NULL && info.namNum != 0) ||
        (ptablecolumn->phtim == NULL && info.timNum != 0) ||
        (ptablecolumn->phflo == NULL && info.floNum != 0))
    {
        destroyD3_int(ptablecolumn->phint, info.intNum, info.rowNum);
        destroyD3_nam(ptablecolumn->phnam, info.namNum, info.rowNum);
        destroyD3_tim(ptablecolumn->phtim, info.timNum, info.rowNum);
        destroyD3_float(ptablecolumn->phflo, info.floNum, info.rowNum);
        *ptablecolumn = giveBlankClmh();
        *locRowNum = 0;
    }
    else
	{
		*locRowNum += EXPPT;
	}
    //if bug look here.
}

void addrow(tbl *table, int *introw, nam *namrow, tim *timrow, float *florow)
{
    if(table->lrn <= table->info.rowNum + 1)
    {
        extendTblclm(table->info, &table->clm, &table->lrn);
        if(table->lrn == 0)
        {
            table->info.rowNum = 0;
            printf("add row failed, stire all.\n");
        }
        else
        {
            addrow(table, introw, namrow, timrow, florow);
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
            table->clm.phnam[i][table->info.rowNum + 1] = namrow[i];
        }
        for(int i = 0; i < table->info.intNum; i++)
        {
            table->clm.phtim[i][table->info.rowNum + 1] = timrow[i];
        }
        for(int i = 0; i < table->info.floNum; i++)
        {
            table->clm.phflo[i][table->info.rowNum + 1] = florow[i];
        }
        table->info.rowNum = table->info.rowNum + 1;
    }
}

#endif
