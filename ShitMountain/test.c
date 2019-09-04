#include<stdio.h>
#include<stdlib.h> 
#include"dbstruct.h"
#include"dbio.c"
#include"dboperation.c"



int main()
{
	tbl table; 
	char **iteml = constructD2_char(3, STRLENLIMIT, '\0');
	iteml[0] = fillnam("sdkfjal");
	iteml[1] = fillnam("dsfsldfks");
	iteml[2] = fillnam("fdsskdfnwaa");
    FILE *pfile = fopen("sdkfjal.tbl", "wb");
    writeItem(pfile, 3, iteml);
    
    fclose(pfile);
    destroyD2_char(iteml, 3);
    iteml = NULL;
	

    return 0;
}
