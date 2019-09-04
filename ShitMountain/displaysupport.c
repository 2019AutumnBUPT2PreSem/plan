#ifndef DISPLAYSUPPORT_C
#define DISPLATSUPPORT_C

#include"arraysupport.c"
#include"dbstruct.h"

void displayInfo(tblinfo info);// dispaly the number on screen
void displayItem(int n, char* *pitem);// display the item on screen

void displayInt16(int n);// support to justify
void displayNam(char* name);// display the name on screen
void displayTim(tim time);// display the time on screen
void displayFloat16(float x);// support to justify 

void displayInfo(tblinfo info)// dispaly the number on screen
{
    printf("name : ");
    for(int i = 0; i < STRLENLIMIT; i++)
    {
        printf("%c", info.name[i]);
    }
    printf("\nintNum : %d\nstrNum : %d\ntimNum : %d\nrowNum : %d\n", 
           info.intNum, info.namNum, info.timNum, info.rowNum);
}

void displayItem(int n, char** pitem)// display the item on screen
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < STRLENLIMIT; j++)
            if(pitem[i][j] == '\0')
            {
                printf(" ");
            }
            else
                printf("%c", pitem[i][j]);
        printf("|");
    }
}

void display_int(int n)// support to justify
{
    printf("%16d", n);
}
void display_nam(char* name)// display the name on screen
{
    for(int j = 0; j < STRLENLIMIT; j++)
        if(name[j] == '\0')
        {
            printf(" ");
        }
        else
            printf("%c", name[j]);
}
void display_tim(tim time)// display the time on screen
{
    printf("%02d/%02d/%02d%02d:%02d:%02d", time.yea, time.mon, time.day, time.hou, time.min, time.sec);
}
#endif
