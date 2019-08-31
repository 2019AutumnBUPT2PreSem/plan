#ifndef DISPLAYSUPPORT_C
#define DISPLATSUPPORT_C

#include"arraysupport.c"
#include"dbstruct.h"

void displayInt16(int n);
void displayNam(nam name);
void displayTime(time tim);
void displayFloat16(float x);

void displayInt(int n)
{
    printf("%16d", n);
}
void displayNam(nam name)
{
    for(int j = 0; j < STRLENLIMIT; j++)
        if(name.c[j] == '\0')
        {
            printf(" ");
        }
        else
            printf("%c", name.c[j]);
}
void displayTime(time tim)
{
    printf("%02d/%02d/%02d%02d:%02d:%02d", tim.yea, tim.mon, tim.day, tim.hou, tim.min, tim.sec);
}
void displayFloat(float x)
{
    printf("%16f", x);
}

#endif