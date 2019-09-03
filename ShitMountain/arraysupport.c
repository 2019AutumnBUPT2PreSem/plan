//Scarecrow and abyssdust
#ifndef ARRAYSUPPORT_C
#define ARRAYSUPPORT_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dbstruct.h"

/*______________________________________________________________________________________________*/
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
/*______________________________________________________________________________________________*/
// construct supportive function that deals with char
#define _db_type char

#define _constructD1 constructD1_char
#define _constructD2 constructD2_char
#define _constructD3 constructD3_char
#define _destroyD1 destroyD1_char
#define _destroyD2 destroyD2_char
#define _destroyD3 destroyD3_char
#define _initD1 initD1_char
#define _initD2 initD2_char
#define _initD3 initD3_char
#define _extendD1 extendD1_char
#define _extendD2N extendD2N_char
#define _extendD2M extendD2M_char
#define _extendD3M extendD3M_char

#include "multitype.c"
/*______________________________________________________________________________________________*/
// construct supportive function that deals with tim
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
/*______________________________________________________________________________________________*/
// construct supportive function that deals with float
/*
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
*/
/*______________________________________________________________________________________________*/
// construct supportive function that deals with int*
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
/*______________________________________________________________________________________________*/
// construct supportive function that deals with char*
typedef char* charp;
#define _db_type charp

#define _constructD1 constructD1_charp
#define _constructD2 constructD2_charp
#define _constructD3 constructD3_charp
#define _destroyD1 destroyD1_charp
#define _destroyD2 destroyD2_charp
#define _destroyD3 destroyD3_charp
#define _initD1 initD1_charp
#define _initD2 initD2_charp
#define _initD3 initD3_charp
#define _extendD1 extendD1_charp
#define _extendD2N extendD2N_charp
#define _extendD2M extendD2M_charp
#define _extendD3M extendD3M_charp

#include "multitype.c"
/*______________________________________________________________________________________________*/
// construct supportive function that deals with int
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
/*______________________________________________________________________________________________*/
// construct supportive function that deals with int
/*
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
*/
/*______________________________________________________________________________________________*/
// construct supportive function that deals with int
typedef char** charpp;
#define _db_type charpp

#define _constructD1 constructD1_charpp
#define _constructD2 constructD2_charpp
#define _constructD3 constructD3_charpp
#define _destroyD1 destroyD1_charpp
#define _destroyD2 destroyD2_charpp
#define _destroyD3 destroyD3_charpp
#define _initD1 initD1_charpp
#define _initD2 initD2_charpp
#define _initD3 initD3_charpp
#define _extendD1 extendD1_charpp
#define _extendD2N extendD2N_charpp
#define _extendD2M extendD2M_charpp
#define _extendD3M extendD3M_charpp

#include "multitype.c"
/*_________________________________function list_____________________________________________________________*/
int cmp_int(int a, int b);
int cmp_nam(char *a, char *b);
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

#endif
