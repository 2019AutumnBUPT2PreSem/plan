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

tblclmh extendTblclmh(tblinfo info, tblclmh tablecolumn, int *locRowNum);

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

tblclmh assignTblclmh(tblinfo info)
{
    tblclmh newclmh;
    newclmh.phint = constructD1(intp, info.intNum, NULL);
    if(newclmh.phint == NULL)
    {
        destroyD1(intp, newclmh.phint);
        return giveBlankClmh();
    }
    else
    {
        newclmh.phnam = constructD1(namp, info.namNum, NULL);
        if(newclmh.phnam == NULL)
        {
            destroyD1(intp, newclmh.phint);
            destroyD1(namp, newclmh.phnam);
            return giveBlankClmh();
        }
        else
        {
            newclmh.phtim = constructD1(timp, info.timNum, NULL);
            if(newclmh.phtim == NULL)
            {
                destroyD1(intp, newclmh.phint);
                destroyD1(namp, newclmh.phnam);
                destroyD1(timp, newclmh.phtim);
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
                    destroyD1(flop, newclmh.phtim);
                    return giveBlankClmh();
                }
            }
        }
    }
}

tblclmh extendTblclmh(tblinfo info, tblclmh tablecolumn, int *locRowNum)
{
    *locRowNum = *locRowNum + EXPPT;
    tablecolumn.phint = extendD2N_(&tablecolumn.phint, info.intNum, *locRowNum);
    tablecolumn.phnam = extendD2N_(&tablecolumn.phnam, info.namNum, *locRowNum);
    tablecolumn.phtim = extendD2N_(&tablecolumn.phtim, info.timNum, *locRowNum);
    tablecolumn.phflo = extendD2N_(&tablecolumn.phflo, info.floNum, *locRowNum);
    if(tablecolumn.phint == NULL || tablecolumn.phnam == NULL || tablecolumn.phtim == NULL || tablecolumn.phflo == NULL)
    {
        return giveBlankClmh();
    }
    //if bug look here.
}

void addrow(tbl *table, int *introw, nam *namrow, time *timrow, float *florow)
{
    if(table->lrn <= table->info.rowNum + 1)
    {
        table->clm = extendTblclmh(table->info, table->clm, &table->lrn);
        if(table->clm.phint == NULL && )
        {
            addrow(table, )
        }
        else
        {
            printf("add row failed, stire all.\n"); // need to be completed
        }
    }
    else
    {
        
    }
    
    
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

#endif
