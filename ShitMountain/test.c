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
    char *name;
    
    tbl try = giveBlankTbl();
	
	name=fillnam("try");
	setInfo(&try.info,name,2,2,0,0);


	try.clm = assignTblChart(try.info);
	try.lrn = 0;
	
	int *pint = constructD1_int(2, 0);
	char **pnam = constructD2_char(2, STRLENLIMIT, '\0');

	pint[0] = 111;
	pint[1] = 123;

	pnam[0] = fillnam("testinf");
	pnam[1] = fillnam("teststa");

	
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	addrow(&try, pint, pnam, NULL);
	

	displayInfo(try.info);
	printf("***************************************\n");
	display_tbl(try);
	encloseTable(&try);

	name=fillnam("try");
	setInfo(&try.info,name,2,2,2,1);

	
	exposeTable(&try);
	display_tbl(try);

    return 0;
}
