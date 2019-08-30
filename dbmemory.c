#ifndef DBMEMORY_C
#define DBMEMORY_C

#include <stdio.h>
#include <stdlib.h>

#define _db_type_ char

_db_type_ *construct_column_D2(int n, _db_type_ init)
{
    _db_type_ *newlist = (_db_type_*)malloc(n * sizeof(_db_type_));
    if(newlist != NULL)
    {
        for(int i = 0; i < n; i++)
        {
            newlist[i] = init;
        }
    }
    return newlist;
}

void destroy_column_D2(_db_type_ *poi)
{
    if(poi == NULL)
    {
        printf("You are trying to release a empty pointer.");
    }
    else
    {
        free(poi);
    }
}





#endif