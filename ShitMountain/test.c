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
	setInfo(&try.info,name,2,2,2,1);
	iteml=constructD1_charp(getClmNum(try.info),NULL);
	iteml[0]=fillnam("int1");
	iteml[1]=fillnam("int2");
	iteml[2]=fillnam("nam1");
	iteml[3]=fillnam("nam2");
	iteml[4]=fillnam("tim1");
	iteml[5]=fillnam("tim2");
	try.pitem = iteml;

	try.clm = assignTblChart(try.info);
	try.lrn = 1;
	
	int *pint = constructD1_int(2, 0);
	char **pnam = constructD2_char(2, STRLENLIMIT, '\0');
	tim *ptim = constructD1_tim(2, giveBlankTim());

	pint[0] = 111;
	pint[1] = 123;

	pnam[0] = fillnam("test info 1");
	pnam[1] = fillnam("test start");

	ptim[0] = setTim(19, 9, 6, 3, 16, 12);
	ptim[1] = setTim(19, 9, 6, 3, 32, 8);
	
	
	try.clm.phint = &pint;
	try.clm.phnam = &pnam;
	try.clm.phtim = &ptim;
	
	encloseTable(&try);

	//addrow(&try, pint, pnam, ptim);
	//printf("%d %d %s %s\n", try.clm.phint[0], try.clm.phint[1], try.clm.phnam[0], try.clm.phnam[1]);
	//encloseTable(&try);

    return 0;
}
