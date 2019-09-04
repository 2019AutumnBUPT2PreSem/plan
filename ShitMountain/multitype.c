//m and n can't be zero.
#include<stdio.h>
#include<stdlib.h>
#include"dbstruct.h"


//_db_type is sort.
//init is initialized type.
_db_type* _constructD1(int n,_db_type init);  //Create a one-dimensional array.  
void _initD1(_db_type *p, int n, _db_type init);  //Initialize the one-dimensional array.
void _destroyD1(_db_type *p);  //Destroy a one-dimensional array.
_db_type* _extendD1(_db_type *p, int n, int add, _db_type init);  //Expand column.

_db_type** _constructD2(int m, int n, _db_type init);  //Create a two-dimensional array.
void _initD2(_db_type **p, int m, int n, _db_type init);  //Initialize the two-dimensional array.
void _destroyD2(_db_type **p, int m);  //Destroy a two-dimensional array.
_db_type** _extendD2N(_db_type **p,int m, int n, int add, _db_type init);  //Expand column.
_db_type** _extendD2M(_db_type **p,int m, int n, int add, _db_type init);  //Expand line.

_db_type*** _constructD3(int l, int m, int n, _db_type init);  //Create a three-dimensional array.
void _initD3(_db_type ***p,int l, int m, int n, _db_type init);  //Initialize the three-dimensional array.
void _destroyD3(_db_type ***p,int l, int m);  //Destroy a three-dimensional array.
_db_type*** _extendD3M(_db_type ***p, int l, int m, int n, int add, _db_type init);  //Expand column.

/*
_db_type *_constructColumnD2(int n, _db_type init); 
void _destroyColumnD2(_db_type *poi);
int _searchID(int rowlen, int m, int n);
_db_type *_access(_db_type *head, int rowlen, int m, int n);
*/

//Create a one-dimensional array.
_db_type* _constructD1(int n, _db_type init)
{
    _db_type *p = (_db_type*)malloc(sizeof(_db_type) * n);  //Dynamically allocate memory.
	if(p == NULL)
	{
		printf("Memory overflow while locating 1 dimension array");
	}
	else
	{
		_initD1(p, n, init);  //Initialization function.
	}
    return p;
}
//Initialize the one-dimensional array.
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
			p[i] = init;  //Initialization.
		}
	}
}
//Destroy a one-dimensional array.
// Remember to set p as NULL after use destroyD1
void _destroyD1(_db_type *p)
{
	if(p != NULL)
    free(p);  //Free memory.
}
//Expand column.
// The following function will return NULL when failed, set p to NULL if that happens.
_db_type* _extendD1(_db_type *p, int n, int add, _db_type init)
{
	_db_type *q = (_db_type*)realloc(p,sizeof(_db_type) * (n + add));  //Expand memory.
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

//Create a two-dimensional array.
_db_type** _constructD2(int m, int n, _db_type init)
{
    _db_type **p = (_db_type**)malloc(sizeof(_db_type*) * m);  //Dynamically allocate memory.
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
				_destroyD2(p, i);  //Free memory if allocation fails。
				return NULL;
	    	}
		}
    	_initD2(p, m, n, init);  //Initialization function.
	}
    return p;
}

//Initialize the two-dimensional array.
void _initD2(_db_type **p, int m, int n, _db_type init)
{
	int i,j;
	if(p != NULL)
    {
		
		for(i = 0; i < m && p[i] != NULL; i++)
		{
			for(j = 0; j < n; j++)
			{
				p[i][j] = init;  //Initialization.
			}	
		}
		if(i < m)
		{
			printf("the %dth column has not been located.\n", i);
		}
	}
}

//Destroy a two-dimensional array.
// remember to set p as NULL after use destroyD2
void _destroyD2(_db_type **p, int m)
{
	if(p != NULL)
	{
		for(int i = 0; i < m; i++)
		{
			_destroyD1(p[i]);  //Destroy a one-dimensional array.
		}
    	free(p);
	}
}

//Expand column.
// The following function will return NULL when failed, set p to NULL if that happens.
_db_type** _extendD2N(_db_type **p,int m, int n, int add, _db_type init)
{
	for(int i=0; i < m; i++)
	{
		p[i] = _extendD1(p[i], n, add, init);  //Expand column.
		if(p[i] == NULL)
		{
			printf("Extend failed.\n");
			_destroyD2(p, m);  //Free memory.
			return NULL;
		}
	}
	return p;
}

//Expand line.
// The following function will return NULL when failed, set p to NULL if that happens.
_db_type** _extendD2M(_db_type **p,int m, int n, int add, _db_type init)
{
	int i;
	_db_type **q;
	q = (_db_type**)realloc(p, sizeof(_db_type*) * (m + add));  //Expand memory.
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
			for(int j = i - 1; j >= m; j--)
			{
				_destroyD1(q[j]);
				q[j] = NULL;
			}
			_destroyD2(q, m);
			q = NULL;
		}
	}
	return q;
}

//Create a three-dimensional array.
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
				p[i] = _constructD2(m, n, init);  //Create a two-dimensional array.
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

//Initialize the three-dimensional array.
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

//Destroy a three-dimensional array.
// remember to set p as NULL after use destroyD2
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

//Expand column.
// The following function will return NULL when failed, set p to NULL if that happens.
_db_type*** _extendD3M(_db_type ***p, int l, int m, int n, int add, _db_type init)  //l is line, m is colum, n is STRLENLIMIT.
{
	for(int i = 0; i < l; i++)
	{
		p[i] = _extendD2M(p[i], m, n, add, init);
		if(p[i] == NULL)
		{
			for(int j = i + 1; j < l; j++)
			{
				_destroyD2(p[j], m);
				p[j] = NULL;
			}
			_destroyD3(p, i, m + add);
			return NULL;
		}
	}
	return p;
}

#undef _db_type

#undef _constructD1
#undef _constructD2
#undef _constructD3 
#undef _destoryD1
#undef _destoryD2
#undef _destoryD3
#undef _initD1
#undef _initD2
#undef _initD3
#undef _extendD1
#undef _extendD2N
#undef _extendD2M
#undef _extendD3M

