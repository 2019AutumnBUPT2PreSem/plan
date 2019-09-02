#ifndef DBOPERATION_C
#define DBOPERATION_C

#include"arraysupport.c"
#include"dbstruct.h"

void setInfo(tblinfo *pinfo, const char* name, int intNum, int strNum, int timNum, int floNum, int rowNum);
int getClmNum(tblinfo info);

//void setItem(tblinfo info, nam **ppitem);

tblclmh assignTblclmh(tblinfo info);
void resignTblclmh(tblclmh tablecolumn); //need to be done

tblclmh assignTblChart(tblinfo info);
void resignTblChart(tblclmh tablecolumn, tblinfo info); //need to be done

void cpyTblclmh(tblinfo info, tblclmh clmh1, tblclmh clmh2);
void extendTblclm(tblinfo info, tblclmh *tablecolumn, int *locRowNum);

void setInfo(tblinfo *pinfo, const char* name, 
              int intNum, int namNum, int timNum, int floNum, int rowNum)
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
    pinfo->rowNum = rowNum;
}

int getClmNum(tblinfo info)
{
    return info.intNum + info.namNum + info.timNum + info.floNum;
}

tblclmh assignTblclmh(tblinfo info) // creat space foe column head
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
        if(newclmh.phnam == NULL)
        {
            destroyD1(intp, newclmh.phint);
            return giveBlankClmh();
        }
        else
        {
            newclmh.phtim = constructD1(timp, info.timNum, NULL);
            if(newclmh.phtim == NULL)
            {
                destroyD1(intp, newclmh.phint);
                destroyD1(namp, newclmh.phnam);
                return giveBlankClmh();
            }
            else
            {
                newclmh.phflo = constructD1(flop, info.floNum, NULL);
                if(newclmh.phflo = NULL)
                {
                    destroyD1(intp, newclmh.phint);
                    destroyD1(namp, newclmh.phnam);
                    destroyD1(timp, newclmh.phtim);
                    return giveBlankClmh();
                }
            }
        }
    }
    return newclmh;
}

void resignTblclmh(tblclmh tablecolumn)
{
	destroyD1(intp, tablecolumn.phint);
    destroyD1(namp, tablecolumn.phnam);
    destroyD1(timp, tablecolumn.phtim);
    destroyD1(flop, tablecolumn.phflo);
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
    
    newclmh.phint = constructD2(int, info.intNum, info.rowNum, 0);
    if(newclmh.phint == NULL)
    {
        return giveBlankClmh();
    }
    else
    {
        newclmh.phnam = constructD2(nam, info.namNum, info.rowNum, giveBlankNam());
        if(newclmh.phnam == NULL)
        {
            destroyD2(int, newclmh.phint, info.intNum);
            return giveBlankClmh();
        }
        else
        {
            newclmh.phtim = constructD2(time, info.timNum, info.rowNum, giveBlankTime());
            if(newclmh.phtim == NULL)
            {
                destroyD2(int, newclmh.phint, info.intNum);
                destroyD2(nam, newclmh.phnam, info.namNum);
                return giveBlankClmh();
            }
            else
            {
                newclmh.phflo = constructD2(float, info.floNum, info.rowNum, 0.0);
                if(newclmh.phflo = NULL)
                {
                    destroyD2(int, newclmh.phint, info.intNum);
                    destroyD2(nam, newclmh.phnam, info.namNum);
                    destroyD2(tim, newclmh.phtim, info.timNum);
                    return giveBlankClmh();
                }
            }
        }
    }
    return newclmh;
}

void resignTblChart(tblclmh tablecolumn, tblinfo info)
{
	destroyD2(int, tablecolumn.phint, info.intNum);
    destroyD2(nam, tablecolumn.phnam, info.namNum);
    destroyD2(tim, tablecolumn.phtim, info.timNum);
    destroyD2(float, tablecolumn.phflo, info.floNum);
}
void extendTblclm(tblinfo info, tblclmh *ptablecolumn, int *locRowNum)
{
    *locRowNum = *locRowNum + EXPPT;
    ptablecolumn->phint = extendD2N(int, ptablecolumn->phint, info.intNum, *locRowNum);
    ptablecolumn->phnam = extendD2N(nam, ptablecolumn->phnam, info.namNum, *locRowNum);
    ptablecolumn->phtim = extendD2N(time, ptablecolumn->phtim, info.timNum, *locRowNum);
    ptablecolumn->phflo = extendD2N(float, ptablecolumn->phflo, info.floNum, *locRowNum);
    if((ptablecolumn->phint == NULL && info.intNum != 0) ||
        (ptablecolumn->phnam == NULL && info.namNum != 0) ||
        (ptablecolumn->phtim == NULL && info.timNum != 0) ||
        (ptablecolumn->phflo == NULL && info.floNum != 0))
    {
        destroyD2(int, ptablecolumn->phint, info.intNum);
        destroyD2(nam, ptablecolumn->phnam, info.namNum);
        destroyD2(time, ptablecolumn->phtim, info.timNum);
        destroyD2(float, ptablecolumn->phflo, info.floNum);
        *ptablecolumn = giveBlankClmh();
        *locRowNum = 0;
    }
    //if bug look here.
}

void addrow(tbl *table, int *introw, nam *namrow, time *timrow, float *florow)
{
    if(table->lrn <= table->info.rowNum + 1)
    {
        extendTblclmh(table->info, &table->clm, &table->lrn);
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
