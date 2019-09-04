#include<stdio.h>
#include<stdlib.h> 
#include"dbstruct.h"
#include"dbio.c"
#include"dboperation.c"



int main()
{
	tbl table; 
	char *tblname[2] ;
	tblname[0] = fillnam("sdkfjal");
	
    FILE *pfile = fopen("sdkfjal.tbl", "wb");
    fwrite(tblname[0], sizeof(char), STRLENLIMIT, pfile);
    
    fclose(pfile);
    free(tblname);
	

    return 0;
}
