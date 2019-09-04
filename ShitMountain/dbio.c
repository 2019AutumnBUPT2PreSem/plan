#ifndef DBIO_C
#define DBIO_C

#include<stdio.h>
#include"dbstruct.h"
#include"dboperation.c"

/*
in 1 file ther will be 16 char and 4 int to describe the chart follows.
16 char is for name,
the ints are:
1 intNum
2 namNum
3 timNum
4 rowNum
*/

void readHead(FILE *pfile, tblinfo *pinfo);
// read the header from the file
void writeHead(FILE *pfile, tblinfo info);
// weite the header into the file
void readItem(FILE *pfile, int clmNum, char **pitem);
// read the data from the file 
void writeItem(FILE *pfile, int clmNum, char **pitem);
// write the data into the file
void readChart(FILE *pfile, tblinfo info, tblclmh clm);
// read the chart from the file 
void writeChart(FILE *pfile, tblinfo info, tblclmh clm);
// write the chart into the file 
void readTable(FILE *pfile, tbl *ptable);
//read the structure from the file 
void writeTable(FILE *pfile, tbl *ptable);
// write the structure into the file 
void readHead(FILE *pfile, tblinfo *pinfo)
{
    pinfo->name = (char*)malloc(sizeof(char) * STRLENLIMIT);
    if(pinfo->name != NULL)
    {
        fread(pinfo->name, sizeof(char), STRLENLIMIT, pfile);
        fread(&pinfo->intNum, sizeof(int), 1, pfile);
        fread(&pinfo->namNum, sizeof(int), 1, pfile);
        fread(&pinfo->timNum, sizeof(int), 1, pfile);
        fread(&pinfo->rowNum, sizeof(int), 1, pfile);
    }
    else
    {
        *pinfo = giveBlankInfo();
    }
    
    
}
void writeHead(FILE *pfile, tblinfo info)
{
    fwrite(info.name, sizeof(char), STRLENLIMIT, pfile);
    free(info.name);
    fwrite(&info.intNum, sizeof(int), 1, pfile);
    fwrite(&info.namNum, sizeof(int), 1, pfile);
    fwrite(&info.timNum, sizeof(int), 1, pfile);
    fwrite(&info.rowNum, sizeof(int), 1, pfile);
}

void readItem(FILE *pfile, int n, char **pitem)
{
    for(int i = 0; i < n; i++, pitem++)
    {
        fread(pitem[i], sizeof(char), STRLENLIMIT, pfile);
    }
}
void writeItem(FILE *pfile, int n, char **pitem)
{
    for(int i = 0; i < n; i++, pitem++)
    {
        fwrite(pitem[i], sizeof(char), STRLENLIMIT, pfile);
    }
}

void readChart(FILE *pfile, tblinfo info, tblclmh clm)
{
    tblclmh temp = assignTblclmh(info);
    cpyTblclmh(info, clm, temp);
    for(int i = 0; i < info.rowNum; i++)
    {
        for (int j = 0; j < info.intNum; j++)
        {
            fread(temp.phint[j],sizeof(int), 1, pfile);
            temp.phint[j]++;
        }
        for (int j = 0; j < info.namNum; j++)
        {
            readItem(pfile, 1, temp.phnam[j]);
            temp.phnam[j]++;
        }
        for (int j = 0; j < info.timNum; j++)
        {
            fread(temp.phtim[j],sizeof(tim), 1, pfile);
            temp.phtim[j]++;
        }
    }
    resignTblclmh(clm);
}
void writeChart(FILE *pfile, tblinfo info, tblclmh clm)
{
    tblclmh temp = assignTblclmh(info);
    cpyTblclmh(info, clm, temp);
    for(int i = 0; i < info.rowNum; i++)
    {
        for (int j = 0; j < info.intNum; j++)
        {
            fwrite(temp.phint[j],sizeof(int), 1, pfile);
            temp.phint[j]++;
        }
        for (int j = 0; j < info.namNum; j++)
        {
            readItem(pfile, 1, temp.phnam[j]);
            temp.phnam[j]++;
        }
        for (int j = 0; j < info.timNum; j++)
        {
            fwrite(temp.phtim[j],sizeof(tim), 1, pfile);
            temp.phtim[j]++;
        }
    }
    resignTblclmh(clm); //need to be done
}

void readTable(FILE *pfile, tbl *ptable)
{
    readHead(pfile, &ptable->info);
    char **itml = constructD2_char(getClmNum(ptable->info), STRLENLIMIT, '\0');
    if(itml == NULL) 
    {
        *ptable = giveBlankTbl();
    }
    else
    {
        readItem(pfile, getClmNum(ptable->info), itml);
        ptable->clm = assignTblChart(ptable->info);
        if((ptable->clm.phint == NULL && ptable->info.intNum != 0) ||
        (ptable->clm.phnam == NULL && ptable->info.namNum != 0) ||
        (ptable->clm.phtim == NULL && ptable->info.timNum != 0))
        {
            destroyD2_int(ptable->clm.phint, ptable->info.intNum);
            destroyD3_char(ptable->clm.phnam, ptable->info.namNum, ptable->info.rowNum);
            destroyD2_tim(ptable->clm.phtim, ptable->info.timNum);
            ptable->lrn = 0;
        }
        else
        {
            ptable->lrn = ptable->info.rowNum;
            readChart(pfile, ptable->info, ptable->clm);
        }
    }
}
void writeTable(FILE *pfile, tbl *ptable)
{
    writeHead(pfile, ptable->info);
    writeItem(pfile, getClmNum(ptable->info), ptable->pitem);
    destroyD2_char(ptable->pitem, getClmNum(ptable->info));
    writeChart(pfile, ptable->info, ptable->clm);
    resignTblChart(ptable->clm,ptable->info); //need to be done
    *ptable = giveBlankTbl();
}

#endif
