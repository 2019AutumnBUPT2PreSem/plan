#include<stdarg.h>
#include"dbstruct.h"

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
    int tbn;
    vtb tb[DBLIMIT];
} dbc;

void addtbl(dbc *container, ...);
