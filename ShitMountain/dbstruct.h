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
typedef char* nam;
typedef struct tableinfo
{
    nam name;
    int intNum;
    int namNum;
    int timNum;
    int floNum;
    int rowNum;
} tblinfo;
/*
typedef struct tablerow
{
    int *pint; // by default, pint[0] is internal ID, pint[1] is valid tag.
    nam *pnam;
    tim *ptim;
    float *pflo;
} tblrow;
*/
typedef struct tablecolumn
{
    int **phint; // pointer to the head of a list of int, all the same.
    nam **phnam;
    tim **phtim;
    float **phflo;
} tblclmh; // column head

typedef struct table
{
    tblinfo info;
    nam *pitem;
    //int *defaultmap;
    //int recordMode; // -1 : abandon; 0 : empty; 1 : row; 2 : column
    //tblrow *prow;
    int lrn; // located row number
    tblclmh clm;
    //struct tbale **phtbl;
} tbl;

tblclmh giveBlankClmh(void)
{
    tblclmh newclmh;
    newclmh.phint = NULL;
    newclmh.phnam = NULL;
    newclmh.phtim = NULL;
    newclmh.phflo = NULL;
}
nam giveBlankNam(void)
{
    nam blankNam;
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        blankNam[i] = '\0';
    }
    return blankNam;
}
tblinfo giveBlankInfo(void)
{
    tblinfo info;
    info.name = giveBlankNam();
    info.intNum = 0;
    info.namNum = 0;
    info.timNum = 0;
    info.floNum = 0;
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
