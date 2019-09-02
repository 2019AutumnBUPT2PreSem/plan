#include<stdio.h>
#include"dbio.c"


#include"dbstruct.h"
#include"dboperation.c"

int main()
{
    tim ym;

    scanf("%d%d%d%d%d%d",&ym.yea,&ym.mon,&ym.day,&ym.hou,&ym.min,&ym.sec);

    printf("%d%d%d%d%d%d",ym.yea,ym.mon,ym.day,ym.hou,ym.min,ym.sec);

    return 0;
}
