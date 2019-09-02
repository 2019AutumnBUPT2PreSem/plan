//Scarecrow and abyssdust
#ifndef ARRAYSUPPORT_C
#define ARRAYSUPPORT_C

#include<stdio.h>
#include<stdlib.h>
#include"dbstruct.h"

// construct supportive function that deals with int
#define _db_type int

#define _constructD1 constructD1_int
#define _constructD2 constructD2_int
#define _destroyD1 destroyD1_int
#define _destroyD2 destroyD2_int
#define _initD1 initD1_int
#define _initD2 initD2_int
#define _extendD1 extendD1_int
#define _extendD2N extendD2N_int

#include "multitype.c"

#undef _constructD1
#undef _constructD2 
#undef _destoryD1
#undef _destoryD2
#undef _initD1
#undef _initD2
#undef _extendD1
#undef _extendD2N

// construct supportive function that deals with char*
#define _db_type nam

#define _constructD1 constructD1_nam
#define _constructD2 constructD2_nam
#define _destroyD1 destroyD1_nam
#define _destroyD2 destroyD2_nam
#define _initD1 initD1_nam
#define _initD2 initD2_nam
#define _extendD1 extendD1_nam
#define _extendD2N extendD2N_nam

#include "multitype.c"

#undef _constructD1
#undef _constructD2 
#undef _destoryD1
#undef _destoryD2
#undef _initD1
#undef _initD2
#undef _extendD1
#undef _extendD2N

// construct supportive function that deals with int
#define _db_type tim

#define _constructD1 constructD1_tim
#define _constructD2 constructD2_tim
#define _destroyD1 destroyD1_tim
#define _destroyD2 destroyD2_tim
#define _initD1 initD1_tim
#define _initD2 initD2_tim
#define _extendD1 extendD1_tim
#define _extendD2N extendD2N_tim

#include "multitype.c"

#undef _constructD1
#undef _constructD2 
#undef _destoryD1
#undef _destoryD2
#undef _initD1
#undef _initD2
#undef _extendD1
#undef _extendD2N

// construct supportive function that deals with int
#define _db_type float

#define _constructD1 constructD1_float
#define _constructD2 constructD2_float
#define _destroyD1 destroyD1_float
#define _destroyD2 destroyD2_float
#define _initD1 initD1_float
#define _initD2 initD2_float
#define _extendD1 extendD1_float
#define _extendD2N extendD2N_float

#include "multitype.c"

#undef _constructD1
#undef _constructD2 
#undef _destoryD1
#undef _destoryD2
#undef _initD1
#undef _initD2
#undef _extendD1
#undef _extendD2N

typedef int* intp;
#define _db_type intp

#define _constructD1 constructD1_intp
#define _constructD2 constructD2_intp
#define _destroyD1 destroyD1_intp
#define _destroyD2 destroyD2_intp
#define _initD1 initD1_intp
#define _initD2 initD2_intp
#define _extendD1 extendD1_intp
#define _extendD2N extendD2N_intp

#include "multitype.c"

#undef _constructD1
#undef _constructD2 
#undef _destoryD1
#undef _destoryD2
#undef _initD1
#undef _initD2
#undef _extendD1
#undef _extendD2N

typedef nam* namp;
#define _db_type namp

#define _constructD1 constructD1_namp
#define _constructD2 constructD2_namp
#define _destroyD1 destroyD1_namp
#define _destroyD2 destroyD2_namp
#define _initD1 initD1_namp
#define _initD2 initD2_namp
#define _extendD1 extendD1_namp
#define _extendD2N extendD2N_namp

#include "multitype.c"

#undef _constructD1
#undef _constructD2 
#undef _destoryD1
#undef _destoryD2
#undef _initD1
#undef _initD2
#undef _extendD1
#undef _extendD2N

typedef tim* timp;
#define _db_type timp

#define _constructD1 constructD1_timp
#define _constructD2 constructD2_timp
#define _destroyD1 destroyD1_timp
#define _destroyD2 destroyD2_timp
#define _initD1 initD1_timp
#define _initD2 initD2_timp
#define _extendD1 extendD1_timp
#define _extendD2N extendD2N_timp

#include "multitype.c"

#undef _constructD1
#undef _constructD2 
#undef _destoryD1
#undef _destoryD2
#undef _initD1
#undef _initD2
#undef _extendD1
#undef _extendD2N

typedef float* flop;
#define _db_type flop

#define _constructD1 constructD1_flop
#define _constructD2 constructD2_flop
#define _destroyD1 destroyD1_flop
#define _destroyD2 destroyD2_flop
#define _initD1 initD1_flop
#define _initD2 initD2_flop
#define _extendD1 extendD1_flop
#define _extendD2N extendD2N_flop

#include "multitype.c"

#undef _constructD1
#undef _constructD2 
#undef _destoryD1
#undef _destoryD2
#undef _initD1
#undef _initD2
#undef _extendD1
#undef _extendD2N

cmp_int(int a, int b);
cmp_nam(nam a, nam b);
cmp_tim(tim a, tim b);
cmp_float(float a, float b);


// constructD1  constructs a one-dimensional array
#define constructD1(_db_type, n, init) (constructD1_#_db_type((n),(init)))

// constructD2  constructs a two-dimensional array
#define constructD2(_db_type, m, n, init) (constructD2_#_db_type ((m),(n),(init)))

// destroyD1 free a one- dimensional array
#define destroyD1(_db_type, p) (destoryD1_#_db_type (p))

// destroyD2 free a two-dimensional array
#define destroyD2(_db_type, p, m) (destoryD2_#_db_type ((p),(m)))

//initD1 init a one-dimensional array
#define initD1(_db_type, p, n, init) (initD1_#_db_type ((p),(n),(init)))

//initD2 init a two-dimensional array
#define initD2(_db_type, p, m, n, init) (initD2_#_db_type ((p),(m),(n),(init)))

#define extendD1(_db_type,p,n) (extendD1_#_db_type ((p),(n)))

#define extendD2N(_db_type,p,m,n) (extendD2N_#_db_type ((p),(m),(n)))

#define cmp(_db_type, a, b) (cmp_#_db_type ((a),(b)))

#endif
