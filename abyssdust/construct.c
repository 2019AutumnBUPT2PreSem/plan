#define constructD1 constructD1_##_db_type 
#define constructD2 constructD2_##_db_type 
#define destoryD1 destoryD1_##_db_type 
#define destoryD2 destoryD2_##_db_type 
_db_type* constructD1(int n,_db_type init);
_db_type** constructD2(int m, int n,_db_type init);

void destroyD1(_db_type *p);
void destroyD2(_db_type **p, int m);

_db_type** constructD2(int m, int n, _db_type init)
{
    _db_type **p = (_db_type**)malloc(sizeof(_db_type*) * m);
    int i,j;
	if(p == NULL)
		printf("Memory overflow while locating 2 dimension array");
    else
    {
		for(i = 0; i < m; i++)
		{
	    	p[i] = constructD1(n, init);
	    	if(p[i] == NULL)
	    	{
				printf(", row %d of 2 dimension array", i);
				destroyD2(p, i);
				return NULL;
	    	}
		}
		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
				p[i][j] = init;		
		}
	}
    return p;
}

_db_type* constructD1(int n, _db_type init)
{
    _db_type *p = (_db_type*)malloc(sizeof(_db_type) * n);
    if(p == NULL)
	printf("Memory overflow while locating 1 dimension array");
	else
	{
		for(int i = 0; i < n; i++)
		p[i] = init;
	}
    return p;
}

void destroyD1(_db_type *p)
{
    free(p);
}

void destroyD2(_db_type **p, int m)
{
    for(int i = 0; i < m; i++)
		destroyD1(p[i]);
    free(p);
}

#undef _db_type
