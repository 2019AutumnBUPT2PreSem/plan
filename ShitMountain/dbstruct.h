#ifndef DBSTRUCT_H
#define DBSTRUCT_H

#define STRLENLIMIT 16
#define TBLINFONUM 8
#define EXPPT 20// expand per tim

typedef struct yymmddhhmmss
{
    int yea;
    int mon;
    int day;
    int hou;
    int min;
    int sec;
} tim;
typedef struct tableinfo
{
    char* name;
    int intNum;
    int namNum;
    int timNum;
    int rowNum;
} tblinfo;
typedef struct tablecolumn
{
    int **phint; // pointer to the head of a list of int, all the same.
    char ***phnam;
    tim **phtim;
} tblclmh; // column head

typedef struct table
{
    tblinfo info;
    char **pitem;
    int lrn; // located row number
    tblclmh clm;
} tbl;

tblclmh giveBlankClmh(void)
{
    tblclmh newclmh;
    newclmh.phint = NULL;
    newclmh.phnam = NULL;
    newclmh.phtim = NULL;
}
tblinfo giveBlankInfo(void)
{
    tblinfo info;
    info.name = NULL;
    info.intNum = 0;
    info.namNum = 0;
    info.timNum = 0;
    info.rowNum = 0;
    return info;
}
tbl giveBlankTbl(void)
{
    tbl table;
    table.info = giveBlankInfo();
    table.pitem = NULL;
    table.lrn = 0;
    table.clm = giveBlankClmh(); 
}
tim giveBlankTim(void)
{
    tim blankTim;
    blankTim.yea = 0;
    blankTim.mon = 0;
    blankTim.day = 0;
    blankTim.hou = 0;
    blankTim.min = 0;
    blankTim.sec = 0;
    return blankTim;
}

#endif
