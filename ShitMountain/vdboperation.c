#include"dbstruct.h"

typedef struct virtualTable
{
    vch vtbSchm;
    idm vtbMeta;
} vtb;

typedef struct vtbschemetic
{
    int itmNum;
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

int gettype(tblinfo info, int n)
{
    if (info.intNum <= n)
    {
        
    }
    
}