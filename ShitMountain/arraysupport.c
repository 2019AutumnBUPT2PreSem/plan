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

#define constructD1(_db_type, n, init) (constructD1_##_db_type((n),(init)))
#define constructD2(_db_type, m, n, init) (constructD2_##_db_type ((m),(n),(init)))
#define destroyD1(_db_type, p) (destoryD1_##_db_type (p))
#define destroyD2(_db_type, p, m) (destoryD2_##_db_type ((p),(m)))
#define initD1(_db_type, p, n, init) (initD1_##_db_type ((p),(n),(init)))
#define initD2(_db_type, p, m, n, init) (initD2_##_db_type ((p),(m),(n),(init)))

#endif