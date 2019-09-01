#ifndef DBIO_C
#define DBIO_C

#include<stdio.h>
#include"dbstruct.h"
#include"dboperation.c"

/*
in 1 file ther will be 16 char and 8 int to describe the chart follows.
16 char is for name,
the ints are:
1 intNum
2 namNum
3 timNum
4 floNum
5 rowNum
6 0
7 0
8 0
*/

void readHead(FILE *pfile, tblinfo *pinfo);
void writeHead(FILE *pfile, tblinfo info);

void readItem(FILE *pfile, tblinfo info, nam *pitem);
void writeItem(FILE *pfile, tblinfo info, nam *pitem);

void readChart(FILE *pfile, tblinfo info, tblclmh *clm);
void writeChart(FILE *pfile, tblinfo info, tblclmh clm);

void readTable();
void writeTable();

void readHead(FILE *pfile, tblinfo *pinfo)
{
    int temp;
    fread(pinfo->name.c, sizeof(char), STRLENLIMIT, pfile);
    fread(&pinfo->intNum, sizeof(int), 1, pfile);
    fread(&pinfo->namNum, sizeof(int), 1, pfile);
    fread(&pinfo->timNum, sizeof(int), 1, pfile);
    fread(&pinfo->floNum, sizeof(int), 1, pfile);
    fread(&pinfo->rowNum, sizeof(int), 1, pfile);
    fread(&temp, sizeof(int), 1, pfile);
    fread(&temp, sizeof(int), 1, pfile);
    fread(&temp, sizeof(int), 1, pfile);
}
void writeHead(FILE *pfile, tblinfo info)
{
    int temp = 0;
    fwrite(info.name.c, sizeof(char), STRLENLIMIT, pfile);
    fwrite(&info.intNum, sizeof(int), 1, pfile);
    fwrite(&info.namNum, sizeof(int), 1, pfile);
    fwrite(&info.timNum, sizeof(int), 1, pfile);
    fwrite(&info.floNum, sizeof(int), 1, pfile);
    fwrite(&info.rowNum, sizeof(int), 1, pfile);
    fwrite(&temp, sizeof(int), 1, pfile);
    fwrite(&temp, sizeof(int), 1, pfile);
    fwrite(&temp, sizeof(int), 1, pfile);
}

void readItem(FILE *pfile, tblinfo info, nam *pitem)
{
    for(int i = 0; i < (info.intNum +  info.namNum + info.timNum + info.floNum); i++)
    {
        fread(pitem[i].c, sizeof(char), 16, pfile);
    }
}
void writeItem(FILE *pfile, tblinfo info, nam *pitem)
{
    for(int i = 0; i < (info.intNum +  info.namNum + info.timNum + info.floNum); i++)
    {
        fwrite(pitem[i].c, sizeof(char), 16, pfile);
    }
}

void readChart(FILE *pfile, tblinfo info, tblclmh clm)
{
    tblclmh temp = creatTblclmh(info);
    cpyTblclmh(info, clm, temp);
    for(int i = 0; i < info.rowNum; i++)
    {
        for (int j = 0; j < info.intNum; j++)
        {
            fread(temp.phint[i],sizeof(int), 1, pfile);
            temp.phint[i]++;
        }
        for (int j = 0; j < info.namNum; j++)
        {
            fread(temp.phnam[i],sizeof(nam), 1, pfile);
            temp.phnam[i]++;
        }
        for (int j = 0; j < info.timNum; j++)
        {
            fread(temp.phtim[i],sizeof(time), 1, pfile);
            temp.phtim[i]++;
        }
        for (int j = 0; j < info.floNum; j++)
        {
            fread(temp.phflo[i],sizeof(float), 1, pfile);
            temp.phflo[i]++;
        }
    }
}
void writeChart(FILE *pfile, tblinfo info, tblclmh clm)
{
    tblclmh temp = creatTblclmh(info);
    cpyTblclmh(info, clm, temp);
    for(int i = 0; i < info.rowNum; i++)
    {
        for (int j = 0; j < info.intNum; j++)
        {
            fwrite(temp.phint[i],sizeof(int), 1, pfile);
            temp.phint[i]++;
        }
        for (int j = 0; j < info.namNum; j++)
        {
            fwrite(temp.phnam[i],sizeof(nam), 1, pfile);
            temp.phnam[i]++;
        }
        for (int j = 0; j < info.timNum; j++)
        {
            fwrite(temp.phtim[i],sizeof(time), 1, pfile);
            temp.phtim[i]++;
        }
        for (int j = 0; j < info.floNum; j++)
        {
            fwrite(temp.phflo[i],sizeof(float), 1, pfile);
            temp.phflo[i]++;
        }
    }
}



#endif
