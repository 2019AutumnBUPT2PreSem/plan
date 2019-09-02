//Scarecrow and abyssdust
#ifndef ARRAYSUPPORT_C
#define ARRAYSUPPORT_C

#include<stdio.h>
#include<stdlib.h>
#include"dbstruct.h"

// construct supportive function that deals with int
#define _db_type int
#include "multitype.c"

// construct supportive function that deals with char*
#define _db_type nam
#include "multitype.c"

// construct supportive function that deals with int
#define _db_type tim
#include "multitype.c"

// construct supportive function that deals with int
#define _db_type float
#include "multitype.c"

typedef int* intp;
#define _db_type intp
#include "multitype.c"

typedef nam* namp;
#define _db_type namp
#include "multitype.c"

typedef tim* timp;
#define _db_type timp
#include "multitype.c"

typedef float* flop;
#define _db_type flop
#include "multitype.c"

// constructD1  constructs a one-dimensional array
#define constructD1(_db_type, n, init) (constructD1_##_db_type((n),(init)))

// constructD2  constructs a two-dimensional array
#define constructD2(_db_type, m, n, init) (constructD2_##_db_type ((m),(n),(init)))

// destroyD1 free a one- dimensional array
#define destroyD1(_db_type, p) (destoryD1_##_db_type (p))

// destroyD2 free a two-dimensional array
#define destroyD2(_db_type, p, m) (destoryD2_##_db_type ((p),(m)))

//initD1 init a one-dimensional array
#define initD1(_db_type, p, n, init) (initD1_##_db_type ((p),(n),(init)))

//initD2 init a two-dimensional array
#define initD2(_db_type, p, m, n, init) (initD2_##_db_type ((p),(m),(n),(init)))

#define extendD1(_db_type,p,n) (extendD1_##_db_type ((p),(n)))

#define extendD2N(_db_type,p,m,n) (extendD2N_##_db_type ((p),(m),(n)))

cmp_int(int a, int b);
cmp_nam(nam a, nam b);
cmp_tim(tim a, tim b);
cmp_float(float a, float b);



#endif
