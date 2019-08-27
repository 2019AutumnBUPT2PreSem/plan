#include<stdio.h>
#include<stdlib.h>
#define ROWLIMIT 100
#define MANAGEDB 8
typedef struct yymmddhhmmss
{
    int year;
    int mon;
    int day;
    int h;
    int min;
    int sec;
} time;

typedef struct tablerow
{
    int *pint;
    char **pstr;
    time *ptime;
    float *pflo;
    tbl *ptbl;
    int *tblcolumn; //int this programe, key must be a number.
} tblrow;

typedef struct table
{
    char *name;
    int keyIDColumn;
    int intNum;
    int strNum;
    int timeNum;
    int floatNum;
    int tblNum;
    int rowNum;
    int *defaultMap;
    tblrow *prow;
} tbl;

tbl* init_resource(void);
int free_resource(tbl* resource);

tbl* creat_table(tbl *resource);
void init_table(tbl *dirty_table);
void set_table(tbl *table, char *name, int keyIDColumn, int intNum, int strNum, int tblNum, int rowNum);
int* calc_size(tbl tblInfo);
void pack_row(int *size, int *pint, char **pstr, time *ptime, float *pflo, tbl *ptbl, int *tblcolumn);

tbl* init_resource(void)
{
    tbl* newtbl;
    newtbl = (tbl*)malloc(sizeof(tbl));
    newtbl->prow = (tblrow*)malloc(ROWLIMIT * sizeof(tblrow));
}
int free_resource(tbl* resource)
{

}

tbl* creat_table(tbl *resource)
{
    

}

void init_table(tbl *dirty_table);
void set_table(tbl *table, char *name, int keyIDColumn, int intNum, int strNum, int tblNum, int rowNum);
int* calc_size(tbl tblInfo);
void pack_row(tbl *resource, int *size, int *pint, char **pstr, time *ptime, float *pflo, tbl *ptbl, int *tblcolumn);


