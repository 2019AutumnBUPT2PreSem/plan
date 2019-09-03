#include<stdio.h>
#include<stdlib.h> 
#include"dbstruct.h"
#include"dbio.c"




int main()
{
	FILE *pfile;
	pfile=fopen("test.txt","ab");
	nam name;
	writeItem(pfile,2 ,name);
	fclose(pfile);
    //fwrite(item.c, sizeof(char), 16, pfile);
 
	


/*
	pfile=fopen("test.txt","rb");
    readItem(pfile,1,&pitem[1]);
	fclose(pfile);
*/
	//displayItem(1, &item);
    return 0;
}
