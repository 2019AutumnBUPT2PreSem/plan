#ifndef DISPLAYSUPPORT_C
#define DISPLATSUPPORT_C

#include"arraysupport.c"
#include"dbstruct.h"

void displayInfo(tblinfo info);
void displayItem(int n, nam *pitem);

void displayInt16(int n);
void displayNam(nam name);
void displayTim(tim time);
void displayFloat16(float x);

void displayInfo(tblinfo info)
{
    printf("name : ");
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        printf("%c", info.name[i]);
    }
    printf("\nintNum : %d\nstrNum : %d\ntimNum : %d\nfloNum : %d\nrowNum : %d\n", 
           info.intNum, info.namNum, info.timNum, info.floNum, info.rowNum);
}

void displayItem(int n, nam *pitem)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < STRLENLIMIT; j++)
            if(pitem[i].c[j] == '\n')
            {
                printf(" ");
            }
            else
                printf("%c", pitem[i].c[j]);
        printf("|");
    }
}

void display_int(int n)
{
    printf("%16d", n);
}
void display_nam(nam name)
{
    for(int j = 0; j < STRLENLIMIT; j++)
        if(nam[j] == '\0')
        {
            printf(" ");
        }
        else
            printf("%c", nam[j]);
}
void display_tim(tim time)
{
    printf("%02d/%02d/%02d%02d:%02d:%02d", time.yea, time.mon, time.day, time.hou, time.min, time.sec);
}
void display_float(float x)
{
    printf("%16f", x);
}
#endif
