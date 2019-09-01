#ifndef DISPLAYSUPPORT_C
#define DISPLATSUPPORT_C

#include"arraysupport.c"
#include"dbstruct.h"

void displayInt16(int n);
void displayNam(nam name);
void displayTime(time tim);
void displayFloat16(float x);

void displayInfo(tblinfo info)
{
    printf("name : ");
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        printf("%c", info.name.c[i]);
    }
    printf("\nintNum : %d\nstrNum : %d\ntimNum : %d\nfloNum : %d\nrowNum : %d\n", 
           info.intNum, info.namNum, info.timNum, info.floNum, info.rowNum);
}

void displayItem(tblinfo info, nam *pitem)
{
    for(int i = 0; i < (info.intNum +  info.namNum + info.timNum + info.floNum); i++)
    {
        for(int j = 0; j < STRLENLIMIT; j++)
            if(pitem[i].c[j] == '\0')
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
        if(name.c[j] == '\0')
        {
            printf(" ");
        }
        else
            printf("%c", name.c[j]);
}
void display_time(time tim)
{
    printf("%02d/%02d/%02d%02d:%02d:%02d", tim.yea, tim.mon, tim.day, tim.hou, tim.min, tim.sec);
}
void display_float(float x)
{
    printf("%16f", x);
}
#endif
