#include<stdio.h>
#include<stdlib.h>


#define constructD1(_db_type, n, init) (constructD1##_db_type((n),(init)))
#define constructD2(_db_type, m, n, init) (constructD2##_db_type ((m),(n),(init)))
#define destroyD1(_db_type, p ) (destoryD1##_db_type (p))
#define destroyD2(_db_type, p, m) (destoryD2##_db_type ((p),(m)))

// 鍒涘缓绫诲瀷涓篿nt鐨勫疄渚嬪嚱鏁?
#define _db_type int
#include "construct.c"

// 鍒涘缓绫诲瀷涓篶har鐨勫疄渚嬪嚱鏁?
#define _db_type char
#include "construct.c"

// 鍒涘缓绫诲瀷涓篺loat鐨勫疄渚嬪嚱鏁?
#define _db_type float
#include "construct.c"



int main()
{
  int n;
  n = constructD2(int,2,3,'/0');
  printf("hello");
 

  return 0;
}


