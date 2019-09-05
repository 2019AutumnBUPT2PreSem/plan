#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include"dbstruct.h"
#include"arraysupport.c"
#include"dboperation.c"
#include"dbio.c"
#include"utilsupport.c"
#include"decoration.c" 
#include"service.c"

int main()
{
    char *name, **iteml;
    
    tbl try = giveBlankTbl();
    name=fillnam("try");
	setInfo(&try.info,name,2,2,2,0);
	iteml=constructD1_charp(getClmNum(try.info),NULL);
	iteml[0]=fillnam("int1");
	iteml[1]=fillnam("int2");
	iteml[2]=fillnam("nam1");
	iteml[3]=fillnam("nam2");
	iteml[4]=fillnam("tim1");
	iteml[5]=fillnam("tim2");
	try.pitem = iteml;

    //initTable(&try);
    exposeTable(&try);
    return 0;
}
