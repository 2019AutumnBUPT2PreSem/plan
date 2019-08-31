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
#define _db_type time
#include "multitype.c"

// construct supportive function that deals with int
#define _db_type float
#include "multitype.c"

typedef int* intp;
#define _db_type intp
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

#endif
