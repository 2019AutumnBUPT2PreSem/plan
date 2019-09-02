//m and n can't be zero.
#include<stdio.h>
#include<stdlib.h>
#include"dbstruct.h"



void _initD1(_db_type *p, int n, _db_type init);
void _destroyD1(_db_type *p);
_db_type* _constructD1(int n,_db_type init);
_db_type* _extendD1(_db_type **p,int n);


void _initD2(_db_type **p, int m, int n, _db_type init);
void _destroyD2(_db_type **p, int m);
_db_type** _constructD2(int m, int n,_db_type init);
_db_type** _extendD2N(_db_type **p,int m, int n);

/*
_db_type *_constructColumnD2(int n, _db_type init); 
void _destroyColumnD2(_db_type *poi);
int _searchID(int rowlen, int m, int n);
_db_type *_access(_db_type *head, int rowlen, int m, int n);
*/
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
	if(p != NULL)
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



_db_type* _extendD1(_db_type *p, int n, int add, _db_type init)
{
	_db_type *q = (_db_type*)realloc(p,sizeof(_db_type) * (n + add));
	if (q == NULL)
	{
		_destroyD1(p);
	}
	else
	{
		for(int i = n; i < n + add; i++)
		{
			q[i] = init;
		}
	}
	
	return q;	
}
void _initD2(_db_type **p, int m, int n, _db_type init)
{
	int i,j;
	if(p == NULL)
	{
		printf("trying to init a empty list.\n");
	}
    else
    {
		
		for(i = 0; i < m && p[i] != NULL; i++)
		{
			for(j = 0; j < n; j++)
			{
				p[i][j] = init;	
			}	
		}
		if(i < m)
		{
			printf("the %dth column has not been located.\n", i);
		}
	}
}
void _destroyD2(_db_type **p, int m)
{
	if(p != NULL)
	{
		for(int i = 0; i < m; i++)
		{
			_destroyD1(p[i]);
		}
    	free(p);
	}
}
_db_type** _constructD2(int m, int n, _db_type init)
{
    _db_type **p = (_db_type**)malloc(sizeof(_db_type*) * m);
	if(p == NULL)
	{
		printf("Memory overflow while locating 2 dimension array.\n");
	}
	else
	{
		int i;
		for(i = 0; i < m; i++)
		{
	    	p[i] = _constructD1(n, init);
	    	if(p[i] == NULL)
	    	{
				printf(", row %d of 2 dimension array", i);
				_destroyD2(p, i);
				return NULL;
	    	}
		}
    	_initD2(p, m, n, init);
	}
    return p;
}

_db_type** _extendD2N(_db_type **p,int m, int n, int add, _db_type init)
{
	for(int i=0; i < m; i++)
	{
		p[i] = _extendD1(p[i], n, add, init);
	}
	//need security method
	return p;
}
 
void _initD3(_db_type ***p, int l, int m, int n, _db_type init)
{
	if(p != NULL)
	{
		for(int i = 0; i < l; i++)
		{
			_initD2(p[i], m, n, init);
		}
	}
}
void _destroyD3(_db_type ***p, int l, int m)
{
	if(p != NULL)
	{
		for(int i = 0; i < l; i++)
		{
			_destroyD2(p[i], m);
		}
		free(p);
	}
}
_db_type*** _constructD3(int l, int m, int n,_db_type init)
{
	int i;
	_db_type ***p;
	if(l > 0)
	{
		p = (_db_type***)malloc(sizeof(_db_type**) * l);
		if(p != NULL)
		{
			for(i = 0; i < l && (i == 0 || p[i - 1] != NULL); i++)
			{
				p[i] = _constructD2(m, n, init);
			}
			if(p[i - 1] == NULL)
			{
				for(i = i - 1; i >= 0; i--)
				{
					_destroyD2(p[i], m);
				}
			}	
		}
		return p;
	}
	return NULL;
}
_db_type** _extendD2M(_db_type **p,int m, int n, int add, _db_type init)
{
	int i;
	_db_type q;
	q = (_db_type**)realloc(p, sizeof(_db_type*) * (m + add));
	if(q == NULL)
	{
		_destroyD2(p, m);
	}
	else
	{
		for(i = m; i < m + add && (i == m || q[i - 1] != NULL); i++)
		{
			q[i] = _constructD1(n, init);
		}
		if(q[i - 1] == NULL)
		{
			for(i = i - 1; i >= m; i--)
			{
				_destroyD1(q[i]);
			}
			_destroyD2(q, m);
			q = NULL;
		}
	}
	return q;
	
}
_db_type*** _extendD3M(_db_type ***p, int l, int m, int n, int add, _db_type init)
{
	for(int i = 0; i < l; i++)
	{
		p[i] = _extendD2M(p[i], m, n, add, init);
	}
	// need security method
	return p;
}

//int* _sort(_db_type *list, int n,  int *accmap)

/*
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
*/

#undef _db_type

#undef _constructD1
#undef _constructD2 
#undef _destoryD1
#undef _destoryD2
#undef _initD1
#undef _initD2
#undef _extendD1
#undef _extendD2N

