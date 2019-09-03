//Scarecrow and abyssdust
#ifndef ARRAYSUPPORT_C
#define ARRAYSUPPORT_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dbstruct.h"

// construct supportive function that deals with int
#define _db_type int

#define _constructD1 constructD1_int
#define _constructD2 constructD2_int
#define _constructD3 constructD3_int
#define _destroyD1 destroyD1_int
#define _destroyD2 destroyD2_int
#define _destroyD3 destroyD3_int
#define _initD1 initD1_int
#define _initD2 initD2_int
#define _initD3 initD3_int
#define _extendD1 extendD1_int
#define _extendD2N extendD2N_int
#define _extendD2M extendD2M_int
#define _extendD3M extendD3M_int

#include "multitype.c"

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

// construct supportive function that deals with char*
#define _db_type nam

#define _constructD1 constructD1_nam
#define _constructD2 constructD2_nam
#define _constructD3 constructD3_nam
#define _destroyD1 destroyD1_nam
#define _destroyD2 destroyD2_nam
#define _destroyD3 destroyD3_nam
#define _initD1 initD1_nam
#define _initD2 initD2_nam
#define _initD3 initD3_nam
#define _extendD1 extendD1_nam
#define _extendD2N extendD2N_nam
#define _extendD2M extendD2M_nam
#define _extendD3M extendD3M_nam

#include "multitype.c"

// construct supportive function that deals with int
#define _db_type tim

#define _constructD1 constructD1_tim
#define _constructD2 constructD2_tim
#define _constructD3 constructD3_tim
#define _destroyD1 destroyD1_tim
#define _destroyD2 destroyD2_tim
#define _destroyD3 destroyD3_tim
#define _initD1 initD1_tim
#define _initD2 initD2_tim
#define _initD3 initD3_tim
#define _extendD1 extendD1_tim
#define _extendD2N extendD2N_tim
#define _extendD2M extendD2M_tim
#define _extendD3M extendD3M_tim

#include "multitype.c"

// construct supportive function that deals with int
#define _db_type float

#define _constructD1 constructD1_float
#define _constructD2 constructD2_float
#define _constructD3 constructD3_float
#define _destroyD1 destroyD1_float
#define _destroyD2 destroyD2_float
#define _destroyD3 destroyD3_float
#define _initD1 initD1_float
#define _initD2 initD2_float
#define _initD3 initD3_float
#define _extendD1 extendD1_float
#define _extendD2N extendD2N_float
#define _extendD2M extendD2M_float
#define _extendD3M extendD3M_float

#include "multitype.c"

typedef int* intp;
#define _db_type intp

#define _constructD1 constructD1_intp
#define _constructD2 constructD2_intp
#define _constructD3 constructD3_intp
#define _destroyD1 destroyD1_intp
#define _destroyD2 destroyD2_intp
#define _destroyD3 destroyD3_intp
#define _initD1 initD1_intp
#define _initD2 initD2_intp
#define _initD3 initD3_intp
#define _extendD1 extendD1_intp
#define _extendD2N extendD2N_intp
#define _extendD2M extendD2M_intp
#define _extendD3M extendD3M_intp

#include "multitype.c"

typedef nam* namp;
#define _db_type namp

#define _constructD1 constructD1_namp
#define _constructD2 constructD2_namp
#define _constructD3 constructD3_namp
#define _destroyD1 destroyD1_namp
#define _destroyD2 destroyD2_namp
#define _destroyD3 destroyD3_namp
#define _initD1 initD1_namp
#define _initD2 initD2_namp
#define _initD3 initD3_namp
#define _extendD1 extendD1_namp
#define _extendD2N extendD2N_namp
#define _extendD2M extendD2M_namp
#define _extendD3M extendD3M_namp

#include "multitype.c"

typedef tim* timp;
#define _db_type timp

#define _constructD1 constructD1_timp
#define _constructD2 constructD2_timp
#define _constructD3 constructD3_timp
#define _destroyD1 destroyD1_timp
#define _destroyD2 destroyD2_timp
#define _destroyD3 destroyD3_timp
#define _initD1 initD1_timp
#define _initD2 initD2_timp
#define _initD3 initD3_timp
#define _extendD1 extendD1_timp
#define _extendD2N extendD2N_timp
#define _extendD2M extendD2M_timp
#define _extendD3M extendD3M_timp

#include "multitype.c"

typedef float* flop;
#define _db_type flop

#define _constructD1 constructD1_flop
#define _constructD2 constructD2_flop
#define _constructD3 constructD3_flop
#define _destroyD1 destroyD1_flop
#define _destroyD2 destroyD2_flop
#define _destroyD3 destroyD3_flop
#define _initD1 initD1_flop
#define _initD2 initD2_flop
#define _initD3 initD3_flop
#define _extendD1 extendD1_flop
#define _extendD2N extendD2N_flop
#define _extendD2M extendD2M_flop
#define _extendD3M extendD3M_flop

#include "multitype.c"
/*_________________________________function list_____________________________________________________________*/
int cmp_int(int a, int b);
int cmp_nam(nam a, nam b);
int cmp_tim(tim a, tim b);
//int cmp_float(float a, float b);
/*______________________________________________________________________________________________*/
int CompFun4Int(int comp,int comped)
{
	if(comp>comped)
		return 1;
	else if(comp==comped)
		return 0;
	else
		return -1;
}

/* 
int cmp_nam(nam a, nam b)
{

	if(strncmp(a.c,b.c)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int cmp_tim(tim a, tim b)
{
	int counter=0;
	if(a.yea==b.yea)
	{
		counter++;
	}
	if(a.mon==b.mon)
	{
		counter++;
	}
	if(a.day==b.day)
	{
		counter++;
	}
	if(a.hou==b.hou)
	{
		counter++;
	}
	if(a.min==b.min)
	{
		counter++;
	}
	if(a.sec==b.sec)
	{
		counter++;
	}
	if(counter==6)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//int cmp_float(float a, float b);
*/ 

#endif
