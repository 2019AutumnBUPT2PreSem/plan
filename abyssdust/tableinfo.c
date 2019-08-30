#include<stdio.h>
#include<stdlib.h>

// 创建类型为int的实例函数
#define _db_type int
#include "construct.c"

// 创建类型为char的实例函数
#define _db_type char
#include "construct.c"

// 创建类型为float的实例函数
#define _db_type float
#include "construct.c"

#define constructD1(_db_type, n, init) (constructD1_##_db_type((n),(init)))
#define constructD2(_db_type, m, n, init) (constructD2_##_db_type ((m),(n),(init)))
#define destroyD1(_db_type, p) (destoryD1_##_db_type (p))
#define destroyD2(_db_type, p, m) (destoryD2_##_db_type ((p),(m)))
