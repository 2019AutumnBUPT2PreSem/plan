#ifndef DBOPERATION_C
#define DBOPERATION_C

#include<stdio.h>
#include<stdlib.h>

#define ROWLIMIT 100
#define MANAGEDB 8

typedef struct yymmddhhmmss
{
    int yea;
    int mon;
    int day;
    int hou;
    int min;
    int sec;
} time;

typedef struct tablerow
{
    int *pint;
    char **pstr;
    time *ptim;
    float *pflo;
    tbl *ptbl;
    int key; //in this programe, key must be a int number.
} tblrow;

typedef struct tablecolumn
{
    int **phint;
} tblclm;

typedef struct table
{
    int recordMode; // -1 : abandon; 0 : anyway; 1 : row; 2 : column
    char *name;
    int keyIDColumn;
    int intNum;
    int strNum;
    int timNum;
    int floNum;
    int tblNum;
    int locatedRowNum;
    int rowNum;
    int *defaultMap;
    tblrow *prow;
    tblclm *pclm;
} tbl;

tblrow *loca_row(int n)
{
    return (tblrow *)malloc(n * sizeof(tblrow));
}
tbl *loca_table(int n)
{
    return (tbl *)malloc(n * sizeof(tbl));
}

void free_row()
{

}
void free_table()
{

}


void init_row(tblrow *dirty_row)
{
    dirty_row -> pint = NULL;
    dirty_row -> pstr = NULL;
    dirty_row -> ptim = NULL;
    dirty_row -> pflo = NULL;
    dirty_row -> ptbl = NULL;
    dirty_row -> key = -1;
}
void init_table(tbl *dirty_table)
{
    dirty_table->recordMode = 1;
    dirty_table->name = NULL;
    dirty_table->keyIDColumn = -1;
    dirty_table->intNum = 0;
    dirty_table->strNum = 0;
    dirty_table->timNum = 0;
    dirty_table->floNum = 0;
    dirty_table->tblNum = 0;
    dirty_table->prow = loca_row(ROWLIMIT);
    if(dirty_table->prow == NULL)
    {
        dirty_table->locatedRowNum = 0;
    }
    else
    {
        dirty_table->locatedRowNum = ROWLIMIT;
        for(int i = 0; i < ROWLIMIT; i++)
        {
            init_row(&dirty_table->prow[i]); 
        }
    }
    dirty_table->rowNum = 0;
    dirty_table->defaultMap = NULL;
}

tbl *expand_table(tbl * )


void set_table(tbl *table, char *name, int keyIDColumn, int intNum, int strNum, int tblNum, int rowNum);
int* calc_size(tbl tblInfo);
void pack_row(tbl *resource, int *size, int *pint, char **pstr, time *ptime, float *pflo, tbl *ptbl, int *tblcolumn);

#endif