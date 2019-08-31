#ifndef DBIO_C
#define DBIO_C

#include<stdio.h>
#include"dbstruct.h"

/*
in 1 file ther will be 16 char and 8 int to describe the chart follows.
16 char is for name,
the ints are:
1 intNum
2 namNum
3 timNum
4 floNum
5 tblNum
6 rowNum
7 0
8 0
*/

void readHead(FILE *pfile, tblinfo *pinfo);
void writeHead(FILE *pfile, tblinfo info);

void readItem(FILE *pfile, tblinfo info, nam *pitem);
void writeItem(FILE *pfile, tblinfo info, nam *pitem);

void readChart(FILE *pfile, tblinfo info, tblclmh *clm);
void writeChart(FILE *pfile, tblinfo info, tblclmh clm);

void readHead(FILE *pfile, tblinfo *pinfo)
{
    int temp;
    fread(pinfo->name.c, sizeof(char), STRLENLIMIT, pfile);
    fread(&pinfo->intNum, sizeof(int), 1, pfile);
    fread(&pinfo->namNum, sizeof(int), 1, pfile);
    fread(&pinfo->timNum, sizeof(int), 1, pfile);
    fread(&pinfo->floNum, sizeof(int), 1, pfile);
    fread(&pinfo->tblNum, sizeof(int), 1, pfile);
    fread(&pinfo->rowNum, sizeof(int), 1, pfile);
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
    fwrite(&info.tblNum, sizeof(int), 1, pfile);
    fwrite(&info.rowNum, sizeof(int), 1, pfile);
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

void readChart(FILE *pfile, tblinfo info, tblclmh *clm)
{
    
}
void writeChart(FILE *pfile, tblinfo info, tblclmh clm)
{
    
}


#endif