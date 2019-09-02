#include<stdarg.h>
#include"dbstruct.h"

#define TBLIMIT 20
#define DBLIMIT 20

typedef struct virtualTableInfo
{
    int itmNum;
    vch vtbSchm;
    idm vtbMeta;
} vtbinfo;

typedef struct vtbschemetic
{
    tbl *ptbl;
    int *ncolumn;
} vch;

typedef struct IDmeta
{
    int tblNum;
    tbl* tblList; 
    int *i2t; // the jth column in vtb will  correspond to i2t[j]th tbl element in tblList
    int *iti; // the jth column in vtb will  correspond to i2t[j]th tbl element in tblList's iti[j]th column
} idm;

typedef struct virtualTable
{
    vtbinfo vinfo;
    int **maptbl;
} vtb;

typedef struct dbcontainer
{
    int vtbn;
    vtb vtb[DBLIMIT];
    int tbn;
    tbl vtb[TBLIMIT];
} dbc;

void addtbl(dbc *container, int n,  ...)
{
    va_list val;
    va_start(val, n);
    for(int i = 0; i < n; i++)
    {
        char *p;
    }
    va_end(val);
}
