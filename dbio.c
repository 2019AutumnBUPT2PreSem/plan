#ifndef DBIO_C
#define DBIO_C

#include<stdio.h>
#include"dbstruct.h"
/*
void read_file(FILE *pfile, tbl *target);
*/
void read_head(FILE *pfile, tblinfo *info);
void write_head(FILE *pfile, tblinfo info);
/*
void read_chart_row(FILE *pfile, tblinfo info, );
void read_chart_clm(FILE *pfile, tblinfo info, )
*/

void read_head(FILE *pfile, tblinfo *info)
{
    int temp;
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        fscanf(pfile, "%c", &info->name[i]);
    }
    fscanf(pfile, "%d", &info->intNum);
    fscanf(pfile, "%d", &info->strNum);
    fscanf(pfile, "%d", &info->timNum);
    fscanf(pfile, "%d", &info->floNum);
    fscanf(pfile, "%d", &info->tblNum);
    fscanf(pfile, "%d", &info->rowNum);
    fscanf(pfile, "%d", &temp);
    fscanf(pfile, "%d", &temp);
}
void write_head(FILE *pfile, tblinfo info)
{
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        fprintf(pfile, "%c", info.name[i]);
    }
    fprintf(pfile, "%d", info.intNum);
    fprintf(pfile, "%d", info.strNum);
    fprintf(pfile, "%d", info.timNum);
    fprintf(pfile, "%d", info.floNum);
    fprintf(pfile, "%d", info.tblNum);
    fprintf(pfile, "%d", info.rowNum);
    fprintf(pfile, "%d", 0);
    fprintf(pfile, "%d", 0);
}
void display_info()
{
    
}


#endif

_db_type_