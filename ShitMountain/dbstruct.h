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
typedef struct char16
{
    char c[STRLENLIMIT];
} nam;
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
/*
typedef struct tablerow
{
    int *pint; // by default, pint[0] is internal ID, pint[1] is valid tag.
    char **pstr;
    time *ptim;
    float *pflo;
} tblrow;
*/
typedef struct tablecolumn
{
    int **phint; // pointer to the head of a list of int, all the same.
    char ***phstr;
    time **phtim;
    float **phflo;
} tblclmh; // column head

typedef struct table
{
    tblinfo info;
    nam *item;
    int recordMode; // -1 : abandon; 0 : empty; 1 : row; 2 : column
    //tblrow *prow;
    tblclmh clm;
    //struct tbale **phtbl;
} tbl;

#endif