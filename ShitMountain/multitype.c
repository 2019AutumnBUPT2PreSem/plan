#include<stdio.h>
#include<stdlib.h>
#include"dbstruct.h"

#define _db_type time

#define _constructD1 constructD1_ ## _db_type
#define _constructD2 constructD2_ ## _db_type
#define _destroyD1 destroyD1_ ## _db_type
#define _destroyD2 destroyD2_ ## _db_type

_db_type* _constructD1(int n,_db_type init);
_db_type** _constructD2(int m, int n,_db_type init);
void _destroyD1(_db_type *p);
void _destroyD2(_db_type **p, int m);

_db_type *_constructColumnD2(int n, _db_type init); 
void _destroyColumnD2(_db_type *poi);
int _searchID(int rowlen, int m, int n);
_db_type *_access(_db_type *head, int rowlen, int m, int n);

void _initD1(_db_type *p, int n, _db_type init)
{
	if(p == NULL)
	{
		printf("trying to init a empty list.\n");
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			p[i] = init;
		}
	}
}
void _destroyD1(_db_type *p)
{
    free(p);
}
_db_type* _constructD1(int n, _db_type init)
{
    _db_type *p = (_db_type*)malloc(sizeof(_db_type) * n);
	if(p == NULL)
	{
		printf("Memory overflow while locating 1 dimension array");
	}
	else
	{
		_initD1(p, n, init);
	}
    return p;
}

void _initD2(_db_type *p, int m, int n, _db_type init)
{
	int i,j;
	if(p == NULL)
		printf("Memory overflow while locating 2 dimension array");
    else
    {
		
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
				p[i][j] = init;		
		}
	}
}

void destroyD2(_db_type **p, int m)
{
    for(int i = 0; i < m; i++)
		_destroyD1(p[i]);
    free(p);
}

_db_type** _constructD2(int m, int n, _db_type init)
{
    _db_type **p = (_db_type**)malloc(sizeof(_db_type*) * m);
	if(p == NULL)
	{

	}
	else
	{
		int 
		for(int i = 0; i < m; i++)
		{
	    	p[i] = _constructD1(n, init);
	    	if(p[i] == NULL)
	    	{
				printf(", row %d of 2 dimension array", i);
				destroyD2(p, i);
				return NULL;
	    	}
		}
    	_initD2(p, m, n, init);
	}
	
	
    return p;
}



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

#undef _constructD1
#undef _constructD2 
#undef destoryD1
#undef destoryD2

