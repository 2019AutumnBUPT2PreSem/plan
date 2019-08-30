#ifndef DBMEMORY_C
#define DBMEMORY_C

#include <stdio.h>
#include <stdlib.h>

_db_type *_constructColumnD2(int n, _db_type init); 

void _destroyColumnD2(_db_type *poi);

int _searchID(int rowlen, int m, int n);

_db_type *_access(_db_type *head, int rowlen, int m, int n); 

_db_type *_constructColumnD2(int n, _db_type init)
{
    _db_type *newlist = (_db_type*)malloc(n * sizeof(_db_type));
    if(newlist != NULL)
    {
        for(int i = 0; i < n; i++)
        {
            newlist[i] = init;
        }
    }
    return newlist;
}

void _destroyColumnD2(_db_type *poi)
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

int _searchID(int rowlen, int m, int n)//???? 
{
	int certer=0;
    certer = n + m * rowlen;
	return certer;
}

_db_type *_access(_db_type *head, int rowlen, int m, int n)
{
    return &head[_searchID(rowlen, m, n)];
}




#undef _db_type

#endif