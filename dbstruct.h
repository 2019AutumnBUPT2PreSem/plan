#ifndef DBSTRUCT_H
#define DBSTRUCT_H

#define STRLENLIMIT 16
#define TBLINFONUM 8

typedef struct yymmddhhmmss
{
    int yea;
    int mon;
    int day;
    int hou;
    int min;
    int sec;
} time;

typedef struct tableinfo
{
    char name[16];
    int intNum;
    int strNum;
    int timNum;
    int floNum;
    int tblNum;
    int rowNum;
    
} tblinfo;

typedef struct tablerow
{
    int *pint; // by default, pint[0] is internal ID, pint[1] is valid tag.
    char **pstr;
    time *ptim;
    float *pflo;
    struct table *ptbl;
    int *keyID; //in this programe, key must be a int number.
} tblrow;

typedef struct tablecolumn
{
    int **phint; // pointer to the head of a list of int, all the same.
    char ***phstr;
    time **phtim;
    float **phflo;
    struct tbale **phtbl;
    int **phkeyID;// note the correspondence of tbl and keyID is complicated in column mode
} tblclmh; // column head

typedef struct table
{
    tblinfo info;
    int recordMode; // -1 : abandon; 0 : empty; 1 : row; 2 : column
    tblrow *prow;
    tblclmh clm;
} tbl;

#endif