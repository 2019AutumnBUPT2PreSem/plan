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
// write the header into the file
void trscptHead(FILE *pfile, tblinfo *pinfo);
// support the function both apply space and copy content
void revtrsHead(FILE *pfile, tblinfo *pinfo);
// reverse transcription
void readNameL(FILE *pfile, int clmNum, char **pitem);
// read the data from the file 
void writeNameL(FILE *pfile, int clmNum, char **pitem);
// write the data into the file
void trscptItem(FILE *pfile, tbl *ptable);
// support the function both apply space and copy item
void revtrsItem(FILE *pfile, tbl *ptable);
// reverse transcription
void readChart(FILE *pfile, tblinfo info, tblclmh clm);
// read the chart from the file 
void writeChart(FILE *pfile, tblinfo info, tblclmh clm);
// write the chart into the file 
void trscptChart(FILE *pfile, tbl *ptable);
// support the function both apply space and copy chart
void revtrsChart(FILE *pfile, tbl *ptable);
// reverse transcription
void readTable(FILE *pfile, tbl *ptable);
// read the structure from the file 
void writeTable(FILE *pfile, tbl *ptable);
// write the structure into the file
void initTable(tblinfo info, char **iteml);
// need "wb"

void readHead(FILE *pfile, tblinfo *pinfo) // read the header from the file
{
    fread(pinfo->name, sizeof(char), STRLENLIMIT, pfile);
    fread(&pinfo->intNum, sizeof(int), 1, pfile);
    fread(&pinfo->namNum, sizeof(int), 1, pfile);
    fread(&pinfo->timNum, sizeof(int), 1, pfile);
    fread(&pinfo->rowNum, sizeof(int), 1, pfile);    
}
void writeHead(FILE *pfile, tblinfo info) // write the header into the file
{
    fwrite(info.name, sizeof(char), STRLENLIMIT, pfile);
    fwrite(&info.intNum, sizeof(int), 1, pfile);
    fwrite(&info.namNum, sizeof(int), 1, pfile);
    fwrite(&info.timNum, sizeof(int), 1, pfile);
    fwrite(&info.rowNum, sizeof(int), 1, pfile);
}


void trscptHead(FILE *pfile, tblinfo *pinfo) // support the function both apply space and copy content

{
    pinfo->name = (char*)malloc(sizeof(char) * STRLENLIMIT);
    if(pinfo->name != NULL)
    {
        readHead(pfile, pinfo);// read the chart head
    }
    else
    {
        *pinfo = giveBlankInfo();// give a blank info
    }
}
void revtrsHead(FILE *pfile, tblinfo *pinfo) // reverse transcription

{
    if(pinfo->name != NULL)
    {
        writeHead(pfile, *pinfo);// write the header into the file
        destroyD1_char(pinfo->name);
        *pinfo = giveBlankInfo();
    }
    else
    {
        printf("the head is already empty.\n");
    }
    
}

void readNameL(FILE *pfile, int n, char **pitem) // read the data from the file 
{
    for(int i = 0; i < n; i++)
    {
        fread(pitem[i], sizeof(char), STRLENLIMIT, pfile);
    }
}
void writeNameL(FILE *pfile, int n, char **pitem) // write the data into the file
{
    for(int i = 0; i < n; i++)
    {
        fwrite(pitem[i], sizeof(char), STRLENLIMIT, pfile);
    }
}

void trscptItem(FILE *pfile, tbl *ptable) // support the function both apply space and copy item

{
    char **newiteml = constructD2_char(getClmNum(ptable->info), STRLENLIMIT, '\0');
    if(newiteml != NULL)
    {
        readNameL(pfile, getClmNum(ptable->info), newiteml);
        ptable->pitem = newiteml;
    }
    else
    {
        printf("stire all");
        *ptable = giveBlankTbl();
    }
}
void revtrsItem(FILE *pfile, tbl *ptable) // reverse transcription
{
    if(ptable->pitem != NULL)
    {
        writeNameL(pfile, getClmNum(ptable->info), ptable->pitem);
        destroyD2_char(ptable->pitem, getClmNum(ptable->info));
        ptable->pitem = NULL;
    }
    else
    {
        printf("the item is already empty.\n");
    }
}

