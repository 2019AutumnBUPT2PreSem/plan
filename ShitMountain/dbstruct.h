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
// support the function to store the time 

typedef struct char16
{
    char c[STRLENLIMIT];
} nam;
//support the function to store name

typedef struct tableinfo
{
    nam name;
    int intNum;
    int namNum;
    int timNum;
    int floNum;
    int rowNum;
} tblinfo;
//support the function to store the number of data

typedef struct tablecolumn
{
    int **phint; // pointer to the head of a list of int, all the same.
    nam **phnam;
    tim **phtim;
    float **phflo;
} tblclmh; // column head
//support the function to store each column head

typedef struct table
{
    tblinfo info;
    nam *pitem;
    int lrn; // located row number
    tblclmh clm;
} tbl;
//support the function to store the record about the form

tblclmh giveBlankClmh(void)
{
    tblclmh newclmh;
    newclmh.phint = NULL;
    newclmh.phnam = NULL;
    newclmh.phtim = NULL;
    newclmh.phflo = NULL;
}
//give the form a new blank column head

nam giveBlankNam(void)
{
    nam blankNam;
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        blankNam.c[i] = '\0';
    }
    return blankNam;
}
//give the form head new blank head

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
//give the form new blank info

tbl giveBlankTbl(void)
{
    tbl table;
    table.info = giveBlankInfo();
    table.pitem = NULL;
    table.lrn = 0;
    table.clm = giveBlankClmh(); 
}
//give a new blank form

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
// give a new time to the form
#endif
