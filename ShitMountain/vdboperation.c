#include"dbstruct.h"

typedef struct virtualTable
{
    int n;
    tbl *ptbl;
    int *ncolumn;
} vtbl;

int gettype(tblinfo info, int n)
{
    if (info.intNum <= n)
    {
        
    }
    
}