void readChart(FILE *pfile, tblinfo info, tblclmh clm) // read the chart from the file 
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
            fread(temp.phnam[j],sizeof(char), STRLENLIMIT, pfile);
            temp.phnam[j]++;
        }
        for (int j = 0; j < info.timNum; j++)
        {
            fread(temp.phtim[j],sizeof(tim), 1, pfile);
            temp.phtim[j]++;
        }
    }
    resignTblclmh(temp);
}
void writeChart(FILE *pfile, tblinfo info, tblclmh clm) // write the chart into the file 
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
            fwrite(temp.phnam[j],sizeof(char), STRLENLIMIT, pfile);
            temp.phnam[j]++;
        }
        for (int j = 0; j < info.timNum; j++)
        {
            fwrite(temp.phtim[j],sizeof(tim), 1, pfile);
            temp.phtim[j]++;
        }
    }
    resignTblclmh(temp); //need to be done
}

void trscptChart(FILE *pfile, tbl *ptable) // support the function both apply space and copy chart
{
    ptable->clm = assignTblChart(ptable->info);
    if((ptable->clm.phint == NULL && ptable->info.intNum != 0) ||
        (ptable->clm.phnam == NULL && ptable->info.namNum != 0) ||
        (ptable->clm.phtim == NULL && ptable->info.timNum != 0))
    {
        resignTblChart(ptable->clm, ptable->info);
        ptable->clm = giveBlankClmh();
        ptable->lrn = 0;
        printf("read failed, stire all.\n"); 
    }
    else
    {
        ptable->lrn = ptable->info.rowNum;
        readChart(pfile, ptable->info, ptable->clm);
    }
}
void revtrsChart(FILE *pfile, tbl *ptable) // reverse transcription
{
    if((ptable->clm.phint == NULL && ptable->info.intNum != 0) ||
        (ptable->clm.phnam == NULL && ptable->info.namNum != 0) ||
        (ptable->clm.phtim == NULL && ptable->info.timNum != 0))
    {
        printf("the chart is empty.\n");
    }
    writeChart(pfile, ptable->info, ptable->clm);
    resignTblChart(ptable->clm, ptable->info);
    ptable->clm = giveBlankClmh();
}

void readTable(FILE *pfile, tbl *ptable) //read the structure from the file 
{
    trscptHead(pfile, &ptable->info);
    if(ptable->info.name != NULL)
    {
        trscptItem(pfile, ptable);
        if(ptable->pitem != NULL)
        {
            trscptChart(pfile, ptable);
        }
    }
}
void writeTable(FILE *pfile, tbl *ptable) // write the structure into the file
{
    if(ptable->info.name != NULL && ptable->pitem != NULL && 
        ((ptable->clm.phint == NULL && ptable->info.intNum != 0) ||
        (ptable->clm.phnam == NULL && ptable->info.namNum != 0) ||
        (ptable->clm.phtim == NULL && ptable->info.timNum != 0))
        && ptable->lrn >= ptable->info.rowNum)
    {
        revtrsHead(pfile, &ptable->info);
        revtrsItem(pfile, ptable);
        revtrsChart(pfile, ptable);
    }
    else
    {
        resignTblChart(ptable->clm, ptable->info);
        destroyD2_char(ptable->pitem, getClmNum(ptable->info));
        destroyD1_char(ptable->info.name);
        printf("danger!, table error.\n");
    }
    *ptable = giveBlankTbl();
}

void initTable(tblinfo info, char **iteml)// need "wb"
{
    tbl table = giveBlankTbl();
    if(info.name != NULL)
    {
        table.info = info;
        table.pitem = iteml;

        char *filename = fillfilenam(info.name);
        if(filename != NULL)
        {
            FILE *pfile = fopen(filename, "wb");
            writeTable(pfile, &table);
            fclose(pfile);
            destroyD1_char(filename);
        }
        else
        {
            printf("file name not yet assigned.\n");
        }
    }
    else
    {
        printf("idiot, you've written wrong info.\n");
    }
    
}
#endif