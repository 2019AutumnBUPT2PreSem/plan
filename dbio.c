#ifndef DBIO_C
#define DBIO_C

#include<stdio.h>
#include"dbstruct.h"

/*
in 1 file ther will be 16 char and 8 int to describe the chart follows.
16 char is for name,
the ints are:
1 intNum
2 strNum
3 timNum
4 floNum
5 tblNum
6 rowNum
7 0
8 0
*/

void read_head(FILE *pfile, tblinfo *info);
void write_head(FILE *pfile, tblinfo info);
void display_info(tblinfo info);
void set_info(tblinfo *info, const char* name, int intNum, int strNum, int timNum, int floNum, int tblNum, int rowNum);

void read_head(FILE *pfile, tblinfo *info)
{
    int temp;
    fread(info->name, sizeof(char), STRLENLIMIT, pfile);
    fread(&info->intNum, sizeof(int), 1, pfile);
    fread(&info->strNum, sizeof(int), 1, pfile);
    fread(&info->timNum, sizeof(int), 1, pfile);
    fread(&info->floNum, sizeof(int), 1, pfile);
    fread(&info->tblNum, sizeof(int), 1, pfile);
    fread(&info->rowNum, sizeof(int), 1, pfile);
    fread(&temp, sizeof(int), 1, pfile);
    fread(&temp, sizeof(int), 1, pfile);
}
void write_head(FILE *pfile, tblinfo info)
{
    int temp = 0;
    fwrite(info.name, sizeof(char), STRLENLIMIT, pfile);
    fwrite(&info.intNum, sizeof(int), 1, pfile);
    fwrite(&info.strNum, sizeof(int), 1, pfile);
    fwrite(&info.timNum, sizeof(int), 1, pfile);
    fwrite(&info.floNum, sizeof(int), 1, pfile);
    fwrite(&info.tblNum, sizeof(int), 1, pfile);
    fwrite(&info.rowNum, sizeof(int), 1, pfile);
    fwrite(&temp, sizeof(int), 1, pfile);
    fwrite(&temp, sizeof(int), 1, pfile);
}
void display_info(tblinfo info)
{
    printf("name : ");
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        printf("%c", info.name[i]);
    }
    printf("\nintNum : %d\nstrNum : %d\ntimNum : %d\nfloNum : %d\ntblNum : %d\nrowNum : %d\n", 
           info.intNum, info.strNum, info.timNum, info.floNum, info.tblNum, info.rowNum);
}
void set_info(tblinfo *info, const char* name, 
              int intNum, int strNum, int timNum, int floNum, int tblNum, int rowNum)
{
    int i;
    for(i = 0; i < STRLENLIMIT; i++)
    {
        if(i > 0 && info->name[i - 1] == '\0')
        {
            info->name[i] = '\0';
        }
        else
        {
            info->name[i] = name[i];
        }
    }
    info->intNum = intNum;
    info->strNum = strNum;
    info->timNum = timNum;
    info->floNum = floNum;
    info->tblNum = tblNum;
    info->rowNum = rowNum;
}

#endif